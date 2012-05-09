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
			MostrarPuntuacion();
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
	}

	return 0;
}
