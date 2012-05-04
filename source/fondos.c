/**
 * Mecanismo para mostrar im�genes est�ticas de fondo de pantalla
 */

#include <nds.h>
#include "fondos.h"


/* A�adir aqu� los includes para cada fondo. */
#include "FondoAzul.h"
#include "FondoLogo.h"
#include "FondoPuma.h"
#include "FondoPuntuacion.h"


/* Identificadores de los fondos */
static int Fondo2, Fondo3, FondoSub3;

/* Procedimiento para configurar el sistema de fondos. */
void initFondos() {
	// Fondo 2 de la pantalla principal (alta prioridad)
	Fondo2 = bgInit(2, BgType_Bmp16, BgSize_B16_128x128, 0, 0);
	bgSetPriority(Fondo2, 0);
	// Fondo 3 de la pantalla principal (baja prioridad)
	Fondo3 = bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 4, 0);
	bgSetPriority(Fondo3, 3);
	// Fondo 3 de la pantalla secundaria (baja prioridad)
	FondoSub3 = bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	bgSetPriority(FondoSub3, 3);
}

/* Para cada imagen que se quiera llevar a pantalla hay que hacer una de estas funciones. */

void mostrarFondoPuma() {
    dmaCopy(FondoPumaBitmap, /* Variable generada autom�ticamente */
    		bgGetGfxPtr(Fondo3), /* Direcci�n del fondo 3 principal */
            FondoPumaBitmapLen); /* Longitud (en bytes) generada autom�ticamente */
}

void mostrarFondoAzul() {
    dmaCopy(FondoAzulBitmap, /* Variable generada autom�ticamente */
            bgGetGfxPtr(Fondo3), /* Direcci�n del fondo 3 principal */
            FondoAzulBitmapLen); /* Longitud (en bytes) generada autom�ticamente */
}

void mostrarFondoLogo() {
    dmaCopy(FondoLogoBitmap, /* Variable generada autom�ticamente */
            bgGetGfxPtr(FondoSub3), /* Direcci�n del fondo 3 secundario */
            FondoLogoBitmapLen); /* Longitud (en bytes) generada autom�ticamente */
}

void mostrarFondoPuntuacion() {
    dmaCopy(FondoPuntuacionBitmap, /* Variable generada autom�ticamente */
            bgGetGfxPtr(FondoSub3), /* Direcci�n del fondo 3 secundario */
            FondoPuntuacionBitmapLen); /* Longitud (en bytes) generada autom�ticamente */
}
