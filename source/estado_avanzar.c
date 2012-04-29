// Estado 'Avanzar personaje' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "graficos.h"
#include "sprites.h"

// Variables de estado
uint32 DistanciaRecorrida = 0;
uint8 VelocidadAvance = 2;
uint8 PosicionPersonaje[3] = {0,128,0}; // [0] = X; [1] = Y; [2] = boolean(Invertir)

uint32 BloqueExtremoIzq = 0, BloqueExtremoDer = 0;
uint32 Bloques[65][2]= {{0, 0}, {0, 176}, {63, 0}, {64, 176}, {78, 86}, {127, 0}, {128, 176}, {142, 86} , {151, 160}, {167, 16}, {187, 144}, {194, 32}, {206, 86}, {299, 172}, {363, 172}, {400, 116}, {471, 76}, {473, 160}, {535, 40}, {537, 160}, {609, 5}, {673, 5}, {737, 5}, {801, 5}, {879, 112}, {949, 6}, {1045, 171}, {1046, 51}, {1109, 155},{1110, 67}, {1173, 171}, {1174, 83}, {1237, 171}, {1301, 171}, {1322, 85}, {1365, 171}, {1386, 85}, {1397, 155}, {1429, 171}, {1450, 85}, {1476, 101}, {1493, 171}, {1514, 85}, {1525, 155}, {1557, 171}, {1578, 85}, {1604, 101}, {1621, 171}, {1642, 85}, {1653, 155}, {1685, 171}, {1706, 85}, {1732, 101}, {1749, 171}, {1770, 85}, {1781, 155}, {1813, 171}, {1834, 85}, {1860, 101}, {1973, 5}, {2037, 5}, {2101, 5}, {2165, 5}, {2229, 5}, {2293, 5}};
uint32 CantidadBloques = 65;


/* Avanza un paso
 * Esta función se llama cada vez que se recibe una interrupción VBlank
 * Se encarga de actualizar los sprites que se muestran en pantalla
 */
void Avanzar() {

	// Actualiza el sprite del personaje para crear la animación
	if( obtenerFrames() == 0 ) {
		dibujar_personaje( 0 );
	} else if( obtenerFrames() == 15 ) {
		dibujar_personaje( 1 );
	} else if( obtenerFrames() == 30 ) {
		dibujar_personaje( 2 );
	} else if( obtenerFrames() == 45 ) {
		dibujar_personaje( 3 );
	}

	// Avanza un poco la distancia recorrida del mapa
	DistanciaRecorrida = DistanciaRecorrida + VelocidadAvance;

	// Limpia los bloques que hubiera anteriormente
	limpiar_bloques();
	// Dibuja los nuevos bloques que se vean en pantalla
	dibujar_bloques();

	// Actualiza las pantallas
	oamUpdate(&oamMain);
	oamUpdate(&oamSub);

}


/**
 * Dibuja el personaje del juego en la posición (X,Y) dada por PosicionPersonaje[]
 * Mov indica el sprite concreto para la animación
 * Si PosicionPersonaje[2] es 1, el sprite se da la vuelta
 * ** OAM Index: se reserva el 0
 */
void dibujar_personaje(uint8 Mov) {

	oamSet(&oamMain,
			0, // OAM Index
			PosicionPersonaje[0], PosicionPersonaje[1], // Posición X e Y
			0, 0, SpriteSize_32x32, SpriteColorFormat_256Color,
			corredor[Mov], // Puntero al sprite
			-1, FALSE, FALSE, FALSE, PosicionPersonaje[2], FALSE
			);

}

/**
 * Dibuja las plataformas que correspondan en pantalla
 * ** OAM Index: se reservan del 1 hasta el 30 (no creo que se llegue nunca a tanto)
 */
void dibujar_bloques() {
	uint8 oam = 1;
	uint32 i;
	for( i = BloqueExtremoIzq; i <= BloqueExtremoDer; i++ ){
		oamSet(&oamMain,
				oam, // OAM Index
				Bloques[i][0] - DistanciaRecorrida, Bloques[i][1], // Posición X e Y
				0, 0, SpriteSize_64x32, SpriteColorFormat_256Color,
				bloque, // Puntero al sprite
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
	while( Bloques[BloqueExtremoIzq][0] + 64 < DistanciaRecorrida ) BloqueExtremoIzq++; // Ya no se ve
	while( Bloques[BloqueExtremoDer][0] < DistanciaRecorrida + 256 && BloqueExtremoDer != CantidadBloques - 1 ) BloqueExtremoDer++;  // Ahora se ve
}
