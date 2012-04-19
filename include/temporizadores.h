/*-------------------------------------
temporizadores.h
-------------------------------------*/
#include <nds.h>

extern int obtenerTiempo();
extern void resetearTiempo();

extern void HabilitarIntTemp();
extern void DeshabilitarIntTemp();

extern void prepararTemporizador(int frecuencia);
extern void iniciarTemporizador();
extern void pararTemporizador();
extern void intTemporizador();
