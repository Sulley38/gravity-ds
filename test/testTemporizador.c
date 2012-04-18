
#include "temporizadores.h"
#include <nds.h>
#include <stdio.h>

int main() {

	consoleDemoInit();
	irqSet(IRQ_TIMER0,intTemporizador);

	prepararTemporizador(0,1);
	iniciarTemporizador(0);

	while(TRUE) {
		if( tiempo == 60 )
			pararTemporizador(0);

		printf("%d segundos\n",tiempo);
	}

	return 0;
}
