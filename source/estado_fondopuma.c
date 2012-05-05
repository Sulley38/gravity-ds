// Estado 'Fondo Puma' definido en el aut�mata

#include <nds.h>
#include "defines.h"
#include "fondos.h"
#include "estado_fondopuma.h"
#include "temporizadores.h"


/* Cabeceras espec�ficas de cada fondo */
#include "FondoAzul.h"
#include "FondoLogo.h"
#include "FondoPuma.h"
#include "FondoPuntuacion.h"

/**
 * Muestra las im�genes de Puma Corporation y el logo del juego, y espera 3 segundos antes de pasar al men�.
 */
void mostrarPantallaInicio() {

	// Carga la imagen de Puma Corp. y el logo del juego
	cargarFondo(FondoPumaBitmap, Fondo3, FondoPumaBitmapLen);
	cargarFondo(FondoLogoBitmap, FondoSub3, FondoLogoBitmapLen);

	// Espera 3 segundos
	iniciarTemporizador(0);
	while( obtenerTiempo() < 3 );
	pararTemporizador(0);
	resetearTiempo();

	// Carga los fondos principales del juego
	cargarFondo(FondoAzulBitmap, Fondo3, FondoAzulBitmapLen);
	cargarFondo(FondoPuntuacionBitmap, FondoSub3, FondoPuntuacionBitmapLen);

	// Pasa al men�
	ESTADO = MENU;
}
