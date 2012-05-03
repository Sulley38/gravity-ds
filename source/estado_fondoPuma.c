#include <nds.h>
#include "defines.h"
#include "temporizadores.h"
#include "fondos.h"

//MUESTRA EL FONDO PRINCIPAL
void mostrarPantallaInicio(){

	initFondos();
	mostrarFondoPuma();
	mostrarFondoArribaSub();

	iniciarTemporizador(0);

	while (obtenerTiempo()<3){}

	pararTemporizador(0);
	resetearTiempo();
	mostrarFondoAzul();

	ESTADO = MENU;

}
