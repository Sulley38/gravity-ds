
#include <nds.h>
#include "defines.h"
#include "estado_avanzar.h"
#include "sprites.h"

void HacerCuentaAtras() {
	// Stub

	// Pasar al siguiente estado
	establecerPaletaAvanzarPersonaje();
	InicializarVariablesJuego();
	ESTADO = AVANZAR_PERSONAJE;
}
