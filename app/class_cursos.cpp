/* Librerias */
#include <iostream>
#include <string>
#include <vector>
#include "class_cursos.h"
/*Cabezeras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos
#include "xlsxwriter.h"//Para escribir archivo final

using namespace std;
using namespace xlnt;

//Constructor cursos, en donde irán las variables del archivo excel en orden.
Cursos::Cursos(string _codigo, string _ncurso, string _ido, string np, string ap, string _bloque){
  codigo_cursos = _codigo;
  nombre_curso = _ncurso;
  id_docente = _ido;
  nombre_p = np;
  apellido_p = ap;
  bloque = _bloque;
}

Cursos::~Cursos() {
}

bool Cursos::cursos_inf(string id){
      bool Es_inf = false;
      size_t encontrar_INF = id.find("INF");
      if (encontrar_INF!=string::npos)
      {
        Es_inf = true;
      }
  return Es_inf;
}
