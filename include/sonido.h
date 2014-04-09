/*  Copyright 2012 Daniel Franco, Iván Matellanes, Asier Mujika
 *
 *  This file is part of Gravity DS.
 *
 *  Gravity DS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation, either version 3 of the License,
 *  or (at your option) any later version.
 *
 *  Gravity DS is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Gravity DS is distributed. 
 *  If not, see <http://www.gnu.org/licenses/>.
 */

/*-------------------------------------
sonido.h
-------------------------------------*/

#ifndef SONIDO_H
#define SONIDO_H

/* Inicializa el sistema y el sonido de la moneda */
extern void cargarSonido();

/* Reproduce el sonido de moneda pulsada */
extern void sonidoMoneda();
/* Ajusta el sonido conforme pasa el tiempo */
extern void ajustarSonidoMoneda();

/* Reproduce el sonido de la cuenta atrás */
extern void sonidoCuenta( uint16 frecuencia );
/* Reduce gradualmente el volumen del sonido de la cuenta atrás */
extern void ajustarSonidoCuenta();


#endif // SONIDO_H
