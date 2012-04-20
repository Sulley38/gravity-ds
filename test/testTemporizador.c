// Fichero de prueba del temporizador
#include "temporizadores.h"
#include <nds.h>
#include <stdio.h>

int main() {

	consoleDemoInit();
	irqSet(IRQ_TIMER0,intTemporizador);
	HabilitarIntTemp();

	prepararTemporizador(1);

	iprintf( "Chicos! Hoy vamos a aprender a contar hasta 20.\n" );
	iniciarTemporizador();
	while(obtenerTiempo() < 20) {}

	iprintf( "Muy bieeeeen!\n" );
	pararTemporizador();

	iprintf( "Ahora pongo a cero y contamos hasta 10.\n" );
	resetearTiempo();
	iniciarTemporizador();
	while(obtenerTiempo() < 10) {}

	iprintf( "Estupendo! Eso es todo.\n" );
	pararTemporizador();

	while(TRUE) {}

	return 0;
}
