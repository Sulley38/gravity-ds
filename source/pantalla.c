/**
 * Control de la pantalla táctil por encuesta.
 */

#include <nds.h>
#include "defines.h"
#include "pantalla.h"

/**
 * Devuelve en un entero sin signo de 16 bits la posición que se ha pulsado de la pantalla.
 * Los 8 primeros bits representan la coordenada X y los 8 restantes la coordenada Y.
 * El resultado no se devuelve hasta que se deja de pulsar.
 */
uint16 pantallaEncuesta() {
	touchPosition pos_pantalla;
	uint16 boton = 0;
	uint16 pre = 1;

	oamUpdate(&oamMain);

	while(!boton){
		touchRead(&pos_pantalla);
		if( pos_pantalla.px >= 60 && pos_pantalla.px <= 188 && !pre) {
			if( pos_pantalla.py >= 20 && pos_pantalla.py <= 84 )					boton = 1;
			else if( pos_pantalla.py >= 110 && pos_pantalla.py <= 174 )				boton = 2;
		}
		pre = pos_pantalla.px;
	}
	return boton;
}
