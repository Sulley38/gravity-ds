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
estado_menu.h
-------------------------------------*/

#ifndef E_MENU_H
#define E_MENU_H

/* Dibuja los botones del menú */
extern void CargarMenu();
/* Muestra un par de botones con las opciones de jugar o salir */
extern void MostrarMenu();

/* Estas funciones dibujan los botones del menú en las coordenadas indicadas */
extern void dibujar_botonJugar(int X, int Y);
extern void dibujar_botonContinuar(int X, int Y);
extern void dibujar_botonSalir(int X, int Y);

#endif // E_MENU_H
