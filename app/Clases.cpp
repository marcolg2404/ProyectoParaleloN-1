#include "Clases.h"
#include <iostream>
#include <string>
#include <vector>


/*Cabezeras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos
using namespace std;
using namespace xlnt;

/*Declaracion de los métodos*/

//CLASE 1: PROFESOR
Profesor::Profesor(int _id, string _nombre,vector<string> _bloques)
{
  id_profe = _id;
  nombre = _nombre;
  lunes = _bloques;
}

void Profesor::mostrar() /// funcion para mostrar el contenido de cada objeto
{
  cout << id_profe <<" "<< nombre << endl;
  for (int i=0 ;i<lunes.size();i++)
  {
    cout << lunes[i] << "\t";
  }
  cout << endl;
  for (int i=0 ;i<martes.size();i++)
  {
    cout << martes[i] << "\t";
  }
  cout << endl;
  for (int i=0 ;i<miercoles.size();i++)
  {
    cout << miercoles[i] << "\t";
  }
  cout << endl;
  for (int i=0 ;i<sabado.size();i++)
  {
    cout << sabado[i] << "\t";
  }
  cout << endl;
}

void Profesor::set_martes(vector<string> _ma)
{
    martes=_ma;
}

void Profesor::set_miercoles(vector<string>_mi )
{
    miercoles = _mi;
}

void Profesor::set_jueves(vector<string> _ju)
{
  jueves= _ju;
}

void Profesor::set_viernes(vector<string> _vi)
{
  viernes = _vi;
}

void Profesor::set_sabado(vector<string> _sa)
{
  sabado=_sa;
}

//CLASE 2: CURSOS
Cursos::Cursos(){

}
void Cursos::set_Cursos(string _codigo, string _ncurso, int _ido, string np, int _bloque){
  codigo_cursos = _codigo;
  nombre_curso = _ncurso;
  id_docente = _ido;
  nombre_p = np;
  bloque = _bloque;
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

void Cursos::cursos_mostrar(){
  cout<< codigo_cursos << " " << nombre_curso << " "<< id_docente<< " " << bloque << endl;
}
Cursos::~Cursos()
{
  //destructor
}


//CLASE 3: HORARIO
void Horario::crear_formato(lxw_worksheet *hoja, lxw_workbook *archivo){
  lxw_format *formato = workbook_add_format(archivo);
  format_set_bold(formato);
  format_set_align(formato, LXW_ALIGN_CENTER);
  worksheet_write_string(hoja, 0, 0, "Periodo", formato); //Hoja, fila,columna , dato, formato)
  worksheet_write_string(hoja, 0, 1, "Lunes", formato);
  worksheet_write_string(hoja, 0, 2, "Martes", formato);
  worksheet_write_string(hoja, 0, 3, "Miércoles", formato);
  worksheet_write_string(hoja, 0, 4, "Jueves", formato);
  worksheet_write_string(hoja, 0, 5, "Viernes", formato);
  worksheet_write_string(hoja, 0, 6, "Sábado", formato);
  worksheet_write_number(hoja, 1, 0, 1, formato);
  worksheet_write_number(hoja, 2, 0, 2, formato);
  worksheet_write_number(hoja, 3, 0, 3, formato);
  worksheet_write_number(hoja, 4, 0, 4, formato);
  worksheet_write_number(hoja, 5, 0, 5, formato);
  worksheet_write_number(hoja, 6, 0, 6, formato);
  worksheet_write_number(hoja, 7, 0, 7, formato);
  worksheet_write_number(hoja, 8, 0, 8, formato);
}
