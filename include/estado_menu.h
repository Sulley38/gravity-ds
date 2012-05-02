/*-------------------------------------
estado_menu.h
-------------------------------------*/

#ifndef E_MENU_H
#define E_MENU_H

/* Muestra un par de botones con las opciones de jugar o salir */
extern void MostrarMenu();

/* Estas funciones dibujan los botones del menú en las coordenadas indicadas */
extern void dibujar_botonJugar(uint8 X, uint8 Y);
extern void dibujar_botonContinuar(uint8 X, uint8 Y);
extern void dibujar_botonSalir(uint8 X, uint8 Y);

#endif // E_MENU_H
