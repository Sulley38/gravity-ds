/*-------------------------------------
teclado.h
-------------------------------------*/

extern int tecla; // variable para guardar el valor de la tecla pulsada

//Esta funci�n tiene que devolver el valor de la tecla pulsada
extern int TeklaPulsada();

//Este procedimiento habilita las interrupciones del teclado
extern void HabilitarIntTec();

//Este procedimiento deshabilita las interrupciones del teclado
extern void DeshabilitarIntTec();

//Rutina de atenci�n a la interrupci�n del teclado
extern void IntTec();
