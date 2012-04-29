/*-------------------------------------
graficos.h
-------------------------------------*/

#ifndef GRAFICOS_H
#define GRAFICOS_H

/* Definir el sistema de v�deo */
extern void initVideo();

/* Devuelve los frames dibujados en lo que va de segundo */
extern uint8 obtenerFrames();
/* Atenci�n a las interrupciones de refresco vertical */
extern void intVBlank();


#endif // GRAFICOS_H
