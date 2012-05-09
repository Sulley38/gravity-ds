/*-------------------------------------
estado_puntuacion.h
-------------------------------------*/

#ifndef E_PUNTUACION_H
#define E_PUNTUACION_H

/* Imprime el n�mero indicado en las coordenadas indicadas (X,Y) */
void imprimir_numeros(uint8 x, uint8 y, int n);

/* Dibuja los elementos de la tabla de puntuaciones */
extern void CargarPuntuacion();

/* Muestra la puntuaci�n total de la partida */
extern void MostrarPuntuacion();

#endif // E_PUNTUACION_H
