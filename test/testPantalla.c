#include <nds.h>
#include <stdio.h>
#include "pantalla.h"

int ESTADO;

int main() {

	consoleDemoInit();
	touchPosition pantalla;

	while(TRUE)	{
		pantalla = posicionPantalla();
		iprintf("%d, %d", pantalla.px, pantalla.py);
	}

	return 0;
}
