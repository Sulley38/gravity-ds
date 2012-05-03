/*---------------------------------------------------------------------------------
Este código se ha implementado basándose en el ejemplo "Simple sprite demo" de 
dovoto y otro de Jaeden Amero
---------------------------------------------------------------------------------*/

#include <nds.h>
#include "fondos.h"

/* añadir aquí los includes para cada fondo. */
#include "FondoEstrellado.h"
#include "puma1993.h"
#include "degradado.h"
#include "FondoArriba.h"

/* Seleccionar un canal DMA para copiar a memoria las imágenes */
static const int DMA_CHANNEL = 3;

/* Procedimiento para configurar el sistema de fondos. */
void initFondos() {
    /*  Establecer la afinidad del fondo 3 de la pantalla principal con color de 16 bits. */
    REG_BG3CNT = BG_BMP16_256x256 |
                 BG_BMP_BASE(0) | // La dirección inicial de memoria
                 BG_PRIORITY(3); // Baja prioridad

    /*  Establecer la matriz de transformación afin del fondo 3 de la pantalla principal
        a la matriz de identidad. */
    REG_BG3PA = 1 << 8;
    REG_BG3PB = 0;
    REG_BG3PC = 0;
    REG_BG3PD = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situación del fondo 3 de la pantalla principal. */
    /*  Esto deberá cambiar según la posición en la que se quiera poner el gráfico */
    REG_BG3X = 0;
    REG_BG3Y = 0;
/*******************************************************************************************/

    /*  Establecer la afinidad del fondo 2 de la pantalla principal con color de 16 bits. */
    REG_BG2CNT = BG_BMP16_128x128 |
                 BG_BMP_BASE(8) | // La dirección inicial de memoria
                 BG_PRIORITY(2);  // Baja prioridad

    /*  Establecer la matriz de transformación afin del fondo 2 de la pantalla principal 
        a la matriz de identidad. */
    REG_BG2PA = 1 << 8;
    REG_BG2PB = 0;
    REG_BG2PC = 0;
    REG_BG2PD = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situación del fondo 2 de la pantalla principal. */
    /*  Esto deberá cambiar según la posición en la que se quiera poner el gráfico */
    REG_BG2X = -(SCREEN_WIDTH / 2 - 32) << 8;
    REG_BG2Y = -32 << 8;
/*******************************************************************************************/

    /*  Establecer la afinidad del fondo 3 de la pantalla secundaria con color de 16 bits. */
    REG_BG3CNT_SUB = BG_BMP16_256x256 |
                     BG_BMP_BASE(0) | // La dirección inicial de memoria
                     BG_PRIORITY(3); // Baja prioridad

    /*  Establecer la matriz de transformación afin del fondo 3 de la pantalla secundaria
        a la matriz de identidad. */
    REG_BG3PA_SUB = 1 << 8;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situación del fondo 3 de la pantalla secundaria. */
    /*  Esto deberá cambiar según la posición en la que se quiera poner el gráfico */
    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 0;
/*******************************************************************************************/
}

/* Para cada imagen que se quiera llevar a pantalla hay que hacer una de estas funciones. */

void mostrarFondoEstrellado() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     FondoEstrelladoBitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     FondoEstrelladoBitmapLen); /* Longitud (en bytes) generada automáticamente */
}

void mostrarFondoEstrelladoSub() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     FondoEstrelladoBitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM_SUB(0), /* Dirección del fondo 3 principal */
                     FondoEstrelladoBitmapLen); /* Longitud (en bytes) generada automáticamente */
}

void mostrarFondoPuma() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     puma1993Bitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     puma1993BitmapLen); /* Longitud (en bytes) generada automáticamente */
}

void mostrarFondoAzul() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     degradadoBitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo 3 principal */
                     degradadoBitmapLen); /* Longitud (en bytes) generada automáticamente */
}
void mostrarFondoArribaSub() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     FondoArribaBitmap, /* Variable generada automáticamente */
                     (uint16 *)BG_BMP_RAM_SUB(0), /* Dirección del fondo 3 principal */
                     FondoArribaBitmapLen); /* Longitud (en bytes) generada automáticamente */
}
