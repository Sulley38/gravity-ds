// Estado 'Pausa' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "estado_pausa.h"
#include "pantalla.h"


/**
 * Muestra un par de botones con las opciones de continuar juego o salir.
 * Cambia de estado según lo que se haya pulsado.
 */
uint8 DesplazamientoAnimacion_Pausa = 0;
uint8 Animar_Pausa = 0;
int pantallaPulsada_Pausa = 0;

void Pausar() {

	touchPosition pos_pantalla;
	touchRead(&pos_pantalla);

	dibujar_botonContinuar(60-DesplazamientoAnimacion_Pausa,20);
	dibujar_botonSalir(60+DesplazamientoAnimacion_Pausa,110);

	if( pos_pantalla.px >= 60 && pos_pantalla.px <= 188 && Animar_Pausa==0) {
		if( pos_pantalla.py >= 20 && pos_pantalla.py <= 84 ) {

			Animar_Pausa = 1;
		} else if( pos_pantalla.py >= 110 && pos_pantalla.py <= 174 ) {
			Animar_Pausa = 2;
		}
	}
	else if(Animar_Pausa){
		DesplazamientoAnimacion_Pausa += 5;
		if (DesplazamientoAnimacion_Pausa==160){
			 if (Animar_Pausa==1){
				// Elimina los botones
				 oamClear(&oamMain,122,4);
				 ESTADO = AVANZAR_PERSONAJE;
			 }
			 else{
				 // Elimina los botones y los elementos del juego
				 oamClear(&oamMain,0,51);
				 oamClear(&oamMain,122,2);
				 ESTADO = MENU;
			 }
			 DesplazamientoAnimacion_Pausa = 0;
			 Animar_Pausa = 0;
		}


	}
}
