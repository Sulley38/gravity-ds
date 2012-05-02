/*-------------------------------------
temporizadores.h
-------------------------------------*/

#ifndef TEMPORIZADORES_H
#define TEMPORIZADORES_H

extern int obtenerTiempo();
extern void resetearTiempo();

extern void HabilitarIntTemp();
extern void DeshabilitarIntTemp();

extern void prepararTemporizador(int frecuencia, int temp);
extern void iniciarTemporizador(int temp);
extern void pararTemporizador(int temp);
extern void intTemporizador0();
extern void intTempMoneda();
extern void ruidoMoneda();

#endif // TEMPORIZADORES_H
