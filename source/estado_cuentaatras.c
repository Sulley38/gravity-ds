
#include <nds.h>
#include "defines.h"
#include "sprites.h"

void HacerCuentaAtras() {
	// Stub

	// Pasar al siguiente estado
	establecerPaletaAvanzarPersonaje();
	InicializarVariablesJuego();
	ESTADO = AVANZAR_PERSONAJE;
}
