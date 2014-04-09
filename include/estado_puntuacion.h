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
estado_puntuacion.h
-------------------------------------*/

#ifndef E_PUNTUACION_H
#define E_PUNTUACION_H

/* Lee el fichero de puntuaciones "gravityds-scores.txt" y rellena el vector de puntuaciones */
extern void LeerFicheroPuntuaciones();

/* Escribe el fichero "gravityds-scores.txt" con los valores del vector de puntuaciones */
extern void EscribirFicheroPuntuaciones();

/* Imprime en la pantalla secundaria las puntuaciones leídas */
extern void ImprimirPuntuaciones();

/* Dibuja los elementos de la tabla de puntuaciones */
extern void CargarPuntuacion();

/* Muestra la puntuación total de la partida */
extern void MostrarTablaPuntuacion();

/* Inserta la puntuación obtenida en el vector de puntuaciones */
void InsertarPuntuacion();

/* Imprime el número indicado en las coordenadas indicadas (X,Y) */
extern void imprimir_numeros(uint8 X, uint8 Y, uint32 N);
extern void imprimir_numeros_sub(uint8 X, uint8 Y, uint32 N, int oamBase);

#endif // E_PUNTUACION_H
