/**
 * Mecanismo para mostrar im�genes est�ticas de fondo de pantalla
 */

#include <nds.h>
#include "fondos.h"

/* A�adir aqu� los includes para cada fondo. */
#include "FondoAzul.h"
#include "FondoPuma.h"
#include "FondoPuntuacion.h"

/* Seleccionar un canal DMA para copiar a memoria las im�genes */
static const int DMA_CHANNEL = 3;

/* Procedimiento para configurar el sistema de fondos. */
void initFondos() {
    /*  Establecer la afinidad del fondo 3 de la pantalla principal con color de 16 bits. */
    REG_BG3CNT = BG_BMP16_256x256 |
                 BG_BMP_BASE(0) | // La direcci�n inicial de memoria
                 BG_PRIORITY(3); // Baja prioridad

    /*  Establecer la matriz de transformaci�n afin del fondo 3 de la pantalla principal
        a la matriz de identidad. */
    REG_BG3PA = 1 << 8;
    REG_BG3PB = 0;
    REG_BG3PC = 0;
    REG_BG3PD = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situaci�n del fondo 3 de la pantalla principal. */
    /*  Esto deber� cambiar seg�n la posici�n en la que se quiera poner el gr�fico */
    REG_BG3X = 0;
    REG_BG3Y = 0;
/*******************************************************************************************/

    /*  Establecer la afinidad del fondo 2 de la pantalla principal con color de 16 bits. */
    REG_BG2CNT = BG_BMP16_128x128 |
                 BG_BMP_BASE(8) | // La direcci�n inicial de memoria
                 BG_PRIORITY(2);  // Baja prioridad

    /*  Establecer la matriz de transformaci�n afin del fondo 2 de la pantalla principal 
        a la matriz de identidad. */
    REG_BG2PA = 1 << 8;
    REG_BG2PB = 0;
    REG_BG2PC = 0;
    REG_BG2PD = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situaci�n del fondo 2 de la pantalla principal. */
    /*  Esto deber� cambiar seg�n la posici�n en la que se quiera poner el gr�fico */
    REG_BG2X = -(SCREEN_WIDTH / 2 - 32) << 8;
    REG_BG2Y = -32 << 8;
/*******************************************************************************************/

    /*  Establecer la afinidad del fondo 3 de la pantalla secundaria con color de 16 bits. */
    REG_BG3CNT_SUB = BG_BMP16_256x256 |
                     BG_BMP_BASE(0) | // La direcci�n inicial de memoria
                     BG_PRIORITY(3); // Baja prioridad

    /*  Establecer la matriz de transformaci�n afin del fondo 3 de la pantalla secundaria
        a la matriz de identidad. */
    REG_BG3PA_SUB = 1 << 8;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 1 << 8;

/*******************************************************************************************/
    /*  Definir la situaci�n del fondo 3 de la pantalla secundaria. */
    /*  Esto deber� cambiar seg�n la posici�n en la que se quiera poner el gr�fico */
    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 0;
/*******************************************************************************************/
}

/* Para cada imagen que se quiera llevar a pantalla hay que hacer una de estas funciones. */

void mostrarFondoPuma() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     FondoPumaBitmap, /* Variable generada autom�ticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Direcci�n del fondo 3 principal */
                     FondoPumaBitmapLen); /* Longitud (en bytes) generada autom�ticamente */
}

void mostrarFondoAzul() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     FondoAzulBitmap, /* Variable generada autom�ticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Direcci�n del fondo 3 principal */
                     FondoAzulBitmapLen); /* Longitud (en bytes) generada autom�ticamente */
}

void mostrarFondoPuntuacion() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     FondoPuntuacionBitmap, /* Variable generada autom�ticamente */
                     (uint16 *)BG_BMP_RAM_SUB(0), /* Direcci�n del fondo 3 principal */
                     FondoPuntuacionBitmapLen); /* Longitud (en bytes) generada autom�ticamente */
}
