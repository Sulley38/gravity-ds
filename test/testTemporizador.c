// Fichero de prueba del temporizador
#include "temporizadores.h"
#include <nds.h>
#include <stdio.h>

int main() {

	int tmp = 0;

	consoleDemoInit();
	irqSet(IRQ_TIMER0,intTemporizador);
	HabilitarIntTemp();

	prepararTemporizador(1);

	iprintf( "Chicos! Hoy vamos a aprender a contar hasta 20.\n" );
	iniciarTemporizador();
	while(tmp < 20) {
		if( tmp < obtenerTiempo() ) {
			tmp++;
			iprintf( "%d ...\n", tmp );
		}
	}

	iprintf( "Muy bieeeeen!\n" );
	pararTemporizador();

	iprintf( "Ahora pongo a cero y contamos hasta 10.\n" );
	tmp = 0;
	resetearTiempo();
	iniciarTemporizador();
	while(tmp < 10) {
		if( tmp < obtenerTiempo() ) {
			tmp++;
			iprintf( "%d ...\n", tmp );
		}
	}

	iprintf( "Estupendo! Eso es todo.\n" );
	pararTemporizador();

	while(TRUE) {}

	return 0;
}
