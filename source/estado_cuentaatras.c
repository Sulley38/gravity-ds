// Estado 'Cuenta atr�s' definido en el aut�mata

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "estado_cuentaatras.h"
#include "fondos.h"
#include "sonido.h"
#include "temporizadores.h"

/* Ficheros de cabecera de cada texto por fondos */
#include "CuentaAtras1.h"
#include "CuentaAtras2.h"
#include "CuentaAtras3.h"
#include "CuentaAtrasGo.h"


/* Variable de control de la cuenta atr�s */
uint8 Cuenta;
s32 FactorEscala;
float DesplazamientoSuperior;

/**
 * Carga la situaci�n inicial para hacer la cuenta atr�s e inicia el temporizador.
 */
void InicializarCuentaAtras() {
	// Inicializar variables
	Cuenta = 3;
	FactorEscala = 1 << 8; // 1.0 en representaci�n 24.8
	DesplazamientoSuperior = 1;

	// Cargar primer n�mero
	cargarFondoPaleta(Fondo2, CuentaAtras3Bitmap, CuentaAtras3BitmapLen, CuentaAtras3Pal, CuentaAtras3PalLen);
	bgSetCenter(Fondo2, 0, -32);
	bgUpdate();
	bgShow(Fondo2);
	sonidoCuenta(5000);

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
	ajustarSonidoCuenta();
	// Establece la posici�n y pasa al siguiente n�mero cada segundo
	switch( Cuenta ) {
	case 3:
		bgSetCenter(Fondo2, (SCREEN_WIDTH/2) - (DIMENSION_ESCALADA/2), (SCREEN_HEIGHT/2) - (DIMENSION_ESCALADA/2));
		if( obtenerTiempo() >= 1 ) {
			FactorEscala = 1 << 8;
			bgSetScale(Fondo2, FactorEscala, FactorEscala);
			bgSetCenter(Fondo2, 0, -32);
			cargarFondoPaleta(Fondo2, CuentaAtras2Bitmap, CuentaAtras2BitmapLen, CuentaAtras2Pal, CuentaAtras2PalLen);
			sonidoCuenta(5000);
			resetearTiempo();
			Cuenta--;
		}
	  break;
	case 2:
		bgSetCenter(Fondo2, (SCREEN_WIDTH/2) - (DIMENSION_ESCALADA/2), (SCREEN_HEIGHT/2) - (DIMENSION_ESCALADA/2));
		if( obtenerTiempo() >= 1 ) {
			FactorEscala = 1 << 8;
			bgSetScale(Fondo2, FactorEscala, FactorEscala);
			bgSetCenter(Fondo2, 0, -32);
			cargarFondoPaleta(Fondo2, CuentaAtras1Bitmap, CuentaAtras1BitmapLen, CuentaAtras1Pal, CuentaAtras1PalLen);
			sonidoCuenta(5000);
			resetearTiempo();
			Cuenta--;
		}
	  break;
	case 1:
		bgSetCenter(Fondo2, (SCREEN_WIDTH/2) - (DIMENSION_ESCALADA/2), (SCREEN_HEIGHT/2) - (DIMENSION_ESCALADA/2));
		if( obtenerTiempo() >= 1 ) {
			FactorEscala = 1 << 8;
			bgSetScale(Fondo2, FactorEscala, FactorEscala);
			bgSetCenter(Fondo2, 0, -32);
			cargarFondoPaleta(Fondo2, CuentaAtrasGoBitmap, CuentaAtrasGoBitmapLen, CuentaAtrasGoPal, CuentaAtrasGoPalLen);
			sonidoCuenta(7500);
			resetearTiempo();
			Cuenta--;
		}
	  break;
	case 0:
		// Permite empezar a jugar y desplaza el fondo hacia arriba
		Avanzar();
		EncuestaTeclado();
		bgSetCenter(Fondo2, (SCREEN_WIDTH/2) - (DIMENSION_ESCALADA/2), (SCREEN_HEIGHT/2) - (DIMENSION_ESCALADA/2) - DesplazamientoSuperior);
		DesplazamientoSuperior *= 1.15;
		if( obtenerTiempo() >= 1 ) {
			bgHide(Fondo2);
			bgSetCenter(Fondo2, 0, 0);
			bgSetScale(Fondo2, 1 << 8, 1 << 8);
			pararTemporizador(0);
			sonidoCuenta(0);
			resetearTiempo();
			// Pasar al siguiente estado
			ESTADO = AVANZAR_PERSONAJE;
		}
	  break;
	default:
		ESTADO = FIN; // En caso de error, salir
	  break;
	}

	// Actualiza los cambios de tama�o y posici�n de los fondos
	bgUpdate();
}
