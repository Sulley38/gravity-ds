#include "teclado.h"
#include <nds.h>
#include <stdio.h>

int main() {

	consoleDemoInit();
	irqSet(IRQ_KEYS,RutTec);
	HabilitarIntTec();

	iprintf( "Chicos! Hoy vamos a aprender a contar hasta 20.\n" );
	while(TRUE)	{

	}
	return 0;
}
