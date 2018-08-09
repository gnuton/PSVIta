[![Build Status](https://travis-ci.org/gnuton/PSVIta.svg?branch=master)](https://travis-ci.org/gnuton/PSVIta)
# PSVIta
PSVita experiments

# CLI PS Vita Template

# Graphical PS Vita Template

# IDE support
1. Download QtCreator
2. cd project_dir 
3. mkdir build
4. cmake ..
5. Open QtCreator > Open Project > Select CMakeList.txt file > When asked for build dir. Select build/
6. Run VitaShell on the vita and press SELECT to activate FTP
6. To build you can use the IDE or just
   make && curl -T hello_cpp_world.vpk ftp://anonymous@IP_TO_PSVITA:1337/ux0:yourdir/a.vpk

   

