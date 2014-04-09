/*  Copyright 2012 Daniel Franco, Iván Matellanes, Asier Mujika
 *
 *  This file is part of Gravity DS.
 *
 *  Gravity DS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation, either version 3 of the License,
 *  or (at your option) any later version.
 *
 *  Gravity DS is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Gravity DS is distributed. 
 *  If not, see <http://www.gnu.org/licenses/>.
 */

// Estado 'Avanzar personaje' definido en el autómata

#include <nds.h>
#include <stdlib.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_pausa.h"
#include "estado_puntuacion.h"
#include "graficos.h"
#include "pantalla.h"
#include "sonido.h"
#include "sprites.h"
#include "temporizadores.h"


/* Variables de estado del personaje */
uint16 DistanciaRecorrida;
uint8 VelocidadHorizontal, VelocidadVertical, VelocidadRecuperacion;
int16 PosicionPersonaje[3]; // [0] = X; [1] = Y; [2] = 0 hacia abajo, 1 hacia arriba

/* Variables de estado de los bloques */
uint16 BloqueExtremoIzq, BloqueExtremoDer;
static const uint16 Bloques[CANTIDAD_BLOQUES][3] = {{0,176,0},{0,100,0},{64,176,0},{64,100,0},{128,176,0},{128,100,0},{192,176,0},{192,100,0},{256,176,0},{256,100,0},{320,176,0},{320,100,0},{384,176,0},{384,160,0},{384,100,0},{448,176,0},{448,100,0},{512,176,0},{512,100,0},{576,176,0},{576,100,0},{640,176,0},{640,100,0},{704,176,0},{704,116,0},{704,100,0},{768,176,0},{832,176,0},{896,176,0},{960,176,0},{1023,0,0},{1024,176,0},{1024,160,0},{1024,144,0},{1087,83,0},{1087,0,0},{1151,83,0},{1151,0,0},{1215,83,0},{1215,16,0},{1215,0,0},{1279,83,0},{1279,0,0},{1343,83,0},{1343,0,0},{1407,83,0},{1407,0,0},{1471,83,0},{1471,67,0},{1471,0,0},{1535,0,0},{1598,143,0},{1598,127,0},{1599,0,0},{1662,143,0},{1662,143,0},{1663,0,0},{1726,143,0},{1726,143,0},{1727,0,0},{1755,75,0},{1790,143,0},{1790,143,0},{1791,0,0},{1819,75,0},{1819,75,0},{1854,143,0},{1854,143,0},{1855,0,0},{1884,75,0},{1884,75,0},{1919,159,0},{1919,16,0},{1948,75,0},{1948,75,0},{1983,143,0},{1983,0,0},{2012,75,0},{2012,75,0},{2047,143,0},{2047,0,0},{2076,75,0},{2076,75,0},{2111,143,0},{2111,0,0},{2140,75,0},{2140,75,0},{2175,143,0},{2175,0,0},{2204,75,0},{2204,75,0},{2239,143,0},{2239,0,0},{2268,75,0},{2268,59,0},{2303,143,0},{2303,0,0},{2367,143,0},{2367,0,0},{2431,143,0},{2431,127,0},{2431,0,0},{2495,143,0},{2495,0,0},{2560,143,0},{2560,72,0},{2560,56,0},{2560,0,0},{2624,143,0},{2624,72,0},{2624,0,0},{2688,127,0},{2688,72,0},{2688,9,0},{2752,127,0},{2752,72,0},{2752,9,0},{2816,127,0},{2816,9,0},{2880,127,0},{2880,9,0},{2931,25,0},{2944,127,0},{2983,41,0},{3008,127,0},{3031,57,0},{3054,143,0},{3078,73,0},{3099,159,0},{3123,89,0},{3147,175,0},{3171,105,0},{3212,175,0},{3235,105,0},{3276,175,0},{3347,89,0},{3385,160,0},{3392,73,0},{3430,144,0},{3438,57,0},{3476,128,0},{3487,41,0},{3525,112,0},{3551,41,0},{3570,96,0},{3615,41,0},{3634,96,0},{3665,128,0},{3679,41,0},{3712,144,0},{3775,144,0},{3809,84,0},{3839,144,0},{3921,67,0},{3955,122,0},{3966,51,0},{3966,51,0},{4019,122,0},{4030,51,0},{4082,122,0},{4094,51,0},{4146,122,0},{4230,28,0},{4294,28,0},{4301,100,0},{4358,28,0},{4365,100,0},{4429,100,0},{4518,18,0},{4561,81,0},{4582,18,0},{4625,81,0},{4646,18,0},{4688,81,0},{4783,0,0},{4847,0,0},{4859,61,0},{4910,0,0},{4923,61,0},{4987,61,0},{5039,0,0},{5199,175,0},{5200,0,0},{5231,65,1},{5231,1,1},{5263,175,0},{5264,0,0},{5327,175,0},{5327,0,0},{5391,175,0},{5391,0,0},{5392,127,1},{5392,63,1},{5455,175,0},{5455,0,0},{5519,175,0},{5519,0,0},{5559,64,1},{5559,0,1},{5582,0,0},{5583,175,0},{5646,0,0},{5647,175,0},{5696,128,1},{5696,64,1},{5710,0,0},{5711,175,0},{5774,127,1},{5774,0,1},{5790,159,0},{5854,159,0},{5900,100,0},{5918,159,0},{5964,100,0},{6017,159,0},{6081,159,0},{6091,100,0},{6155,100,0},{6187,159,0},{6251,159,0},{6380,0,0},{6414,70,0},{6444,0,0},{6555,175,0},{6586,98,0},{6619,175,0},{6773,26,0},{6804,98,0},{6837,26,0},{6968,148,0},{6997,82,0},{7032,148,0},{7150,58,0},{7183,120,0},{7214,58,0},{7341,175,0},{7342,0,0},{7405,175,0},{7406,0,0},{7469,175,0},{7470,0,0},{7475,64,1},{7532,175,0},{7534,0,0},{7596,175,0},{7597,128,1},{7597,0,0},{7597,0,1},{7660,175,0},{7661,0,0},{7758,90,0},{7790,154,0},{7790,20,0},{7822,90,0},{7942,90,0},{7961,154,0},{7961,20,0},{8006,90,0},{8104,176,0},{8104,0,0},{8167,176,0},{8168,0,0},{8231,0,0},{8232,176,0},{8295,0,0},{8296,176,0},{8311,86,0},{8359,0,0},{8360,176,0},{8375,86,0},{8384,160,0},{8400,15,0},{8420,144,0},{8426,31,0},{8439,86,0},{8531,172,0},{8595,172,0},{8647,100,0},{8704,76,0},{8706,160,0},{8767,40,0},{8770,160,0},{8842,5,0},{8906,5,0},{8970,5,0},{9034,5,0},{9112,112,0},{9182,6,0},{9277,171,0},{9278,51,0},{9341,155,0},{9342,67,0},{9405,171,0},{9406,83,0},{9469,171,0},{9533,171,0},{9555,85,0},{9597,171,0},{9619,85,0},{9629,155,0},{9661,171,0},{9683,85,0},{9708,101,0},{9725,171,0},{9747,85,0},{9757,155,0},{9789,171,0},{9811,85,0},{9836,101,0},{9853,171,0},{9875,85,0},{9885,155,0},{9917,171,0},{9939,85,0},{9964,101,0},{9981,171,0},{10003,85,0},{10013,155,0},{10045,171,0},{10067,85,0},{10092,101,0},{10206,5,0},{10270,5,0},{10334,5,0},{10398,5,0},{10462,5,0},{10526,5,0},{10526,5,0},{10526,5,0},{10590,164,0},{10665,19,0},{10729,19,0},{10806,150,0},{10870,150,0},{10934,150,0},{10950,80,0},{10979,64,0},{11021,48,0},{11048,32,0},{11117,3,0},{11181,3,0},{11245,165,0},{11245,3,0},{11245,3,0},{11306,82,0},{11309,165,0},{11370,82,0},{11434,82,0},{11514,159,0},{11578,159,0},{11642,12,0},{11706,82,0},{11706,12,0},{11770,82,0},{11834,124,0},{11898,160,0},{11962,160,0},{12026,21,0},{12098,160,0},{12167,16,0},{12231,16,0},{12243,160,0},{12295,16,0},{12375,160,0},{12449,19,0},{12531,160,0},{12595,160,0},{12659,12,0},{12723,156,0},{12723,12,0},{12787,12,0},{12787,12,0},{12893,161,0},{12957,6,0},{12957,6,0},{13021,6,0},{13066,161,0},{13130,24,0},{13194,24,0},{13217,118,0},{13281,118,0},{13388,164,0},{13452,164,0},{13453,147,0},{13455,32,0},{13516,164,0},{13516,164,0},{13580,164,0},{13622,89,0},{13667,65,0},{13703,42,0},{13772,21,0},{13836,122,0},{13836,21,0},{13900,122,0},{13900,104,0},{13900,21,0},{13964,122,0},{13964,40,0},{13964,21,0},{14028,122,0},{14028,21,0},{14029,104,0},{14092,122,0},{14092,40,0},{14092,40,0},{14092,21,0},{14156,122,0},{14156,21,0},{14157,104,0},{14220,122,0},{14220,40,0},{14220,21,0},{14284,122,0},{14284,21,0},{14285,104,0},{14348,122,0},{14348,40,0},{14348,21,0},{14425,159,0},{14489,159,0},{14501,37,0},{14553,159,0},{14553,142,0},{14565,37,0},{14617,159,0},{14681,159,0},{14682,142,0},{14682,37,0},{14745,159,0},{14809,159,0},{14809,143,0},{14809,127,0},{14809,111,0},{14809,95,0},{14809,79,0},{14809,63,0},{14809,47,0}};
/* Variables de estado de las nubes */
static int16 Nubes[3][3] = {{100,-10,0}, {200,50,0}, {300,20,0}};

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
	VelocidadRecuperacion = 1;
	PosicionPersonaje[0] = 128;
	PosicionPersonaje[1] = 104;
	PosicionPersonaje[2] = 0;

	BloqueExtremoIzq = 0;
	BloqueExtremoDer = 0;

	SiguienteMoneda = (rand() % 401) + 600;
	NumeroMonedas = 0;
	MonedasRecogidas = 0;

	TecladoActivo = 0;
}


/**
 * Avanza un paso aumentando la distancia recorrida.
 * También actualiza la posición de las nubes.
 */
void Avanzar() {
	DistanciaRecorrida += VelocidadHorizontal;
	actualizar_nubes();
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
	// Dibuja las monedas y las nubes en la pantalla
	dibujar_monedas();
	dibujar_nubes();

	// Mueve el personaje en vertical si no está apoyado
	if( !EnPlataforma() ) {
		if( !PosicionPersonaje[2] ) // Hacia abajo
			PosicionPersonaje[1] += VelocidadVertical;
		else  // Hacia arriba
			PosicionPersonaje[1] -= VelocidadVertical;
	}

	// Comprueba si hay choque con una plataforma, si no lo hay y está retrasado (como Intxi) recupera la posición
	if( Colision() )
		PosicionPersonaje[0] -= VelocidadHorizontal;
	else if( PosicionPersonaje[0] < 128 )
		PosicionPersonaje[0] += VelocidadRecuperacion;

	// Actualiza el sprite del personaje para crear la animación
	dibujar_personaje();
	// Actualiza la puntuación en la pantalla superior
	actualizar_puntuacion();

	// Comprueba si el personaje ha muerto
	if( PosicionPersonaje[1] + ALTURA_PERSONAJE < 0 || PosicionPersonaje[1] > SCREEN_HEIGHT || PosicionPersonaje[0] + ANCHURA_PERSONAJE < 0 ) {
		CargarPuntuacion();
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
			3, // Prioridad (menor -> arriba)
			3, // Índice de paleta
			SpriteSize_64x64, SpriteColorFormat_256Color,
			Bloque, // Puntero al sprite
			Bloques[i][2] - 1, FALSE, FALSE, FALSE, FALSE, FALSE
			);
		oam++;
	}
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
			2, // Prioridad (menor -> arriba)
			2, // Índice de paleta
			SpriteSize_16x16, SpriteColorFormat_256Color,
			Moneda, // Puntero al sprite
			-1, FALSE, !Monedas[i][2], FALSE, FALSE, FALSE
			);
	}
}

/**
 * Dibuja las nubes que correspondan en pantalla
 * ** OAM Index: se reservan del 41 hasta el 43
 */
void dibujar_nubes() {
	uint16 i;
	for( i = 0; i < 3; i++ ) {
		oamSet(&oamMain,
			i + 41, // OAM Index
			Nubes[i][0], Nubes[i][1], // Posición X e Y
			3, // Prioridad (menor -> arriba)
			5, // Índice de paleta
			SpriteSize_32x32, SpriteColorFormat_256Color,
			Nube, // Puntero al sprite
			-1, FALSE, FALSE, FALSE, FALSE, FALSE
			);
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
	while( Bloques[BloqueExtremoIzq][0] + ANCHURA_BLOQUE(Bloques[BloqueExtremoIzq][2]) < DistanciaRecorrida && BloqueExtremoIzq != CANTIDAD_BLOQUES )
		BloqueExtremoIzq++; // Ya no se ve
	while( Bloques[BloqueExtremoDer][0] < DistanciaRecorrida + SCREEN_WIDTH && BloqueExtremoDer != CANTIDAD_BLOQUES - 1 )
		BloqueExtremoDer++;  // Ahora se ve
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
 * Recalcula la posición de las nubes.
 */
void actualizar_nubes() {
	uint8 i;
	for( i = 0; i < 3; i++ ) {
		Nubes[i][0] -= VelocidadHorizontal/3;
		if( Nubes[i][0] < -40 ) {
			Nubes[i][0] += 300;
			Nubes[i][1] = rand() % 120;
		}
	}
}

/**
 * Actualiza los contadores de la pantalla secundaria.
 * ** OAM Index Sub: se reservan del 100 al 114
 */
void actualizar_puntuacion() {
	imprimir_numeros_sub(58, 165, DistanciaRecorrida/100, 100);
	imprimir_numeros_sub(205, 165, MonedasRecogidas, 110);
}


/**
 * Devuelve 1 si está apoyado en una plataforma, 0 de lo contrario
 */
uint8 EnPlataforma() {
	uint16 i;
	for( i = BloqueExtremoIzq; i <= BloqueExtremoDer; i++ ) {
		if( !PosicionPersonaje[2] ) {
			// Plataforma por debajo
			if( (Bloques[i][1] <= PosicionPersonaje[1] + ALTURA_PERSONAJE) && (Bloques[i][1] + VelocidadVertical > PosicionPersonaje[1] + ALTURA_PERSONAJE) && (
				((Bloques[i][0] < PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida) && (Bloques[i][0] + ANCHURA_BLOQUE(Bloques[i][2]) > PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida)) ||
				((Bloques[i][0] < PosicionPersonaje[0] + DistanciaRecorrida) && (Bloques[i][0] + ANCHURA_BLOQUE(Bloques[i][2]) > PosicionPersonaje[0] + DistanciaRecorrida))
				) ) {
				PosicionPersonaje[1] = Bloques[i][1] - ALTURA_PERSONAJE; // Corrige la posición Y si ha bajado demasiado y ha traspasado un bloque
				return 1;
			}

		} else {
			// Plataforma por encima
			if( (Bloques[i][1] + ALTURA_BLOQUE(Bloques[i][2]) >= PosicionPersonaje[1]) && (Bloques[i][1] + ALTURA_BLOQUE(Bloques[i][2]) - VelocidadVertical < PosicionPersonaje[1]) && (
				((Bloques[i][0] < PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida) && (Bloques[i][0] + ANCHURA_BLOQUE(Bloques[i][2]) > PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida)) ||
				((Bloques[i][0] < PosicionPersonaje[0] + DistanciaRecorrida) && (Bloques[i][0] + ANCHURA_BLOQUE(Bloques[i][2]) > PosicionPersonaje[0] + DistanciaRecorrida))
				) ) {
				PosicionPersonaje[1] = Bloques[i][1] + ALTURA_BLOQUE(Bloques[i][2]);  // Corrige la posición Y si ha subido demasiado y ha traspasado un bloque
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
		if( !Bloques[i][2] ) {
			// Bloque horizontal
			if( (Bloques[i][0] <= PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida ) && (Bloques[i][0] + VelocidadHorizontal > PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida) && (
				 ((Bloques[i][1] > PosicionPersonaje[1]) && (Bloques[i][1] < PosicionPersonaje[1] + ALTURA_PERSONAJE)) ||
				 ((Bloques[i][1] + ALTURA_BLOQUE(Bloques[i][2]) > PosicionPersonaje[1]) && (Bloques[i][1] + ALTURA_BLOQUE(Bloques[i][2]) < PosicionPersonaje[1] + ALTURA_PERSONAJE))
				) ) {
				PosicionPersonaje[0] = Bloques[i][0] - ANCHURA_PERSONAJE - DistanciaRecorrida; // Corrige la posición X si ha avanzado demasiado y ha traspasado un bloque
				return 1;
			}
		} else {
			// Bloque vertical
			if( (Bloques[i][0] <= PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida ) && (Bloques[i][0] + VelocidadHorizontal > PosicionPersonaje[0] + ANCHURA_PERSONAJE + DistanciaRecorrida) && (
				 ((Bloques[i][1] < PosicionPersonaje[1] + ALTURA_PERSONAJE) && (Bloques[i][1] + ALTURA_BLOQUE(Bloques[i][2]) >= PosicionPersonaje[1] + ALTURA_PERSONAJE)) ||
				 ((Bloques[i][1] < PosicionPersonaje[1]) && (Bloques[i][1] + ALTURA_BLOQUE(Bloques[i][2]) >= PosicionPersonaje[1] ))
				) ) {
				PosicionPersonaje[0] = Bloques[i][0] - ANCHURA_PERSONAJE - DistanciaRecorrida; // Corrige la posición X si ha avanzado demasiado y ha traspasado un bloque
				return 1;
			}
		}
	}
	return 0;
}
