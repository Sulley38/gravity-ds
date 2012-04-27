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
		if(cuenta>3000){
			oamSet(&oamMain, //main graphics engine context
					0,           //oam index (0 to 127)
					20, 20,   //x and y pixle location of the sprite
					0,                    //priority, lower renders last (on top)
					0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
					SpriteSize_32x32,
					SpriteColorFormat_256Color,
					corredorA,                  //pointer to the loaded graphics
					-1,                  //sprite rotation data
					FALSE,               //double the size when rotating?
					FALSE,			//hide the sprite?
					FALSE, FALSE, //vflip, hflip
					FALSE	//apply mosaic
					);


		}
		else{
			oamSet(&oamMain, //main graphics engine context
					0,           //oam index (0 to 127)
					20, 20,   //x and y pixle location of the sprite
					0,                    //priority, lower renders last (on top)
					0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
					SpriteSize_32x32,
					SpriteColorFormat_256Color,
					corredorB,                  //pointer to the loaded graphics
					-1,                  //sprite rotation data
					FALSE,               //double the size when rotating?
					FALSE,			//hide the sprite?
					FALSE, FALSE, //vflip, hflip
					FALSE	//apply mosaic
					);
		}
		oamUpdate(&oamMain);
		oamUpdate(&oamSub);
		cuenta ++;
		cuenta= cuenta%6000;
	}

	return 0;
}
