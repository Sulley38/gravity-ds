/**
 * Motor gráfico y control de fotogramas por segundo
 */

#include <nds.h>
#include "estado_avanzar.h"
#include "graficos.h"

uint8 Frame = 0;

/* Definir el sistema de vídeo */
void initVideo() {
    /*  Mapear la memoria VRAM para mostrar gráficos en las dos pantallas. */
    vramSetPrimaryBanks(VRAM_A_MAIN_BG_0x06000000,
                     VRAM_B_MAIN_BG_0x06020000,
                     VRAM_C_SUB_BG_0x06200000,
                     VRAM_E_LCD);

    vramSetBankE(VRAM_E_MAIN_SPRITE);
    vramSetBankD(VRAM_D_SUB_SPRITE);

    /*  Establecer el modo de vídeo de la pantalla principal. */
    videoSetMode(MODE_5_2D | // Establecer el modo gráfico 5
                 DISPLAY_BG2_ACTIVE | // Activar el fondo 2
                 DISPLAY_BG3_ACTIVE); // Activar el fondo 3

    /*  Establecer el modo de vídeo de la pantalla secundaria. */
    videoSetModeSub(MODE_5_2D | // Establecer el modo gráfico 5
                    DISPLAY_BG3_ACTIVE); // Activar el fondo 3
}



/* Devuelve los frames dibujados en lo que va de segundo */
uint8 obtenerFrames() {
	return Frame;
}

/** Rutina de atención a las interrupciones de refresco vertical
 * Por defecto, la consola envía una de estas interrupciones 60 veces por segundo (60 fps)
 */
void intVBlank() {
	Frame++;
	if( Frame == 60 ) Frame = 0;
	Avanzar();
}
