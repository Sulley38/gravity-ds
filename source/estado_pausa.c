
#include <nds.h>
#include "defines.h"
#include "estado_pausa.h"
#include "graficos.h"
#include "main.h"
#include "sprites.h"
#include "pantalla.h"

touchPosition pos_pantalla;

void Pausar() {

	oamSet(&oamMain, //main graphics engine context
			100,           //oam index (0 to 127)
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
			101,           //oam index (0 to 127)
			80, 20,   //x and y pixle location of the sprite
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
			102,           //oam index (0 to 127)
			140, 20,   //x and y pixle location of the sprite
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
			103,           //oam index (0 to 127)
			170, 20,   //x and y pixle location of the sprite
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
			104,           //oam index (0 to 127)
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
	oamSet(&oamMain, //main graphics engine context
			105,           //oam index (0 to 127)
			80,100,   //x and y pixle location of the sprite
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
	oamSet(&oamMain, //main graphics engine context
			106,           //oam index (0 to 127)
			140,100,   //x and y pixle location of the sprite
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
	oamSet(&oamMain, //main graphics engine context
			107,           //oam index (0 to 127)
			170,100,   //x and y pixle location of the sprite
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

	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);

	if( pos_pantalla.px >= 20 && pos_pantalla.px <= 170 ) {
		if( pos_pantalla.py >= 20 && pos_pantalla.py <= 84 ) {
			ESTADO = AVANZAR_PERSONAJE;
		} else if( pos_pantalla.py >= 100 && pos_pantalla.py <= 164 ) {
			ESTADO = FIN;
		}
	}
}
