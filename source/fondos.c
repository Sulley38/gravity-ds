/*  Copyright 2012 Daniel Franco, Iván Matellanes, Asier Mujika
 *
 *  This file is part of Gravity DS.
 *
 *  Gravity DS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation, either version 3 of the License,
 *  or (at your option) any later version.
 *
 *  Gravity DS is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Gravity DS is distributed. 
 *  If not, see <http://www.gnu.org/licenses/>.
 */

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
	Fondo3 = bgInit(3, BgType_Bmp16, BgSize_B16_256x256, 4, 0);
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
	// Limpia el fondo anterior
	dmaFillHalfWords(0x0000, bgGetGfxPtr(fondo), 65536 );
	// Copia el nuevo fondo
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
	// Limpia los datos anteriores
	dmaFillHalfWords(0x0000, bgGetGfxPtr(fondo), 65536 );
	dmaFillHalfWords(0x0000, BG_PALETTE, 512 );
	bgSet(fondo, 0, 1 << 8, 1 << 8, 0, 0, 0, 0);
	// Copia los nuevos datos
	dmaCopy(imagen, /* Variable generada automáticamente, contiene los datos de la imagen */
	    	bgGetGfxPtr(fondo), /* Dirección del fondo 3 principal */
	        longitud_imagen); /* Longitud de la imagen (en bytes) generada automáticamente */
	dmaCopy(paleta,  /* Variable generada automáticamente, contiene los datos de la paleta */
			BG_PALETTE, /* Dirección de la paleta de fondos */
			longitud_paleta );  /* Longitud de la paleta (en bytes) generada automáticamente */
}

/**
 * Carga una imagen completamente negra de tamaño 256x256 en el fondo indicado.
 */
void cargarFondoNegro(int fondo) {
	// Limpia los datos anteriores
	bgSet(fondo, 0, 1 << 8, 1 << 8, 0, 0, 0, 0);
	// Copia los nuevos datos
	dmaFillHalfWords(0x0101, bgGetGfxPtr(fondo), 65536);
	dmaFillHalfWords(0x0000, BG_PALETTE, 512);
}
