#include <nds.h>
#include "defines.h"
#include "estado_pausa.h"
#include "fondos.h"
#include "graficos.h"
#include "interrupciones.h"
#include "sprites.h"
#include "teclado.h"

int main() {
	//TODO LO DEL MAIN
	powerOn(POWER_ALL_2D);lcdMainOnBottom();initVideo();initFondos();rellenarTablaInt();mostrarFondoEstrellado();mostrarFondoEstrelladoSub();initSpriteMem();
	guardarSpritesEnMemoria();establecerPaletaPrincipal();establecerPaletaSecundaria();

	//LO MIO
	consoleDemoInit();
	Pausar();

	while(TRUE){}
	return 0;
}
