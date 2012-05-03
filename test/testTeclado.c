// Fichero de prueba del teclado

#include <nds.h>
#include <stdio.h>
#include "defines.h"
#include "estado_avanzar.h"

int ESTADO;

int main() {

	consoleDemoInit();
	iprintf( "Pulsa cualquier tecla.\n" );

	int i;
	while(TRUE) {
		for( i = 0; i < 10; ++i ) {
			if( TECLA_PULSADA(i) ) {
				iprintf( "Has pulsado la tecla %d\n", i );
				while( TECLA_PULSADA(i) ); // Espera a que se libere la tecla
			}
		}
	}
	return 0;
}
