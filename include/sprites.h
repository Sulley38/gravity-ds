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
sprites.h
-------------------------------------*/

#ifndef SPRITES_H
#define SPRITES_H

/* Direcciones de memoria en las que están guardados los sprites */
extern u16* Corredor[4];
extern u16* Nube;
extern u16* Bloque;
extern u16* Moneda;
extern u16* botonJugar[2];
extern u16* botonContinuar[2];
extern u16* botonSalir[2];
extern u16* Numeros[10];
extern u16* NumerosSub[10];

/* Función principal para cargar lo relacionado con sprites */
extern void cargarSprites();

/* Inicializa la memoria de sprites */
void initSpriteMem();
/* Define la paleta de colores extendida para todos los sprites del juego */
void establecerPaletaSprites();
/* Guarda los sprites en memoria para luego poder usarlos */
void guardarSpritesEnMemoria();

#endif // SPRITES_H
