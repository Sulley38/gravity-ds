
#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "sprites.h"

void MostrarMenu() {

	// Esto hay que arreglar

	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);

	oamSet(&oamMain,
		51, // OAM Index
		20, 20, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		0, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		cuadrado, // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
	oamSet(&oamMain,
		52, // OAM Index
		20, 100, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		0, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		cuadrado2, // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);


	oamUpdate(&oamMain);

	if( pos_pantalla.px >= 20 && pos_pantalla.px <= 84 ) {
		if( pos_pantalla.py >= 20 && pos_pantalla.py <= 84 ) {
			 // Elimina los botones
			oamClear(&oamMain,51,2);
			ESTADO = CUENTA_ATRAS;
		} else if( pos_pantalla.py >= 100 && pos_pantalla.py <= 164 ) {
			ESTADO = FIN;
		}
	}

}
