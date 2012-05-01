/*-------------------------------------
sprites.h
-------------------------------------*/

#ifndef SPRITES_H
#define SPRITES_H

/* Constantes de tama�o de los sprites **/
#define ANCHURA_PANTALLA 256
#define ALTURA_PANTALLA 192
#define ANCHURA_PERSONAJE 32
#define ALTURA_PERSONAJE 32
#define ANCHURA_BLOQUE 64
#define ALTURA_BLOQUE 16

/* Direcciones de memoria en las que est�n guardados los sprites */
extern u16* cuadrado;
extern u16* cuadrado2;
extern u16* corredor[4];
extern u16* bloque;
extern u16* play[2];
extern u16* resume[2];
extern u16* boton_exit[2];

/* Inicializa la memoria de sprites */
extern void initSpriteMem();
/* Define la paleta de colores extendida para todos los sprites del juego */
extern void cargarPaletaSprites();
/* Guarda los sprites en memoria para luego poder usarlos */
extern void guardarSpritesEnMemoria();

#endif // SPRITES_H
