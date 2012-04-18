// Fichero de prueba del temporizador
#include "temporizadores.h"
#include <nds.h>
#include <stdio.h>

int main() {

	consoleDemoInit();
	irqSet(IRQ_TIMER0,intTemporizador);
	HabilitarIntTemp();

	prepararTemporizador(0,1);
	iniciarTemporizador(0);

	iprintf( "Chicos! Hoy vamos a aprender a contar hasta 20.\n" );
	while(TRUE) {
		if( tiempo > 20 ) {
			iprintf( "Fin de la ejecucion!\n" );
			pararTemporizador(0);
		}
	}

	return 0;
}
