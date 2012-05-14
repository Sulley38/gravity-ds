// Estado 'Puntuación' definido en el autómata

#include <nds.h>
#include <fat.h>
#include <stdio.h>
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

// Variables de los sprites de números
uint8 oamIndex;
static const uint8 Ancho[10] = {13,11,12,12,12,13,11,11,10,10};
// Variables de puntuaciones
uint32 PuntuacionTotal;
static uint32 Puntuaciones[10];
// Variable de control del menú puntuacion
uint8 BotonPulsado_Puntuacion;

/**
 * Lee el fichero de puntuaciones "gravityds-scores.txt" y rellena el vector de puntuaciones.
 * Si el fichero no existe o no llega a 10 números, se llenan los huecos restantes con ceros.
 */
void LeerFicheroPuntuaciones() {
	fatInitDefault();
	// Abre el archivo y lee las puntuaciones guardadas (si las hay)
	uint8 i = 0;
	FILE* archivo = fopen("/NDS/gravityds-scores.txt", "r");
	if( archivo != NULL ) {
		while( !feof(archivo) ) {
			fscanf(archivo, "%d", &Puntuaciones[i]);
			i++;
		}
		fclose(archivo);
	}
	// Rellena las puntuaciones restantes con ceros
	while( i < 10 ) {
		Puntuaciones[i] = 0;
		i++;
	}
}

/**
 * Escribe en el fichero "gravityds-scores.txt" los valores del vector de puntuaciones.
 * Si el fichero no existe, lo crea.
 */
void EscribirFicheroPuntuaciones() {
	uint8 i;
	FILE* archivo = fopen("/NDS/gravityds-scores.txt", "w");
	if( archivo != NULL ) {
		for( i = 0; i < 10; ++i )
			fprintf( archivo, "%d\n", Puntuaciones[i] );
		fclose(archivo);
	}
}

/**
 * Imprime en la pantalla secundaria las puntuaciones leídas.
 * ** OAM Index Sub: se reservan del 0 al 99
 */
void ImprimirPuntuaciones() {
	uint8 i;
	for( i = 0; i < 10; ++i ) {
		if( i < 5 ) imprimir_numeros_sub( 30, 50 + 20*i, Puntuaciones[i], i*10 );
		else imprimir_numeros_sub( 150, 50 + 20*(i-5), Puntuaciones[i], i*10 );
	}
}

/**
 * Dibuja los elementos de la tabla de puntuaciones.
 * ** OAM Index: se reservan del 51 al 80
 */
void CargarPuntuacion() {
	// Carga la tabla como fondo
	cargarFondoPaleta(Fondo2, FondoScoreBitmap, FondoScoreBitmapLen, FondoScorePal, FondoScorePalLen);
	bgShow(Fondo2);

	// Inicializa variables
	oamIndex = 51;
	BotonPulsado_Puntuacion = 0;

	// Puntuación: (Distancia recorrida / 100) + 2 * Monedas recogidas
	PuntuacionTotal = (MonedasRecogidas*2) + (DistanciaRecorrida/100);
	// Imprime las monedas recogidas en la pantalla.
	imprimir_numeros(150, 69, MonedasRecogidas);
	// Imprime la distancia recorrida en la pantalla.
	imprimir_numeros(150, 98, DistanciaRecorrida/100);
	// Imprime los puntos totales obtenidos del jugador
	imprimir_numeros(150, 130, PuntuacionTotal);

	// Guarda la puntuación en el vector, actualiza la pantalla secundaria y guarda el fichero
	InsertarPuntuacion();
	ImprimirPuntuaciones();
	EscribirFicheroPuntuaciones();
}

/*
 * Muestra la puntuación total de la partida.
 * Da la opción de volver a jugar o regresar al menú principal.
 * ** OAM Index: se liberan todos los índices
 * ** OAM Index: se liberan del 100 al 114
 */
void MostrarTablaPuntuacion() {
	if( !BotonPulsado_Puntuacion ) {
		// Espera que se pulse un botón
		BotonPulsado_Puntuacion = pantallaEncuestaPuntuacion();
	} else {
		// Limpiar la pantalla
		bgHide(Fondo2);
		oamClear(&oamMain,0,128);
		oamClear(&oamSub,100,15);
		if( BotonPulsado_Puntuacion == 1 ) {
			// Pasar al estado Cuenta atrás
			InicializarVariablesJuego();
			ESTADO = CUENTA_ATRAS;
		} else {
			// Pasar al estado Menu
			oamClear(&oamSub,0,100);
			CargarMenu();
			ESTADO = MENU;
		}
	}
}

/**
 * Inserta la puntuación obtenida en el vector de puntuaciones.
 * Si no se supera la décima mejor puntuación, no se hace nada.
 */
void InsertarPuntuacion() {
	uint8 i = 10, j;
	// Buscar la posición en la que toca insertar
	while( i > 0 && PuntuacionTotal > Puntuaciones[i-1] ) i--;
	// Desplazar los elementos por debajo una posición más, desechando el último
	for( j = 9; j > i; --j ) Puntuaciones[j] = Puntuaciones[j-1];
	// Insertar la puntuación
	if( i < 10 ) Puntuaciones[i] = PuntuacionTotal;
}


/* Imprime el número indicado en las coordenadas indicadas (X,Y) */
void imprimir_numeros(uint8 X, uint8 Y, uint32 N) {
	uint8 ancho_total = 0;
	// Cálculo del ancho que va a ocupar el número
	uint32 i;
	for( i = N; i >= 10; i /= 10 ) ancho_total += Ancho[i%10];
	// Imprimir de derecha a izquierda
	int16 X_Actual = X + ancho_total;
	for( i = 0; N != 0 || i == 0; i++ ) {
		oamSet(&oamMain,
			oamIndex, // OAM Index
			X_Actual, Y, // Posición X e Y
			0, // Prioridad (menor -> arriba)
			4, // Índice de paleta
			SpriteSize_16x16, SpriteColorFormat_256Color,
			Numeros[N%10], // Puntero al sprite
			-1, FALSE, FALSE, FALSE, FALSE, FALSE
			);
		oamIndex++;
		N /= 10;
		X_Actual -= Ancho[N%10];
	}
}

/* Imprime en la pantalla secundaria el número indicado en las coordenadas indicadas (X,Y) */
void imprimir_numeros_sub(uint8 X, uint8 Y, uint32 N, int oamBase) {
	uint8 ancho_total = 0;
	// Cálculo del ancho que va a ocupar el número
	uint32 i;
	for( i = N; i >= 10; i /= 10 ) ancho_total += Ancho[i%10];
	// Imprimir de derecha a izquierda
	int16 X_Actual = X + ancho_total;
	for( i = 0; N != 0 || i == 0; i++ ) {
		oamSet(&oamSub,
			oamBase + i, // OAM Index
			X_Actual, Y, // Posición X e Y
			0, // Prioridad (menor -> arriba)
			0, // Índice de paleta
			SpriteSize_16x16, SpriteColorFormat_256Color,
			NumerosSub[N%10], // Puntero al sprite
			-1, FALSE, FALSE, FALSE, FALSE, FALSE
			);
		N /= 10;
		X_Actual -= Ancho[N%10];
	}
}
