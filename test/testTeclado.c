// Fichero de prueba del teclado

#include "teclado.h"
#include <nds.h>
#include <stdio.h>

int ESTADO;

int main() {

	consoleDemoInit();
	irqSet(IRQ_KEYS,intTeclado);
	HabilitarIntTec();

	iprintf( "Chicos! Hoy vamos a aprender a contar hasta 20.\n" );
	while(TRUE)	{

	}
	return 0;
}
