/*  Copyright 2012 Daniel Franco, Iv�n Matellanes, Asier Mujika
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

// Estado 'Pausa' definido en el aut�mata

#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "estado_pausa.h"
#include "fondos.h"
#include "pantalla.h"


/* Variables de control del men� pausa */
uint8 DesplazamientoAnimacion_Pausa, BotonPulsado_Pausa;

void CargarPausa() {
	// Pone una transparencia
	cargarFondoNegro(Fondo2);
	REG_BLDCNT = BLEND_ALPHA | BLEND_SRC_BG2 | BLEND_DST_BG3 | BLEND_DST_SPRITE;
	REG_BLDALPHA = 3 << 1 | 1 << 10;
	bgShow(Fondo2);
	// Muestra los botones
	dibujar_botonContinuar(60, 20);
	dibujar_botonSalir(60, 110);
	// Inicializa las variables
	DesplazamientoAnimacion_Pausa = 0;
	BotonPulsado_Pausa = 0;
}

/**
 * Muestra un par de botones con las opciones de continuar juego o salir.
 * Espera una respuesta t�ctil v�lida y hace una animaci�n cuando la recibe.
 */
void Pausar() {
	// Espera una entrada t�ctil del usuario
	if( !BotonPulsado_Pausa )
		BotonPulsado_Pausa = pantallaEncuestaMenu();
	// Hace la animaci�n
	DesplazamientoAnimacion_Pausa += 5;
	dibujar_botonContinuar(60 - DesplazamientoAnimacion_Pausa, 20);
	dibujar_botonSalir(60 + DesplazamientoAnimacion_Pausa, 110);
	if( DesplazamientoAnimacion_Pausa == 160 ) {
		 // Elimina los botones y la transparencia
		 oamClear(&oamMain,122,4);
		 REG_BLDCNT = 0;
		 REG_BLDALPHA = 0;
		 bgHide(Fondo2);
		 if( BotonPulsado_Pausa == 1 ) {
			 ESTADO = AVANZAR_PERSONAJE;
		 } else {
			 // Elimina los elementos del juego
			 oamClear(&oamMain,0,128);
			 oamClear(&oamSub,0,128);
			 CargarMenu();
			 ESTADO = MENU;
		 }
	}

}
