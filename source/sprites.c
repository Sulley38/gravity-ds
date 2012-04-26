/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>
#include "defines.h"
#include "sprites.h"

u16* gfx;
u16* gfx3;
u16* gfx2;
u16* gfxSub;
u16* cuadrado;
u16* cuadrado2;

/* Inicializar la memoria de Sprites. */
void initSpriteMem() {

	oamInit(&oamMain, SpriteMapping_1D_32, FALSE);
	oamInit(&oamSub, SpriteMapping_1D_32, FALSE);

	/* Reserva de memoria para cada sprite que quiera incluirse en la pantalla */
	gfx = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfx2 = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfx3 = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
	gfxSub = oamAllocateGfx(&oamSub, SpriteSize_16x16, SpriteColorFormat_256Color);
	cuadrado = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	cuadrado2 = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
}

/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla principal. El 0 es transparente y los no definidos son negros.
 */
void establecerPaletaPrincipal() {

	SPRITE_PALETTE[1] = RGB15(31,0,0); // los pixels a 1 se mostrarán rojos
	SPRITE_PALETTE[2] = RGB15(0,0,31); // los pixels a 2 se mostrarán azules
}

/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla secundaria. El 0 es transparente y los no definidos son negros.
 */
void establecerPaletaSecundaria() {

	SPRITE_PALETTE_SUB[1] = RGB15(0,31,0); // los pixels a 1 se mostrarán verdes
}

/* Dibujado de un Sprite de 16x16 pixels */
/* Debido al funcionamiento de los bancos de memoria, las primeras cuatro filas 
 * forman el cuadrante superior izquiero, las siguientes, el cuadrante superior 
 * derecho, las siguientes el cuadrante inferior izquierdo y las últimas cuatro
 * filas, el cuadrante inferior derecho, como se muestra al lado.
 */
u8 rombo[256] = 
{
	0,0,0,0,0,0,2,2,0,0,0,0,0,2,2,2,	//	0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,
	0,0,0,0,2,2,2,2,0,0,0,2,2,2,2,2,	//	0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,
	0,0,2,2,2,2,2,2,0,2,2,2,2,2,2,2,	//	0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,	//	0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0,
	2,2,0,0,0,0,0,0,2,2,2,0,0,0,0,0,	//	0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,
	2,2,2,2,0,0,0,0,2,2,2,2,2,0,0,0,	//	0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,
	2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,0,	//	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,	//	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,	//	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,	//	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,	//	0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
	0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,	//	0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,	//	0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,
	1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,	//	0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,
	1,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,	//	0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,
	1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,	//	0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,
};

/* Para cada Sprite que se quiera llevar a pantalla hay que hacer una de estas funciones. */

void guardarSpritesEnMemoria(){ 
	int i;
	for(i = 0; i < 16 * 16 / 2; i++) //muestra un cuadrado en la memoria de la pantalla principal
	{
		gfx[i] = 1 | (1 << 8); 
		// el cuadrado de 16x16 pixels se guarda con todo unos en las primeras 
		// posiciones de la memoria de sprites reservada a la pantalla principal	
		gfxSub[i] = 1 | (1 << 8); 
		// el cuadrado de 16x16 pixels se guarda con todo unos en las primeras 
		// posiciones de la memoria de sprites reservada a la pantalla secundaria
		gfx2[i] = rombo[i*2] | (rombo[(i*2)+1]<<8);
		// el cuadrado de 16x16 pixels se guarda con los valores para dibujar un rombo 
		// a partir del primer cuadrado en la memoria de sprites reservada a la pantalla principal	
		gfx3[i] = rombo[i*2] | (rombo[(i*2)+1]<<8);

	}
	for(i = 0; i < 64 * 64 / 2; i++) {
		cuadrado[i] = 1 | (1 << 8);
		cuadrado2[i] = 2 | (2 << 8);
	}
}
