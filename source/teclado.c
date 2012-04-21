/*-------------------------------------
teclado.c
-------------------------------------*/

// añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "teclado.h"

int tecla; // variable para guardar el valor de la tecla pulsada

//Este procedimiento habilita las interrupciones del teclado
void HabilitarIntTec()
{
	//Para ello primero se deshabilitan todas las interrupciones
	DisableInts();
	//Escribir un 1 en el bit correspondiente al teclado del REG_IE
	IE = IE | 1 << 12;

	TECLAS_CNT = (1 | 1<<1 | 1<<3 | 1 << 14 ) & ~(1<<15);
	//Para acabar, se habilitan todas las interrupciones
	EnableInts();
}

//Este procedimiento deshabilita las interrupciones del teclado
void DeshabilitarIntTec()
{
	//Para ello primero se deshabilitan todas las interrupciones
	DisableInts();
	//Escribir un 0 en el bit correspondiente al teclado del REG_IE
	IE = IE & ~(1 << 12);
	//Para acabar, se habilitan todas las interrupciones
	EnableInts();
}

//Rutina de atención a la interrupción del teclado
void RutTec()
{
	if (TECLAS_DAT==1015){
		iprintf( "START\n");
	}
	else{
		iprintf( " A | B\n");
	}
	DeshabilitarIntTec();
}
