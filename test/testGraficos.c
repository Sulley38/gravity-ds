
#include <nds.h>
#include "defines.h"
#include "graficos.h"
#include "interrupciones.h"
#include "sprites.h"

int ESTADO = AVANZAR_PERSONAJE;

int main() {

	int posiciones_moneda[15][3]=
	/*  COPIAPEGA DEL PRINCIPAL */
	powerOn(POWER_ALL_2D);lcdMainOnBottom();initVideo();rellenarTablaInt();
	cargarSprites();

	oamSet(&oamMain,
			0, // OAM Index
			50,50, // Posición X e Y
			1, // Prioridad (menor -> arriba)
			1, // Índice de paleta
			SpriteSize_16x16, SpriteColorFormat_256Color,
			moneda, // Puntero al sprite
			-1, FALSE, FALSE, FALSE, FALSE, FALSE
			);
	oamUpdate(&oamMain);
	/*Empieza lo mio*/
	while(1);

	return 0;
}
