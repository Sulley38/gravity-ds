/**
 * Sistema de sonido
 * Reproduce un sonido cuando se pulsa una moneda en la pantalla táctil.
 */

#include <nds.h>
#include "sonido.h"
#include "temporizadores.h"


// Variables que guardan el canal de reproducción de los sonidos
int sonido_moneda, sonido_cuenta;
// Variables para controlar el progreso de los sonidos
uint8 tiempo_sonido_moneda, volumen_sonido_cuenta;

/* Inicializa el sistema y el sonido de la moneda */
void cargarSonido() {
	/* Pone en marcha el sistema de sonido */
	soundEnable();
	/* Genera el sonido de la moneda */
	sonido_moneda = soundPlayPSG(DutyCycle_50, 6000, 120, 64);
	soundPause(sonido_moneda);
	sonido_cuenta = soundPlayPSG(DutyCycle_50, 5000, volumen_sonido_cuenta, 64);
	soundPause(sonido_cuenta);
}


/**
 * Reproduce el sonido de moneda pulsada.
 */
void sonidoMoneda() {
	tiempo_sonido_moneda = 0;
	soundSetVolume(sonido_moneda, 120);
	soundSetFreq(sonido_moneda, 6000);
	soundResume(sonido_moneda);
	iniciarTemporizador(1);
}

/**
 * Ajusta el sonido conforme pasa el tiempo.
 * Esta función la llama el temporizador cada vez que interrumpe.
 */
void ajustarSonidoMoneda() {
	tiempo_sonido_moneda++;

	switch( tiempo_sonido_moneda ) {
	case 1:
		soundSetFreq(sonido_moneda, 9000);
		soundSetVolume(sonido_moneda, 105);
	  break;
	case 2:
		soundSetVolume(sonido_moneda, 90);
	  break;
	case 3:
		soundSetVolume(sonido_moneda, 75);
	  break;
	case 4:
		soundSetVolume(sonido_moneda, 60);
	  break;
	case 5:
		soundPause(sonido_moneda);
		pararTemporizador(1);
	  break;
	default:
		soundPause(sonido_moneda);
	  break;
	}
}


/**
 * Reproduce el sonido de la cuenta atrás.
 * Si la frecuencia que se le pasa es 0, detiene el sonido.
 */
void sonidoCuenta( uint16 frecuencia ) {
	if( frecuencia > 0 ) {
		volumen_sonido_cuenta = 80;
		soundSetVolume(sonido_cuenta, volumen_sonido_cuenta);
		soundSetFreq(sonido_cuenta, frecuencia);
		soundResume(sonido_cuenta);
	} else {
		soundPause(sonido_cuenta);
	}
}

/**
 * Reduce gradualmente el volumen del sonido de la cuenta atrás.
 * Se llama una vez cada frame desde la función de la cuenta atrás.
 */
void ajustarSonidoCuenta() {
	(volumen_sonido_cuenta > 3) ? (volumen_sonido_cuenta -= 3) : (volumen_sonido_cuenta = 0);
	soundSetVolume(sonido_cuenta, volumen_sonido_cuenta);
}

