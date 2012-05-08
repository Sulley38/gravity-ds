/**
 * Mecanismo para mostrar imágenes en las capas de fondos BG0, BG1, BG2 Y BG3 y trabajar con ellas.
 */

#include <nds.h>
#include "fondos.h"


/* Identificadores de los fondos */
int Fondo2, Fondo3, FondoSub3;

/* Procedimiento para configurar el sistema de fondos. */
void initFondos() {
	// Fondo 2 de la pantalla principal (cuenta atrás y transparencia, alta prioridad)
	Fondo2 = bgInit(2, BgType_Bmp8, BgSize_B8_256x256, 0, 0);
	bgSetPriority(Fondo2, 0);
	// Fondo 3 de la pantalla principal (imágen estática, baja prioridad)
	Fondo3 = bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 8, 0);
	bgSetPriority(Fondo3, 3);
	// Fondo 3 de la pantalla secundaria (imágen estática, baja prioridad)
	FondoSub3 = bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	bgSetPriority(FondoSub3, 3);
}


/**
 * Copia 'imagen' en formato bitmap de 'longitud_imagen' bytes en la dirección de memoria de 'fondo'.
 * Se utiliza la interfaz DMA para una copia más eficiente.
 * Los parámetros 'imagen' y 'longitud_imagen' los genera grit en los ficheros de cabecera.
 */
void cargarFondoBitmap(int fondo, const void * imagen, uint32 longitud_imagen ) {
	dmaCopy(imagen, /* Variable generada automáticamente, contiene los datos de la imagen */
	    	bgGetGfxPtr(fondo), /* Dirección del fondo */
	        longitud_imagen); /* Longitud de la imagen (en bytes) generada automáticamente */
}

/**
 * Copia 'imagen' en formato de paleta de 'longitud_imagen' bytes en la dirección de memoria de 'fondo'.
 * Se utiliza la interfaz DMA para una copia más eficiente.
 * Los parámetros 'imagen', 'paleta' y las longitudes los genera grit en los ficheros de cabecera.
 */
void cargarFondoPaleta(int fondo, const void * imagen, uint32 longitud_imagen, const void * paleta, uint32 longitud_paleta ) {
	dmaCopy(imagen, /* Variable generada automáticamente, contiene los datos de la imagen */
	    	bgGetGfxPtr(fondo), /* Dirección del fondo 3 principal */
	        longitud_imagen); /* Longitud de la imagen (en bytes) generada automáticamente */
	dmaCopy( paleta,  /* Variable generada automáticamente, contiene los datos de la paleta */
			BG_PALETTE, /* Dirección de la paleta de fondos */
			longitud_paleta );  /* Longitud de la paleta (en bytes) generada automáticamente */
}
