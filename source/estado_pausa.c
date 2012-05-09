// Estado 'Pausa' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "estado_menu.h"
#include "estado_pausa.h"
#include "fondos.h"
#include "pantalla.h"


/* Variables de control del menú pausa */
uint8 DesplazamientoAnimacion_Pausa, BotonPulsado_Pausa;

void CargarPausa() {
	// Pone una transparencia
	REG_BLDCNT = BLEND_ALPHA | BLEND_SRC_BG2 | BLEND_DST_BG3 | BLEND_DST_SPRITE;
	REG_BLDALPHA = 3 << 1 | 1 << 10;
	cargarFondoNegro(Fondo2);
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
 * Espera una respuesta táctil válida y hace una animación cuando la recibe.
 */
void Pausar() {
	// Espera una entrada táctil del usuario
	if( !BotonPulsado_Pausa )
		BotonPulsado_Pausa = pantallaEncuestaMenu();
	// Hace la animación
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
			 oamClear(&oamMain,0,41);
			 CargarMenu();
			 ESTADO = MENU;
		 }
	}

}
