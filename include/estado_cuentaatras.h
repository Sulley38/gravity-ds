/*-------------------------------------
estado_cuentaatras.h
-------------------------------------*/

#ifndef E_CUENTAATRAS_H
#define E_CUENTAATRAS_H

/* Definiciones para el c�lculo de la posici�n de las im�genes */
#define DIMENSION_IMAGEN 128
#define DIMENSION_ESCALADA (DIMENSION_IMAGEN / fixedToFloat(FactorEscala,8))

/* Prepara el temporizador y carga la situaci�n inicial para hacer la cuenta atr�s */
extern void InicializarCuentaAtras();

/* Muestra unas im�genes de 3, 2, 1, YA! */
extern void HacerCuentaAtras();

/* Termina la cuenta atr�s quitando el GO! de la pantalla */
extern void TerminarCuentaAtras();

#endif // E_CUENTAATRAS_H
