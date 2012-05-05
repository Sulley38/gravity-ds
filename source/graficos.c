/**
 * Motor gr�fico y control de fotogramas por segundo
 */

#include <nds.h>
#include "defines.h"
#include "graficos.h"

uint8 Frame = 0;

/* Definir el sistema de v�deo */
void initVideo() {
	/*  Poner en marcha el motor gr�fico 2D. */
    powerOn(POWER_ALL_2D);

    /*  Mapear la memoria VRAM para mostrar gr�ficos en las dos pantallas. */
    vramSetPrimaryBanks(VRAM_A_MAIN_BG,
                VRAM_B_MAIN_SPRITE,
                VRAM_C_SUB_BG,
                VRAM_D_SUB_SPRITE);

    /* Reserva el banco F para poder escribir en �l la paleta de colores extendida */
    vramSetBankF(VRAM_F_LCD);

    /*  Establecer el modo de v�deo de las pantallas principal y secundaria. */
    videoSetMode(MODE_5_2D);
    videoSetModeSub(MODE_5_2D);
}


/* Devuelve los frames dibujados en lo que va de segundo */
uint8 obtenerFrames() {
	return Frame;
}

/** Rutina de atenci�n a las interrupciones de refresco vertical
 * Por defecto, la consola env�a una de estas interrupciones 60 veces por segundo (60 fps)
 */
void intVBlank() {
	Frame = (Frame + 1) % 60;
}
