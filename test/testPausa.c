#include <nds.h>
#include "defines.h"
#include "estado_pausa.h"
#include "graficos.h"
#include "interrupciones.h"
#include "sprites.h"

int ESTADO;

int main() {
	// LO DEL MAIN
	powerOn(POWER_ALL_2D);lcdMainOnBottom();initVideo();rellenarTablaInt();
	initSpriteMem();guardarSpritesEnMemoria();cargarPaletaSprites();

	// La prueba de los botones
	consoleDemoInit();
	Pausar();
	while(TRUE);
	return 0;
}
