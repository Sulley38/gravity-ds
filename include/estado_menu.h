/*-------------------------------------
estado_menu.h
-------------------------------------*/

#ifndef E_MENU_H
#define E_MENU_H

/* Muestra un par de botones con las opciones de jugar o salir */
extern void MostrarMenu();

/* Estas funciones dibujan los botones del menú en las coordenadas indicadas */
extern void dibujar_botonJugar(int X, int Y);
extern void dibujar_botonContinuar(int X, int Y);
extern void dibujar_botonSalir(int X, int Y);

#endif // E_MENU_H
