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
estado_cuentaatras.h
-------------------------------------*/

#ifndef E_CUENTAATRAS_H
#define E_CUENTAATRAS_H

/* Definiciones para el cálculo de la posición de las imágenes */
#define DIMENSION_IMAGEN 256
#define DIMENSION_ESCALADA (DIMENSION_IMAGEN / fixedToFloat(FactorEscala,8))

/* Prepara el temporizador y carga la situación inicial para hacer la cuenta atrás */
extern void InicializarCuentaAtras();

/* Muestra unas imágenes de 3, 2, 1, YA! */
extern void HacerCuentaAtras();

#endif // E_CUENTAATRAS_H
