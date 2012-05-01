/*-------------------------------------
defines.h
-------------------------------------*/

#ifndef DEFINES_H
#define DEFINES_H

//Aqu� se definen los registros del gestor de interrupciones
#define IME		(*(vuint32*)0x04000208) //Interrupt Master Enable -- Habilita o deshabilita todas las interrupciones
#define IE		(*(vuint32*)0x04000210) //Interrupt Enable -- Activa o desactiva las interrupciones una a una
#define IF		(*(vuint32*)0x04000214) //Interrupt Flag -- Guarda las peticiones de interrupci�n

// Aqu� se definen algunas funciones para el tratamiento de las interrupciones
#define EnableInts() REG_IME=1 //habilita todas las interrupciones
#define DisableInts() REG_IME=0 //deshabilita todas las interrupciones

// Aqu� se definen los registros del teclado 
#define TECLAS_DAT	(*(vu16*)0x4000130) //registro de datos del teclado
#define TECLAS_CNT	(*(vu16*)0x4000132) //registro de control del teclado

// Aqu� se definen los registros del temporizador
#define TIMER0_CNT   (*(vuint16*)0x04000102) //registro de control del temporizador
// El temporizador se activa poniendo un 1 en el 7� bit.
// El temporizador interrumpir� al desbordarse el contador, si hay un 1 en el 6� bit.
// Los dos bits de menos peso indican lo siguiente:
//			00 frecuencia 33554432 hz
//			01 frecuencia 33554432/64 hz
//			10 frecuencia 33554432/256 hz
//			11 frecuencia 33554432/1024 hz

#define TIMER0_DAT    (*(vuint16*)0x04000100) //registro de datos del temporizador
// Se utiliza para indicar a partir de qu� valor tiene que empezar a contar


// Para no liarse con los n�meros a cada teclas se le ha asignado un nombre
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

// Para no liarse con los n�meros a cada estado se le puede asignar un nombre
#define MENU			0
#define CUENTA_ATRAS	1
#define AVANZAR_PERSONAJE	2
#define PAUSA			3
#define PUNTUACION		4
#define FIN				9


// Variable global de estado
extern int ESTADO;

#endif // DEFINES_H
