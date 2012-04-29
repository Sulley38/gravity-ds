/*-------------------------------------
estado_avanzar.h
-------------------------------------*/

#ifndef E_AVANZAR_H
#define E_AVANZAR_H

/* Avanza un paso */
extern void Avanzar();

/* Dibuja el personaje del juego en la posición (X,Y) dada por PosicionPersonaje[] */
void dibujar_personaje(uint8 Mov);
/* Dibuja las plataformas que correspondan en pantalla */
void dibujar_bloques();
/* Limpia todas las plataformas de la pantalla y recalcula los bloques que pueden aparecer */
void limpiar_bloques();

#endif // E_AVANZAR_H
