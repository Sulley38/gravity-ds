// Fichero de prueba del temporizador

#include <nds.h>
#include <stdio.h>
#include "temporizadores.h"

int ESTADO;

int main() {

	int tmp = 0;
	consoleDemoInit();

	// Preparar el temporizador
	irqSet(IRQ_TIMER0,intTemporizador0);
	HabilitarIntTemp();
	prepararTemporizador(1,0);

	// Contar hasta 20
	iprintf( "Chicos! Hoy vamos a aprender a contar hasta 20.\n" );
	iniciarTemporizador(0);
	while(tmp < 20) {
		if( tmp < obtenerTiempo() ) {
			tmp++;
			iprintf( "%d ...\n", tmp );
		}
	}

	iprintf( "Muy bieeeeen!\n" );
	pararTemporizador(0);

	// Poner a cero
	iprintf( "Ahora pongo a cero y contamos hasta 10.\n" );
	tmp = 0;
	resetearTiempo();

	// Contar hasta 10
	iniciarTemporizador(0);
	while(tmp < 10) {
		if( tmp < obtenerTiempo() ) {
			tmp++;
			iprintf( "%d ...\n", tmp );
		}
	}

	iprintf( "Estupendo! Eso es todo.\n" );
	pararTemporizador(0);

	while(TRUE);

	return 0;
}
