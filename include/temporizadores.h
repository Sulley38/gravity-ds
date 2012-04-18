/*-------------------------------------
temporizadores.h
-------------------------------------*/
#include <nds.h>

extern int tiempo;

extern void HabilitarIntTemp();
extern void DeshabilitarIntTemp();

extern void prepararTemporizador(uint8 id, int frecuencia);
extern void iniciarTemporizador(uint8 id);
extern void pararTemporizador(uint8 id);
extern void intTemporizador();
