
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
                        lxw_workbook  *wb_salas  = workbook_new("Horarios.xlsx");
                        vector<Profesor> profes;
                        vector<Cursos> cursos;
                        vector<Sala> salas;
                        int **matrix;
                        int recorriendo_hoja=0;
                        string curso_asignado;

                        profes = asignacion_profesores(Archivo_Docentes);
                        asignacion_sabado(profes, Archivo_Docentes);
                        cursos = rescatando_cursos(Archivo_Cursos);
                        salas = guardar_salas(Archivo_Salas);

                        int profesores_completados=0;

                        /*for(int x=0;x<salas.size();x++)
                           {
                           cout<<salas[x].get_nombre_sala()<<endl;
                           salas[x].mostrar_sala();
                           }*/

                        /*Ordenamiento vectores salas y profes*/
                        sort(profes.begin(),profes.end());
                        sort(cursos.begin(),cursos.end());

                        /*Llenado de archivo con las salascorrespondientes*/
                        for(int b=0; b<salas.size(); b++) {
                                const char* char_sala = (salas[b].get_nombre_sala()).c_str();
                                lxw_worksheet *hoja = workbook_add_worksheet (wb_salas, char_sala);
                                crear_formato(hoja,wb_salas);
                        }
                        int sala_recorrida=0;




                        //Pasa el nombre de la sala a char
                        //cout<<char_sala<<endl;
                        //lxw_worksheet *hoja = workbook_add_worksheet(wb_salas,char_sala); //Agregar hoja con titulo de la sala
                        //crear_formato(hoja,wb_salas); //se agrega formato a la hoja
                        while(profesores_completados<profes.size()) {
                                string **salax = salas[sala_recorrida].get_sala();
                                const char* char_sala = (salas[sala_recorrida].get_nombre_sala()).c_str();
                                lxw_worksheet *hoja = workbook_get_worksheet_by_name (wb_salas, char_sala);         //(wb_salas,char_sala); //Agregar hoja con titulo de la sala

                                for(int profe_recorrido=0; profe_recorrido<profes.size(); profe_recorrido++) {

                                        vector<Cursos> Cursos_encontrados = encuentra_cp(profes[profe_recorrido],cursos);

                                        for(int curso_recorrido=0; curso_recorrido<Cursos_encontrados.size(); curso_recorrido++) {

                                                int horas_necesarias = Cursos_encontrados[curso_recorrido].get_horas();         //cantidad de horas que se deben realizar por curso
                                                //cout<<horas_necesarias<<endl;
                                                int **Horario_profesor = profes[profe_recorrido].get_horario();         //horario del profesor
                                                int vuelta_completa=0;
                                                for(int columna=0; columna<6; columna++)         //columna
                                                {
                                                        for(int fila=0; fila<7; fila++) {         //fila
                                                                if ((Horario_profesor[fila][columna]==1) && (salax[fila][columna]=="-") && (horas_necesarias>0)) {
                                                                        curso_asignado=(Cursos_encontrados[curso_recorrido].getcodigo_curso() + "-" + (to_string(Cursos_encontrados[curso_recorrido].getID_profe())));
                                                                        salax[fila][columna]=curso_asignado;
                                                                        horas_necesarias=horas_necesarias-2;
                                                                        Horario_profesor[fila][columna]==0;
                                                                        profes[profe_recorrido].cambiar_disponibilidad(fila,columna);
                                                                        salas[sala_recorrida].cambiar_seccion(fila,columna,curso_asignado);
                                                                        //cout<<curso_asignado<<endl;

                                                                }
                                                                if(columna==5 && fila ==6){
                                                                  vuelta_completa++;
                                                                }
                                                                if(vuelta_completa==1 && horas_necesarias>0){
                                                                  sala_recorrida++;
                                                                  delete [] salax;
                                                                  string **salax = salas[sala_recorrida].get_sala();
                                                                }
                                                        }

                                                }

                                        }
                                        profesores_completados++;
                                        //cout<<profesores_completados<<endl;
                                }
                        }

                           for(int b=0; b<salas.size(); b++) {
                                salas[b].mostrar_sala();
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
