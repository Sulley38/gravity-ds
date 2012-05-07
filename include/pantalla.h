/*-------------------------------------
pantalla.h
-------------------------------------*/

#ifndef PANTALLA_H
#define PANTALLA_H

/* Devuelve en un 1 si se ha pulsado el primer botón, o un 2 si se ha pulsado el segundo */
extern uint8 pantallaEncuestaMenu();

/* Devuelve un 1 si se ha pulsado la moneda situada en la posición (X,Y) */
extern uint8 pantallaEncuestaMoneda( int16 X, int16 Y );

#endif // PANTALLA_H
