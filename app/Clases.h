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
void cambiar_disponibilidad(int,int);
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
int get_horas();
int getID_profe();
string getcodigo_curso();
void cursos_mostrar();
void set_Cursos(string, int, int);
virtual ~Cursos();

private: //atributos
string codigo_cursos;
int id_docente;
int bloque;
};


/* CLASE 3: SALA */
class Sala {

public:
Sala(string);
void iniciar_matriz();
void mostrar_sala();
void cambiar_seccion(int, int, string);
string **get_sala();
string get_nombre_sala();

virtual ~Sala();

private:
string _sala;
string matriz[7][6];
};

//sobrecarga del operador de la clase vector creo que puedo ocuparlo para el resto tambien
bool operator<( Profesor &s1, Profesor &s2);
bool operator<( Cursos &s1, Cursos &s2);
bool operator== (Cursos &n1, Cursos &n2);
#endif // CLASES_H
