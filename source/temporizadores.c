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
	IE = IE | 1 << 3;

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
void prepararTemporizador(uint8 id, int frecuencia)
{
	int latch = -1;

	latch = 65532 - (1/frecuencia)*33554432;
	if( latch < 0 ) {
		latch = 65532 - (1/frecuencia)*(33554432/64);
		if( latch < 0 ) {
			latch = 65532 - (1/frecuencia)*(33554432/256);
			if( latch < 0 ) {
				latch = 65532 - (1/frecuencia)*(33554432/1024);
				if( latch < 0 ) {
					iprintf( "No se puede contar a tan baja frecuencia\n" );
					latch = 0;
				}
			}
		}
	}

	TIMER0_DAT = latch;
	iprintf( "Latch ajustado a %d\n\n", latch );
	TIMER0_CNT = 3 | 1 << 6; // bits 0, 1 y 6 encendidos
}

void iniciarTemporizador(uint8 id)
{
	TIMER0_CNT = TIMER0_CNT | 1 << 7; // enciende bit 7
}

void pararTemporizador(uint8 id)
{
	TIMER0_CNT = TIMER0_CNT & ~(1 << 7); // apaga bit 7
}

//Rutina de atención a la interrupción del temporizador
void intTemporizador()
{
	tiempo++;
	iprintf( "%d ...\n", tiempo );
}
