/**
 * Motor gráfico y control de fotogramas por segundo
 */

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "graficos.h"
#include "sprites.h"

uint8 Frame = 0;

/* Definir el sistema de vídeo */
void initVideo() {
    /*  Mapear la memoria VRAM para mostrar gráficos en las dos pantallas. */
    vramSetPrimaryBanks(VRAM_A_MAIN_BG_0x06000000,
                     VRAM_B_MAIN_BG_0x06020000,
                     VRAM_C_SUB_BG_0x06200000,
                     VRAM_D_SUB_SPRITE);

    vramSetBankE(VRAM_E_MAIN_SPRITE);
    vramSetBankF(VRAM_F_LCD);

    /*  Establecer el modo de vídeo de la pantalla principal. */
    videoSetMode(MODE_5_2D | // Establecer el modo gráfico 5
                 DISPLAY_BG2_ACTIVE | // Activar el fondo 2
                 DISPLAY_BG3_ACTIVE); // Activar el fondo 3

    /*  Establecer el modo de vídeo de la pantalla secundaria. */
    videoSetModeSub(MODE_5_2D | // Establecer el modo gráfico 5
                    DISPLAY_BG3_ACTIVE); // Activar el fondo 3
}


/* Devuelve los frames dibujados en lo que va de segundo */
uint8 obtenerFrames() {
	return Frame;
}

/** Rutina de atención a las interrupciones de refresco vertical
 * Por defecto, la consola envía una de estas interrupciones 60 veces por segundo (60 fps)
 */
void intVBlank() {
	Frame++;
	if( Frame == 60 ) Frame = 0;
}

/**
 * Dibujamos el boton PLAY en la pantalla
 */
void dibujar_play(int x, int y){
	oamSet(&oamMain, //main graphics engine context
				120,           //oam index (0 to 127)
				x, y,   //x and y pixle location of the sprite
				0,                    //priority, lower renders last (on top)
				2,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
				SpriteSize_64x64,
				SpriteColorFormat_256Color,
				play[0],                  //pointer to the loaded graphics
				-1,                  //sprite rotation data
				FALSE,               //double the size when rotating?
				FALSE,			//hide the sprite?
				FALSE, FALSE, //vflip, hflip
				FALSE	//apply mosaic
				);

	oamSet(&oamMain, //main graphics engine context
					121,           //oam index (0 to 127)
					x+64, y,   //x and y pixle location of the sprite
					0,                    //priority, lower renders last (on top)
					2,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
					SpriteSize_64x64,
					SpriteColorFormat_256Color,
					play[1],                  //pointer to the loaded graphics
					-1,                  //sprite rotation data
					FALSE,               //double the size when rotating?
					FALSE,			//hide the sprite?
					FALSE, FALSE, //vflip, hflip
					FALSE	//apply mosaic
					);}

/**
 * Dibujamos el boton EXIT en la pantalla
 */
	void dibujar_exit(int x, int y){
		oamSet(&oamMain, //main graphics engine context
							122,           //oam index (0 to 127)
							x, y,   //x and y pixle location of the sprite
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
							123,           //oam index (0 to 127)
							x+64, y,   //x and y pixle location of the sprite
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
	}

	/**
	 * Dibujamos el boton RESUME en la pantalla
	 */
	void dibujar_resume(int x, int y){
			oamSet(&oamMain, //main graphics engine context
								124,           //oam index (0 to 127)
								x, y,   //x and y pixle location of the sprite
								0,                    //priority, lower renders last (on top)
								2,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
								SpriteSize_64x64,
								SpriteColorFormat_256Color,
								resume[0],                  //pointer to the loaded graphics
								-1,                  //sprite rotation data
								FALSE,               //double the size when rotating?
								FALSE,			//hide the sprite?
								FALSE, FALSE, //vflip, hflip
								FALSE	//apply mosaic
								);

			oamSet(&oamMain, //main graphics engine context
								125,           //oam index (0 to 127)
								x+64, y,   //x and y pixle location of the sprite
								0,                    //priority, lower renders last (on top)
								2,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
								SpriteSize_64x64,
								SpriteColorFormat_256Color,
								resume[1],                  //pointer to the loaded graphics
								-1,                  //sprite rotation data
								FALSE,               //double the size when rotating?
								FALSE,			//hide the sprite?
								FALSE, FALSE, //vflip, hflip
								FALSE	//apply mosaic
								);
		}




