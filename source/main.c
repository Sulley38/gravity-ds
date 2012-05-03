/**
 * Fichero principal del videojuego Gravity-DS
 *  Copyright 2012 - Puma Corporation
 */

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_cuentaatras.h"
#include "estado_fondopuma.h"
#include "estado_menu.h"
#include "estado_pausa.h"
#include "estado_puntuacion.h"
#include "graficos.h"
#include "interrupciones.h"
#include "sonido.h"
#include "sprites.h"


int ESTADO = FONDO_PUMA;

//---------------------------------------------------------------------------------
int main(void){
//---------------------------------------------------------------------------------

	/*
	*  Establecer la pantalla inferior como principal, inicializar el sistema gráfico y el de audio,
	*  y cargar los sprites
	*/
	lcdMainOnBottom();
	initVideo();
	cargarSonido();
	cargarSprites();

	/* Llena la tabla de interrupciones con las rutinas correspondientes para manejarlas */
	rellenarTablaInt();

	/* Bucle principal */
	uint8 CurrentFrame;
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
		  break;
		case AVANZAR_PERSONAJE:
			Avanzar();
		  break;
		case PAUSA:
			Pausar();
		  break;
		case PUNTUACION:
			PedirPuntuacion();
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
