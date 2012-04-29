#include <nds.h>
#include <stdio.h>
#include "pantalla.h"

void main(){


	consoleDemoInit();
	touchPosition pantalla;


		while(TRUE)	{
			pantalla = posicionPantalla();
			iprintf("%d, %d", pantalla.px, pantalla.py);
	}

}
