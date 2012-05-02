/*-------------------------------------
estado_avanzar.h
-------------------------------------*/

#ifndef E_AVANZAR_H
#define E_AVANZAR_H

/* Número de bloques que hay en el nivel */
#define CANTIDAD_BLOQUES 65

/* Inicializa las variables de la partida */
extern void InicializarVariablesJuego();
/* Avanza un paso */
extern void Avanzar();
/* Permuta la dirección de la gravedad entre arriba y abajo */
extern void CambiarGravedad();

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

#endif // E_AVANZAR_H
