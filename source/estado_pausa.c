// Estado 'Pausa' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "estado_pausa.h"
#include "graficos.h"
#include "sprites.h"
#include "pantalla.h"


void Pausar() {

	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);

	dibujar_botonContinuar(60,20);
	dibujar_botonSalir(60,110);

	if( pos_pantalla.px >= 60 && pos_pantalla.px <= 188 ) {
		if( pos_pantalla.py >= 20 && pos_pantalla.py <= 84 ) {
			// Elimina los botones
			oamClear(&oamMain,122,4);
			ESTADO = AVANZAR_PERSONAJE;
		} else if( pos_pantalla.py >= 110 && pos_pantalla.py <= 174 ) {
			ESTADO = FIN;
		}
	}
}

