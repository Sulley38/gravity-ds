// Fichero de prueba del framerate

#include <nds.h>
#include <stdio.h>
#include "graficos.h"
#include "temporizadores.h"

int main() {

	consoleDemoInit();

	// Preparar el temporizador y los VBlank
	irqSet(IRQ_VBLANK,intVBlank);
	irqSet(IRQ_TIMER0,intTemporizador);
	HabilitarIntTemp();
	prepararTemporizador(1);

	// Bucle principal
	int frame = 0, segundo = obtenerTiempo();
	iniciarTemporizador();
	while(1) {

		if( segundo != obtenerTiempo() ) {
			iprintf( "Pintando a %d fps\n", frame );
			zeroFrames();
			segundo = obtenerTiempo();
		}

		/* Espera al siguiente frame */
		frame = getFrames();
		while( frame == getFrames() ) {}
	}



	return 0;
}
