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
 * Devuelve un 1 si se ha pulsado la moneda situada en la posición (X,Y)
 */
uint8 pantallaEncuestaMoneda( int16 X, int16 Y ) {
	touchPosition pos_pantalla;
	uint8 tocado = 0;

	touchRead(&pos_pantalla);
	if(pos_pantalla.px >= X && pos_pantalla.px <= X + 16)
		if(pos_pantalla.py >= Y && pos_pantalla.py <= Y + 16)
			tocado = 1 ;

	return tocado;
}
