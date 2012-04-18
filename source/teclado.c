/*-------------------------------------
teclado.c
-------------------------------------*/

// a�adir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "graficos.h"

int tecla; // variable para guardar el valor de la tecla pulsada

//Esta funci�n tiene que devolver el valor de la tecla pulsada
int TeclaPulsada() 
{
	//...
	return 0;
}

//Este procedimiento habilita las interrupciones del teclado
void HabilitarIntTec()
{
	//Para ello primero se deshabilitan todas las interrupciones
	//Escribir un 1 en el bit correspondiente al teclado del REG_IE
	//Para acabar, se habilitan todas las interrupciones
}

//Este procedimiento deshabilita las interrupciones del teclado
void DeshabilitarIntTec()
{
	//Para ello primero se deshabilitan todas las interrupciones
	//Escribir un 0 en el bit correspondiente al teclado del REG_IE
	//Para acabar, se habilitan todas las interrupciones
}

//Rutina de atenci�n a la interrupci�n del teclado
void RutTec()
{
	//...
		
}
