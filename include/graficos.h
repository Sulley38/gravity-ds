/* Definir el sistema de v�deo */
extern void initVideo();

/* Pone a cero el contador de frames */
// Se llama cada segundo desde intTemporizador()
extern void zeroFrames();
/* Devuelve los frames dibujados en lo que va de segundo */
extern int getFrames();
/* Atenci�n a las interrupciones de refresco vertical */
extern void intVBlank();
