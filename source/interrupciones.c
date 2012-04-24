/*-------------------------------------
interrupciones.c
-------------------------------------*/

// añadir los includes que sean necesarios
#include <nds.h>
#include "graficos.h"
#include "interrupciones.h"
#include "teclado.h"
#include "temporizadores.h"

//Este procedimiento inicializa la tabla de interrupciones para que el gestor de interrupciones sepa
//qué rutina de atención tiene que ejecutar cuando le llega una petición de interrupción. Además es 
//aquí donde se configuran los registros de control de los periféricos.
void rellenarTablaInt()
{
	irqSet(IRQ_VBLANK,intVBlank);
	irqSet(IRQ_TIMER0,intTemporizador);
	irqSet(IRQ_KEYS,RutTec);

	HabilitarIntTemp();
	HabilitarIntTec();

	prepararTemporizador(1);
}
