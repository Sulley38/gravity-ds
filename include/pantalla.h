/*-------------------------------------
pantalla.h
-------------------------------------*/

#ifndef PANTALLA_H
#define PANTALLA_H

/* Devuelve en un 1 si se ha pulsado el primer bot�n, o un 2 si se ha pulsado el segundo */
extern uint8 pantallaEncuestaMenu();

/* Devuelve un 1 si se ha pulsado la moneda situada en la posici�n (X,Y) */
extern uint8 pantallaEncuestaMoneda( int16 X, int16 Y );

/* Devuelve un 1 si se ha pulsado en volver a jugar, o un 2 si se ha pulsado en ir al men� */
extern uint8 pantallaEncuestaPuntuacion();

#endif // PANTALLA_H
