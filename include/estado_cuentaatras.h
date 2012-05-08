/*-------------------------------------
estado_cuentaatras.h
-------------------------------------*/

#ifndef E_CUENTAATRAS_H
#define E_CUENTAATRAS_H

/* Definiciones para el cálculo de la posición de las imágenes */
#define DIMENSION_IMAGEN 256
#define DIMENSION_ESCALADA (DIMENSION_IMAGEN / fixedToFloat(FactorEscala,8))

/* Prepara el temporizador y carga la situación inicial para hacer la cuenta atrás */
extern void InicializarCuentaAtras();

/* Muestra unas imágenes de 3, 2, 1, YA! */
extern void HacerCuentaAtras();

#endif // E_CUENTAATRAS_H
