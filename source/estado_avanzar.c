
#include <nds.h>
#include "defines.h"
#include "fondos.h"
#include "estado_avanzar.h"

void Avanzar() {
	// Stub

	/* Mostrar fondos en pantalla */
	mostrarFondoEstrellado();
	mostrarFondoEstrelladoSub();

	oamUpdate(&oamMain);
	oamUpdate(&oamSub);

}
