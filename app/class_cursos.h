#ifndef CLASS_CURSOS_H
#define CLASS_CURSOS_H
#include <string>
#include <vector>
#include <sstream>
#include <xlnt/xlnt.hpp>//Para leer archivos
#include "xlsxwriter.h"//Para escribir archivo final


using namespace std;
using namespace xlnt;


//Se crea clase cursos donde tomara las variables del excel Cursos.xlsx y los mostrará
class Cursos{
private: //atributos
  string codigo_cursos;
  string nombre_curso;
  string id_docente;
  string nombre_p;
  string apellido_p;
  string bloque;

public: //metodos
Cursos(string, string,string,string,string,string);
//void crear_formato(lxw_worksheet *hoja, lxw_workbook *archivo);
bool cursos_inf(string id);
Cursos();
virtual ~Cursos();
};

#endif /* CLASS_CURSOS_H */
