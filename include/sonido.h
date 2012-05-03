/*-------------------------------------
sonido.h
-------------------------------------*/

#ifndef SONIDO_H
#define SONIDO_H

/* Inicializa el sistema y el sonido de la moneda */
extern void cargarSonido();

/* Reproduce el sonido de moneda pulsada */
extern void ruidoMoneda();
/* Ajusta el sonido conforme pasa el tiempo */
extern void ajustarSonido(uint8 tiempoTranscurrido);

#endif // SONIDO_H
