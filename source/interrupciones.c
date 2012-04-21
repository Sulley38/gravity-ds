/*-------------------------------------
interrupciones.c
-------------------------------------*/

// a�adir los includes que sean necesarios
#include <nds.h>
#include "interrupciones.h"
#include "teclado.h"
#include "temporizadores.h"

//Este procedimiento inicializa la tabla de interrupciones para que el gestor de interrupciones sepa
//qu� rutina de atenci�n tiene que ejecutar cuando le llega una petici�n de interrupci�n. Adem�s es 
//aqu� donde se configuran los registros de control de los perif�ricos.
void rellenarTablaInt()
{
	irqSet(IRQ_KEYS,RutTec);
	irqSet(IRQ_TIMER0,intTemporizador);

	HabilitarIntTemp();
	HabilitarIntTec();

	prepararTemporizador(1);
}
