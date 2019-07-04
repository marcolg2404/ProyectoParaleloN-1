#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
/*Librerias propias de C++*/
#include <vector>
#include <string>

/*Cabeceras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos
#include "xlsxwriter.h"//Para escribir archivo final

using namespace std;
using namespace xlnt;

/* Se definirán todas las clases a usar*/

/*CLASE 1: PROFESOR*/

class Profesor {
/*Métodos de la clase*/
public:

Profesor(int); /*1 . Constructor*/
void mostrar(); /*2. Función que muestra el contenido de cada objeto como matriz*/
void iniciar_matriz(); /*3. Inicia la matriz con ceros*/
/*Métodos para llenar cada día de la matriz*/
void set_lunes(int *); /*4. */
void set_martes(int * ); /*5. */
void set_miercoles(int*); /*6. */
void set_jueves(int*); /*7. */
void set_viernes(int*); /*8. */
void set_sabado(int*); /*9. */
/*10. Función que cambia la disponibilidad del profesor, de Disponible a No Disponible*/
void cambiar_disponibilidad(int,int);
int get_id(); /*11. Obtiene la ID del profesor*/
int **get_horario(); /*12. Copia de la matriz horario original*/
/*Atributos de la clase*/
private:
int id_profe; /*Función para la obtención de la ID de los profesores*/
int horario [7][6]; /*Matriz de 7 bloques 6 días*/
};

/* CLASE 2: CURSOS */
class Cursos {
/*Métodos de la clase*/
public:
Cursos();/*0. Constructor vacío*/
void set_Cursos(string, int, int);/*1.Constructor*/
int get_horas(); /*2. Obtiene las horas de bloques según horas pedagógicas*/
int getID_profe(); /*3. Obtiene la ID del docentes*/
string getcodigo_curso(); /*4. Obtiene el código/ID del curso*/
void Resta_hora(); /*5. Resta horas de los bloques ya vayan siendo asignados*/
void cursos_mostrar(); /*6. Muestra la ID de Cursos e ID de docentes*/
virtual ~Cursos();

/*Atributos de la clase*/
private:
string codigo_cursos; /*Obtiene los códigos de los cursos*/
int id_docente; /*Obtiene las ID's de los profesores*/
int bloque; /*Obtiene las horas pedagógicas de cada curso*/
};


/* CLASE 3: SALA */
class Sala {
/*Métodos de la clase*/
public:
Sala(string)/*1. */;
void iniciar_matriz(); /*2. Crea matriz original*/
void mostrar_sala(); /*3. Función que muestra el contenido (Horario)  */
void cambiar_seccion(int, int, string); /*4. Llena la matriz con el código*/
string **get_sala(); /*5. Función que copia la matriz original*/
string get_nombre_sala(); /*6. Función que nombra las salas*/

virtual ~Sala();
/*Atributos de la clase*/
private:
string _sala;
string matriz[7][6]; /*Matriz con 7 bloques y 6 días*/
};

bool operator<( Profesor &s1, Profesor &s2); /*13. (Profesor)Función que ordena las ID de los profesores de menor a mayor*/
bool operator<( Cursos &s1, Cursos &s2); /*7. (Cursos)Función que ordena las ID de Cursos de menor a mayor*/
bool operator== (Cursos &n1, Cursos &n2); /*8. (Cursos)Función que determina cuantos cursos tiene un profesor, según ID*/

#endif // CLASES_H
