// Estado 'Fondo Puma' definido en el autómata

#include <nds.h>
#include "defines.h"
#include "fondos.h"
#include "estado_fondopuma.h"
#include "temporizadores.h"


/**
 * Muestra la imagen del puma y espera 3 segundos antes de pasar al menú
 */
void mostrarPantallaInicio(){

	// Carga el sistema de fondos y la imagen de Puma Corp.
	initFondos();
	mostrarFondoPuma();
	mostrarFondoLogo();

	// Espera 3 segundos
	iniciarTemporizador(0);
	while( obtenerTiempo() < 3 );
	pararTemporizador(0);
	resetearTiempo();

	// Muestra los fondos principales del juego
	mostrarFondoAzul();
	mostrarFondoPuntuacion();

	// Pasa al menú
	ESTADO = MENU;
}
