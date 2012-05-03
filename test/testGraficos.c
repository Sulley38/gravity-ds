
#include <nds.h>
#include "defines.h"
#include "graficos.h"
#include "interrupciones.h"
#include "sprites.h"

int ESTADO = AVANZAR_PERSONAJE;
int posiciones_moneda[9][3]={{260,151,1}, {290,48,1}, {320,213,1}, {350,208,1}, {380,122,1}, {410,159,1}, {440,208,1}, {470,71,1}, {500,214,1}};

void dibujar_monedas(){
	int i;
	for (i=0;i<9;i++){
		oamSet(&oamMain,
				i+60, // OAM Index
				posiciones_moneda[i][0],posiciones_moneda[i][1], // Posición X e Y
				1, // Prioridad (menor -> arriba)
				1, // Índice de paleta
				SpriteSize_8x16, SpriteColorFormat_256Color,
				Moneda, // Puntero al sprite
				-1, FALSE, posiciones_moneda[i][2], FALSE, FALSE, FALSE
				);
	}
}

void limpiar_monedas(){
	int i;
	for (i=0;i<9;i++){
		posiciones_moneda[i][0] -= 5;
		if (posiciones_moneda[i][0]<-26){
			posiciones_moneda[i][0] = 270;
			posiciones_moneda[i][1] = ((posiciones_moneda[i][1]*1397+123)%150)+20;
			posiciones_moneda[i][2] = 0;
		}
	}

}

int main(){


	/*  COPIAPEGA DEL PRINCIPAL */
	powerOn(POWER_ALL_2D);lcdMainOnBottom();initVideo();rellenarTablaInt();
	cargarSprites();
	/*Empieza lo mio*/
	while(1){
		dibujar_monedas();
		limpiar_monedas();
		swiWaitForVBlank();
		oamUpdate(&oamMain);
	}
	return 0;
}
