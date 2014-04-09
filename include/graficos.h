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
graficos.h
-------------------------------------*/

#ifndef GRAFICOS_H
#define GRAFICOS_H

/* Definir el sistema de vídeo */
extern void initVideo();

/* Devuelve los frames dibujados en lo que va de segundo */
extern uint8 obtenerFrames();
/* Atención a las interrupciones de refresco vertical */
extern void intVBlank();

#endif // GRAFICOS_H
