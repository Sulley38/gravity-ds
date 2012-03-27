
# Gravity DS #

## Proyecto de EC ##

### Prerrequisitos a instalar ###
+ EGit: http://download.eclipse.org/egit/updates
+ devKitPro: http://sourceforge.net/projects/devkitpro/files/Automated%20Installer/devkitProUpdater-1.5.0.exe/download

### Configuración de EGit ###
En Window > Preferences > Team > Git > Configuration > Pestaña "User settings", añadir estas 4 entradas:
> user.name --> [Nombre Apellido]
> user.email --> [Tu e-mail]
> github.user --> [Nombre de cuenta GitHub.com]
> github.token --> [API Token de cuenta GitHub.com] (ver https://github.com/settings/admin)
Guardar los cambios haciendo click en "Apply"
  
### Configuración del proyecto ###
+ Importar el proyecto a Eclipse desde Git, lanzar el "New Project Wizard" y seleccionando Makefile con código existente en C
+ En Project > Properties > C/C++ Build > Behaviour > Build (Incremental build), cambiar 'all' por 'build' y guardar los cambios
+ En Project > Properties > Path and Symbols > Import Settings, seleccionar el archivo 'config.xml' y aceptar

