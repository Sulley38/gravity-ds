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

// Estado 'Fondo Puma' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "fondos.h"
#include "estado_fondopuma.h"
#include "estado_menu.h"
#include "temporizadores.h"

// Cabeceras específicas de cada fondo
#include "FondoAzul.h"
#include "FondoLogo.h"
#include "FondoPuma.h"

// Variable para controlar la transparencia del fondo
uint8 Transparencia = 32;

/**
 * Carga la situación inicial antes de entrar al bucle principal.
 */
void CargarEstadoInicial() {
	// Hace transparente el fondo
	REG_BLDCNT = BLEND_FADE_BLACK | BLEND_SRC_BG3;
	REG_BLDY = 16;

	// Carga la imagen de Puma Corp. y el logo del juego
	cargarFondoBitmap(Fondo3, FondoPumaBitmap, FondoPumaBitmapLen);
	cargarFondoBitmap(FondoSub3, FondoLogoBitmap, FondoLogoBitmapLen);

	// Muestra el fondo durante 3 segundos con efecto de transparencia
	iniciarTemporizador(0);
}

/**
 * Muestra la imagen de Puma Corporation con un efecto de transparencia.
 * La transparencia cambia una vez cada dos frames.
 * Tras cuatro segundos, pasa al siguiente estado.
 */
void mostrarPantallaInicio() {
	if( obtenerTiempo() < 3 ) {
		// Ir mostrando el fondo poco a poco
		if( Transparencia > 0 ) Transparencia--;
		REG_BLDY = Transparencia/2;
	} else if( obtenerTiempo() < 4 ) {
		// Ir quitando el fondo poco a poco
		if( Transparencia < 32 ) Transparencia++;
		REG_BLDY = Transparencia/2;
	} else {
		// Detener el temporizador
		pararTemporizador(0);
		resetearTiempo();
		REG_BLDCNT = 0;

		// Pasa al menú
		cargarFondoBitmap(Fondo3, FondoAzulBitmap, FondoAzulBitmapLen);
		CargarMenu();
		ESTADO = MENU;
	}
}
