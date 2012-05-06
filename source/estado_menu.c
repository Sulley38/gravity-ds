// Estado 'Menú' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_cuentaatras.h"
#include "estado_menu.h"
#include "sprites.h"
#include "pantalla.h"


/* Variables de control de la animación del menú */
uint8 DesplazamientoAnimacion_Menu = 0;
int8 EstadoMenu_Menu = -1;

/**
 * Muestra un par de botones con las opciones de jugar o salir.
 * Funciona por subestados:
 * - Estado 1: Dibuja los botones
 * - Estado 2: Espera a que se pulse la pantalla
 * - Estado 3: Hace la animación y pasa al juego o sale
 */
void MostrarMenu() {
	if( EstadoMenu_Menu < 0 ) {
		// Muestra los botones
		dibujar_botonJugar(60, 20);
		dibujar_botonSalir(60, 110);
		EstadoMenu_Menu = 0;
	} else if( EstadoMenu_Menu == 0 ) {
		// Espera una entrada táctil del usuario
		EstadoMenu_Menu = pantallaEncuestaMenu();
	} else {
		DesplazamientoAnimacion_Menu += 5;
		dibujar_botonJugar(60, 20 - DesplazamientoAnimacion_Menu);
		dibujar_botonSalir(60, 110 + DesplazamientoAnimacion_Menu);
		if( DesplazamientoAnimacion_Menu == 80 && EstadoMenu_Menu == 1 ) {
			// Reestablece la animación
			EstadoMenu_Menu = -1;
			DesplazamientoAnimacion_Menu = 0;
			 // Elimina los botones
			oamClear(&oamMain,120,2);
			oamClear(&oamMain,124,2);
			// Cambio de estado: inicializa las variables y pasa al juego
			InicializarCuentaAtras();
			InicializarVariablesJuego();
			ESTADO = CUENTA_ATRAS;
		} else if( DesplazamientoAnimacion_Menu == 80 && EstadoMenu_Menu == 2 ) {
			// Fin del juego
			ESTADO = FIN;
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
