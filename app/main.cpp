
#include "Clases.h"
#include "funciones.h"
#include "Clases.cpp"
#include "funciones.cpp"
#include <iostream>
#include <wchar.h>
#include <string>
#include <vector>
#include <algorithm>
#include <omp.h>
#include "mpi.h"

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
                        int Procesos,Procesador;
                        int sala_recorrida=0;
                        int lab_recorrido=0;

                        MPI_Init(NULL, NULL);
                        MPI_Comm_size(MPI_COMM_WORLD, &Procesos);
                        MPI_Comm_rank(MPI_COMM_WORLD, &Procesador);

                        /* Asignación de los vectores con la información de los 3 archivos*/
                        profes = asignacion_profesores(Archivo_Docentes);
                        asignacion_sabado(profes, Archivo_Docentes);
                        cursos = rescatando_cursos(Archivo_Cursos);
                        guardar_salas(Archivo_Salas,salas,labs);

                        /*Ordenamiento vectores salas y profes*/
                        sort(profes.begin(),profes.end());
                        sort(cursos.begin(),cursos.end());

                        omp_set_num_threads(Procesos);

                        #pragma omp parallel
                        {
                          #pragma omp for
                                for (int i = 0; i <profes.size(); ++i)
                                {
                                        Generar_Horario(cursos,salas,labs,profes[i],sala_recorrida,lab_recorrido);
                                }

                        }
                        if(Procesador==0) {
                                Guardar_archivo(salas,labs,wb_salas);

                        }


                        MPI_Finalize();



                }
                else{
                        cout<<"Error, los archivos estan vacíos."<<endl;
                }
        }
        else{
                cout<<"No se ingresaron los archivos necesarios (Cursos.xlsx, Docentes.xlsx y Salas.xlsx)."<<endl;
        }
}
