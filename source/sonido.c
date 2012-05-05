/**
 * Sistema de sonido
 * Reproduce un sonido cuando se pulsa una moneda en la pantalla táctil.
 */

#include <nds.h>
#include "sonido.h"
#include "temporizadores.h"


// Variable que guarda el canal de reproducción del sonido
int sonido_moneda;
// Variable para controlar el progreso del sonido
uint8 tiempo_sonido_moneda = 0;

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
 * Esta función la llama el temporizador cada vez que interrumpe.
 */
void ajustarSonido() {
	tiempo_sonido_moneda++;
	if(tiempo_sonido_moneda == 1) {
		soundSetFreq(sonido_moneda, 10500);
	} else if(tiempo_sonido_moneda == 4) {
		soundSetVolume(sonido_moneda, 60);
	} else if(tiempo_sonido_moneda == 5) {
		pararTemporizador(1);
		soundPause(sonido_moneda);
		soundSetFreq(sonido_moneda, 7000);
		tiempo_sonido_moneda = 0;
	}
}
