// Estado 'Cuenta atr�s' definido en el aut�mata

#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"

void HacerCuentaAtras() {
	// Stub

	// Pasar al siguiente estado
	InicializarVariablesJuego();
	ESTADO = AVANZAR_PERSONAJE;
}
