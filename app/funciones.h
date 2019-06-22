#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Clases.h"
#include <vector>
#include <string>


void funcion_formato();
vector<Profesor>asignacion_profesores(string );
vector<Cursos> rescatando_cursos(string );
void asignacion_sabado(vector<Profesor> &);
int *StringtoBool(vector<string> );
char* obtener_salas(char** , int );
char* obtener_cursos(char** , int );
char* obtener_docentes(char** , int );
vector<string> guardar_salas(string );
vector<Sala> Matrices_salas(vector<string>);
int encuentra_cp(Profesor , vector<Cursos> );
void crear_formato(lxw_worksheet, lxw_workbook);
#endif // FUNCIONES_H_INCLUDED
