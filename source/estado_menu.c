// Estado 'Menú' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_cuentaatras.h"
#include "estado_menu.h"
#include "estado_puntuacion.h"
#include "fondos.h"
#include "sprites.h"
#include "pantalla.h"

// Cabeceras de los fondos
#include "FondoLogo2.h"


/* Variables de control del menú */
uint8 DesplazamientoAnimacion_Menu, BotonPulsado_Menu;
int escalaBoton;

/* Carga los elementos del menú */
void CargarMenu() {
	// Inicializa las variables
	DesplazamientoAnimacion_Menu = 0;
	BotonPulsado_Menu = 0;
	escalaBoton = 2048;
	oamAffineTransformation(&oamMain, 1, escalaBoton, 0, 0,  escalaBoton);
	// Carga el fondo del logotipo
	cargarFondoBitmap(FondoSub3, FondoLogo2Bitmap, FondoLogo2BitmapLen);
	// Muestra los botones
	dibujar_botonJugar(60, 20);
	dibujar_botonSalir(60, 110);
}

/**
 * Muestra un par de botones con las opciones de jugar o salir.
 * Espera una respuesta táctil válida y hace una animación cuando la recibe.
 */
void MostrarMenu() {
	if(escalaBoton > 256) {
		escalaBoton = (escalaBoton*933)/1000;
		oamAffineTransformation(&oamMain, 1, escalaBoton, 0, 0, escalaBoton);
		dibujar_botonJugar(60, 20);
		dibujar_botonSalir(60, 110);
	} else {
		// Espera una entrada táctil del usuario
		if( !BotonPulsado_Menu )
			BotonPulsado_Menu = pantallaEncuestaMenu();
		// Hace la animación del menú
		DesplazamientoAnimacion_Menu += 5;
		dibujar_botonJugar(60, 20 - DesplazamientoAnimacion_Menu);
		dibujar_botonSalir(60, 110 + DesplazamientoAnimacion_Menu);
		if( DesplazamientoAnimacion_Menu == 80 && BotonPulsado_Menu == 1 ) {
			 // Elimina los botones
			oamClear(&oamMain,120,2);
			oamClear(&oamMain,124,2);
			// Cambio de estado: inicializa las variables y pasa al juego
			InicializarVariablesJuego();
			ImprimirPuntuaciones();
			ESTADO = CUENTA_ATRAS;
		} else if( DesplazamientoAnimacion_Menu == 80 && BotonPulsado_Menu == 2 ) {
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
	int x_corrector = (64-((64*256)/escalaBoton))/2;
	oamSet(&oamMain,
		120, // OAM Index
		X+x_corrector + 1, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		0, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonJugar[0], // Puntero al sprite
		1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		121, // OAM Index
		X + 64 - x_corrector, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		0, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonJugar[1], // Puntero al sprite
		1, FALSE, FALSE, FALSE, FALSE, FALSE
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
	int x_corrector = (64-((64*256)/escalaBoton))/2;
	oamSet(&oamMain,
		124, // OAM Index
		X + x_corrector + 1, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		0, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonSalir[0], // Puntero al sprite
		1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		125, // OAM Index
		X + 64 - x_corrector, Y, // Posición X e Y
		0, // Prioridad (menor -> arriba)
		0, // Índice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonSalir[1], // Puntero al sprite
		1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
}
