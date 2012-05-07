/*-------------------------------------
estado_avanzar.h
-------------------------------------*/

#ifndef E_AVANZAR_H
#define E_AVANZAR_H

/* Número de bloques y monedas que hay en el nivel */
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
/* Dibuja las monedas en la pantalla */
void dibujar_monedas();
/* Limpia las monedas de la pantalla y recalcula su posición */
void actualizar_monedas();

/* Devuelve 1 si está apoyado en una plataforma, 0 de lo contrario */
uint8 EnPlataforma();
/* Devuelve 1 si está chocando con una plataforma, 0 de lo contrario */
uint8 Colision();

#endif // E_AVANZAR_H
