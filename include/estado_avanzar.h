/*-------------------------------------
estado_avanzar.h
-------------------------------------*/

#ifndef E_AVANZAR_H
#define E_AVANZAR_H

/* Número de bloques que hay en el nivel */
#define CANTIDAD_BLOQUES 65

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


/* Dibuja el personaje del juego en la posición (X,Y) dada por PosicionPersonaje[] */
void dibujar_personaje();
/* Dibuja las plataformas que correspondan en pantalla */
void dibujar_bloques();
/* Limpia todas las plataformas de la pantalla y recalcula los bloques que pueden aparecer */
void limpiar_bloques();

/* Devuelve 1 si está apoyado en una plataforma, 0 de lo contrario */
uint8 EnPlataforma();
/* Devuelve 1 si está chocando con una plataforma, 0 de lo contrario */
uint8 Colision();
/*Dibuja las monedas en la pantalla*/
void dibujar_monedas();
/*Con esta función comprobamos si se ha tocado una moneda de la pantalla*/
uint8 tocar(uint8 x, uint8 y);

/* Va actualizando la posicion de las monedas en la pantalla, comprueva si
 * las monedas han llegado al final de la pantalla, en ese caso vuelve
 * a actualizar la posición de la moneda poniendola en una posición aleatoria
 * de la pantalla. También comprueva si alguna moneda se ha tocado, en ese caso
 * sumará los puntos correspondientes ha cojer una moneda y la hará desaparecer.*/
void limpiar_monedas();

#endif // E_AVANZAR_H
