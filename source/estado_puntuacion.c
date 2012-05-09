// Estado 'Puntuaci�n' definido en el aut�mata

#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "estado_puntuacion.h"
#include "fondos.h"

/* Cabecera del fondo para la tabla de puntuaci�n */
#include "FondoScore.h"

/**
 * Dibuja los elementos de la tabla de puntuaciones.
 */
void CargarPuntuacion() {
	/* Carga la tabla como fondo */
	cargarFondoPaleta(Fondo2, FondoScoreBitmap, FondoScoreBitmapLen, FondoScorePal, FondoScorePalLen);
	bgShow(Fondo2);

	// TODO: rellenar tabla con la puntuaci�n

}

/*
 * Muestra la puntuaci�n total de la partida.
 * Da la opci�n de volver a jugar o regresar al men� principal.
 */
void MostrarPuntuacion() {

	// TODO: esperar bot�n pulsado o tecla pulsada
	while(1){

	}

	CargarMenu();
	ESTADO = MENU;
}
