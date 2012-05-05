/*-------------------------------------
temporizadores.h
-------------------------------------*/

#ifndef TEMPORIZADORES_H
#define TEMPORIZADORES_H

/* Macros para acceder directamente a los registros de cualquier temporizador */
#define TEMP_CONTROL(n) (*(vuint16*)(0x04000102 + (n << 2)))
#define TEMP_DATOS(n) (*(vuint16*)(0x04000100 + (n << 2)))

/* Este procedimiento habilita las interrupciones del temporizador */
extern void HabilitarIntTemp();
/* Este procedimiento deshabilita las interrupciones del temporizador */
extern void DeshabilitarIntTemp();

/* Establece la frecuencia de interrupción del temporizador 'id' a la indicada por el parámetro */
extern void prepararTemporizador(uint8 id, uint16 frecuencia);
/* Activa el temporizador 'id' */
extern void iniciarTemporizador(uint8 id);
/* Desactiva el temporizador 'id' */
extern void pararTemporizador(uint8 id);

// Temporizador 0
extern uint16 obtenerTiempo();
extern void resetearTiempo();
extern void intTemporizador0();

// Temporizador 1
extern void intTemporizador1();

#endif // TEMPORIZADORES_H
