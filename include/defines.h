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
defines.h
-------------------------------------*/

#ifndef DEFINES_H
#define DEFINES_H

//Aquí se definen los registros del gestor de interrupciones
#define IME		(*(vuint32*)0x04000208) //Interrupt Master Enable -- Habilita o deshabilita todas las interrupciones
#define IE		(*(vuint32*)0x04000210) //Interrupt Enable -- Activa o desactiva las interrupciones una a una
#define IF		(*(vuint32*)0x04000214) //Interrupt Flag -- Guarda las peticiones de interrupción

// Aquí se definen algunas funciones para el tratamiento de las interrupciones
#define EnableInts() REG_IME=1 //habilita todas las interrupciones
#define DisableInts() REG_IME=0 //deshabilita todas las interrupciones

// Aquí se definen los registros del teclado 
#define TECLAS_DAT	(*(vu16*)0x4000130) //registro de datos del teclado
#define TECLAS_CNT	(*(vu16*)0x4000132) //registro de control del teclado

// No nos hace falta definir los registros de temporizador, tenemos una macro para acceder a ellos

// Para no liarse con los números a cada teclas se le ha asignado un nombre
#define A			0 
#define B			1
#define SELECT			2 
#define START			3
#define DERECHA			4 
#define IZQUIERDA		5
#define ARRIBA			6 
#define ABAJO			7
#define R			8 
#define L			9

// Para no liarse con los números a cada estado se le puede asignar un nombre
#define FONDO_PUMA		0
#define MENU			1
#define CUENTA_ATRAS	2
#define AVANZAR_PERSONAJE	3
#define PAUSA			4
#define PUNTUACION		5
#define FIN				9


// Variable global de estado
extern int ESTADO;


#endif // DEFINES_H
