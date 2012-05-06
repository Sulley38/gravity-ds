// Estado 'Avanzar personaje' definido en el aut�mata

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_pausa.h"
#include "graficos.h"
#include "sprites.h"
#include "temporizadores.h"
#include "sonido.h"



/* Variables Globales*/
int PUNTOS_TOTALES=0;
int ESTADO=3;

/* Variables de estado de las monedas */
int posiciones_moneda[9][3]={{260,151,0}, {290,48,0}, {320,213,0}, {350,208,0}, {380,122,0}, {410,159,0}, {440,208,0}, {470,71,1}, {500,214,1}};

/* Variables de estado del personaje */
uint16 DistanciaRecorrida;
uint8 VelocidadHorizontal, VelocidadVertical;
int16 PosicionPersonaje[3]; // [0] = X; [1] = Y; [2] = 0 hacia abajo, 1 hacia arriba

/* Variables de estado de los bloques */
uint16 BloqueExtremoIzq, BloqueExtremoDer;
static const uint16 Bloques[CANTIDAD_BLOQUES][2]= {{0, 0}, {0, 176}, {64, 0}, {64, 176}, {78, 86}, {128, 0}, {128, 176}, {142, 86} , {150, 160}, {168, 16}, {188, 144}, {194, 32}, {206, 86}, {300, 172}, {362, 172}, {400, 106}, {470, 76}, {472, 160}, {536, 40}, {536, 160}, {608, 5}, {672, 5}, {736, 5}, {800, 5}, {879, 112}, {949, 6}, {1044, 170}, {1046, 50}, {1108, 154},{1110, 68}, {1172, 170}, {1174, 82}, {1238, 170}, {1300, 170}, {1322, 84}, {1364, 170}, {1386, 84}, {1398, 154}, {1430, 170}, {1450, 84}, {1476, 100}, {1492, 170}, {1514, 84}, {1524, 154}, {1556, 170}, {1578, 84}, {1604, 100}, {1620, 170}, {1642, 84}, {1652, 154}, {1684, 170}, {1706, 84}, {1732, 100}, {1750, 170}, {1770, 84}, {1780, 154}, {1812, 170}, {1834, 84}, {1860, 100}, {1972, 4}, {2036, 4}, {2100, 4}, {2164, 4}, {2228, 4}, {2292, 4}};

/* Variable de puntuaci�n */
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
 * Se guarda una variable de control para evitar detecciones m�ltiples de una tecla pulsada.
 */
void EncuestaTeclado() {
	// Encuesta de teclado
	if( !TecladoActivo && (TECLA_PULSADA(A) || TECLA_PULSADA(B) || TECLA_PULSADA(ARRIBA) || TECLA_PULSADA(ABAJO)) ) {
		if( EnPlataforma() ) // Cambia el sentido de la gravedad cuando se est� apoyado en una plataforma
			PosicionPersonaje[2] = !PosicionPersonaje[2];
	} else if( ESTADO == AVANZAR_PERSONAJE && !TecladoActivo && TECLA_PULSADA(START) ) {
		CargarPausa();
		ESTADO = PAUSA; // Entra en el men� de pausa
	}
	TecladoActivo = TECLA_PULSADA(A) || TECLA_PULSADA(B) || TECLA_PULSADA(ARRIBA) || TECLA_PULSADA(ABAJO);
}

/**
 * Actualiza convenientemente los sprites que se muestran en pantalla.
 * Esta funci�n se llama desde el bucle principal, una vez por frame.
 */
void ActualizarPantalla() {

	//Dibuja las monedas en la pantalla
	dibujar_monedas();
	//Va actualizando la posicion de las monedas y comprueban si se han tocado
	limpiar_monedas();

	// Limpia los bloques que hubiera anteriormente
	limpiar_bloques();
	// Dibuja los nuevos bloques que se vean en pantalla
	dibujar_bloques();

	// Mueve el personaje en vertical si no est� apoyado
	if( !EnPlataforma() ) {
		if( !PosicionPersonaje[2] ) // Hacia abajo
			PosicionPersonaje[1] += VelocidadVertical;
		else  // Hacia arriba
			PosicionPersonaje[1] -= VelocidadVertical;
	}

	// Comprueba si hay choque con una plataforma
	if( Colision() )
		PosicionPersonaje[0] -= VelocidadHorizontal;

	// Actualiza el sprite del personaje para crear la animaci�n
	dibujar_personaje();

	// Comprueba si el personaje ha muerto
	if( PosicionPersonaje[1] + ALTURA_PERSONAJE < 0 || PosicionPersonaje[1] > SCREEN_HEIGHT || PosicionPersonaje[0] + ANCHURA_PERSONAJE < 0 ) {
		oamClear(&oamMain,0,51);
		ESTADO = PUNTUACION;
	}
}


/**
 * Dibuja el personaje del juego en la posici�n (X,Y) dada por PosicionPersonaje[]
 * El sprite concreto para la animaci�n se calcula a partir del frame actual
 * Si PosicionPersonaje[2] es 1, el sprite se da la vuelta
 * ** OAM Index: se reserva el 0
 */
void dibujar_personaje() {
	oamSet(&oamMain,
		0, // OAM Index
		PosicionPersonaje[0], PosicionPersonaje[1], // Posici�n X e Y
		1, // Prioridad (menor -> arriba)
		1, // �ndice de paleta
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
			Bloques[i][0] - DistanciaRecorrida, Bloques[i][1], // Posici�n X e Y
			1, // Prioridad (menor -> arriba)
			1, // �ndice de paleta
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
 * Actualiza los �ndices de los bloques que vayan a entrar en la pantalla en el pr�ximo frame
 */
void limpiar_bloques() {
	// Limpiar los 30 espacios asignados a bloques
	oamClear(&oamMain,1,30);
	// Buscar los bloques que entrar�n en la pantalla
	while( Bloques[BloqueExtremoIzq][0] + ANCHURA_BLOQUE < DistanciaRecorrida && BloqueExtremoIzq != CANTIDAD_BLOQUES )
		BloqueExtremoIzq++; // Ya no se ve
	while( Bloques[BloqueExtremoDer][0] < DistanciaRecorrida + SCREEN_WIDTH && BloqueExtremoDer != CANTIDAD_BLOQUES - 1 )
		BloqueExtremoDer++;  // Ahora se ve
}


/**
 * Devuelve 1 si est� apoyado en una plataforma, 0 de lo contrario
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
				PosicionPersonaje[1] = Bloques[i][1] - ALTURA_PERSONAJE; // Corrige la posici�n Y si ha bajado demasiado y ha traspasado un bloque
				return 1;
			}

		} else {
			// Buscar por encima
			if( (Bloques[i][1] + ALTURA_BLOQUE >= PosicionPersonaje[1]) && (Bloques[i][1] + ALTURA_BLOQUE - VelocidadVertical < PosicionPersonaje[1]) && (
				((Bloques[i][0] <= PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida) && (Bloques[i][0] + ANCHURA_BLOQUE > PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida)) ||
				((Bloques[i][0] <= PosicionPersonaje[0] + DistanciaRecorrida) && (Bloques[i][0] + ANCHURA_BLOQUE > PosicionPersonaje[0] + DistanciaRecorrida))
				) ) {
				PosicionPersonaje[1] = Bloques[i][1] + ALTURA_BLOQUE;  // Corrige la posici�n Y si ha subido demasiado y ha traspasado un bloque
				return 1;
			}

		}
	}
	return 0;
}

/**
 * Devuelve 1 si est� chocando con una plataforma, 0 de lo contrario.
 */
uint8 Colision() {
	uint16 i;
	for( i = BloqueExtremoIzq; i <= BloqueExtremoDer; i++ ) {
		if( (Bloques[i][0] <= PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida ) && (Bloques[i][0] + VelocidadHorizontal > PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida) && (
			 ((Bloques[i][1] > PosicionPersonaje[1]) && (Bloques[i][1] < PosicionPersonaje[1] + ALTURA_PERSONAJE)) ||
			 ((Bloques[i][1] + ALTURA_BLOQUE > PosicionPersonaje[1]) && (Bloques[i][1] + ALTURA_BLOQUE < PosicionPersonaje[1] + ALTURA_PERSONAJE))
			) ) {
			PosicionPersonaje[0] = Bloques[i][0] - ANCHURA_PERSONAJE - DistanciaRecorrida; // Corrige la posici�n X si ha avanzado demasiado y ha traspasado un bloque
			return 1;
		}
	}
	return 0;
}

/*Dibuja las monedas en la pantalla*/
void dibujar_monedas(){
	int i;
	for (i=0;i<9;i++){
		oamSet(&oamMain,
				i+60, // OAM Index
				posiciones_moneda[i][0],posiciones_moneda[i][1], // Posici�n X e Y
				1, // Prioridad (menor -> arriba)
				2, // �ndice de paleta
				SpriteSize_16x16, SpriteColorFormat_256Color,
				Moneda, // Puntero al sprite
				-1, FALSE, !posiciones_moneda[i][2], FALSE, FALSE, FALSE
				);
	}
}


/*Con esta funci�n comprobamos si se ha tocado una moneda de la pantalla*/
uint8 tocar(uint8 x, uint8 y){

	uint8 tocado = 0;
	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);

if (pos_pantalla.px >= x && pos_pantalla.px <= x+16){
	if (pos_pantalla.py >= y && pos_pantalla.py <= y+16){
		tocado=1;
		sonidoMoneda();
	}
}
return tocado;
}

/* Va actualizando la posicion de las monedas en la pantalla, comprueva si
 * las monedas han llegado al final de la pantalla, en ese caso vuelve
 * a actualizar la posici�n de la moneda poniendola en una posici�n aleatoria
 * de la pantalla. Tambi�n comprueva si alguna moneda se ha tocado, en ese caso
 * sumar� los puntos correspondientes ha cojer una moneda y la har� desaparecer.*/
void limpiar_monedas(){
	int i;
	for (i=0;i<9;i++){
		posiciones_moneda[i][0] -= 1;
		if (posiciones_moneda[i][0]<-26){
			posiciones_moneda[i][0] = 270;
			posiciones_moneda[i][1] = ((posiciones_moneda[i][1]*1397+123)%150)+20;
			posiciones_moneda[i][2] = 1;
		}
		if (tocar(posiciones_moneda[i][0],posiciones_moneda[i][1]) == 1){
			PUNTOS_TOTALES+= 50;
			posiciones_moneda[i][2]=0;
		}
	}


}
