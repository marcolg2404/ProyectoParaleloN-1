/* Librerias */
/*Cabeceras de las funciones y clases a utilizar*/
#include "Clases.h"
#include "funciones.h"
#include "Clases.cpp"
#include "funciones.cpp"
/*Librerías propias de C++*/
#include <iostream>
#include <wchar.h>
#include <string>
#include <vector>
#include <algorithm>
/*Librerias para su ejecución en paralelo */
#include <omp.h>
#include "mpi.h"
/*Cabezeras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos
#include "xlsxwriter.h"//Para escribir archivo final

using namespace std;
using namespace xlnt;


/* Función principal en donde recibe argumentos tales como:
- Argumento de tipo entero que es la cantidad de parámetros contando el nombre
del ejecutable que es el primer parámetro. (Argumento contar)
- Argumento de tipo caracter, que es un un arreglo que contiene todos los parámetros
recibidos. (Vector de argumento) */
int main(int argc, char **argv)
{
        if (argc>=7) { /*Se salta los bloques de descripcion*/


		/* Se crean variables de tipo string, en donde contendrá los datos de los archivos:
                - Cursos
                - Salas
                - Docentes */
                string Archivo_Cursos = obtener_cursos(argv,argc);
                string Archivo_Salas = obtener_salas(argv,argc);
                string Archivo_Docentes = obtener_docentes(argv,argc);

		/* Se verifica que los archivos a leer no estén vacíos */
                if (!Archivo_Cursos.empty() && !Archivo_Salas.empty() && !Archivo_Docentes.empty()) {
                        /*Variables*/
			/*Se crea variable wb_salas que contiene como archivo final los horarios completados*/
                        lxw_workbook  *wb_salas  = workbook_new("Horarios.xlsx");
			/* Se crean variables de tipo vector y enteros, que contendrán la información de los archivos */
                        vector<Profesor> profes;
                        vector<Cursos> cursos;
                        vector<Sala> salas,labs;

                        int Procesos,Procesador;
                        int sala_recorrida=0;
                        int lab_recorrido=0;

			/*Comienza las llamadas a MPI*/
                        MPI_Init(NULL, NULL);
			/*Averiguamos el número de procesos que están ejecutando nuestro programa*/
                        MPI_Comm_size(MPI_COMM_WORLD, &Procesos);
			/*Averiguamos el rango de nuestro proceso*/
                        MPI_Comm_rank(MPI_COMM_WORLD, &Procesador);

                        /* Asignación de los vectores con la información de los 3 archivos*/
                        profes = asignacion_profesores(Archivo_Docentes);
                        asignacion_sabado(profes, Archivo_Docentes);
                        cursos = rescatando_cursos(Archivo_Cursos);
                        guardar_salas(Archivo_Salas,salas,labs);

                        /*Ordenamiento de vectores salas y profesores*/
                        sort(profes.begin(),profes.end());
                        sort(cursos.begin(),cursos.end());

			/*Nos devuelve la cantidad de hilos, en este caso cantidad de procesos*/
                        omp_set_num_threads(Procesos);

			/*Se define una región a paralelizar*/
                        #pragma omp parallel
                        {
			/*Todos los procesos van verificando los profesores, cuando terminan, el proceso 0 se encargará de guardar el archivo final*/
                          #pragma omp for
                                for (int i = 0; i <profes.size(); ++i)
                                {
                                        Generar_Horario(cursos,salas,labs,profes[i],sala_recorrida,lab_recorrido);
                                }

                        }
                        if(Procesador==0) {
                                Guardar_archivo(salas,labs,wb_salas);

                        }

			/* Termina con MPI. Recordemos que después de esta llamada no podemos llamar a funciones 				MPI, ni siquiera de nuevo a MPI_Init*/
                        MPI_Finalize();



                }

		/*En caso de que los archivos que lea el programa estén vacíos*/
                else{
                        cout<<"Error, los archivos estan vacíos."<<endl;
                }
        }
	/*En caso de que los archivos no se ingresen al momento de ejecutar el programa*/
        else{
                cout<<"No se ingresaron los archivos necesarios (Cursos.xlsx, Docentes.xlsx y Salas.xlsx)."<<endl;
        }
}
