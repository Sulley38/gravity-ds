/*-------------------------------------
estado_avanzar.h
-------------------------------------*/

#ifndef E_AVANZAR_H
#define E_AVANZAR_H

/* Número de bloques y monedas que hay en el nivel */
#define CANTIDAD_BLOQUES 438

/* Definiciones de tamaño de los sprites */
#define ANCHURA_PERSONAJE 32
#define ALTURA_PERSONAJE 32
#define ANCHURA_BLOQUE(n) (64 - 48*n)
#define ALTURA_BLOQUE(n) (16 + 48*n)

/* Macro para comprobar si una tecla ha sido pulsada */
#define TECLA_PULSADA(n) !(TECLAS_DAT & (1 << 10 | 1 << n))

/* Variables de puntuación */
extern uint16 DistanciaRecorrida;
extern uint8 MonedasRecogidas;

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
/* Dibuja las monedas en la pantalla */
void dibujar_monedas();
/* Dibuja las nubes que correspondan en pantalla */
void dibujar_nubes();

/* Limpia todas las plataformas de la pantalla y recalcula los bloques que pueden aparecer */
void limpiar_bloques();
/* Limpia las monedas de la pantalla y recalcula su posición */
void actualizar_monedas();
/* Recalcula la posición de las nubes */
void actualizar_nubes();
/* Actualiza los contadores de la pantalla secundaria */
void actualizar_puntuacion();

/* Devuelve 1 si está apoyado en una plataforma, 0 de lo contrario */
uint8 EnPlataforma();
/* Devuelve 1 si está chocando con una plataforma, 0 de lo contrario */
uint8 Colision();

#endif // E_AVANZAR_H
