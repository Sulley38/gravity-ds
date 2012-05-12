/**
 * Mecanismo para mostrar im�genes en las capas de fondos BG0, BG1, BG2 Y BG3 y trabajar con ellas.
 */

#include <nds.h>
#include "fondos.h"


/* Identificadores de los fondos */
int Fondo2, Fondo3, FondoSub3;

/* Procedimiento para configurar el sistema de fondos. */
void initFondos() {
	// Fondo 2 de la pantalla principal (cuenta atr�s y transparencia, alta prioridad)
	Fondo2 = bgInit(2, BgType_Bmp8, BgSize_B8_256x256, 0, 0);
	bgSetPriority(Fondo2, 0);
	// Fondo 3 de la pantalla principal (im�gen est�tica, baja prioridad)
	Fondo3 = bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 4, 0);
	bgSetPriority(Fondo3, 3);
	// Fondo 3 de la pantalla secundaria (im�gen est�tica, baja prioridad)
	FondoSub3 = bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	bgSetPriority(FondoSub3, 3);
}


/**
 * Copia 'imagen' en formato bitmap de 'longitud_imagen' bytes en la direcci�n de memoria de 'fondo'.
 * Se utiliza la interfaz DMA para una copia m�s eficiente.
 * Los par�metros 'imagen' y 'longitud_imagen' los genera grit en los ficheros de cabecera.
 */
void cargarFondoBitmap(int fondo, const void * imagen, uint32 longitud_imagen ) {
	// Limpia el fondo anterior
	dmaFillHalfWords(0x0000, bgGetGfxPtr(fondo), 65536 );
	// Copia el nuevo fondo
	dmaCopy(imagen, /* Variable generada autom�ticamente, contiene los datos de la imagen */
	    	bgGetGfxPtr(fondo), /* Direcci�n del fondo */
	        longitud_imagen); /* Longitud de la imagen (en bytes) generada autom�ticamente */
}

/**
 * Copia 'imagen' en formato de paleta de 'longitud_imagen' bytes en la direcci�n de memoria de 'fondo'.
 * Se utiliza la interfaz DMA para una copia m�s eficiente.
 * Los par�metros 'imagen', 'paleta' y las longitudes los genera grit en los ficheros de cabecera.
 */
void cargarFondoPaleta(int fondo, const void * imagen, uint32 longitud_imagen, const void * paleta, uint32 longitud_paleta ) {
	// Limpia los datos anteriores
	dmaFillHalfWords(0x0000, bgGetGfxPtr(fondo), 65536 );
	dmaFillHalfWords(0x0000, BG_PALETTE, 512 );
	bgSet(fondo, 0, 1 << 8, 1 << 8, 0, 0, 0, 0);
	bgUpdate();
	// Copia los nuevos datos
	dmaCopy(imagen, /* Variable generada autom�ticamente, contiene los datos de la imagen */
	    	bgGetGfxPtr(fondo), /* Direcci�n del fondo 3 principal */
	        longitud_imagen); /* Longitud de la imagen (en bytes) generada autom�ticamente */
	dmaCopy(paleta,  /* Variable generada autom�ticamente, contiene los datos de la paleta */
			BG_PALETTE, /* Direcci�n de la paleta de fondos */
			longitud_paleta );  /* Longitud de la paleta (en bytes) generada autom�ticamente */
}

/**
 * Carga una imagen completamente negra de tama�o 256x256 en el fondo indicado.
 */
void cargarFondoNegro(int fondo) {
	dmaFillHalfWords(0x0101, bgGetGfxPtr(fondo), 65536);
	dmaFillHalfWords(0x0000, BG_PALETTE, 512);
	// Limpia los datos anteriores
	bgSet(fondo, 0, 1 << 8, 1 << 8, 0, 0, 0, 0);
	bgUpdate();
}
