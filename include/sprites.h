/*-------------------------------------
sprites.h
-------------------------------------*/

#ifndef SPRITES_H
#define SPRITES_H

/* Direcciones de memoria en las que están guardados los sprites */
extern u16* Corredor[4];
extern u16* Bloque;
extern u16* Moneda;
extern u16* botonJugar[2];
extern u16* botonContinuar[2];
extern u16* botonSalir[2];
extern u16* Numeros[10];

/* Función principal para cargar lo relacionado con sprites */
extern void cargarSprites();

/* Inicializa la memoria de sprites */
void initSpriteMem();
/* Define la paleta de colores extendida para todos los sprites del juego */
void establecerPaletaSprites();
/* Guarda los sprites en memoria para luego poder usarlos */
void guardarSpritesEnMemoria();

#endif // SPRITES_H
