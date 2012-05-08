
#include <nds.h>
#include <stdio.h>
#include "fondos.h"
#include "graficos.h"

#include "Teclado.h"

int ESTADO;
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------

	char matriz_teclas[4][10]={
			 {'q','w','e','r','t','y','u','i','o','p'},
			 {'a','s','d','f','g','h','j','k','l','$'},
			 {'z','x','c','v','b','n','m',',','$','$'},
			 {'$','$',' ',' ',' ',' ',' ',' ','$','$'}};

    powerOn(POWER_ALL_2D);lcdMainOnBottom();initVideo();initFondos();
    cargarFondoBitmap(Fondo3, TecladoBitmap, TecladoBitmapLen);

    consoleDemoInit();  //setup the sub screen for printing

	touchPosition pos_pantalla;
	uint16 pre = 1;
	uint8 x_corregida;

	while( 1 ) {
		touchRead(&pos_pantalla);
		if( pos_pantalla.px != 0 && pos_pantalla.py != 0 && !pre ) {
			x_corregida = pos_pantalla.px - (pos_pantalla.px/50)-1;
			iprintf("%c",matriz_teclas[pos_pantalla.py/48][x_corregida/25]);
		}
		pre = pos_pantalla.px;
		swiWaitForVBlank();
	}

    return 0;
}
//
