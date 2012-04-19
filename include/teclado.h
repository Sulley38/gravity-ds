/*-------------------------------------
teclado.h
-------------------------------------*/

extern int tecla; // variable para guardar el valor de la tecla pulsada

//Esta función tiene que devolver el valor de la tecla pulsada
extern int TeclaPulsada();

//Este procedimiento habilita las interrupciones del teclado
extern void HabilitarIntTec();

//Este procedimiento deshabilita las interrupciones del teclado
extern void DeshabilitarIntTec();

//Rutina de atención a la interrupción del teclado
extern void RutTec();
