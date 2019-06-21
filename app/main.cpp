
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
        if (argc>=7) {

                string Archivo_Cursos = obtener_cursos(argv,argc);
                string Archivo_Salas = obtener_salas(argv,argc);
                string Archivo_Docentes = obtener_docentes(argv,argc);;

                if (!Archivo_Cursos.empty() && !Archivo_Salas.empty() && !Archivo_Docentes.empty()) {

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
                        cursos[45].cursos_mostrar();

                        /*
                           vector<string> salass = asignacion_salas(Archivo_Salas);
                           for(int i=0;i<salass.size();i++)
                           {
                           cout<<salass[i]<<endl;
                           }*/
                }

                else{
                        cout<<"Error, los archivos estan vacíos."<<endl;
                }
        }
        else{
                cout<<"No se ingresaron los archivos necesarios (Cursos.xlsx, Docentes.xlsx y Salas.xlsx)."<<endl;
        }
}
