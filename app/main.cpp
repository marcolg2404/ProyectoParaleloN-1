
#include "Clases.h"
#include "funciones.h"
#include "Clases.cpp"
#include "funciones.cpp"
#include <iostream>
#include <wchar.h>
#include <string>
#include <vector>
#include <algorithm>

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
                        int Procesos,Procesador,Divdatos_profes,Procesos_enviar;
                        int profesores_completados=0;
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


                        if (Procesador != 0) {

                                for(int k=0; k<profes.size(); k=k+Procesos) {

                                        MPI_Recv(&Procesos_enviar,1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                                        Generar_Horario(cursos,salas,labs,profes[Procesos_enviar],sala_recorrida,lab_recorrido);
                                        profesores_completados++;
                                }
                        }


                        else{
                                for(int k=0; k<profes.size(); k=k+Procesos) {

                                        for (int i = 1; i < Procesos; i++) {

                                                Procesos_enviar=k+i;
                                                MPI_Send(&Procesos_enviar,1,MPI_INT,i,0,MPI_COMM_WORLD);
                                                Generar_Horario(cursos,salas,labs,profes[k],sala_recorrida,lab_recorrido);
                                                profesores_completados++;


                                        }
                                }
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
