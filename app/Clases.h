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
class Profesor{
public://metodos de la clase
  Profesor(int,string, vector<string> );//constructor
  void mostrar();
  void set_martes(vector<string> );
  void set_miercoles(vector<string> );
  void set_jueves(vector<string> );
  void set_viernes(vector<string> );
  void set_sabado(vector<string> );

private://atributos de la clase
  int id_profe;
  string nombre;
  vector<string> lunes;// disponible o no disponible 0-6 //0-7
  vector<string> martes;
  vector<string> miercoles;
  vector<string> jueves;
  vector<string> viernes;
  vector<string> sabado;
};

/* CLASE 2: CURSOS */
class Cursos
{
public: //metodos
Cursos(string, string, int, string, int);
//void crear_formato(lxw_worksheet *hoja, lxw_workbook *archivo);
bool cursos_inf(string id);
Cursos();
virtual ~Cursos();

private: //atributos
  string codigo_cursos;
  string nombre_curso;
  int id_docente;
  string nombre_p;
  int bloque;
};


/* CLASE 3: HORARIO */
class Horario {
public:
  Horario(string, string,int);
  void crear_formato(lxw_worksheet *hoja, lxw_workbook *archivo);
  Horario();
  virtual ~Horario();

private:
  string id_curso;
  string id_prof;
  int bloque;
};



#endif // CLASES_H
