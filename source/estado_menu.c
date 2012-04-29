
#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "sprites.h"

int ESTADO;

void MostrarMenu() {

	// Esto hay que arreglar

	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);

	oamSet(&oamMain, //main graphics engine context
		0,           //oam index (0 to 127)
		20, 20,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
		SpriteSize_64x64,
		SpriteColorFormat_256Color,
		cuadrado,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data
		FALSE,               //double the size when rotating?
		FALSE,			//hide the sprite?
		FALSE, FALSE, //vflip, hflip
		FALSE	//apply mosaic
		);
	oamSet(&oamMain, //main graphics engine context
		1,           //oam index (0 to 127)
		20,100,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
		SpriteSize_64x64,
		SpriteColorFormat_256Color,
		cuadrado2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data
		FALSE,               //double the size when rotating?
		FALSE,			//hide the sprite?
		FALSE, FALSE, //vflip, hflip
		FALSE	//apply mosaic
		);

	oamUpdate(&oamMain);
	oamUpdate(&oamSub);

	if( pos_pantalla.px >= 20 && pos_pantalla.px <= 84 ) {
		if( pos_pantalla.py >= 20 && pos_pantalla.py <= 84 ) {
			 // Elimina los botones
			oamClearSprite(&oamMain,0);
			oamClearSprite(&oamMain,1);
			ESTADO = AVANZAR_PERSONAJE;
		} else if( pos_pantalla.py >= 100 && pos_pantalla.py <= 164 ) {
			ESTADO = FIN;
		}
	}

}
