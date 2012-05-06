// Estado 'Pausa' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "estado_pausa.h"
#include "pantalla.h"


/* Variables de control de la animación del menú pausa */
uint8 DesplazamientoAnimacion_Pausa = 0;
int8 EstadoMenu_Pausa = -1;

/**
 * Muestra un par de botones con las opciones de continuar juego o salir.
 * Funciona por subestados:
 * - Estado 1: Dibuja los botones
 * - Estado 2: Espera a que se pulse la pantalla
 * - Estado 3: Hace la animación y pasa al juego o sale
 */
void Pausar() {
	if( EstadoMenu_Pausa < 0 ) {
		// Muestra los botones
		dibujar_botonContinuar(60, 20);
		dibujar_botonSalir(60, 110);
		EstadoMenu_Pausa = 0;
	} else if( EstadoMenu_Pausa == 0 ) {
		// Espera una entrada táctil del usuario
		EstadoMenu_Pausa = pantallaEncuestaMenu();
	} else {
		DesplazamientoAnimacion_Pausa += 5;
		dibujar_botonContinuar(60 - DesplazamientoAnimacion_Pausa, 20);
		dibujar_botonSalir(60 + DesplazamientoAnimacion_Pausa, 110);
		if( DesplazamientoAnimacion_Pausa == 160 ) {
			 if( EstadoMenu_Pausa == 1 ) {
				// Elimina los botones
				 oamClear(&oamMain,122,4);
				 ESTADO = AVANZAR_PERSONAJE;
			 } else {
				 // Elimina los botones y los elementos del juego
				 oamClear(&oamMain,0,51);
				 oamClear(&oamMain,122,4);
				 ESTADO = MENU;
			 }
			 // Reestablece la animación
			 DesplazamientoAnimacion_Pausa = 0;
			 EstadoMenu_Pausa = -1;
		}
	}
}
