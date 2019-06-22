
#include "Clases.h"
#include "funciones.h"
#include "Clases.cpp"
#include "funciones.cpp"
#include <iostream>
#include <wchar.h>
#include <string>
#include <vector>
#include <algorithm>

/*Cabezeras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos
#include "xlsxwriter.h"//Para escribir archivo final

using namespace std;
using namespace xlnt;

int main(int argc, char **argv)
{
        if (argc>=7) {

                string Archivo_Cursos = obtener_cursos(argv,argc);
                string Archivo_Salas = obtener_salas(argv,argc);
                string Archivo_Docentes = obtener_docentes(argv,argc);;

                if (!Archivo_Cursos.empty() && !Archivo_Salas.empty() && !Archivo_Docentes.empty()) {
                        lxw_workbook  *wb_salas  = workbook_new("Horarios.xlsx");

                        vector<Profesor> profes;
                        vector<Cursos> cursos;
                        int **matrix;
                        profes = asignacion_profesores(Archivo_Docentes);
                        asignacion_sabado(profes);
                        cursos = rescatando_cursos(Archivo_Cursos);
                        profes[0].mostrar();
                        sort(profes.begin(),profes.end());
                        profes[0].mostrar();
                        cursos[0].cursos_mostrar();
                        sort(cursos.begin(),cursos.end());
                        cursos[45].cursos_mostrar();
                        profes[26].mostrar();

                        vector<string> salas = guardar_salas(Archivo_Salas);
                        //Sala s1("m1-101");
                        //s1.iniciar_matriz();
                        //s1.mostrar_sala();
                        
                        for(int i=0; i<salas.size(); i++)
                        {

                                string sala = salas[i];
                                const char* char_sala = sala.c_str();
                                lxw_worksheet *hoja = workbook_add_worksheet(wb_salas,char_sala);
                                crear_formato(hoja,wb_salas);
                                sala.clear();
                        }
                        workbook_close(wb_salas);

                }
                else{
                        cout<<"Error, los archivos estan vacíos."<<endl;
                }
        }
        else{
                cout<<"No se ingresaron los archivos necesarios (Cursos.xlsx, Docentes.xlsx y Salas.xlsx)."<<endl;
        }
}
