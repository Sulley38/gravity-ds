/*-------------------------------------
temporizadores.c
-------------------------------------*/

// añadir los includes que sean necesarios
#include <nds.h>
#include "defines.h"
#include "graficos.h"
#include "temporizadores.h"

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


// Establece la frecuencia del temporizador 0 a la indicada en interrupciones/seg
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
			}
		}
	}

	if( latch < 0 ) {
		// No se puede contar a la frecuencia indicada: no se activa el temporizador
		DeshabilitarIntTemp();
		TIMER0_CNT = 0;
	} else {
		// Establece los registros
		TIMER0_DAT = latch;
		TIMER0_CNT = divisor | 1 << 6; // bits 0, 1 y 6 encendidos
	}
}

// Activa el temporizador 0
void iniciarTemporizador()
{
	TIMER0_CNT = TIMER0_CNT | 1 << 7; // enciende bit 7
}

// Desactiva el temporizador 0
void pararTemporizador()
{
	TIMER0_CNT = TIMER0_CNT & ~(1 << 7); // apaga bit 7
}

// Rutina de atencion a la interrupcion del temporizador 0
void intTemporizador()
{
	tiempo++;
	zeroFrames();
}
