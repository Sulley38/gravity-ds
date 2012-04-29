/*-------------------------------------
pantalla.h
-------------------------------------*/

#ifndef PANTALLA_H
#define PANTALLA_H

#include <nds.h>

//Nos devuelve la posicion de la pantalla en la que se haya tocado la pantalla tactil por encuesta
//hasta que el usuario toque en algun lugar de la pantalla
touchPosition posicionPantallaEncuesta();

//Nos devuelve la posicion de la pantalla en la que se haya tocado si se ha tocado,
//en caso contrario nos devolverá lad coordenadas 0,0
touchPosition posicionPantalla();


#endif // PANTALLA_H
