
#include <nds.h>
#include "defines.h"
#include "graficos.h"
#include "interrupciones.h"
#include "sprites.h"

int ESTADO = AVANZAR_PERSONAJE;

int main() {

	/*  COPIAPEGA DEL PRINCIPAL */
	powerOn(POWER_ALL_2D);lcdMainOnBottom();initVideo();rellenarTablaInt();
	initSpriteMem();guardarSpritesEnMemoria();establecerPaletaAvanzarPersonaje();

	/*Empieza lo mio*/
	while(1) {
	}

	return 0;
}
