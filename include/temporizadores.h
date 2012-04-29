/*-------------------------------------
temporizadores.h
-------------------------------------*/

#ifndef TEMPORIZADORES_H
#define TEMPORIZADORES_H

extern int obtenerTiempo();
extern void resetearTiempo();

extern void HabilitarIntTemp();
extern void DeshabilitarIntTemp();

extern void prepararTemporizador(int frecuencia);
extern void iniciarTemporizador();
extern void pararTemporizador();
extern void intTemporizador();

#endif // TEMPORIZADORES_H
