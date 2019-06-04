#ifndef CLASS_HORARIO_H
#define CLASS_HORARIO_H
#include <string>
#include <vector>
#include <sstream>
#include <xlnt/xlnt.hpp>//Para leer archivos
#include "xlsxwriter.h"//Para escribir archivo final


using namespace std;
using namespace xlnt;

class Horario {
private:
  string id_curso;
  string id_prof;
  int bloque;

public:
  Horario(string, string,int);
  void crear_formato(lxw_worksheet *hoja, lxw_workbook *archivo);
  Horario();
  virtual ~Horario();
};

#endif /* CLASS_HORARIO_H */
