#include <nds.h>
#include <stdio.h>
#include "estado_pausa.h"

void main(){
	//TODO LO DEL MAIN
	powerOn(POWER_ALL_2D);lcdMainOnBottom();initVideo();initFondos();rellenarTablaInt();mostrarFondoEstrellado();mostrarFondoEstrelladoSub();initSpriteMem();
	guardarSpritesEnMemoria();establecerPaletaPrincipal();establecerPaletaSecundaria();

	//LO MIO
consoleDemoInit();
Pausar();

while(TRUE){}


}
