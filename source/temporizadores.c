/*  Copyright 2012 Daniel Franco, Iv�n Matellanes, Asier Mujika
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

/*-------------------------------------
temporizadores.c
-------------------------------------*/

// a�adir los includes que sean necesarios
#include <nds.h>
#include "defines.h"
#include "sonido.h"
#include "temporizadores.h"


// Este procedimiento habilita las interrupciones del temporizador
void HabilitarIntTemp()
{
	//Para ello primero se deshabilitan todas las interrupciones
	DisableInts();

	//Escribir un 1 en los bits correspondientes a los temporizadores 1 y 2 del REG_IE
	IE = IE | 3 << 3;

	//Para acabar, se habilitan todas las interrupciones
	EnableInts();
}		

// Este procedimiento deshabilita las interrupciones del temporizador
void DeshabilitarIntTemp()
{
	//Para ello primero se deshabilitan todas las interrupciones
	DisableInts();

	//Escribir un 0 en los bits correspondientes a los temporizadores 1 y 2 del REG_IE
	IE = IE & ~(3 << 3);

	//Para acabar, se habilitan todas las interrupciones
	EnableInts();
}

/**
 * Establece la frecuencia de interrupci�n del temporizador 'id' a la indicada por el par�metro.
 * La frecuencia se mide en interrupciones por segundo.
 * Se calcula el valor a partir del cual debe contar y se ajusta el registros de control.
 */
void prepararTemporizador(uint8 id, uint16 frecuencia)
{
	int latch = -1, divisor = 0;
	// Calcula el latch
	latch = 65532 - (33554432/frecuencia);
	if( latch < 0 ) {
		latch = 65532 - (33554432/(frecuencia*64));
		divisor = 1;
		if( latch < 0 ) {
			latch = 65532 - (33554432/(frecuencia*256));
			divisor = 2;
			if( latch < 0 ) {
				latch = 65532 - (33554432/(frecuencia*1024));
				divisor = 3;
			}
		}
	}

	if( latch < 0 ) {
		// No se puede contar a la frecuencia indicada: no se activa el temporizador
		TEMP_CONTROL(id) = 0;
	} else {
		// Establece los registros
		TEMP_DATOS(id) = latch;
		TEMP_CONTROL(id) = divisor | 1 << 6; // bits 0 y 1 ajustados, bit 6 encendido
	}
}

/**
 * Activa el temporizador 'id'.
 * Para ello, enciende el bit 7 de su registro de control.
 */
void iniciarTemporizador(uint8 id)
{
	TEMP_CONTROL(id) = TEMP_CONTROL(id) | 1 << 7;
}

/**
 * Desactiva el temporizador 'id'.
 * Para ello, apaga el bit 7 de su registro de control.
 */
void pararTemporizador(uint8 id)
{
	TEMP_CONTROL(id) = TEMP_CONTROL(id) & ~(1 << 7);
}


// ---------------------------------------
// TEMPORIZADOR 0: Contador gen�rico
// ---------------------------------------

// Variable de tiempo transcurrido
uint16 tiempo_juego = 0;

/* Devuelve el tiempo que ha transcurrido desde la activaci�n el temporziador */
uint16 obtenerTiempo()
{
	return tiempo_juego;
}

/* Pone el contador de tiempo a cero */
void resetearTiempo()
{
	tiempo_juego = 0;
}

/* Rutina de atenci�n a la interrupci�n del temporizador 0 */
void intTemporizador0()
{
	tiempo_juego++;
}

// ---------------------------------------
// TEMPORIZADOR 1: Sonido de moneda
// ---------------------------------------

/* Rutina de atenci�n a la interrupci�n del temporizador 1 */
void intTemporizador1() {
	ajustarSonidoMoneda();
}
