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


# PARA COMPILAR:

* SECUENCIAL:
> g++ main.cpp -o tarea -std=c++14 -lxlsxwriter -Ixlnt/include -lxlnt

* PARALELO:
> mpic++ main.cpp -o tarea -lxlsxwriter -lxlnt

* PARALELO CON OPENMP:
> mpic++ main.cpp -o tarea -lxlsxwriter -lxlnt -fopenmp

# PARA EJECUTAR:

* SECUENCIAL:
>  ./tarea -s ./Archivos/Salas.xlsx -c ./Archivos/Cursos.xlsx -d ./Archivos/Docentes.xlsx

* PARALELO:
> mpirun ./tarea -s ./Archivos/Salas.xlsx -c ./Archivos/Cursos.xlsx -d ./Archivos/Docentes.xlsx

* PARALELO CON OPENMP:
> mpirun --hostfile ./Archivos/hostfile.txt -np N ./tarea -s ./Archivos/Salas.xlsx -c ./Archivos/Cursos.xlsx -d ./Archivos/Docentes.xlsx


* Nota Adicional:
* Compilar clases en secuencial:
>  g++ -c class_cursos.cpp -o tarea -std=c++14 -lxlsxwriter -Ixlnt/include -lxlnt

* Nota 2:
* Se puede compilar también en secuencial:
> g++ main.cpp -o tarea -lxlsxwriter -lxlnt
