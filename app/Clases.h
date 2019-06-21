#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include <vector>
#include <string>

/*Cabezeras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos
#include "xlsxwriter.h"//Para escribir archivo final
using namespace std;
using namespace xlnt;

/* Se definirán todas las clases a usar*/

/* CLASE 1: PROFESOR*/
class Profesor {

public://metodos de la clase
Profesor(int);  //constructor
void mostrar();
void iniciar_matriz();// inicia la matriz con ceros
void set_lunes(int *);  //metodos para llenar cada dia de la matriz
void set_martes(int * );
void set_miercoles(int*);
void set_jueves(int*);
void set_viernes(int*);
void set_sabado(int*);
int get_id();
int **get_horario();

private://atributos de la clase
int id_profe;
int horario [7][6];  //matriz de 7 bloques 6 dias
};

/* CLASE 2: CURSOS */
class Cursos {

public: //metodo
Cursos();// constructor
void set_Cursos(string, int, int);
int get_horas();
int getID_profe();
//void crear_formato(lxw_worksheet *hoja, lxw_workbook *archivo);
bool cursos_inf(string id);
void cursos_mostrar();
virtual ~Cursos();

private: //atributos
string codigo_cursos;
int id_docente;
int bloque;
};


/* CLASE 3: HORARIO */
class Horario {

public:
Horario(string, string,int);
//void crear_formato(lxw_worksheet *hoja, lxw_workbook *archivo);
Horario();
virtual ~Horario();

private:
string id_curso;
string id_prof;
int bloque;
};

//sobrecarga del operador de la clase vector creo que puedo ocuparlo para el resto tambien
bool operator<( Profesor &s1, Profesor &s2);
bool operator<( Cursos &s1, Cursos &s2);
bool operator== (Cursos &n1, Cursos &n2);
#endif // CLASES_H
