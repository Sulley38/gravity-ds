
# Gravity DS #
## Proyecto de Estructura de Computadores ##

### Autores: Daniel Franco, Iván Matellanes y Asier Mujika ###

### Prerrequisitos a instalar ###
+ EGit: http://download.eclipse.org/egit/updates
+ devKitPro: http://sourceforge.net/projects/devkitpro/files/Automated%20Installer/devkitProUpdater-1.5.0.exe/download

### Configuración de EGit ###
En Window > Preferences > Team > Git > Configuration > Pestaña "User settings", añadir estas 4 entradas:

1. user.name --> Nombre Apellido
2. user.email --> Tu e-mail
3. github.user --> Nombre de cuenta GitHub.com
4. github.token --> [API Token](https://github.com/settings/admin) de cuenta GitHub.com

Guardar los cambios clickando "Apply"

### Configuración SSH ###
**Esto sólo es necesario en caso de usar el protocolo SSH para los push/pull**  
En Eclipse, ir a Window > Preferences > General > Network Connections > SSH2, pestaña "Key Management".  
Pulsar en "Generate RSA Key" y poner una contraseña en Passphrase.  
*Esta contraseña se te pedirá cada vez que quieras acceder al repositorio*  
Guardar la clave en la carpeta por defecto clickando "Save Private Key".  
Copiar la clave que aparece en la caja de texto, y pegarla en [tu cuenta](https://github.com/settings/ssh) pulsando "Add SSH Key".  
*De esta forma, tu ordenador queda asociado con la cuenta de GitHub por SSH*  

### Configuración del proyecto ###
Importar el proyecto a Eclipse desde Git, lanzar el "New Project Wizard" y seleccionar Makefile con código existente en C  
En Project > Properties > C/C++ Build > Behaviour > Build (Incremental build), cambiar 'all' por 'build' y guardar los cambios  
En Project > Properties > Path and Symbols > Import Settings, seleccionar el archivo 'config.xml' y aceptar  
