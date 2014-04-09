/*  Copyright 2012 Daniel Franco, Iván Matellanes, Asier Mujika
 *
 *  This file is part of Gravity DS.
 *
 *  Gravity DS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation, either version 3 of the License,
 *  or (at your option) any later version.
 *
 *  Gravity DS is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Gravity DS is distributed. 
 *  If not, see <http://www.gnu.org/licenses/>.
 */

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
	if(pos_pantalla.px >= X - 10 && pos_pantalla.px <= X + 25)
		if(pos_pantalla.py >= Y - 10 && pos_pantalla.py <= Y + 25)
			tocado = 1 ;

	return tocado;
}

/**
 * Devuelve un 1 si se ha pulsado en volver a jugar, o un 2 si se ha pulsado en ir al menú.
 */
uint8 pantallaEncuestaPuntuacion() {
	touchPosition pos_pantalla;
	uint8 boton = 0;
	uint16 pre = 1;

	while( !boton ) {
		touchRead(&pos_pantalla);
		if( pos_pantalla.py >= 160 && pos_pantalla.py <= 190 && !pre ) {
			if( pos_pantalla.px > 5 && pos_pantalla.px <= 120 )
				boton = 1;
			else if( pos_pantalla.px > 140 && pos_pantalla.px <= 220 )
				boton = 2;
		}
		pre = pos_pantalla.px;
	}

	return boton;
}

