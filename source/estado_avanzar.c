// Estado 'Avanzar personaje' definido en el autómata

#include <nds.h>
#include <stdlib.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_pausa.h"
#include "graficos.h"
#include "pantalla.h"
#include "sonido.h"
#include "sprites.h"
#include "temporizadores.h"


/* Variables de estado del personaje */
uint16 DistanciaRecorrida;
uint8 VelocidadHorizontal, VelocidadVertical;
int16 PosicionPersonaje[3]; // [0] = X; [1] = Y; [2] = 0 hacia abajo, 1 hacia arriba

/* Variables de estado de los bloques */
uint16 BloqueExtremoIzq, BloqueExtremoDer;
static const uint16 Bloques[CANTIDAD_BLOQUES][2] = {{0, 0}, {0, 176}, {64, 0}, {64, 176}, {78, 86}, {128, 0}, {128, 176}, {142, 86} , {150, 160}, {168, 16}, {188, 144}, {194, 32}, {206, 86}, {300, 172}, {362, 172}, {400, 106}, {470, 76}, {472, 160}, {536, 40}, {536, 160}, {608, 5}, {672, 5}, {736, 5}, {800, 5}, {879, 112}, {949, 6}, {1044, 170}, {1046, 50}, {1108, 154},{1110, 68}, {1172, 170}, {1174, 82}, {1238, 170}, {1300, 170}, {1322, 84}, {1364, 170}, {1386, 84}, {1398, 154}, {1430, 170}, {1450, 84}, {1476, 100}, {1492, 170}, {1514, 84}, {1524, 154}, {1556, 170}, {1578, 84}, {1604, 100}, {1620, 170}, {1642, 84}, {1652, 154}, {1684, 170}, {1706, 84}, {1732, 100}, {1750, 170}, {1770, 84}, {1780, 154}, {1812, 170}, {1834, 84}, {1860, 100}, {1972, 4}, {2036, 4}, {2100, 4}, {2164, 4}, {2228, 4}, {2292, 4}};

/* Variables de estado de las monedas */
static int16 Monedas[10][3];
int16 SiguienteMoneda;
uint8 NumeroMonedas;
uint8 MonedasRecogidas;

/* Variable de control de la encuesta de teclado */
uint32 TecladoActivo;

/* Inicializa las variables de la partida */
void InicializarVariablesJuego() {
	DistanciaRecorrida = 0;
	VelocidadHorizontal = 3;
	VelocidadVertical = 3;
	PosicionPersonaje[0] = 128;
	PosicionPersonaje[1] = 54;
	PosicionPersonaje[2] = 0;

	BloqueExtremoIzq = 0;
	BloqueExtremoDer = 0;

	NumeroMonedas = 0;
	SiguienteMoneda = (rand() % 401) + 600;
	MonedasRecogidas = 0;

	TecladoActivo = 0;
}


/**
 * Avanza un paso aumentando la distancia recorrida.
 */
void Avanzar() {
	DistanciaRecorrida += VelocidadHorizontal;
}

/**
 * Realiza la encuesta de teclado.
 * Se guarda una variable de control para evitar detecciones múltiples de una tecla pulsada.
 */
void EncuestaTeclado() {
	// Encuesta de teclado
	if( !TecladoActivo && (TECLA_PULSADA(A) || TECLA_PULSADA(B) || TECLA_PULSADA(ARRIBA) || TECLA_PULSADA(ABAJO)) ) {
		if( EnPlataforma() ) // Cambia el sentido de la gravedad cuando se está apoyado en una plataforma
			PosicionPersonaje[2] = !PosicionPersonaje[2];
	} else if( ESTADO == AVANZAR_PERSONAJE && !TecladoActivo && TECLA_PULSADA(START) ) {
		CargarPausa();
		ESTADO = PAUSA; // Entra en el menú de pausa
	}
	TecladoActivo = TECLA_PULSADA(A) || TECLA_PULSADA(B) || TECLA_PULSADA(ARRIBA) || TECLA_PULSADA(ABAJO);
}

/**
 * Actualiza convenientemente los sprites que se muestran en pantalla.
 * Esta función se llama desde el bucle principal, una vez por frame.
 */
void ActualizarPantalla() {

	// Limpia los bloques que hubiera anteriormente
	limpiar_bloques();
	// Dibuja los nuevos bloques que se vean en pantalla
	dibujar_bloques();

	// Actualiza la posicion de las monedas y comprueban si se han tocado
	actualizar_monedas();
	// Dibuja las monedas en la pantalla
	dibujar_monedas();

	// Mueve el personaje en vertical si no está apoyado
	if( !EnPlataforma() ) {
		if( !PosicionPersonaje[2] ) // Hacia abajo
			PosicionPersonaje[1] += VelocidadVertical;
		else  // Hacia arriba
			PosicionPersonaje[1] -= VelocidadVertical;
	}

	// Comprueba si hay choque con una plataforma
	if( Colision() )
		PosicionPersonaje[0] -= VelocidadHorizontal;

	// Actualiza el sprite del personaje para crear la animación
	dibujar_personaje();

	// Comprueba si el personaje ha muerto
	if( PosicionPersonaje[1] + ALTURA_PERSONAJE < 0 || PosicionPersonaje[1] > SCREEN_HEIGHT || PosicionPersonaje[0] + ANCHURA_PERSONAJE < 0 ) {
		oamClear(&oamMain,0,41);
		ESTADO = PUNTUACION;
	}
}


/**
 * Dibuja el personaje del juego en la posición (X,Y) dada por PosicionPersonaje[]
 * El sprite concreto para la animación se calcula a partir del frame actual
 * Si PosicionPersonaje[2] es 1, el sprite se da la vuelta
 * ** OAM Index: se reserva el 0
 */
void dibujar_personaje() {
	oamSet(&oamMain,
		0, // OAM Index
		PosicionPersonaje[0], PosicionPersonaje[1], // Posición X e Y
		1, // Prioridad (menor -> arriba)
		1, // Índice de paleta
		SpriteSize_32x32, SpriteColorFormat_256Color,
		Corredor[(obtenerFrames()%20)/5], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, PosicionPersonaje[2], FALSE
		);
}

/**
 * Dibuja las plataformas que correspondan en pantalla
 * ** OAM Index: se reservan del 1 hasta el 30 (no creo que se llegue nunca a tanto)
 */
void dibujar_bloques() {
	uint8 oam = 1;
	uint16 i;
	for( i = BloqueExtremoIzq; i <= BloqueExtremoDer; i++ ) {
		oamSet(&oamMain,
			oam, // OAM Index
			Bloques[i][0] - DistanciaRecorrida, Bloques[i][1], // Posición X e Y
			2, // Prioridad (menor -> arriba)
			1, // Índice de paleta
			SpriteSize_64x32, SpriteColorFormat_256Color,
			Bloque, // Puntero al sprite
			-1, FALSE, FALSE, FALSE, FALSE, FALSE
			);
		oam++;
	}
}

/**
 * Limpia todas las plataformas de la pantalla y recalcula los bloques que pueden aparecer
 * ** OAM Index: se liberan del 1 hasta el 30
 * Actualiza los índices de los bloques que vayan a entrar en la pantalla en el próximo frame
 */
void limpiar_bloques() {
	// Limpiar los 30 espacios asignados a bloques
	oamClear(&oamMain,1,30);
	// Buscar los bloques que entrarán en la pantalla
	while( Bloques[BloqueExtremoIzq][0] + ANCHURA_BLOQUE < DistanciaRecorrida && BloqueExtremoIzq != CANTIDAD_BLOQUES )
		BloqueExtremoIzq++; // Ya no se ve
	while( Bloques[BloqueExtremoDer][0] < DistanciaRecorrida + SCREEN_WIDTH && BloqueExtremoDer != CANTIDAD_BLOQUES - 1 )
		BloqueExtremoDer++;  // Ahora se ve
}

/**
 * Dibuja las monedas que correspondan en pantalla
 * ** OAM Index: se reservan del 31 hasta el 40
 */
void dibujar_monedas() {
	uint8 i;
	for( i = 0; i < NumeroMonedas; i++ ) {
		oamSet(&oamMain,
			i + 31, // OAM Index
			Monedas[i][0], Monedas[i][1], // Posición X e Y
			1, // Prioridad (menor -> arriba)
			2, // Índice de paleta
			SpriteSize_16x16, SpriteColorFormat_256Color,
			Moneda, // Puntero al sprite
			-1, FALSE, !Monedas[i][2], FALSE, FALSE, FALSE
			);
	}
}

/**
 * Limpia las monedas de la pantalla y recalcula su posición.
 * ** OAM Index: se liberan del 31 hasta el 40
 * Hace invisible la moneda que se ha pulsado y actualiza la puntuación.
 * Reduce la distancia restante para la próxima moneda, y si toca, la añade a la lista.
 */
void actualizar_monedas() {

	// Comprueba si se ha pulsado la moneda y actualiza sus posiciones
	uint8 i;
	for( i = 0; i < NumeroMonedas; i++ ) {
		Monedas[i][0] -= VelocidadHorizontal;
		if( Monedas[i][2] && pantallaEncuestaMoneda(Monedas[i][0], Monedas[i][1]) ) {
			sonidoMoneda();
			MonedasRecogidas++;
			Monedas[i][2] = 0;
		}
	}

	// Comprueba si la primera moneda se va de la pantalla
	if( NumeroMonedas > 0 && Monedas[0][0] < -16 ) {
		for( i = 1; i < NumeroMonedas; i++ ) {
			// Desplaza los elementos de la lista hacia la izquierda
			Monedas[i-1][0] = Monedas[i][0];
			Monedas[i-1][1] = Monedas[i][1];
			Monedas[i-1][2] = Monedas[i][2];
		}
		NumeroMonedas--;
	}

	// Actualiza la distancia restante para la siguiente moneda
	SiguienteMoneda -= VelocidadHorizontal;
	// En caso de que venga una nueva moneda
	if( SiguienteMoneda < 0 ) {
		// Limita el máximo de monedas en pantalla a 10 (pulsadas o no)
		if( NumeroMonedas < 10 ) {
			// Añadir moneda en un Y aleatorio (entre 10 y 162)
			Monedas[NumeroMonedas][0] = 256;
			Monedas[NumeroMonedas][1] = (rand() % 153) + 10;
			Monedas[NumeroMonedas][2] = 1;
			NumeroMonedas++;
		}
		// Calcula aleatoriamente cuándo saldrá la siguiente moneda (entre 200 y 600)
		SiguienteMoneda = (rand() % 401) + 200;
	}

	// Limpia los 10 espacios asignados a monedas
	oamClear(&oamMain,31,10);
}


/**
 * Devuelve 1 si está apoyado en una plataforma, 0 de lo contrario
 */
uint8 EnPlataforma() {
	uint16 i;
	for( i = BloqueExtremoIzq; i <= BloqueExtremoDer; i++ ) {
		if( !PosicionPersonaje[2] ) {
			// Buscar por debajo
			if( (Bloques[i][1] <= PosicionPersonaje[1] + ALTURA_PERSONAJE) && (Bloques[i][1] + VelocidadVertical > PosicionPersonaje[1] + ALTURA_PERSONAJE) && (
				((Bloques[i][0] <= PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida) && (Bloques[i][0] + ANCHURA_BLOQUE > PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida)) ||
				((Bloques[i][0] <= PosicionPersonaje[0] + DistanciaRecorrida) && (Bloques[i][0] + ANCHURA_BLOQUE > PosicionPersonaje[0] + DistanciaRecorrida))
				) ) {
				PosicionPersonaje[1] = Bloques[i][1] - ALTURA_PERSONAJE; // Corrige la posición Y si ha bajado demasiado y ha traspasado un bloque
				return 1;
			}

		} else {
			// Buscar por encima
			if( (Bloques[i][1] + ALTURA_BLOQUE >= PosicionPersonaje[1]) && (Bloques[i][1] + ALTURA_BLOQUE - VelocidadVertical < PosicionPersonaje[1]) && (
				((Bloques[i][0] <= PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida) && (Bloques[i][0] + ANCHURA_BLOQUE > PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida)) ||
				((Bloques[i][0] <= PosicionPersonaje[0] + DistanciaRecorrida) && (Bloques[i][0] + ANCHURA_BLOQUE > PosicionPersonaje[0] + DistanciaRecorrida))
				) ) {
				PosicionPersonaje[1] = Bloques[i][1] + ALTURA_BLOQUE;  // Corrige la posición Y si ha subido demasiado y ha traspasado un bloque
				return 1;
			}

		}
	}
	return 0;
}

/**
 * Devuelve 1 si está chocando con una plataforma, 0 de lo contrario.
 */
uint8 Colision() {
	uint16 i;
	for( i = BloqueExtremoIzq; i <= BloqueExtremoDer; i++ ) {
		if( (Bloques[i][0] <= PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida ) && (Bloques[i][0] + VelocidadHorizontal > PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida) && (
			 ((Bloques[i][1] > PosicionPersonaje[1]) && (Bloques[i][1] < PosicionPersonaje[1] + ALTURA_PERSONAJE)) ||
			 ((Bloques[i][1] + ALTURA_BLOQUE > PosicionPersonaje[1]) && (Bloques[i][1] + ALTURA_BLOQUE < PosicionPersonaje[1] + ALTURA_PERSONAJE))
			) ) {
			PosicionPersonaje[0] = Bloques[i][0] - ANCHURA_PERSONAJE - DistanciaRecorrida; // Corrige la posición X si ha avanzado demasiado y ha traspasado un bloque
			return 1;
		}
	}
	return 0;
}
