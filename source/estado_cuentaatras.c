// Estado 'Cuenta atr�s' definido en el aut�mata

#include <nds.h>
#include "defines.h"
#include "estado_cuentaatras.h"
#include "fondos.h"
#include "temporizadores.h"

/* Ficheros de cabecera de cada texto por fondos */
#include "CuentaAtras1.h"
#include "CuentaAtras2.h"
#include "CuentaAtras3.h"
#include "CuentaAtrasGo.h"


/* Variable de control de la cuenta atr�s */
uint8 Cuenta;
s32 FactorEscala;

/**
 * Carga la situaci�n inicial para hacer la cuenta atr�s e inicia el temporizador.
 */
void InicializarCuentaAtras() {
	// Inicializar variables
	Cuenta = 3;
	FactorEscala = floatToFixed(0.5,8);

	// Cargar primer n�mero
	cargarFondo(CuentaAtras3Bitmap, Fondo2, CuentaAtras3BitmapLen);
	bgSetCenter(Fondo2, -128, -32);
	bgShow(Fondo2);
	bgUpdate();

	// Inicia el temporizador para hacer la animaci�n
	iniciarTemporizador(0);
}

/**
 * Muestra unas im�genes de 3, 2, 1, YA!
 * Para la cuenta se utiliza Fondo2 centrado, asignado a prioridad 0.
 * Cuando la cuenta es 0, se configura un temporizador para quitar el GO! en el estado 'Avanzar personaje'
 */
void HacerCuentaAtras() {

	// Animaci�n de la cuenta atr�s
	FactorEscala += 1 << 2;
	bgSetScale(Fondo2, FactorEscala, FactorEscala);
	bgSetCenter(Fondo2, (SCREEN_WIDTH/2) - (DIMENSION_ESCALADA/2), (SCREEN_HEIGHT/2) - (DIMENSION_ESCALADA/2));
	if( Cuenta == 3 ) {
		// Pasa al siguiente n�mero
		if( obtenerTiempo() >= 1 ) {
			cargarFondo(CuentaAtras2Bitmap, Fondo2, CuentaAtras2BitmapLen);
			bgSetCenter(Fondo2, -128, -32);
			FactorEscala = floatToFixed(0.5,8);
			resetearTiempo();
			Cuenta--;
		}
	} else if( Cuenta == 2 ) {
		// Pasa al siguiente n�mero
		if( obtenerTiempo() >= 1 ) {
			cargarFondo(CuentaAtras1Bitmap, Fondo2, CuentaAtras1BitmapLen);
			bgSetCenter(Fondo2, -128, -32);
			FactorEscala = floatToFixed(0.5,8);
			resetearTiempo();
			Cuenta--;
		}
	} else if( Cuenta == 1 ) {
		// Pasa al siguiente n�mero
		if( obtenerTiempo() >= 1 ) {
			cargarFondo(CuentaAtrasGoBitmap, Fondo2, CuentaAtrasGoBitmapLen);
			bgSetCenter(Fondo2, 8, -16);
			bgSetScale(Fondo2, intToFixed(1,8), intToFixed(1,8));
			resetearTiempo();
			Cuenta--;
			// Pasar al siguiente estado
			ESTADO = AVANZAR_PERSONAJE;
		}
	}

	// Actualiza los cambios de tama�o y posici�n de los fondos
	bgUpdate();
}

/**
 * Termina la cuenta atr�s quitando el GO! de la pantalla.
 * Se llama desde el estado 'Avanzar personaje'
 */
void terminarCuentaAtras() {
	bgHide(Fondo2);
	pararTemporizador(0);
	resetearTiempo();
}
