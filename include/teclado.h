/*-------------------------------------
teclado.h
-------------------------------------*/

#ifndef TECLADO_H
#define TECLADO_H

// Variable para guardar el valor de la tecla pulsada
extern int tecla;

//Este procedimiento habilita las interrupciones del teclado
extern void HabilitarIntTec();

//Este procedimiento deshabilita las interrupciones del teclado
extern void DeshabilitarIntTec();

//Rutina de atención a la interrupción del teclado
extern void intTeclado();


#endif // TECLADO_H
