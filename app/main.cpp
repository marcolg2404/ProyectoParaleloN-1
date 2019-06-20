
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
  asignacion_sabado(profes);
  cursos = rescatando_cursos();
  profes[0].mostrar();
  sort(profes.begin(),profes.end());
  profes[0].mostrar();
  cursos[0].cursos_mostrar();
  sort(cursos.begin(),cursos.end());
  cursos[0].cursos_mostrar();
}
