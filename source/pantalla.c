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
uint16 pantallaTocada() {
	touchPosition screen;
	uint16 posicion = 0;

	// Lee la entrada
	touchRead(&screen);

	// Guarda la posición en la que se ha tocado
	if( screen.px != 0 && screen.px != 0 ) {
		posicion = (screen.px << 8) | screen.py;
		// Espera a que se deje de pulsar la pantalla
		while( screen.px != 0 || screen.px != 0 )
			touchRead(&screen);
	}

	return posicion;
}
