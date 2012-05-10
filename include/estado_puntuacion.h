/*-------------------------------------
estado_puntuacion.h
-------------------------------------*/

#ifndef E_PUNTUACION_H
#define E_PUNTUACION_H

/* Lee el fichero de puntuaciones "gravityds-scores.txt" y rellena el vector de puntuaciones */
extern void LeerFicheroPuntuaciones();
/* Imprime en la pantalla secundaria las puntuaciones leídas */
extern void ImprimirPuntuaciones();

/* Dibuja los elementos de la tabla de puntuaciones */
extern void CargarPuntuacion();

/* Muestra la puntuación total de la partida */
extern void MostrarTablaPuntuacion();

/* Imprime el número indicado en las coordenadas indicadas (X,Y) */
extern void imprimir_numeros(uint8 x, uint8 y, int n);
extern void imprimir_numeros_sub(uint8 x, uint8 y, int n, int oamBase);

#endif // E_PUNTUACION_H
