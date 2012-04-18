/*-------------------------------------
temporizadores.h
-------------------------------------*/
extern int tiempo;

extern void HabilitarIntTemp();
extern void DeshabilitarIntTemp();

extern void prepararTemporizador(short id, int frecuencia);
extern void iniciarTemporizador(short id);
extern void pararTemporizador(short id);
extern void intTemporizador();
