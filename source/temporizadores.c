/*-------------------------------------
temporizadores.c
-------------------------------------*/

// añadir los includes que sean necesarios
#include <nds.h>
#include "defines.h"
#include "graficos.h"
#include "temporizadores.h"

// Variable de tiempo transcurrido
int tiempo = 0;

int tiempo_sonido_moneda=5;
int sonido_moneda;

// Devuelve el tiempo que ha transcurrido de partida
int obtenerTiempo()
{
	return tiempo;
}

// Pone el contador de tiempo a cero
void resetearTiempo()
{
	tiempo = 0;
}


// Este procedimiento habilita las interrupciones del temporizador
void HabilitarIntTemp()
{
	//Para ello primero se deshabilitan todas las interrupciones
	DisableInts();

	//Escribir un 1 en el bit correspondiente al temporizador del REG_IE
	IE = IE | 1 << 3 | 1<<4;

	//Para acabar, se habilitan todas las interrupciones
	EnableInts();
}		

// Este procedimiento deshabilita las interrupciones del temporizador
void DeshabilitarIntTemp()
{
	//Para ello primero se deshabilitan todas las interrupciones
	DisableInts();

	//Escribir un 0 en el bit correspondiente al remporizador del REG_IE
	IE = IE & ~(1 << 3);

	//Para acabar, se habilitan todas las interrupciones
	EnableInts();
}


// Establece la frecuencia del temporizador 0 a la indicada en interrupciones/seg
void prepararTemporizador(int frecuencia, int temp)
{
	int latch = -1, divisor = 0;
	// Calcula el latch
	latch = 65532 - (33554432/frecuencia);
	if( latch < 0 ) {
		latch = 65532 - (33554432/(frecuencia*64));
		divisor = 1;
		if( latch < 0 ) {
			latch = 65532 - (33554432/(frecuencia*256));
			divisor = 2;
			if( latch < 0 ) {
				latch = 65532 - (33554432/(frecuencia*1024));
				divisor = 3;
			}
		}
	}

	if( latch < 0 ) {
		// No se puede contar a la frecuencia indicada: no se activa el temporizador
		DeshabilitarIntTemp();
		TIMER0_CNT = 0;
	} else {
		if (temp==0){
			// Establece los registros
			TIMER0_DAT = latch;
			TIMER0_CNT = divisor | 1 << 6; // bits 0, 1 y 6 encendidos
		}
		if(temp==1){
			TIMER1_DAT = latch;
			TIMER1_CNT = divisor | 1 << 6; // bits 0, 1 y 6 encendidos
		}
	}
}

// Activa el temporizador 0
void iniciarTemporizador(int temp)
{
	if (temp==0)		TIMER0_CNT = TIMER0_CNT | 1 << 7; // enciende bit 7
	if (temp==1)		TIMER1_CNT = TIMER1_CNT | 1 << 7; // enciende bit 7
}

// Desactiva el temporizador 0
void pararTemporizador(int temp)
{
	if (temp==0)		TIMER0_CNT = TIMER0_CNT & ~(1 << 7); // apaga bit 7
	if (temp==1)		TIMER1_CNT = TIMER1_CNT & ~(1 << 7); // apaga bit 7
}

// Rutina de atencion a la interrupcion del temporizador 0
void intTemporizador0()
{
	tiempo++;
}

void intTempMoneda(){
	if (tiempo_sonido_moneda==1)		soundSetFreq(sonido_moneda,10500);
	if (tiempo_sonido_moneda==4)		soundSetVolume(sonido_moneda,60);
	if (tiempo_sonido_moneda==5){
		soundPause(sonido_moneda);
		pararTemporizador(1);
	}

	tiempo_sonido_moneda ++;

}

void ruidoMoneda(){
	iniciarTemporizador(1);
	soundSetFreq(sonido_moneda,7000);
	soundResume(sonido_moneda);
	tiempo_sonido_moneda=0;
}
