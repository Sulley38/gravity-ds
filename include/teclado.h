/*-------------------------------------
teclado.h
-------------------------------------*/

#ifndef TECLADO_H
#define TECLADO_H

/* Macro para comprobar si una tecla ha sido pulsada */
#define TECLA_PULSADA(n) !(TECLAS_DAT & (1 << 10 | 1 << n))

//Este procedimiento habilita las interrupciones del teclado
extern void HabilitarIntTec();

//Este procedimiento deshabilita las interrupciones del teclado
extern void DeshabilitarIntTec();

//Rutina de atenci�n a la interrupci�n del teclado
extern void intTeclado();

#endif // TECLADO_H
