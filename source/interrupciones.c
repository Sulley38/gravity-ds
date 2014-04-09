/*  Copyright 2012 Daniel Franco, Iván Matellanes, Asier Mujika
 *
 *  This file is part of Gravity DS.
 *
 *  Gravity DS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation, either version 3 of the License,
 *  or (at your option) any later version.
 *
 *  Gravity DS is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Gravity DS is distributed. 
 *  If not, see <http://www.gnu.org/licenses/>.
 */

/*-------------------------------------
interrupciones.c
-------------------------------------*/

#include <nds.h>
#include "graficos.h"
#include "interrupciones.h"
#include "temporizadores.h"

//Este procedimiento inicializa la tabla de interrupciones para que el gestor de interrupciones sepa
//qué rutina de atención tiene que ejecutar cuando le llega una petición de interrupción. Además es 
//aquí donde se configuran los registros de control de los periféricos.
void rellenarTablaInt()
{
	irqSet(IRQ_VBLANK,intVBlank);
	irqSet(IRQ_TIMER0,intTemporizador0);
	irqSet(IRQ_TIMER1,intTemporizador1);

	HabilitarIntTemp();
	prepararTemporizador(0,1);
	prepararTemporizador(1,15);
}
