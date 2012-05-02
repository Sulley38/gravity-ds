// Fichero de prueba del teclado

#include "defines.h"
#include "teclado.h"
#include <nds.h>
#include <stdio.h>

int ESTADO;

void imprimir() {
	int tecla = 0;
	while( !TECLA_PULSADA(tecla) ) { tecla++; }
	printf( "Has pulsado la tecla %d\n", tecla );
}

int main() {

	consoleDemoInit();
	irqSet(IRQ_KEYS,imprimir);
	HabilitarIntTec();

	iprintf( "Pulsa cualquier tecla.\n" );
	while(TRUE);
	return 0;
}
