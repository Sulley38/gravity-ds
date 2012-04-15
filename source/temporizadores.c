/*-------------------------------------
temporizadores.c
-------------------------------------*/

// añadir los includes que sean necesarios
#include <nds.h>
#include <stdio.h>

//Este procedimiento habilita las interrupciones del temporizador
void HabilitarIntTemp()
{
	//Para ello primero se deshabilitan todas las interrupciones
	//Escribir un 1 en el bit correspondiente al temporizador del REG_IE
	//Para acabar, se habilitan todas las interrupciones
}		

//Este procedimiento deshabilita las interrupciones del temporizador
void DeshabilitarIntTemp()
{
	//Para ello primero se deshabilitan todas las interrupciones
	//Escribir un 0 en el bit correspondiente al remporizador del REG_IE
	//Para acabar, se habilitan todas las interrupciones
}

//Rutina de atención a la interrupción del temporizador
void RutTenp()
{
	//...
}
