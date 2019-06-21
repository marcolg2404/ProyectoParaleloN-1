#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Clases.h"
#include <vector>
#include <string>


void funcion_formato();
vector<Profesor>asignacion_profesores();
vector<Cursos> rescatando_cursos();
void asignacion_sabado(vector<Profesor> &);
int *StringtoBool(vector<string> );
char* obtener_salas(char** matriz, int largo);
char* obtener_cursos(char** matriz, int largo);
char* obtener_docentes(char** matriz, int largo);
vector<string> asignacion_salas(string archivo);


#endif // FUNCIONES_H_INCLUDED
