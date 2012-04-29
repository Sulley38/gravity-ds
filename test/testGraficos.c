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
extern int cantidad_bloques;
extern int personaje[2];

int main() {


	distancia=0;
	velocidad=2;
	cantidad_bloques=15;
	personaje[0]=0;
	personaje[1]=128;

	int bloques_prueba[15][2]={ {-1, 0}, {0, 168}, {63, 0}, {64, 168}, {78, 78}, {127, 0}, {128, 168}, {142, 78}, {151, 152}, {167, 16}, {187, 136}, {194, 32}, {207, 78}, {299, 164}, {363, 164}};

	/*  COPIAPEGA DEL PRINCIPAL */
	powerOn(POWER_ALL_2D);lcdMainOnBottom();	initVideo();initFondos();rellenarTablaInt();mostrarFondoEstrellado();mostrarFondoEstrelladoSub();
	initSpriteMem();guardarSpritesEnMemoria();establecerPaletaPrincipal();establecerPaletaSecundaria();

	/*Empieza lo mio*/
	while(1) {

		dibujar_personaje(personaje[0],personaje[1],0);

		dibujar_bloques(bloques_prueba,0,16,distancia);
		oamUpdate(&oamMain);

	}

	return 0;
}
