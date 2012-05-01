
#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "sprites.h"

void MostrarMenu() {

	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);

	dibujar_play(60,20);
	dibujar_exit(60,110);

	if( pos_pantalla.px >= 60 && pos_pantalla.px <= 188 ) {
		if( pos_pantalla.py >= 20 && pos_pantalla.py <= 84 ) {
			 // Elimina los botones
			oamClear(&oamMain,51,2);
			ESTADO = CUENTA_ATRAS;
		} else if( pos_pantalla.py >= 110 && pos_pantalla.py <= 174 ) {
			ESTADO = FIN;
		}
	}

}
