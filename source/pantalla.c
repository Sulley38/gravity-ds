
#include <nds.h>
#include "defines.h"

touchPosition pos_pantalla;

touchPosition posicionPantallaEncuesta() {
	touchRead(&pos_pantalla);
	while(pos_pantalla.px == 0 && pos_pantalla.py == 0)
		touchRead(&pos_pantalla);

	return pos_pantalla;
}

touchPosition posicionPantalla() {
	touchRead(&pos_pantalla);
	return pos_pantalla;
}
