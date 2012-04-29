/*-------------------------------------
sprites.h
-------------------------------------*/

#ifndef SPRITES_H
#define SPRITES_H

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
