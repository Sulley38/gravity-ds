/**
 * Sistema de sonido
 * Reproduce un sonido cuando se pulsa una moneda en la pantalla táctil.
 */

#include <nds.h>
#include "sonido.h"
#include "temporizadores.h"


// Variable que guarda el canal de reproducción del sonido
int sonido_moneda;

/* Inicializa el sistema y el sonido de la moneda */
void cargarSonido() {
	/* Pone en marcha el sistema de sonido */
	soundEnable();
	/* Genera el sonido de la moneda */
	sonido_moneda = soundPlayPSG(DutyCycle_50, 7000, 127,64);
	soundPause(sonido_moneda);
}


/* Reproduce el sonido de moneda pulsada */
void sonidoMoneda() {
	soundResume(sonido_moneda);
	iniciarTemporizador(1);
}

/**
 * Ajusta el sonido conforme pasa el tiempo.
 * Esta función la llama el temporizador
 */
void ajustarSonido(uint8 tiempoTranscurrido) {
	if(tiempoTranscurrido == 1) {
		soundSetFreq(sonido_moneda, 10500);
	} else if(tiempoTranscurrido == 4) {
		soundSetVolume(sonido_moneda, 60);
	} else if(tiempoTranscurrido == 5){
		soundPause(sonido_moneda);
		pararTemporizador(1);
		resetearSonido();
		soundSetFreq(sonido_moneda, 7000);
	}
}
