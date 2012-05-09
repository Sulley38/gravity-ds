// Estado 'Puntuación' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "estado_puntuacion.h"
#include "fondos.h"
#include "sprites.h"
#include "pantalla.h"


/* Cabecera del fondo para la tabla de puntuación */
#include "FondoScore.h"



/* Imprime el número indicado en las coordenadas indicadas (X,Y) */
void imprimir_numeros(int x, int y, int n,int oam_base) {
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


/**
 * Dibuja los elementos de la tabla de puntuaciones.
 */
void CargarPuntuacion() {
	/* Carga la tabla como fondo */
	cargarFondoPaleta(Fondo2, FondoScoreBitmap, FondoScoreBitmapLen, FondoScorePal, FondoScorePalLen);
	bgShow(Fondo2);

	//Imprime las monedas recojidas en la pantalla.
	imprimir_numeros(168, 65, MonedasRecogidas, 5);
	//Imprime La distancia recorrida en la pantalla.
	imprimir_numeros(168, 98, DistanciaRecorrida/100, 10);
	//Imprime los puntos totales obtenidos del jugador(Distancia recorrida + 2* las monedas que se hayan recojido).
	imprimir_numeros(168, 130, (MonedasRecogidas*2)+ DistanciaRecorrida/100 , 15);

}

/*
 * Muestra la puntuación total de la partida.
 * Da la opción de volver a jugar o regresar al menú principal.
 */

void MostrarPuntuacion() {
	CargarPuntuacion();

	while(!pantallaEncuestaPuntuacion()){

	}

	bgHide(Fondo2);
	oamClear(&oamMain,0,41);

	//Pasamos al estado Menu.
	CargarMenu();
	ESTADO = MENU;
}


