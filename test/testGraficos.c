/*
 * testGraficos.c
 *
 *  Created on: 27/04/2012
 *      Author: AAA
 */
#include <nds.h>
#include "defines.h"
#include "sprites.h"
#include "teclado.h"
#include "interrupciones.h"

extern int distancia;
extern int velocidad;
int main() {
	distancia=0;
	velocidad=0;
	int bloques_prueba[3][2]={{0,132},{64,132},{128,132}};
	HabilitarIntTec();
	rellenarTablaInt();
	/*  COPIAPEGA DEL PRINCIPAL */
	powerOn(POWER_ALL_2D);lcdMainOnBottom();	initVideo();initFondos();rellenarTablaInt();mostrarFondoEstrellado();mostrarFondoEstrelladoSub();
	initSpriteMem();guardarSpritesEnMemoria();establecerPaletaPrincipal();establecerPaletaSecundaria();

	/*Empieza lo mio*/
	while(1) {

		dibujar_personaje(20,100,0);

		dibujar_bloques(bloques_prueba,0,2,distancia);
		oamUpdate(&oamMain);

	}

	return 0;
}
