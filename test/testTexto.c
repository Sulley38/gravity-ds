#include <nds.h>
#include "defines.h"
#include "graficos.h"
#include "interrupciones.h"
#include "sprites.h"
#include "fondos.h"

#include "FondoAzul.h"
#include "font.h"

int ESTADO = AVANZAR_PERSONAJE;

int main(){

	/*  COPIAPEGA DEL PRINCIPAL */
	powerOn(POWER_ALL_2D);lcdMainOnBottom();initVideo();initFondos();rellenarTablaInt();
	cargarSprites();
	cargarFondoBitmap(Fondo3,FondoAzulBitmap,FondoAzulBitmapLen);

	Fondo2 = bgInit(1, BgType_Text4bpp, BgSize_T_256x256, 20, 0);
	bgSetPriority(Fondo2, 0);

	dmaCopy( fontTiles, bgGetGfxPtr(Fondo2), fontTilesLen );
	dmaCopy( fontPal, BG_PALETTE, fontPalLen );

	u16* Mapa = bgGetMapPtr(Fondo2);
	dmaFillHalfWords( 0x2929, Mapa, 256*128 );

	while(1) {
		swiWaitForVBlank();
	}
	return 0;
}
