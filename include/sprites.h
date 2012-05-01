/*-------------------------------------
sprites.h
-------------------------------------*/

#ifndef SPRITES_H
#define SPRITES_H

/* Constantes de tamaño de los sprites **/
#define ANCHURA_PANTALLA 256
#define ALTURA_PANTALLA 192
#define ANCHURA_PERSONAJE 32
#define ALTURA_PERSONAJE 32
#define ANCHURA_BLOQUE 64
#define ALTURA_BLOQUE 16

/* Direcciones de memoria en las que están guardados los sprites */
extern u16* Corredor[4];
extern u16* Bloque;
extern u16* botonJugar[2];
extern u16* botonContinuar[2];
extern u16* botonSalir[2];

/* Inicializa la memoria de sprites */
extern void initSpriteMem();
/* Define la paleta de colores extendida para todos los sprites del juego */
extern void cargarPaletaSprites();
/* Guarda los sprites en memoria para luego poder usarlos */
extern void guardarSpritesEnMemoria();

#endif // SPRITES_H
