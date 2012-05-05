// Estado 'Menú' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_menu.h"
#include "sprites.h"


/* Variables de control de la animación del menú */
uint8 DesplazamientoAnimacion = 0;
uint8 Animar = 0;
int pantallaPulsada = 0;

/**
 * Muestra un par de botones con las opciones de jugar o salir.
 * Cambia de estado según lo que se haya pulsado.
 * Al pulsar "Jugar", se crea un efecto de desplazamiento del menú.
 */
void MostrarMenu() {

	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);

	dibujar_botonJugar(60,20-DesplazamientoAnimacion);
	dibujar_botonSalir(60,110+DesplazamientoAnimacion);

	if( !Animar ) {
		// Esperar una entrada táctil del usuario
		if( pos_pantalla.px >= 60 && pos_pantalla.px <= 188  && !pantallaPulsada) {
			if( pos_pantalla.py >= 20 && pos_pantalla.py <= 84 ){
				Animar = 1;
			}
			else if( pos_pantalla.py >= 110 && pos_pantalla.py <= 174 ){
				ESTADO = FIN;
			}
		}
		pantallaPulsada = pos_pantalla.px;
	} else {
		if( DesplazamientoAnimacion == 80 ) {
			// Reestablece la animación
			Animar = 0;
			DesplazamientoAnimacion = 0;
			 // Elimina los botones
			oamClear(&oamMain,120,2);
			oamClear(&oamMain,124,2);
			// Cambio de estado: inicializa las variables y pasa al juego
			InicializarCuentaAtras();
			InicializarVariablesJuego();
			ESTADO = CUENTA_ATRAS;
		} else {
			DesplazamientoAnimacion += 5;
		}
	}


}


/**
 * Dibuja el botón PLAY en la posición (X,Y)
 * ** OAM Index: se reservan el 120 y el 121
 */
void dibujar_botonJugar(int X, int Y) {
	oamSet(&oamMain,
		120, // OAM Index
		X, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		0, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonJugar[0], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		121, // OAM Index
		X + 64, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		0, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonJugar[1], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
}

/**
 * Dibuja el botón RESUME en la posición (X,Y)
 * ** OAM Index: se reservan el 122 y el 123
 */
void dibujar_botonContinuar(int X, int Y) {
	oamSet(&oamMain,
		122, // OAM Index
		X, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		0, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonContinuar[0], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		123, // OAM Index
		X + 64, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		0, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonContinuar[1], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
}

/**
 * Dibuja el botón EXIT en la posición (X,Y)
 * ** OAM Index: se reservan el 124 y el 125
 */
void dibujar_botonSalir(int X, int Y) {
	oamSet(&oamMain,
		124, // OAM Index
		X, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		0, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonSalir[0], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		125, // OAM Index
		X + 64, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		0, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonSalir[1], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
}
