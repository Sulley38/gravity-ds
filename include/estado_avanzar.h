/*-------------------------------------
estado_avanzar.h
-------------------------------------*/

#ifndef E_AVANZAR_H
#define E_AVANZAR_H

/* N�mero de bloques y monedas que hay en el nivel */
#define CANTIDAD_BLOQUES 65
#define CANTIDAD_MONEDAS 10

/* Macro para comprobar si una tecla ha sido pulsada */
#define TECLA_PULSADA(n) !(TECLAS_DAT & (1 << 10 | 1 << n))

/* Inicializa las variables de la partida */
extern void InicializarVariablesJuego();

/* Avanza un paso aumentando la distancia recorrida */
extern void Avanzar();
/* Realiza la encuesta de teclado */
extern void EncuestaTeclado();
/* Actualiza convenientemente los sprites que se muestran en pantalla */
extern void ActualizarPantalla();


/* Dibuja el personaje del juego en la posici�n (X,Y) dada por PosicionPersonaje[] */
void dibujar_personaje();
/* Dibuja las plataformas que correspondan en pantalla */
void dibujar_bloques();
/* Limpia todas las plataformas de la pantalla y recalcula los bloques que pueden aparecer */
void limpiar_bloques();

/* Devuelve 1 si est� apoyado en una plataforma, 0 de lo contrario */
uint8 EnPlataforma();
/* Devuelve 1 si est� chocando con una plataforma, 0 de lo contrario */
uint8 Colision();
/*Dibuja las monedas en la pantalla*/
void dibujar_monedas();
/*Con esta funci�n comprobamos si se ha tocado una moneda de la pantalla*/
uint8 tocar(uint8 x, uint8 y);

/* Va actualizando la posicion de las monedas en la pantalla, comprueva si
 * las monedas han llegado al final de la pantalla, en ese caso vuelve
 * a actualizar la posici�n de la moneda poniendola en una posici�n aleatoria
 * de la pantalla. Tambi�n comprueva si alguna moneda se ha tocado, en ese caso
 * sumar� los puntos correspondientes ha cojer una moneda y la har� desaparecer.*/
void limpiar_monedas();

#endif // E_AVANZAR_H
