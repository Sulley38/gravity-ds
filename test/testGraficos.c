
#include <nds.h>
#include "defines.h"
#include "graficos.h"
#include "interrupciones.h"
#include "sprites.h"

int ESTADO = AVANZAR_PERSONAJE;

int main() {

	/*  COPIAPEGA DEL PRINCIPAL */
	powerOn(POWER_ALL_2D);lcdMainOnBottom();initVideo();rellenarTablaInt();
	initSpriteMem();guardarSpritesEnMemoria();cargarPaletaSprites();

	oamSet(&oamMain, //main graphics engine context
		51,           //oam index (0 to 127)
		32, 20,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		2,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
		SpriteSize_64x64,
		SpriteColorFormat_256Color,
		boton_exit[0],                  //pointer to the loaded graphics
		-1,                  //sprite rotation data
		FALSE,               //double the size when rotating?
		FALSE,			//hide the sprite?
		FALSE, FALSE, //vflip, hflip
		FALSE	//apply mosaic
		);

	oamSet(&oamMain, //main graphics engine context
		52,           //oam index (0 to 127)
		96, 20,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		2,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
		SpriteSize_64x64,
		SpriteColorFormat_256Color,
		boton_exit[1],                  //pointer to the loaded graphics
		-1,                  //sprite rotation data
		FALSE,               //double the size when rotating?
		FALSE,			//hide the sprite?
		FALSE, FALSE, //vflip, hflip
		FALSE	//apply mosaic
		);

	oamUpdate(&oamMain);
	/*Empieza lo mio*/
	while(1) {
	}

	return 0;
}
