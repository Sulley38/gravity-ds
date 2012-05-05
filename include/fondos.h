/*-------------------------------------
fondos.h
-------------------------------------*/

#ifndef FONDOS_H
#define FONDOS_H

/* Identificadores de los fondos posibles */
extern int Fondo2, Fondo3, FondoSub3;

/* Procedimiento para inicializar los fondos. */
extern void initFondos(); 

/* Copia 'imagen' de 'longitud' bytes en la dirección de memoria de 'fondo' */
extern void cargarFondo(const void * imagen, int fondo, uint32 longitud);

#endif // FONDOS_H
