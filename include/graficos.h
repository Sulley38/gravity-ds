/* Definir el sistema de vídeo */
extern void initVideo();

/* Pone a cero el contador de frames */
// Se llama cada segundo desde intTemporizador()
extern void zeroFrames();
/* Devuelve los frames dibujados en lo que va de segundo */
extern int getFrames();
/* Atención a las interrupciones de refresco vertical */
extern void intVBlank();
/* Dibuja el personaje en el x,y que se indique */
extern void dibujar_personaje(int x, int y, int invertido);
/* Dibuja los bloques desde min hasta max*/
extern void dibujar_bloques(int pos[3][2],int min,int max, int dist);
