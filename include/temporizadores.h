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
temporizadores.h
-------------------------------------*/

#ifndef TEMPORIZADORES_H
#define TEMPORIZADORES_H

/* Macros para acceder directamente a los registros de cualquier temporizador */
#define TEMP_CONTROL(n) (*(vuint16*)(0x04000102 + (n << 2)))
#define TEMP_DATOS(n) (*(vuint16*)(0x04000100 + (n << 2)))

/* Este procedimiento habilita las interrupciones del temporizador */
extern void HabilitarIntTemp();
/* Este procedimiento deshabilita las interrupciones del temporizador */
extern void DeshabilitarIntTemp();

/* Establece la frecuencia de interrupción del temporizador 'id' a la indicada por el parámetro */
extern void prepararTemporizador(uint8 id, uint16 frecuencia);
/* Activa el temporizador 'id' */
extern void iniciarTemporizador(uint8 id);
/* Desactiva el temporizador 'id' */
extern void pararTemporizador(uint8 id);

// Temporizador 0
extern uint16 obtenerTiempo();
extern void resetearTiempo();
extern void intTemporizador0();

// Temporizador 1
extern void intTemporizador1();

#endif // TEMPORIZADORES_H
