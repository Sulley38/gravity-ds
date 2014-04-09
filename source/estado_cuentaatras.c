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

// Estado 'Cuenta atrás' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_cuentaatras.h"
#include "fondos.h"
#include "sonido.h"
#include "temporizadores.h"

/* Ficheros de cabecera de cada fondo */
#include "CuentaAtras1.h"
#include "CuentaAtras2.h"
#include "CuentaAtras3.h"
#include "CuentaAtrasGo.h"
#include "FondoPuntuacion.h"

/* Variable de control de la cuenta atrás */
uint8 Cuenta;
uint8 CuentaAtrasInicializada = 0;
s32 FactorEscala;
float DesplazamientoSuperior;

/**
 * Carga la situación inicial para hacer la cuenta atrás e inicia el temporizador.
 */
void InicializarCuentaAtras() {
	// Inicializar variables
	Cuenta = 3;
	FactorEscala = 1 << 8; // 1.0 en representación 24.8
	DesplazamientoSuperior = 1;
	// Cargar fondo superior de puntuación
	cargarFondoBitmap(FondoSub3, FondoPuntuacionBitmap, FondoPuntuacionBitmapLen);
	// Cargar primer número
	cargarFondoPaleta(Fondo2, CuentaAtras3Bitmap, CuentaAtras3BitmapLen, CuentaAtras3Pal, CuentaAtras3PalLen);
	bgSetCenter(Fondo2, 0, -32);
	bgShow(Fondo2);
	sonidoCuenta(5000);
	// Inicia el temporizador para hacer la animación
	iniciarTemporizador(0);
	// Activa el registro de cuenta atrás
	CuentaAtrasInicializada = 1;
}

/**
 * Muestra unas imágenes de 3, 2, 1, YA!
 * Para la cuenta se utiliza Fondo2 centrado, asignado a prioridad 0.
 * Cuando la cuenta es 0, se configura un temporizador para quitar el GO! en el estado 'Avanzar personaje'
 */
void HacerCuentaAtras() {
	if( !CuentaAtrasInicializada ) {
		InicializarCuentaAtras();
	} else {
		// Animación de la cuenta atrás
		FactorEscala += 1 << 2;
		bgSetScale(Fondo2, FactorEscala, FactorEscala);
		ajustarSonidoCuenta();
		// Establece la posición y pasa al siguiente número cada segundo
		switch( Cuenta ) {
		case 3:
			bgSetCenter(Fondo2, (SCREEN_WIDTH/2) - (DIMENSION_ESCALADA/2), (SCREEN_HEIGHT/2) - (DIMENSION_ESCALADA/2));
			if( obtenerTiempo() >= 1 ) {
				FactorEscala = 1 << 8;
				cargarFondoPaleta(Fondo2, CuentaAtras2Bitmap, CuentaAtras2BitmapLen, CuentaAtras2Pal, CuentaAtras2PalLen);
				bgSetScale(Fondo2, FactorEscala, FactorEscala);
				bgSetCenter(Fondo2, 0, -32);
				sonidoCuenta(5000);
				resetearTiempo();
				Cuenta--;
			}
		  break;
		case 2:
			bgSetCenter(Fondo2, (SCREEN_WIDTH/2) - (DIMENSION_ESCALADA/2), (SCREEN_HEIGHT/2) - (DIMENSION_ESCALADA/2));
			if( obtenerTiempo() >= 1 ) {
				FactorEscala = 1 << 8;
				cargarFondoPaleta(Fondo2, CuentaAtras1Bitmap, CuentaAtras1BitmapLen, CuentaAtras1Pal, CuentaAtras1PalLen);
				bgSetScale(Fondo2, FactorEscala, FactorEscala);
				bgSetCenter(Fondo2, 0, -32);
				sonidoCuenta(5000);
				resetearTiempo();
				Cuenta--;
			}
		  break;
		case 1:
			bgSetCenter(Fondo2, (SCREEN_WIDTH/2) - (DIMENSION_ESCALADA/2), (SCREEN_HEIGHT/2) - (DIMENSION_ESCALADA/2));
			if( obtenerTiempo() >= 1 ) {
				FactorEscala = 1 << 8;
				cargarFondoPaleta(Fondo2, CuentaAtrasGoBitmap, CuentaAtrasGoBitmapLen, CuentaAtrasGoPal, CuentaAtrasGoPalLen);
				bgSetScale(Fondo2, FactorEscala, FactorEscala);
				bgSetCenter(Fondo2, 0, -32);
				sonidoCuenta(7500);
				resetearTiempo();
				Cuenta--;
			}
		  break;
		case 0:
			// Permite empezar a jugar y desplaza el fondo hacia arriba
			Avanzar();
			EncuestaTeclado();
			bgSetCenter(Fondo2, (SCREEN_WIDTH/2) - (DIMENSION_ESCALADA/2), (SCREEN_HEIGHT/2) - (DIMENSION_ESCALADA/2) - DesplazamientoSuperior);
			DesplazamientoSuperior *= 1.15;
			if( obtenerTiempo() >= 1 ) {
				bgHide(Fondo2);
				pararTemporizador(0);
				sonidoCuenta(0);
				resetearTiempo();
				// Pasar al siguiente estado
				CuentaAtrasInicializada = 0;
				ESTADO = AVANZAR_PERSONAJE;
			}
		  break;
		default:
			ESTADO = FIN; // En caso de error, salir
		  break;
		}
	}

}
