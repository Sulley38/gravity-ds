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
extern u16* cuadrado;
extern u16* cuadrado2;
extern u16* corredor[4];
extern u16* bloque;


/* Inicializa la memoria de sprites */
extern void initSpriteMem();

/* Define los colores posibles para el estado 'Menu' */
extern void establecerPaletaMenu();
/* Define los colores posibles para el estado 'Avanzar personaje' */
extern void establecerPaletaAvanzarPersonaje();

/* Guarda los sprites en memoria para luego poder usarlos */
extern void guardarSpritesEnMemoria();


#endif // SPRITES_H
