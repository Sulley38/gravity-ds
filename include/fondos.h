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
fondos.h
-------------------------------------*/

#ifndef FONDOS_H
#define FONDOS_H

/* Identificadores de los fondos posibles */
extern int Fondo2, Fondo3, FondoSub3;

/* Procedimiento para inicializar los fondos. */
extern void initFondos(); 

/* Copia 'imagen' en formato bitmap de 'longitud_imagen' bytes en la dirección de memoria de 'fondo' */
extern void cargarFondoBitmap(int fondo, const void * imagen, uint32 longitud_imagen );
/* Copia 'imagen' en formato de paleta de 'longitud_imagen' bytes en la dirección de memoria de 'fondo' */
extern void cargarFondoPaleta(int fondo, const void * imagen, uint32 longitud_imagen, const void * paleta, uint32 longitud_paleta );
/* Carga una imagen completamente negra de tamaño 256x256 en el fondo indicado */
extern void cargarFondoNegro(int fondo);

#endif // FONDOS_H
