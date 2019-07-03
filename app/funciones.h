#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Clases.h"
#include <vector>
#include <string>


void funcion_formato();
vector<Profesor>asignacion_profesores(string );
vector<Cursos> rescatando_cursos(string );
void asignacion_sabado(vector<Profesor> &,string);
int *StringtoBool(vector<string> );

char* obtener_salas(char**, int );
char* obtener_cursos(char**, int );
char* obtener_docentes(char**, int );

void Generar_Horario(vector<Cursos> &, vector<Sala> &,vector<Sala> &,Profesor &,int &,int &);
vector<Sala> Matrices_salas(vector<string>);
void guardar_salas(string,vector<Sala> &,vector<Sala> &);
vector<Cursos> encuentra_cp(Profesor, vector<Cursos> );
bool Es_inf(string);
bool Es_lab(string);


void crear_formato(lxw_worksheet *, lxw_workbook *);
//void Generar_archivo(vector<Sala>,lxw_workbook *);
void Guardar_archivo(vector<Sala> &,vector<Sala> &, lxw_workbook *);
#endif // FUNCIONES_H_INCLUDED
