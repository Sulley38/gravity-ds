/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>
#include "graficos.h"
#include "sprites.h"

int frame = 0;

/* Definir el sistema de vídeo */
void initVideo() {
    /*  Mapear la memoria VRAM para mostrar gráficos en las dos pantallas. */
    vramSetPrimaryBanks(VRAM_A_MAIN_BG_0x06000000,
                     VRAM_B_MAIN_BG_0x06020000,
                     VRAM_C_SUB_BG_0x06200000,
                     VRAM_E_LCD);

    vramSetBankE(VRAM_E_MAIN_SPRITE);
    vramSetBankD(VRAM_D_SUB_SPRITE);

    /*  Establecer el modo de vídeo de la pantalla principal. */
    videoSetMode(MODE_5_2D | // Establecer el modo gráfico 5
                 DISPLAY_BG2_ACTIVE | // Activar el fondo 2
                 DISPLAY_BG3_ACTIVE); // Activar el fondo 3

    /*  Establecer el modo de vídeo de la pantalla secundaria. */
    videoSetModeSub(MODE_5_2D | // Establecer el modo gráfico 5
                    DISPLAY_BG3_ACTIVE); // Activar el fondo 3
}

/* Pone a cero el contador de frames */
void zeroFrames() {
	frame = 0;
}

/* Devuelve los frames dibujados en lo que va de segundo */
int getFrames() {
	return frame;
}

/** Rutina de atención a las interrupciones de refresco vertical
 * Por defecto, la consola envía una de estas interrupciones 60 veces por segundo (60 fps)
 */
void intVBlank() {
	frame++;
}

void dibujar_personaje(int x, int y, int invertido){

	oamSet(&oamMain, //main graphics engine context
			0,           //oam index (0 to 127)
			x, y,   //x and y pixle location of the sprite
			0,                    //priority, lower renders last (on top)
			0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
			SpriteSize_32x32,
			SpriteColorFormat_256Color,
			corredor[((frame%20)/5)],                  //pointer to the loaded graphics
			-1,                  //sprite rotation data
			FALSE,               //double the size when rotating?
			FALSE,			//hide the sprite?
			FALSE, invertido, //vflip, hflip
			FALSE	//apply mosaic
			);


}

void dibujar_bloques(int pos[3][2],int min,int max, int dist ){
	int oam=1;
	int i;
	for (i=min;i<max;i++){
		oamSet(&oamMain, //main graphics engine context
				oam,           //oam index (0 to 127)
				pos[i][0]-dist, pos[i][1],   //x and y pixle location of the sprite
				0,                    //priority, lower renders last (on top)
				0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
				SpriteSize_64x32,
				SpriteColorFormat_256Color,
				bloque,                  //pointer to the loaded graphics
				-1,                  //sprite rotation data
				FALSE,               //double the size when rotating?
				FALSE,			//hide the sprite?
				FALSE, FALSE, //vflip, hflip
				FALSE	//apply mosaic
				);
		oam++;
	}


}
