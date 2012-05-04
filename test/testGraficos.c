
#include <nds.h>
#include "defines.h"
#include "graficos.h"
#include "interrupciones.h"
#include "sprites.h"

int PUNTOS_TOTALES=0;
int ESTADO = AVANZAR_PERSONAJE;
int posiciones_moneda[9][3]={{260,151,0}, {290,48,0}, {320,213,0}, {350,208,0}, {380,122,0}, {410,159,0}, {440,208,0}, {470,71,1}, {500,214,1}};

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
				-1, FALSE, !posiciones_moneda[i][2], FALSE, FALSE, FALSE
				);
	}
}

//Con esta función comprobamos si se ha tocado una moneda de la pantalla
uint8 tocar(uint8 x, uint8 y){

	uint8 tocado = 0;
	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);

if (pos_pantalla.px >= x && pos_pantalla.px <= x+8){
	if (pos_pantalla.py >= y && pos_pantalla.py <= y+16){
	tocado=1;}
}
return tocado;
}


void limpiar_monedas(){
	int i;
	for (i=0;i<9;i++){
		posiciones_moneda[i][0] -= 1;
		if (posiciones_moneda[i][0]<-26){
			posiciones_moneda[i][0] = 270;
			posiciones_moneda[i][1] = ((posiciones_moneda[i][1]*1397+123)%150)+20;
			posiciones_moneda[i][2] = 1;
		}
		if (tocar(posiciones_moneda[i][0],posiciones_moneda[i][1]) == 1){
			PUNTOS_TOTALES+= 50;
			posiciones_moneda[i][2]=0;
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
