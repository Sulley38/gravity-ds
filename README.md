
# Gravity DS #
## Proyecto de Estructura de Computadores ##

### Autores: Daniel Franco, Iv�n Matellanes y Asier Mujika ###

### Prerrequisitos a instalar ###
+ EGit: http://download.eclipse.org/egit/updates
+ devKitPro: http://sourceforge.net/projects/devkitpro/files/Automated%20Installer/devkitProUpdater-1.5.0.exe/download

### Configuraci�n de EGit ###
En Window > Preferences > Team > Git > Configuration > Pesta�a "User settings", a�adir estas 4 entradas:

1. user.name --> Nombre Apellido
2. user.email --> Tu e-mail
3. github.user --> Nombre de cuenta GitHub.com
4. github.token --> [API Token](https://github.com/settings/admin) de cuenta GitHub.com

Guardar los cambios clickando "Apply"

### Configuraci�n SSH ###
**Esto s�lo es necesario en caso de usar el protocolo SSH para los push/pull**  
En Eclipse, ir a Window > Preferences > General > Network Connections > SSH2, pesta�a "Key Management".  
Pulsar en "Generate RSA Key" y poner una contrase�a en Passphrase.  
*Esta contrase�a se te pedir� cada vez que quieras acceder al repositorio*  
Guardar la clave en la carpeta por defecto clickando "Save Private Key".  
Copiar la clave que aparece en la caja de texto, y pegarla en [tu cuenta](https://github.com/settings/ssh) pulsando "Add SSH Key".  
*De esta forma, tu ordenador queda asociado con la cuenta de GitHub por SSH*  

### Configuraci�n del proyecto ###
Importar el proyecto a Eclipse desde Git (File > Import > Git > URI - Direcci�n en GitHub), lanzar el "New Project Wizard" y seleccionar Makefile con c�digo existente en C.  
En Project > Properties > C/C++ Build > Behaviour > Build (Incremental build), cambiar 'all' por 'build' y guardar los cambios.  
En Project > Properties > Path and Symbols > Import Settings, seleccionar el archivo 'config.xml' y aceptar.  
Bot�n derecho en la carpeta en el Project Explorer > Index > Rebuild.

### Trabajar con los repositorios ###
Como ya sabr�is, cada uno de nosotros accede a 2 repositorios: local (en nuestro ordenador, cada uno el suyo) y remoto (en GitHub, com�n para los tres).  
Las acciones que vamos a usar son las siguientes:

+ **Add to index**: Cuando quer�is a�adir un archivo nuevo al repositorio, lo primero es a�adirlo al �ndice.
+ **Commit**: Es guardar los cambios que has hecho en el repositorio local. Hay que escribir una descripci�n de lo que se ha hecho. No conviene hacerlo cada 5 minutos, sino cuando terminas de hacer algo.
+ **Push**: Subir los cambios que has hecho al repositorio remoto, de modo que los dem�s podamos recibirlos. Hay que asegurarse de que tienes en el local la �ltima versi�n del remoto, de lo contrario, dar� `error: non fast forward` y primero habr� que hacer *pull*.
+ **Pull**: Bajarse los �ltimos cambios que hayan hecho los dem�s en el repositorio remoto al local.

Todas ellas se realizan desde Eclipse haciendo click con el bot�n derecho en la carpeta del Project Explorer > Team.  
