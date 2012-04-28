/*
 * testGraficos.c
 *
 *  Created on: 27/04/2012
 *      Author: AAA
 */
#include <nds.h>
#include "defines.h"
#include "sprites.h"

int main() {
	int cuenta=0;
	/*  COPIAPEGA DEL PRINCIPAL */
	powerOn(POWER_ALL_2D);lcdMainOnBottom();	initVideo();initFondos();rellenarTablaInt();mostrarFondoEstrellado();mostrarFondoEstrelladoSub();
	initSpriteMem();guardarSpritesEnMemoria();establecerPaletaPrincipal();establecerPaletaSecundaria();

	/*Empieza lo mio*/
	while(1) {

		dibujar_personaje(20,100);

	}

	return 0;
}
