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
 * Motor gráfico y control de fotogramas por segundo
 */

#include <nds.h>
#include "defines.h"
#include "graficos.h"

uint8 Frame = 0;

/* Definir el sistema de vídeo */
void initVideo() {
	/*  Poner en marcha el motor gráfico 2D. */
    powerOn(POWER_ALL_2D);

    /*  Mapear la memoria VRAM para mostrar gráficos en las dos pantallas. */
    vramSetPrimaryBanks(VRAM_A_MAIN_BG_0x06000000,
    			VRAM_B_MAIN_BG_0x06020000,
                VRAM_C_SUB_BG,
                VRAM_D_SUB_SPRITE);
    vramSetBankE(VRAM_E_MAIN_SPRITE);

    /* Reserva el banco F para poder escribir en él la paleta de colores extendida */
    vramSetBankF(VRAM_F_LCD);

    /*  Establecer el modo de vídeo de las pantallas principal y secundaria. */
    videoSetMode(MODE_5_2D);
    videoSetModeSub(MODE_5_2D);
}


/* Devuelve los frames dibujados en lo que va de segundo */
uint8 obtenerFrames() {
	return Frame;
}

/** Rutina de atención a las interrupciones de refresco vertical
 * Por defecto, la consola envía una de estas interrupciones 60 veces por segundo (60 fps)
 */
void intVBlank() {
	Frame = (Frame + 1) % 60;
}
