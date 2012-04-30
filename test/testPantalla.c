#include <nds.h>
#include <stdio.h>
#include "pantalla.h"

int ESTADO;

int main() {

	consoleDemoInit();
	touchPosition pantalla;

	while(TRUE)	{
		pantalla = posicionPantalla();
		if( pantalla.px != 0 || pantalla.py != 0 )
			iprintf("Has tocado en: (%d, %d)\n", pantalla.px, pantalla.py);
	}

	return 0;
}
