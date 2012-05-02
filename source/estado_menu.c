// Estado 'Men�' definido en el aut�mata

#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "sprites.h"


/**
 * Muestra un par de botones con las opciones de jugar o salir.
 * Cambia de estado seg�n lo que se haya pulsado.
 */
int animacion=0;
int animar=0;

void MostrarMenu() {

	if (animar)			animacion +=5;

	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);

	dibujar_botonJugar(60,20-animacion);
	dibujar_botonSalir(60,110+animacion);

	if( pos_pantalla.px >= 60 && pos_pantalla.px <= 188 ) {
		if( pos_pantalla.py >= 20 && pos_pantalla.py <= 84 )
			animar=1;
		else if( pos_pantalla.py >= 110 && pos_pantalla.py <= 174 )
			ESTADO = FIN;
	}

	if (animacion==80){
		animacion=0;
		animar=0;
		 // Elimina los botones
		oamClear(&oamMain,120,2);
		oamClear(&oamMain,124,2);
		ESTADO = CUENTA_ATRAS;
	}


}


/**
 * Dibuja el bot�n PLAY en la posici�n (X,Y)
 * ** OAM Index: se reservan el 120 y el 121
 */
void dibujar_botonJugar(uint8 X, uint8 Y) {
	oamSet(&oamMain,
		120, // OAM Index
		X, Y, // Posici�n X e Y
		0, // Prioridad (menor -> arriba)
		0, // �ndice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonJugar[0], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		121, // OAM Index
		X + 64, Y, // Posici�n X e Y
		0, // Prioridad (menor -> arriba)
		0, // �ndice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonJugar[1], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
}

/**
 * Dibuja el bot�n RESUME en la posici�n (X,Y)
 * ** OAM Index: se reservan el 122 y el 123
 */
void dibujar_botonContinuar(uint8 X, uint8 Y) {
	oamSet(&oamMain,
		122, // OAM Index
		X, Y, // Posici�n X e Y
		0, // Prioridad (menor -> arriba)
		0, // �ndice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonContinuar[0], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		123, // OAM Index
		X + 64, Y, // Posici�n X e Y
		0, // Prioridad (menor -> arriba)
		0, // �ndice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonContinuar[1], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
}

/**
 * Dibuja el bot�n EXIT en la posici�n (X,Y)
 * ** OAM Index: se reservan el 124 y el 125
 */
void dibujar_botonSalir(uint8 X, uint8 Y) {
	oamSet(&oamMain,
		124, // OAM Index
		X, Y, // Posici�n X e Y
		0, // Prioridad (menor -> arriba)
		0, // �ndice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonSalir[0], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		125, // OAM Index
		X + 64, Y, // Posici�n X e Y
		0, // Prioridad (menor -> arriba)
		0, // �ndice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonSalir[1], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
}
