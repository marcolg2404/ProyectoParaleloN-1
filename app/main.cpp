
#include "Clases.h"
#include "funciones.h"
#include "Clases.cpp"
#include "funciones.cpp"
#include <iostream>
#include <wchar.h>
#include <string>
#include <vector>

/*Cabezeras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos
#include "xlsxwriter.h"//Para escribir archivo final

using namespace std;
using namespace xlnt;

int main(int argc, char **argv)
{
  vector<Profesor> profes;
  vector<Cursos> cursos;
  profes = asignacion_profesores();
  cursos = rescatando_cursos();
  profes[1].mostrar();
  for( int i=0; i< cursos.size();i++){
     cursos[i].cursos_mostrar();
  }
  return 0;
}
