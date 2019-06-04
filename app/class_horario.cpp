/* Librerias */
#include <iostream>
#include <string>
#include <vector>
#include "class_horario.h"
/*Cabezeras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos
#include "xlsxwriter.h"//Para escribir archivo final

using namespace std;
using namespace xlnt;


//Esta función crea el formato del excel
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
