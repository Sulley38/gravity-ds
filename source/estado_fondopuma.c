// Estado 'Fondo Puma' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "fondos.h"
#include "estado_fondopuma.h"
#include "temporizadores.h"


/* Cabeceras específicas de cada fondo */
#include "FondoAzul.h"
#include "FondoLogo.h"
#include "FondoPuma.h"
#include "FondoPuntuacion.h"

uint8 Transparencia = 16;

/**
 * Muestra las imágenes de Puma Corporation y el logo del juego, y espera 3 segundos antes de pasar al menú.
 */
void mostrarPantallaInicio() {
	if( REG_BLDCNT == 0 ) {
		// Carga la imagen de Puma Corp. y el logo del juego
		cargarFondo(FondoPumaBitmap, Fondo3, FondoPumaBitmapLen);
		cargarFondo(FondoLogoBitmap, FondoSub3, FondoLogoBitmapLen);
		// Hace transparente el fondo
		REG_BLDCNT = BLEND_FADE_BLACK | BLEND_SRC_BG3;

		// Muestra el fondo durante 3 segundos con efecto de transparencia
		iniciarTemporizador(0);
	} else if( obtenerTiempo() < 2 ) {
		// Ir mostrando el fondo poco a poco
		if( Transparencia > 0 )
			Transparencia--;
	} else if( obtenerTiempo() < 3 ) {
		// Ir quitando el fondo poco a poco
		if( Transparencia < 16 )
			Transparencia++;
	} else {
		// Detener el temporizador
		pararTemporizador(0);
		resetearTiempo();
		REG_BLDCNT = 0;

		// Carga los fondos principales del juego
		cargarFondo(FondoAzulBitmap, Fondo3, FondoAzulBitmapLen);
		cargarFondo(FondoPuntuacionBitmap, FondoSub3, FondoPuntuacionBitmapLen);

		// Pasa al menú
		ESTADO = MENU;
	}
	REG_BLDY = Transparencia;
}
