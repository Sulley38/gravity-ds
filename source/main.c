/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "graficos.h"
#include "fondos.h"
#include "sprites.h"
#include "defines.h"


//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	/* Definir variables */	
	touchPosition pos_pantalla;

	/*  Poner en marcha el motor gráfico 2D. */
    powerOn(POWER_ALL_2D);

	/*
	*  Establecer la pantalla inferior como principal, inicializar el sistema gráfico
	*  y configurar el sistema de fondos.
	*/
	lcdMainOnBottom();
	initVideo();
	initFondos();

	/* Mostrar fondos en pantalla. */
	mostrarFondoEstrellado();
	mostrarFondoEstrelladoSub();

	/* Inicializar memoria de sprites y guardar en ella los sprites */
	initSpriteMem();
	guardarSpritesEnMemoria();

	/* Establecer las paletas para los sprites */
	establecerPaletaPrincipal();
	establecerPaletaSecundaria();

	/* Para poder imprimir en pantalla (hacer trazas) hay que descomentar esta línea */
	//consoleDemoInit();
	/* Una vez descomentada, no se verán los gráficos de la pantalla superior. */	

	while(1) {

		/* ¿Qué se está haciendo aquí? -- Cambiar este texto por la explicación */
		touchRead(&pos_pantalla);
		while(pos_pantalla.px==0 && pos_pantalla.py==0)
			touchRead(&pos_pantalla);

		/* Cada vez que se quiera mostrar un sprite en pantalla hay que hacer una función de estas. */
	
		oamSet(&oamMain, //main graphics engine context
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
		
		oamUpdate(&oamMain);
		oamUpdate(&oamSub);
	}

	return 0;
}
