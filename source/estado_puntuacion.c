// Estado 'Puntuaci�n' definido en el aut�mata

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_cuentaatras.h"
#include "estado_menu.h"
#include "estado_puntuacion.h"
#include "fondos.h"
#include "sprites.h"
#include "pantalla.h"

// Cabecera del fondo para la tabla de puntuaci�n
#include "FondoScore.h"
// Variable de �ndices de los sprites n�meros
uint8 oamIndex;

/* Imprime el n�mero indicado en las coordenadas indicadas (X,Y) */
void imprimir_numeros(uint8 x, uint8 y, int n) {
	int i, x_centrado, numdigitos = 0;
	for( i = n; i != 0; i /= 10 ) numdigitos++;
	// Para centrarlo
	x_centrado = x + numdigitos*5;
	for( i = 0; n != 0 || i == 0; i++ ) {
		oamSet(&oamMain,
			oamIndex, // OAM Index
			x_centrado - 10*i, y, // Posici�n X e Y
			0, // Prioridad (menor -> arriba)
			4, // �ndice de paleta
			SpriteSize_16x16, SpriteColorFormat_256Color,
			Numeros[n%10], // Puntero al sprite
			-1, FALSE, FALSE, FALSE, FALSE, FALSE
			);
		oamIndex++;
		n /= 10;
	}
}


/**
 * Dibuja los elementos de la tabla de puntuaciones.
 * ** OAM Index: se reservan del 41 al 70
 */
void CargarPuntuacion() {
	/* Carga la tabla como fondo */
	cargarFondoPaleta(Fondo2, FondoScoreBitmap, FondoScoreBitmapLen, FondoScorePal, FondoScorePalLen);
	bgShow(Fondo2);

	/* �ndice OAM inicial */
	oamIndex = 41;

	// Imprime las monedas recogidas en la pantalla.
	imprimir_numeros(140, 67, MonedasRecogidas);
	// Imprime la distancia recorrida en la pantalla.
	imprimir_numeros(150, 96, DistanciaRecorrida/10);
	// Imprime los puntos totales obtenidos del jugador
	// (Distancia recorrida / 10) + 2 * las monedas que se hayan recogido
	imprimir_numeros(130, 129, (MonedasRecogidas*2) + DistanciaRecorrida/10);
}

/*
 * Muestra la puntuaci�n total de la partida.
 * Da la opci�n de volver a jugar o regresar al men� principal.
 * ** OAM Index: se liberan del 0 al 70
 */
void MostrarPuntuacion() {
	// Espera que se pulse un bot�n
	uint8 BotonPulsado = pantallaEncuestaPuntuacion();
	// Limpiar la pantalla
	bgHide(Fondo2);
	oamClear(&oamMain,0,71);
	if( BotonPulsado == 1 ) {
		// Pasar al estado Cuenta atr�s
		InicializarCuentaAtras();
		InicializarVariablesJuego();
		ESTADO = CUENTA_ATRAS;
	} else {
		// Pasar al estado Menu
		CargarMenu();
		ESTADO = MENU;
	}
}


