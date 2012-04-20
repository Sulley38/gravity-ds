/*-------------------------------------
temporizadores.c
-------------------------------------*/

// añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include "defines.h"

// Variable de tiempo transcurrido
int tiempo = 0;

// Devuelve el tiempo que ha transcurrido de partida
int obtenerTiempo()
{
	return tiempo;
}

// Pone el contador de tiempo a cero
void resetearTiempo()
{
	tiempo = 0;
}

// Este procedimiento habilita las interrupciones del temporizador
void HabilitarIntTemp()
{
	//Para ello primero se deshabilitan todas las interrupciones
	DisableInts();

	//Escribir un 1 en el bit correspondiente al temporizador del REG_IE
	IE = IE | 1 << 3;

	//Para acabar, se habilitan todas las interrupciones
	EnableInts();
}		

// Este procedimiento deshabilita las interrupciones del temporizador
void DeshabilitarIntTemp()
{
	//Para ello primero se deshabilitan todas las interrupciones
	DisableInts();

	//Escribir un 0 en el bit correspondiente al remporizador del REG_IE
	IE = IE & ~(1 << 3);

	//Para acabar, se habilitan todas las interrupciones
	EnableInts();
}

// Establece la frecuencia del temporizador id a la indicada en interrupciones/seg
void prepararTemporizador(int frecuencia)
{
	int latch = -1, divisor = 0;
	// Calcula el latch
	latch = 65532 - (1/frecuencia)*33554432;
	if( latch < 0 ) {
		latch = 65532 - (1/frecuencia)*(33554432/64);
		divisor = 1;
		if( latch < 0 ) {
			latch = 65532 - (1/frecuencia)*(33554432/256);
			divisor = 2;
			if( latch < 0 ) {
				latch = 65532 - (1/frecuencia)*(33554432/1024);
				divisor = 3;
				if( latch < 0 ) {
					iprintf( "No se puede contar a tan baja frecuencia\n" );
					latch = 0;
				}
			}
		}
	}
	// Establece los registros
	TIMER0_DAT = latch;
	TIMER0_CNT = divisor | 1 << 6; // bits 0, 1 y 6 encendidos
	iprintf( "Latch ajustado a %d\nDividiendo la frecuencia al nivel %d\n---------\n", latch, divisor );
}

// Activa el temporizador
void iniciarTemporizador()
{
	TIMER0_CNT = TIMER0_CNT | 1 << 7; // enciende bit 7
}

// Desactiva el temporizador
void pararTemporizador()
{
	TIMER0_CNT = TIMER0_CNT & ~(1 << 7); // apaga bit 7
}

// Rutina de atencion a la interrupcion del temporizador
// Hay que llamar a HabilitarIntTemp() primero, o no se tendrán en cuenta estas interrupciones
void intTemporizador()
{
	tiempo++;
	iprintf( "%d ...\n", tiempo );
}
