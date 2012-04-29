/*-------------------------------------
sprites.h
-------------------------------------*/

#ifndef SPRITES_H
#define SPRITES_H

extern u16* cuadrado;
extern u16* cuadrado2;
extern u16* corredor[4];
extern u16* bloque;


/* Inicializar la memoria de Sprites. */
extern void initSpriteMem();

/* Dentro de esta funci�n hay que definir el color con el que se mostrar� cada uno de los 256 
 * colores posibles en la pantalla principal. El 0 es transparente y los no definidos son negros.
 */
extern void establecerPaletaPrincipal();

/* Dentro de esta funci�n hay que definir el color con el que se mostrar� cada uno de los 256 
 * colores posibles en la pantalla secundaria. El 0 es transparente y los no definidos son negros.
 */
extern void establecerPaletaSecundaria();

/* Para guardar los sprites en memoria y luego poder usarlos.*/
extern void guardarSpritesEnMemoria();


#endif // SPRITES_H
