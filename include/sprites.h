extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;
extern u16* cuadrado;
extern u16* cuadrado2;
extern u16* corredorA;


/* Inicializar la memoria de Sprites. */
extern void initSpriteMem();

/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla principal. El 0 es transparente y los no definidos son negros.
 */
extern void establecerPaletaPrincipal();

/* Dentro de esta función hay que definir el color con el que se mostrará cada uno de los 256 
 * colores posibles en la pantalla secundaria. El 0 es transparente y los no definidos son negros.
 */
extern void establecerPaletaSecundaria();

/* Para guardar los sprites en memoria y luego poder usarlos.*/
extern void guardarSpritesEnMemoria();
