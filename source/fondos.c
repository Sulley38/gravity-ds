/**
 * Mecanismo para mostrar imágenes en las capas de fondos BG0, BG1, BG2 Y BG3 y trabajar con ellas.
 */

#include <nds.h>
#include "fondos.h"

/* Identificadores de los fondos */
int Fondo2, Fondo3, FondoSub3;

/* Procedimiento para configurar el sistema de fondos. */
void initFondos() {
	// Fondo 2 de la pantalla principal (alta prioridad)
	Fondo2 = bgInit(2, BgType_Bmp16, BgSize_B16_128x128, 6, 0);
	bgSetPriority(Fondo2, 0);
	// Fondo 3 de la pantalla principal (baja prioridad)
	Fondo3 = bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	bgSetPriority(Fondo3, 3);
	// Fondo 3 de la pantalla secundaria (baja prioridad)
	FondoSub3 = bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	bgSetPriority(FondoSub3, 3);
}


/**
 * Copia 'imagen' de 'longitud' bytes en la dirección de memoria de 'fondo'.
 * Se utiliza la interfaz DMA para una copia más eficiente.
 * Los parámetros 'imagen' y 'longitud' los genera grit en los ficheros de cabecera.
 */
void cargarFondo(const void * imagen, int fondo, uint32 longitud) {
	dmaCopy(imagen, /* Variable generada automáticamente, contiene los datos de la imagen */
	    	bgGetGfxPtr(fondo), /* Dirección del fondo 3 principal */
	        longitud); /* Longitud de la imagen (en bytes) generada automáticamente */
}
