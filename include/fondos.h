/*-------------------------------------
fondos.h
-------------------------------------*/

#ifndef FONDOS_H
#define FONDOS_H

/* Identificadores de los fondos posibles */
extern int Fondo2, Fondo3, FondoSub3;

/* Procedimiento para inicializar los fondos. */
extern void initFondos(); 

/* Copia 'imagen' en formato bitmap de 'longitud_imagen' bytes en la dirección de memoria de 'fondo' */
extern void cargarFondoBitmap(int fondo, const void * imagen, uint32 longitud_imagen );
/* Copia 'imagen' en formato de paleta de 'longitud_imagen' bytes en la dirección de memoria de 'fondo' */
extern void cargarFondoPaleta(int fondo, const void * imagen, uint32 longitud_imagen, const void * paleta, uint32 longitud_paleta );
/* Carga una imagen completamente negra de tamaño 256x256 en el fondo indicado */
extern void cargarFondoNegro(int fondo);

#endif // FONDOS_H
