#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/*Libreria de las funciones a utilizar*/
#include "Clases.h"
/*Librerias propias de C++*/
#include <vector>
#include <string>

/*1. Función para la creación del formato del archivo */
void crear_formato(lxw_worksheet *, lxw_workbook *);

vector<Profesor>asignacion_profesores(string ); /*2. Función de tipo vector, que toma la información de Docentes y va llenando la matriz
con los cursos según disponibilidad y cantidad de bloques de estos, se llenan todos los bloques de ser posible */
vector<Cursos> rescatando_cursos(string ); /*3. Función de tipo vector que obtiene la información del archivo cursos
sean estos el código del curso, ID y cantidad de bloques en horas pedagógicas */
vector<Cursos> encuentra_cp(Profesor, vector<Cursos> ); /*4. Función de tipo vector, en el cual busca a un profesor en particular de acuerdo a su ID*/
vector<Sala> Matrices_salas(vector<string>); /*5. Función de tipo vector que recibe el dato de sala y crea la matriz*/


void Generar_Horario(vector<Cursos> &, vector<Sala> &,vector<Sala> &,Profesor &,int &,int &); /*6.Función en la cual genera el horario correspondiente, según la disponibilidad del profesor y cantidad de bloques a considerar
en donde según sea la disponibilidad del profe, cambia de disponible a no disponible y además filtra los Labs, una vez
llena las celdas, se verifica si queda algún espacio disponible, de no ser así, se dirige a la siguiente hoja*/
void asignacion_sabado(vector<Profesor> &,string); /*7. Función en la cual el día sabado se asigna de diferente manera, ya que no debe llenar todas las celdas como
se llenan los demás días ya que son permitidos sólo cuatro bloques*/

int *StringtoBool(vector<string> ); /*8. Función que toma un string y lo convierte a entero para crear una matriz */
char* obtener_docentes(char**, int ); /*9. Función para obtener el argumento del archivo Docentes.xlsx */
char* obtener_cursos(char**, int );  /*10. Función para obtener el argumento del archivo Cursos.xlsx */
char* obtener_salas(char**, int );  /*11. Función para obtener el argumento del archivo salas.xlsx */

bool Es_inf(string);  /*12. Función de tipo boleana, que filtra los cursos de acuerdo a las iniciales del código
para este caso, el filtro de tipo INF es sólo para que estos cursos se registren en los laboratorios */
bool Es_lab(string);  /*13. Función de tipo boleana, en el cual filtra las salas, buscando sólo aquellas que inicien con LAB*/

void guardar_salas(string,vector<Sala> &,vector<Sala> &);  /*14. Función en donde al momento de escribir los datos en la matriz
y pasar a la siguiente sala, guarda la información que se escribió */
void Guardar_archivo(vector<Sala> &,vector<Sala> &, lxw_workbook *); /*15. Función de tipo void, que al momento de escrito los datos en todas las salas, guarda el archivo
para que este después de forma anexa se pueda abrir */

#endif // FUNCIONES_H_INCLUDED
