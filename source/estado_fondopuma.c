// Estado 'Fondo Puma' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "fondos.h"
#include "estado_fondopuma.h"
#include "estado_menu.h"
#include "temporizadores.h"


/* Cabeceras específicas de cada fondo */
#include "FondoAzul.h"
#include "FondoLogo.h"
#include "FondoPuma.h"
#include "FondoPuntuacion.h"

// Variable para controlar la transparencia del fondo
uint8 Transparencia = 32;

/**
 * Carga la situación inicial antes de entrar al bucle principal.
 */
void CargarEstadoInicial() {
	// Hace transparente el fondo
	REG_BLDCNT = BLEND_FADE_BLACK | BLEND_SRC_BG3;
	REG_BLDY = 16;

	// Carga la imagen de Puma Corp. y el logo del juego
	cargarFondoBitmap(Fondo3, FondoPumaBitmap, FondoPumaBitmapLen);
	cargarFondoBitmap(FondoSub3, FondoLogoBitmap, FondoLogoBitmapLen);

	// Muestra el fondo durante 3 segundos con efecto de transparencia
	iniciarTemporizador(0);
}

/**
 * Muestra la imagen de Puma Corporation con un efecto de transparencia.
 * La transparencia cambia una vez cada dos frames.
 * Tras cuatro segundos, pasa al siguiente estado.
 */
void mostrarPantallaInicio() {
	if( obtenerTiempo() < 3 ) {
		// Ir mostrando el fondo poco a poco
		if( Transparencia > 0 ) Transparencia--;
		REG_BLDY = Transparencia/2;
	} else if( obtenerTiempo() < 4 ) {
		// Ir quitando el fondo poco a poco
		if( Transparencia < 32 ) Transparencia++;
		REG_BLDY = Transparencia/2;
	} else {
		// Detener el temporizador
		pararTemporizador(0);
		resetearTiempo();
		REG_BLDCNT = 0;

		// Carga los fondos principales del juego
		cargarFondoBitmap(Fondo3, FondoAzulBitmap, FondoAzulBitmapLen);
		cargarFondoBitmap(FondoSub3, FondoPuntuacionBitmap, FondoPuntuacionBitmapLen);

		// Pasa al menú
		CargarMenu();
		ESTADO = MENU;
	}
}
