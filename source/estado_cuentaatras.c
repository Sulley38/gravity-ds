// Estado 'Cuenta atrás' definido en el autómata

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


/* Variable de control de la cuenta atrás */
uint8 Cuenta;
//int FactorEscala;

/**
 * Prepara el temporizador y carga la situación inicial para hacer la cuenta atrás.
 */
void InicializarCuentaAtras() {
	// Configura el temporizador para hacer la animación
	prepararTemporizador(0,10);
	iniciarTemporizador(0);

	// Primer número
	cargarFondo(CuentaAtras3Bitmap, Fondo2, CuentaAtras3BitmapLen);
	bgSetCenter(Fondo2,64,32);
	bgShow(Fondo2);
	bgUpdate();

	Cuenta = 3;
	//FactorEscala = 0;
}

/**
 * Muestra unas imágenes de 3, 2, 1, YA!
 * Para la cuenta se utiliza Fondo2 centrado, asignado a prioridad 0.
 * Cuando la cuenta es 0, se configura un temporizador para quitar el GO! en el estado 'Avanzar personaje'
 */
void HacerCuentaAtras() {

	// Animación de la cuenta atrás
	if( Cuenta == 3 ) {
		//FactorEscala++;
		//bgSetScale(Fondo2, FactorEscala, FactorEscala);
		//bgSetCenter(Fondo2, 64 + FactorEscala, 32 + FactorEscala);
		// Pasa al siguiente número
		if( obtenerTiempo() > 10 ) {
			cargarFondo(CuentaAtras2Bitmap, Fondo2, CuentaAtras2BitmapLen);
			bgSetCenter(Fondo2,64,32);
			resetearTiempo();
			Cuenta = 2;
		}
	} else if( Cuenta == 2 ) {
		// Pasa al siguiente número
		if( obtenerTiempo() > 10 ) {
			cargarFondo(CuentaAtras1Bitmap, Fondo2, CuentaAtras1BitmapLen);
			bgSetCenter(Fondo2,64,32);
			resetearTiempo();
			Cuenta = 1;
		}
	} else if( Cuenta == 1 ) {
		// Pasa al siguiente número
		if( obtenerTiempo() > 10 ) {
			cargarFondo(CuentaAtrasGoBitmap, Fondo2, CuentaAtrasGoBitmapLen);
			bgSetCenter(Fondo2,4,4);
			resetearTiempo();
			Cuenta = 0;
		}
	} else {
		// Pasar al siguiente estado
		ESTADO = AVANZAR_PERSONAJE;
	}

	// Actualiza los cambios de tamaño y posición de los fondos
	bgUpdate();
}

/**
 * Termina la cuenta atrás quitando el GO! de la pantalla.
 * Se llama desde el bucle principal en el estado avanzar.
 */
void TerminarCuentaAtras() {
	if( obtenerTiempo() > 10 ) {
		bgHide(Fondo2);
		pararTemporizador(0);
		resetearTiempo();
	}
}
