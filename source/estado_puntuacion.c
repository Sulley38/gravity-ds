// Estado 'Puntuación' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "estado_puntuacion.h"
#include "fondos.h"

#include "FondoScore.h"


void PedirPuntuacion() {

	cargarFondoBitmap(Fondo3, FondoScoreBitmap, FondoScoreBitmapLen);
	bgSetCenter(Fondo2, 75, 75);
	bgShow(Fondo2);
	bgUpdate();

	while(1){

	}

	CargarMenu();
	ESTADO = MENU;
}
