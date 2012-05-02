/*-------------------------------------
teclado.h
-------------------------------------*/

#ifndef TECLADO_H
#define TECLADO_H

#define TECLA_PULSADA(n) !(TECLAS_DAT & (1 << 10 | 1 << n))

//Este procedimiento habilita las interrupciones del teclado
extern void HabilitarIntTec();

//Este procedimiento deshabilita las interrupciones del teclado
extern void DeshabilitarIntTec();

//Rutina de atención a la interrupción del teclado
extern void intTeclado();

#endif // TECLADO_H
