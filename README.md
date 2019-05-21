# PROYECTO DE COMPUTACIÓN PARALELA N°1


Se solicita entregar una aplicación en C / C ++ usando OpenMpi y / o OpenMp, que permita entregar la planificación académica por sala y por día de la semana.


*  Se definen que el día está separado en 7 bloques de Lunes a Viernes y en 4 bloques los
días Sábados.

* La planilla de Docentes, dispone de la disponibilidad de cada profesor, por cada día de
semana..

* La planilla de Salas, contiene la información de las salas disponibles.

*  La planilla de Cursos, tiene la información de los profesores que dictan las asignaturas,
junto a los bloques que a la semana se requieren cubrir.

# RESTRICCIONES

* Se pueden juntar hasta 4 bloques en un mismo día.
*  Los laboratorios sólo pueden ser usados por asignaturas cuyo código comiencen con
INF.
* La asignación de sala debe ser coherentes en todos los niveles.

#INSTALACIÓN LIBRERÍA XLNT

**PASO 1**

> $ sudo apt-get update

> $ sudo apt-get upgrade

> $ sudo apt-get install zlibc

**PASO 2: ACTUALIZAR COMPILADOR Y CONFIGURAR VARIABLES DE ENTORNO**

>  $ sudo add-apt-repository ppa:ubuntu-toolchain-r/test

>  $ sudo apt update

> $ sudo apt-get upgrade

> $ sudo apt-get install gcc -6 g++ -6

> $ export CC=/usr/bin/gcc-6

> $ export CXX=/usr/bin/g++-6

**PASO 3: CLONAR REPOSITORIO**

> $ git clone https://github.com/tfussell/xlnt/archive/master.zip

>  $ cd xlnt-master

> $ cmake .

> $ make -j 2

> $ sudo make install
