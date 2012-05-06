/**
 * Control de la pantalla táctil por encuesta.
 */

#include <nds.h>
#include "defines.h"
#include "pantalla.h"

/**
 * Devuelve en un 1 si se ha pulsado el primer botón, o un 2 si se ha pulsado el segundo.
 */
uint8 pantallaEncuestaMenu() {
	touchPosition pos_pantalla;
	uint8 boton = 0;
	uint16 pre = 1;

	while( !boton ) {
		touchRead(&pos_pantalla);
		if( pos_pantalla.px >= 60 && pos_pantalla.px <= 188 && !pre ) {
			if( pos_pantalla.py >= 20 && pos_pantalla.py <= 84 )
				boton = 1;
			else if( pos_pantalla.py >= 110 && pos_pantalla.py <= 174 )
				boton = 2;
		}
		pre = pos_pantalla.px;
	}

	return boton;
}

/**
 * DANI: Hazte una función que te diga si has pulsado una moneda
 */
uint16 pantallaEncuestaMoneda() {
	// DANI: Implementa aquí
	// Sugerencia: puedes hacer que devuelva 0 si no se ha pulsado una moneda o no se ha pulsado nada,
	// o si se ha pulsado moneda, devuelva su posición o su índice
	return 0;
}
