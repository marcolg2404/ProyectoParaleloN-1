
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

                        profes = asignacion_profesores(Archivo_Docentes);
                        asignacion_sabado(profes, Archivo_Docentes);
                        cursos = rescatando_cursos(Archivo_Cursos);
                        salas = guardar_salas(Archivo_Salas);

                        /*for(int x=0;x<salas.size();x++)
                           {
                           cout<<salas[x].get_nombre_sala()<<endl;
                           salas[x].mostrar_sala();
                           }*/

                        /*Ordenamiento vectores salas y profes*/
                        sort(profes.begin(),profes.end());
                        sort(cursos.begin(),cursos.end());

                        string **salax = salas[0].get_sala();
                        const char* char_sala = (salas[0].get_nombre_sala()).c_str(); //Pasa el nombre de la sala a char
                        cout<<char_sala<<endl;
                        lxw_worksheet *hoja = workbook_add_worksheet(wb_salas,char_sala); //Agregar hoja con titulo de la sala
                        crear_formato(hoja,wb_salas); //se agrega formato a la hoja

                        for(int j=0; j<profes.size(); j++) {
                                vector<Cursos> Cursos_encontrados = encuentra_cp(profes[j],cursos);
                                for(int p=0; p<Cursos_encontrados.size(); p++) {

                                        int horas_necesarias = Cursos_encontrados[p].get_horas(); //Profes=(idprofe,horario) ; Cursos = (Codigo_curso, id_docente, bloques)
                                        int **Horario_profesor = profes[j].get_horario();

                                        if (horas_necesarias>0) {
                                                for(int x=0; x<7; x++)
                                                {

                                                        for(int y=0; y<6; y++)
                                                        {
                                                                if ((Horario_profesor[y][x]==1) && (salax[y][x]=="-") && (horas_necesarias>0)) {
                                                                        salax[y][x]=(Cursos_encontrados[p].getcodigo_curso() + "-" + (to_string(Cursos_encontrados[p].getID_profe())));
                                                                        horas_necesarias=horas_necesarias-2;
                                                                }
                                                        }
                                                }

                                        }
                                }
                                Cursos_encontrados.clear();
                        }



                        for(int x=0; x<7; x++)
                        {
                                for(int y=0; y<6; y++)
                                {
                                        worksheet_write_string(hoja, x+1, y+1, salax[x][y].c_str(),NULL);
                                        cout<<salax[x][y]<<" ";
                                }
                                cout<<endl;
                        }
                        cout <<endl;

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
