/**
 * Fichero principal del videojuego Gravity-DS
 *  Copyright 2012 - Puma Corporation
 */

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_cuentaatras.h"
#include "estado_menu.h"
#include "estado_pausa.h"
#include "fondos.h"
#include "graficos.h"
#include "interrupciones.h"
#include "sprites.h"

int ESTADO = MENU;

//---------------------------------------------------------------------------------
int main(void){
//---------------------------------------------------------------------------------

	/*  Poner en marcha el motor gráfico 2D. */
    powerOn(POWER_ALL_2D);

	/*
	*  Establecer la pantalla inferior como principal, inicializar el sistema gráfico
	*  y configurar el sistema de fondos.
	*/
	lcdMainOnBottom();
	initVideo();
	initFondos();

	/* Inicializar memoria de sprites y guardar en ella los sprites */
	initSpriteMem();
	guardarSpritesEnMemoria();

	/* Establece la paleta para el primer estado */
	establecerPaletaMenu();

	/* Llena la tabla de interrupciones con las rutinas correspondientes para manejarlas */
	rellenarTablaInt();

	/* Bucle principal */
	while( ESTADO != FIN ) {

		switch( ESTADO ) {
		case MENU:
			MostrarMenu();
		  break;
		case CUENTA_ATRAS:
			HacerCuentaAtras();
		  break;
		case AVANZAR_PERSONAJE:
		  break;
		case PAUSA:
			Pausar();
		  break;
		default:
		  break;
		}

	}

	return 0;
}


//void OriginalMain() {
/* ¿Qué se está haciendo aquí? -- Cambiar este texto por la explicación */
	//touchPosition pos_pantalla;
	//touchRead(&pos_pantalla);
	//while(pos_pantalla.px==0 && pos_pantalla.py==0)
		//touchRead(&pos_pantalla);
	/* Definir variables */
	//touchPosition pos_pantalla;
	//int frame;

	/* ¿Qué se está haciendo aquí? -- Cambiar este texto por la explicación */
	//touchRead(&pos_pantalla);
	//while(pos_pantalla.px==0 && pos_pantalla.py==0)
		//touchRead(&pos_pantalla);

	/* Cada vez que se quiera mostrar un sprite en pantalla hay que hacer una función de estas. */

	/*oamSet(&oamMain, //main graphics engine context
		0,           //oam index (0 to 127)
		pos_pantalla.px, pos_pantalla.py,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
		SpriteSize_16x16,
		SpriteColorFormat_256Color,
		gfx,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data
		FALSE,               //double the size when rotating?
		FALSE,			//hide the sprite?
		FALSE, FALSE, //vflip, hflip
		FALSE	//apply mosaic
		);
	oamSet(&oamMain, //main graphics engine context
		1,           //oam index (0 to 127)
		70,100,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
		SpriteSize_16x16,
		SpriteColorFormat_256Color,
		gfx2,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data
		FALSE,               //double the size when rotating?
		FALSE,			//hide the sprite?
		FALSE, FALSE, //vflip, hflip
		FALSE	//apply mosaic
		);
	oamSet(&oamMain, //main graphics engine context
		2,           //oam index (0 to 127)
		100, 50,   //x and y pixle location of the sprite
		0,                    //priority, lower renders last (on top)
		0,					  //this is the palette index if multiple palettes or the alpha value if bmp sprite
		SpriteSize_16x16,
		SpriteColorFormat_256Color,
		gfx3,                  //pointer to the loaded graphics
		-1,                  //sprite rotation data
		FALSE,               //double the size when rotating?
		FALSE,			//hide the sprite?
		FALSE, FALSE, //vflip, hflip
		FALSE	//apply mosaic
		);
	oamSet(&oamSub,
		0,
		pos_pantalla.px,
		pos_pantalla.py,
		0,
		0,
		SpriteSize_16x16,
		SpriteColorFormat_256Color,
		gfxSub,
		-1,
		FALSE,
		FALSE,
		FALSE, FALSE,
		FALSE
		);
	*/
	/* Espera al siguiente fotograma */
	//frame = getFrames();
	//while( frame == getFrames() ) {}

	//oamUpdate(&oamMain);
	//oamUpdate(&oamSub);
//}
