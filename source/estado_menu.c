// Estado 'Men�' definido en el aut�mata

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_cuentaatras.h"
#include "estado_menu.h"
#include "sprites.h"
#include "pantalla.h"


/* Variables de control de la animaci�n del men� */
uint8 DesplazamientoAnimacion = 0;
uint8 Animar = 0;
int pantallaPulsada = 0;

/**
 * Muestra un par de botones con las opciones de jugar o salir.
 * Cambia de estado seg�n lo que se haya pulsado.
 * Al pulsar "Jugar", se crea un efecto de desplazamiento del men�.
 */
void MostrarMenu() {

	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);

	dibujar_botonJugar(60,20-DesplazamientoAnimacion);
	dibujar_botonSalir(60,110+DesplazamientoAnimacion);

	if( !Animar ) {
		// Esperar una entrada t�ctil del usuario
		Animar = pantallaEncuesta();
	} else {
		DesplazamientoAnimacion += 5;
		if( DesplazamientoAnimacion == 80 && Animar==1) {
			// Reestablece la animaci�n
			Animar = 0;
			DesplazamientoAnimacion = 0;
			 // Elimina los botones
			oamClear(&oamMain,120,2);
			oamClear(&oamMain,124,2);
			// Cambio de estado: inicializa las variables y pasa al juego
			InicializarCuentaAtras();
			InicializarVariablesJuego();
			ESTADO = CUENTA_ATRAS;
		}
		else if( DesplazamientoAnimacion == 80 && Animar==2)			ESTADO = FIN;
	}
}


/**
 * Dibuja el bot�n PLAY en la posici�n (X,Y)
 * ** OAM Index: se reservan el 120 y el 121
 */
void dibujar_botonJugar(int X, int Y) {
	oamSet(&oamMain,
		120, // OAM Index
		X, Y, // Posici�n X e Y
		0, // Prioridad (menor -> arriba)
		0, // �ndice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonJugar[0], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		121, // OAM Index
		X + 64, Y, // Posici�n X e Y
		0, // Prioridad (menor -> arriba)
		0, // �ndice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonJugar[1], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
}

/**
 * Dibuja el bot�n RESUME en la posici�n (X,Y)
 * ** OAM Index: se reservan el 122 y el 123
 */
void dibujar_botonContinuar(int X, int Y) {
	oamSet(&oamMain,
		122, // OAM Index
		X, Y, // Posici�n X e Y
		0, // Prioridad (menor -> arriba)
		0, // �ndice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonContinuar[0], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		123, // OAM Index
		X + 64, Y, // Posici�n X e Y
		0, // Prioridad (menor -> arriba)
		0, // �ndice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonContinuar[1], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
}

/**
 * Dibuja el bot�n EXIT en la posici�n (X,Y)
 * ** OAM Index: se reservan el 124 y el 125
 */
void dibujar_botonSalir(int X, int Y) {
	oamSet(&oamMain,
		124, // OAM Index
		X, Y, // Posici�n X e Y
		0, // Prioridad (menor -> arriba)
		0, // �ndice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonSalir[0], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);

	oamSet(&oamMain,
		125, // OAM Index
		X + 64, Y, // Posici�n X e Y
		0, // Prioridad (menor -> arriba)
		0, // �ndice de paleta
		SpriteSize_64x64, SpriteColorFormat_256Color,
		botonSalir[1], // Puntero al sprite
		-1, FALSE, FALSE, FALSE, FALSE, FALSE
		);
}
