/**
 * Fichero principal del videojuego Gravity-DS
 *  Copyright 2012 - Puma Corporation
 */

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_cuentaatras.h"
#include "estado_menu.h"
#include "estado_pausa.h"
#include "estado_puntuacion.h"
#include "fondos.h"
#include "graficos.h"
#include "interrupciones.h"
#include "sprites.h"
#include "temporizadores.h"

int ESTADO = MENU;
int sonido_moneda;

//---------------------------------------------------------------------------------
int main(void){
//---------------------------------------------------------------------------------
	sonido_moneda = soundPlayPSG(DutyCycle_50, 7000, 127,64);
	soundPause(sonido_moneda);
	/*  Poner en marcha el motor gráfico 2D. */
    powerOn(POWER_ALL_2D);

	soundEnable();
	prepararTemporizador(12,1);

	/*
	*  Establecer la pantalla inferior como principal, inicializar el sistema gráfico,
	*  configurar el sistema de fondos y cargar los sprites
	*/
	lcdMainOnBottom();
	initVideo();
	//initFondos();
	cargarSprites();

	/* Llena la tabla de interrupciones con las rutinas correspondientes para manejarlas */
	rellenarTablaInt();
	HabilitarIntTemp();

	/* Bucle principal */
	uint8 CurrentFrame;
	while( ESTADO != FIN ) {
		switch( ESTADO ) {
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
