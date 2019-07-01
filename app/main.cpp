
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
                        /*Variables*/
                        lxw_workbook  *wb_salas  = workbook_new("Horarios.xlsx"); //Se crea variable wb_salas que contiene como archivo final los horarios completados
                        vector<Profesor> profes;
                        vector<Cursos> cursos;
                        vector<Sala> salas,labs;

                        /* Asignación de los vectores con la información de los 3 archivos*/
                        profes = asignacion_profesores(Archivo_Docentes);
                        asignacion_sabado(profes, Archivo_Docentes);
                        cursos = rescatando_cursos(Archivo_Cursos);
                        guardar_salas(Archivo_Salas,salas,labs);

                        /*Ordenamiento vectores salas y profes*/
                        sort(profes.begin(),profes.end());
                        sort(cursos.begin(),cursos.end());

                        /*Se generan los horarrios correspondientes a cada sala*/
                        Generar_Horario(cursos,salas,labs,profes);

                        /*Llenado de archivo con las hojas de salas correspondientes*/
                        Guardar_archivo(salas,labs,wb_salas);

                }
                else{
                        cout<<"Error, los archivos estan vacíos."<<endl;
                }
        }
        else{
                cout<<"No se ingresaron los archivos necesarios (Cursos.xlsx, Docentes.xlsx y Salas.xlsx)."<<endl;
        }
}
