/*-------------------------------------
teclado.c
-------------------------------------*/

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "teclado.h"
#include "sonido.h"


//Este procedimiento habilita las interrupciones del teclado
void HabilitarIntTec()
{
	//Para ello primero se deshabilitan todas las interrupciones
	DisableInts();
	//Escribir un 1 en el bit correspondiente al teclado del REG_IE
	IE = IE | 1 << 12;
	// Ajusta el registro de control del teclado para las teclas que queremos usar
	TECLAS_CNT = (1 << 0 | 1 << 1 | 1 << 3 | 1 << 6 | 1 << 7 | 1 << 14) & ~(1 << 15);
	//Para acabar, se habilitan todas las interrupciones
	EnableInts();
}

//Este procedimiento deshabilita las interrupciones del teclado
void DeshabilitarIntTec()
{
	//Para ello primero se deshabilitan todas las interrupciones
	DisableInts();
	//Escribir un 0 en el bit correspondiente al teclado del REG_IE
	IE = IE & ~(1 << 12);
	//Para acabar, se habilitan todas las interrupciones
	EnableInts();
}

//Rutina de atención a la interrupción del teclado
void intTeclado()
{
	if( ESTADO == AVANZAR_PERSONAJE && (TECLA_PULSADA(A) || TECLA_PULSADA(B) || TECLA_PULSADA(ARRIBA) || TECLA_PULSADA(ABAJO)) ) {
		//CambiarGravedad();
		sonidoMoneda();
	} else if( ESTADO == AVANZAR_PERSONAJE && (TECLA_PULSADA(START)) ) {
		ESTADO = PAUSA;
	}
}
