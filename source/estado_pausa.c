#include <nds.h>
#include "defines.h"
#include "estado_pausa.h"
#include "graficos.h"
#include "sprites.h"
#include "pantalla.h"

touchPosition pos_pantalla;

void Pausar() {

	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);

	//Dibujamos los botones
	dibujar_resume(60,20);
	dibujar_exit(60,110);

	oamUpdate(&oamMain);

	if( pos_pantalla.px >= 60 && pos_pantalla.px <= 188 ) {
		if( pos_pantalla.py >= 20 && pos_pantalla.py <= 84 ) {

			oamClear(&oamMain,120,6);// Elimina los botones

			ESTADO = AVANZAR_PERSONAJE;
		} else if( pos_pantalla.py >= 110 && pos_pantalla.py <= 174 ) {
			ESTADO = FIN;
		}
	}
}
