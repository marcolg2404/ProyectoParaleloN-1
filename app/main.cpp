#include <iostream>
#include <wchar.h>
#include <string>
#include <vector>

/*Cabezera funciones*/
#include "funciones.h"
/*Cabezeras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos
#include "xlsxwriter.h"//Para escribir archivo final

using namespace std;
using namespace xlnt;

void Crear_formato(lxw_worksheet *hoja, lxw_workbook *archivo){
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

int main(int argc, char **argv)/*Se pasan los argumentos. El primer argumento de la función argc nos indica el número total de parámetros.
                                        Mediante el segundo argumento argv, podemos acceder a los valores de los parámetros pasados al programa, siempre el primer parámetro,
                                        es decir argv[0] contiene el nombre del programa.*/
{
        /*En esta función especifica a que si no se pasan los tres archivos Salas.xlsx Docentes.xlsx Cursos.xlsx no los leerá*/

        if (argc >= 7) {

                workbook wb_Docentes; //woorkbook=archivo, worksheet=hoja
                workbook wb_Salas;
                workbook wb_Cursos;



                for (int j = 1; j < argc; j=j+2) {
                        char *argumento = argv[j];
                        if(argumento[1]=='c') {
                                wb_Cursos.load(argv[j+1]);
                        }
                        if(argumento[1]=='d') {
                                wb_Docentes.load(argv[j+1]);
                        }
                        if(argumento[1]=='s') {
                                wb_Salas.load(argv[j+1]);
                        }
                }
                auto ws = wb_Salas.active_sheet();

                /* Como conocer las hojas dentro del archivo
                vector<string>prueba=wb_Salas.sheet_titles();
                for(int i;i<prueba.size();i++){
                cout<<prueba[i]<<endl;

                } */

                cout << "Procesando Salas" << endl;
                int aux=0;
                string sala;

                vector<string>vectorCursos_filas;
                for (auto fila : ws.rows(false)) //row=fila
                {
                        for (auto celda : fila) //cell=celda
                        {
                          aux++;
                          if(aux>2){ //Se omiten las cabeceras del excel
                          vectorCursos_filas.push_back(celda.to_string());
                        }
                      }
                }

                lxw_workbook *workbook=workbook_new("Horarios.xlsx");

                for(int i=0;i<vectorCursos_filas.size();i=i+2)
                {
                    sala=(vectorCursos_filas[i]+"-"+vectorCursos_filas[i+1]);
                    /*se pasa el string sala a char*/
                    int n= sala.length()+1;
                    char Sala_char[n]; //Hacer funcion string a char
                    for(int k=0; k<sala.length(); k++){
                      Sala_char[k] = sala[k];
                    }
                    lxw_worksheet *worksheet = workbook_add_worksheet(workbook,Sala_char); //Se crea una nueva hoja con el titulo de la sala
                    Crear_formato(worksheet, workbook);

                }
                workbook_close(workbook); //Se guarda el archivo
                cout << "Proceso completado" << endl;
                return 0;

              }

        else{
                printf("No se ingresaron los 3 archivos .xlsx correspondientes (-s Salas.xlsx, -c Cursos.xlsx y -d Docentes.xlsx)\n");
                return 1;
        }

}
