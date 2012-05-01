
#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "sprites.h"

void MostrarMenu() {

	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);

	oamUpdate(&oamMain);

	dibujar_botonJugar(60,20);
	dibujar_botonSalir(60,110);


	if( pos_pantalla.px >= 60 && pos_pantalla.px <= 188 ) {
		if( pos_pantalla.py >= 20 && pos_pantalla.py <= 84 ) {
			 // Elimina los botones
			oamClear(&oamMain,120,2);
			oamClear(&oamMain,124,2);
			ESTADO = CUENTA_ATRAS;
		} else if( pos_pantalla.py >= 110 && pos_pantalla.py <= 174 ) {
			ESTADO = FIN;
		}
	}

}


void dibujar_botonJugar(uint8 X, uint8 Y) {
	oamSet(&oamMain,
		120, // OAM Index
		X, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		2, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonJugar[0], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		121, // OAM Index
		X + 64, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		2, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonJugar[1], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
}

void dibujar_botonContinuar(uint8 X, uint8 Y) {
	oamSet(&oamMain,
		122, // OAM Index
		X, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		2, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonContinuar[0], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		123, // OAM Index
		X + 64, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		2, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonContinuar[1], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
}

void dibujar_botonSalir(uint8 X, uint8 Y) {
	oamSet(&oamMain,
		124, // OAM Index
		X, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		2, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonSalir[0], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		125, // OAM Index
		X + 64, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		2, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonSalir[1], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
}
