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
 * Fichero principal del videojuego Gravity-DS
 *  Copyright 2012 - Puma Corporation
 */

#include <nds.h>
#include <stdlib.h>
#include <time.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_cuentaatras.h"
#include "estado_fondopuma.h"
#include "estado_menu.h"
#include "estado_pausa.h"
#include "estado_puntuacion.h"
#include "fondos.h"
#include "graficos.h"
#include "interrupciones.h"
#include "sonido.h"
#include "sprites.h"

// Definición e inicialización de la variable global de estado
int ESTADO = FONDO_PUMA;

//---------------------------------------------------------------------------------
int main(void){
//---------------------------------------------------------------------------------

	/*
	*  Establece la pantalla inferior como principal e inicializa los sistemas de
	*  gráficos (fondos y sprites) y sonido.
	*/
	lcdMainOnBottom();
	initVideo();
	initFondos();
	cargarSprites();
	cargarSonido();

	/* Semilla para generar los números aleatorios */
	srand( time(0) );

	/* Llena la tabla de interrupciones con las rutinas correspondientes para manejarlas */
	rellenarTablaInt();

	/* Carga las 10 mejores puntuaciones desde el fichero de texto */
	LeerFicheroPuntuaciones();

	/* Bucle principal */
	uint8 CurrentFrame;
	CargarEstadoInicial();
	while( ESTADO != FIN ) {
		switch( ESTADO ) {
		case FONDO_PUMA:
			mostrarPantallaInicio();
		  break;
		case MENU:
			MostrarMenu();
		  break;
		case CUENTA_ATRAS:
			HacerCuentaAtras();
			ActualizarPantalla();
		  break;
		case AVANZAR_PERSONAJE:
			Avanzar();
			EncuestaTeclado();
			ActualizarPantalla();
		  break;
		case PAUSA:
			Pausar();
		  break;
		case PUNTUACION:
			MostrarTablaPuntuacion();
		  break;
		default:
		  break;
		}

		// Espera al siguiente frame
		CurrentFrame = obtenerFrames();
		while( obtenerFrames() == CurrentFrame );
		// Actualiza las pantallas
		oamUpdate(&oamMain);
		oamUpdate(&oamSub);
		bgUpdate();
	}

	return 0;
}
