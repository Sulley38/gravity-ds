#include <nds.h>
#include "defines.h"
#include "graficos.h"
#include "interrupciones.h"
#include "sprites.h"
#include "fondos.h"

#include "FondoScore.h"
#include "FondoAzul.h"

int ESTADO = AVANZAR_PERSONAJE;

void imprimir_numero(int x, int y, int n,int oam_base) {
	int i,x_centrado;
	int log=0;
	for (i=n;i!=0;i /=10){
		log ++;
	}
	//Para centrarlo
	x_centrado = x + log*5;
	for (i=0; n!=0 || i==0;i++){
		oamSet(&oamMain,
			i+oam_base, // OAM Index
			x_centrado-10*i,y, // Posición X e Y
			1, // Prioridad (menor -> arriba)
			4, // Índice de paleta
			SpriteSize_16x16, SpriteColorFormat_256Color,
			Numeros[n%10], // Puntero al sprite
			-1, FALSE, FALSE, FALSE, FALSE, FALSE
			);
		n /= 10;
	}
}

int main(){
	int i=0;

	/*  COPIAPEGA DEL PRINCIPAL */
	powerOn(POWER_ALL_2D);lcdMainOnBottom();initVideo();initFondos();rellenarTablaInt();
	cargarSprites();

	// Pasa al menú
	/*Empieza lo mio*/

	cargarFondoBitmap(Fondo3,FondoAzulBitmap,FondoAzulBitmapLen);
	bgShow(Fondo3);

	cargarFondoPaleta(Fondo2, FondoScoreBitmap, FondoScoreBitmapLen, FondoScorePal, FondoScorePalLen);
	bgShow(Fondo2);
	while(1){
		imprimir_numero(168,65,100,5);


		swiWaitForVBlank();
		oamUpdate(&oamMain);
		i++;
	}
	return 0;
}
