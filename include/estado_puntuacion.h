/*-------------------------------------
estado_puntuacion.h
-------------------------------------*/

#ifndef E_PUNTUACION_H
#define E_PUNTUACION_H

/* Lee el fichero de puntuaciones "gravityds-scores.txt" y rellena el vector de puntuaciones */
extern void LeerFicheroPuntuaciones();

/* Escribe el fichero "gravityds-scores.txt" con los valores del vector de puntuaciones */
extern void EscribirFicheroPuntuaciones();

/* Imprime en la pantalla secundaria las puntuaciones le�das */
extern void ImprimirPuntuaciones();

/* Dibuja los elementos de la tabla de puntuaciones */
extern void CargarPuntuacion();

/* Muestra la puntuaci�n total de la partida */
extern void MostrarTablaPuntuacion();

/* Inserta la puntuaci�n obtenida en el vector de puntuaciones */
void InsertarPuntuacion();

/* Imprime el n�mero indicado en las coordenadas indicadas (X,Y) */
extern void imprimir_numeros(uint8 X, uint8 Y, uint32 N);
extern void imprimir_numeros_sub(uint8 X, uint8 Y, uint32 N, int oamBase);

#endif // E_PUNTUACION_H
