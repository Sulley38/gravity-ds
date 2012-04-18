/*-------------------------------------
temporizadores.c
-------------------------------------*/

// añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include "defines.h"

int tiempo = 0;

//Este procedimiento habilita las interrupciones del temporizador
void HabilitarIntTemp()
{
	//Para ello primero se deshabilitan todas las interrupciones
	DisableInts();

	//Escribir un 1 en el bit correspondiente al temporizador del REG_IE
	IE |= 1 << 3;

	//Para acabar, se habilitan todas las interrupciones
	EnableInts();
}		

//Este procedimiento deshabilita las interrupciones del temporizador
void DeshabilitarIntTemp()
{
	//Para ello primero se deshabilitan todas las interrupciones
	DisableInts();

	//Escribir un 0 en el bit correspondiente al remporizador del REG_IE
	IE = IE & ~(1 << 3);

	//Para acabar, se habilitan todas las interrupciones
	EnableInts();
}

//Establece la frecuencia del temporizador id a la indicada en interrupciones/seg
void prepararTemporizador(short id, int frecuencia)
{
	int div[4] = {1, 64, 256, 1024};
	int latch = -1, i = 0;

	while( latch < 0 ) {
		if( i == 4 ) return; // Error
		latch = 65532 - (1/frecuencia)*(33554432/div[i]);
		i++;
	}

	TIMER0_DAT = latch;
	TIMER0_CNT = TIMER0_CNT | 1 << 6 | 1 << 1 | 1 << 0;
}

void iniciarTemporizador(short id)
{
	TIMER0_CNT = TIMER0_CNT | 1 << 7;
}

void pararTemporizador(short id)
{
	TIMER0_CNT = TIMER0_CNT & ~(1 << 7);
}

//Rutina de atención a la interrupción del temporizador
void intTemporizador()
{
	tiempo++;
}
