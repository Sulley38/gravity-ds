// Estado 'Puntuación' definido en el autómata

#include <nds.h>
#include <stdio.h>
#include <fat.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_cuentaatras.h"
#include "estado_menu.h"
#include "estado_puntuacion.h"
#include "fondos.h"
#include "sprites.h"
#include "pantalla.h"

// Cabecera del fondo para la tabla de puntuación
#include "FondoScore.h"
// Variable de índices de los sprites números
uint8 oamIndex;

int puntuaciones[10];
int TOTAL_PUNTOS=0;

/* Imprime el número indicado en las coordenadas indicadas (X,Y) */
void imprimir_numeros(uint8 x, uint8 y, int n) {
	int i, x_centrado, numdigitos = 0;
	for( i = n; i != 0; i /= 10 ) numdigitos++;
	// Para centrarlo
	x_centrado = x + numdigitos*5;
	for( i = 0; n != 0 || i == 0; i++ ) {
		oamSet(&oamMain,
			oamIndex, // OAM Index
			x_centrado - 10*i, y, // Posición X e Y
			0, // Prioridad (menor -> arriba)
			4, // Índice de paleta
			SpriteSize_16x16, SpriteColorFormat_256Color,
			Numeros[n%10], // Puntero al sprite
			-1, FALSE, FALSE, FALSE, FALSE, FALSE
			);
		oamIndex++;
		n /= 10;
	}
}

/* Imprime el número indicado en la pantalla secundaria en las coordenadas indicadas (X,Y) */
void imprimir_numeros_sub(uint8 x, uint8 y, int n, int oamBase) {
	int i, x_centrado, numdigitos = 0;
	for( i = n; i != 0; i /= 10 ) numdigitos++;
	// Para centrarlo
	x_centrado = x + numdigitos*5;
	for( i = 0; n != 0 || i == 0; i++ ) {
		oamSet(&oamSub,
			oamBase + i, // OAM Index
			x_centrado - 10*i, y, // Posición X e Y
			0, // Prioridad (menor -> arriba)
			0, // Índice de paleta
			SpriteSize_16x16, SpriteColorFormat_256Color,
			NumerosSub[n%10], // Puntero al sprite
			-1, FALSE, FALSE, FALSE, FALSE, FALSE
			);
		n /= 10;
	}
}


/**
 * Dibuja los elementos de la tabla de puntuaciones.
 * ** OAM Index: se reservan del 51 al 80
 */
void CargarPuntuacion() {
	/* Carga la tabla como fondo */
	cargarFondoPaleta(Fondo2, FondoScoreBitmap, FondoScoreBitmapLen, FondoScorePal, FondoScorePalLen);
	bgShow(Fondo2);

	/* Índice OAM inicial */
	oamIndex = 51;

	// Imprime las monedas recogidas en la pantalla.
	imprimir_numeros(160, 67, MonedasRecogidas);
	// Imprime la distancia recorrida en la pantalla.
	imprimir_numeros(160, 96, DistanciaRecorrida/100);
	TOTAL_PUNTOS =(MonedasRecogidas*2) + DistanciaRecorrida/100;
	// Imprime los puntos totales obtenidos del jugador
	// (Distancia recorrida / 100) + 2 * Monedas recogidas
	imprimir_numeros(160, 129, TOTAL_PUNTOS);
}

/*
 * Muestra la puntuación total de la partida.
 * Da la opción de volver a jugar o regresar al menú principal.
 * ** OAM Index: se liberan todos los índices
 */
void MostrarPuntuacion() {
	// Espera que se pulse un botón
	uint8 BotonPulsado = pantallaEncuestaPuntuacion();
	// Limpiar la pantalla
	bgHide(Fondo2);
	oamClear(&oamMain,0,127);
	oamClear(&oamSub,0,127);
	if( BotonPulsado == 1 ) {
		// Pasar al estado Cuenta atrás
		InicializarCuentaAtras();
		InicializarVariablesJuego();
		ESTADO = CUENTA_ATRAS;
	} else {
		// Pasar al estado Menu
		CargarMenu();
		ESTADO = MENU;
	}
}
/*Inserta en el array la puntuación del jugador si supera la puntuación de almenos el
 *  décimo jugador con puntuacion más baja que se muestra en la pantalla secuandaria*/
void Insertar_Puntuacion(int x, int vector[10]){
	int k=0;
	int i=0;
	while (k<9){
		if (x >= vector[i]){
			i++;}
	k++;
	}
	if (i!=0){
		vector[i-1]=x;
	}

}


void Actualizar_High_Scores(){
	fatInitDefault();
	consoleDemoInit();


	int i=0;

	FILE* test = fopen ("/app_data/Puntuaciones.txt", "r");

	if (test != 0){

		while(!feof(test)){
		fscanf(test,"%d",&puntuaciones[i]);
		i++;
		}
	}
	Insertar_Puntuacion(TOTAL_PUNTOS ,puntuaciones[10]);

	fprintf(test,"%d",puntuaciones[10]);

	fclose(test);
}

