/*-------------------------------------
teclado.h
-------------------------------------*/

#ifndef TECLADO_H
#define TECLADO_H

//Este procedimiento habilita las interrupciones del teclado
extern void HabilitarIntTec();

//Este procedimiento deshabilita las interrupciones del teclado
extern void DeshabilitarIntTec();

//Rutina de atenci�n a la interrupci�n del teclado
extern void intTeclado();

#endif // TECLADO_H
