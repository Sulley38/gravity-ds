// Estado 'Puntuación' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "estado_puntuacion.h"
#include "fondos.h"

/* Cabecera del fondo para la tabla de puntuación */
#include "FondoScore.h"

/**
 * Dibuja los elementos de la tabla de puntuaciones.
 */
void CargarPuntuacion() {
	/* Carga la tabla como fondo */
	cargarFondoPaleta(Fondo2, FondoScoreBitmap, FondoScoreBitmapLen, FondoScorePal, FondoScorePalLen);
	bgShow(Fondo2);

	// TODO: rellenar tabla con la puntuación

}

/*
 * Muestra la puntuación total de la partida.
 * Da la opción de volver a jugar o regresar al menú principal.
 */
void MostrarPuntuacion() {

	// TODO: esperar botón pulsado o tecla pulsada
	while(1){

	}

	CargarMenu();
	ESTADO = MENU;
}
