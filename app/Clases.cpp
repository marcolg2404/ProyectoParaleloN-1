#include "Clases.h"
#include <iostream>
#include <string>
#include <vector>


/*Cabezeras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos
using namespace std;
using namespace xlnt;

/*Declaracion de los métodos*/

//CLASE 1: PROFESOR
Profesor::Profesor(int _id, string _nombre)
{
        id_profe = _id;
        nombre = _nombre;

}
void Profesor::iniciar_matriz(){
        for(int x=0; x<7; x++) // loop 3 times for three lines
        {
                for(int y=0; y<6; y++) //
                {
                        horario[x][y]=0; //
                }
        }
}

void Profesor::mostrar() /// funcion para mostrar el contenido de cada objeto como matriz
{
        for(int x=0; x<7; x++)
        {
                for(int y=0; y<6; y++)
                {
                        cout<<horario[x][y]<<" "; // muestra el actual
                }
                cout<<endl; //cuando el loop de dentro termina se salta una linea
        }
        cout <<endl;
}

void Profesor::set_lunes(int *_lu){
        horario[0][0]=_lu[0];
        horario[1][0]=_lu[1];
        horario[2][0]=_lu[2];
        horario[3][0]=_lu[3];
        horario[4][0]=_lu[4];
        horario[5][0]=_lu[5];
        horario[6][0]=_lu[6];
}
void Profesor::set_martes(int *_ma)
{
        horario[0][1]=_ma[0];
        horario[1][1]=_ma[1];
        horario[2][1]=_ma[2];
        horario[3][1]=_ma[3];
        horario[4][1]=_ma[4];
        horario[5][1]=_ma[5];
        horario[6][1]=_ma[6];
}

void Profesor::set_miercoles(int *_mi )
{
        horario[0][2]=_mi[0];
        horario[1][2]=_mi[1];
        horario[2][2]=_mi[2];
        horario[3][2]=_mi[3];
        horario[4][2]=_mi[4];
        horario[5][2]=_mi[5];
        horario[6][2]=_mi[6];
}

void Profesor::set_jueves(int *_ju)
{
        horario[0][3]=_ju[0];
        horario[1][3]=_ju[1];
        horario[2][3]=_ju[2];
        horario[3][3]=_ju[3];
        horario[4][3]=_ju[4];
        horario[5][3]=_ju[5];
        horario[6][3]=_ju[6];
}

void Profesor::set_viernes(int *_vi)
{
        horario[0][4]=_vi[0];
        horario[1][4]=_vi[1];
        horario[2][4]=_vi[2];
        horario[3][4]=_vi[3];
        horario[4][4]=_vi[4];
        horario[5][4]=_vi[5];
        horario[6][4]=_vi[6];
}

void Profesor::set_sabado(int *_sa)
{
        horario[0][5]=_sa[0];
        horario[1][5]=_sa[1];
        horario[2][5]=_sa[2];
        horario[3][5]=_sa[3];
        horario[4][5]=0;
        horario[5][5]=0;
        horario[6][5]=0;
}

int Profesor::get_id(){
        return id_profe;
}

bool operator<(Profesor &s1, Profesor &s2){
        if(s1.get_id() < s2.get_id()) {
                return true;
        }
        else{
                return false;
        }
}
//CLASE 2: CURSOS
Cursos::Cursos(){

}
void Cursos::set_Cursos(string _codigo, string _ncurso, int _ido, string np, int _bloque){
        codigo_cursos = _codigo;
        nombre_curso = _ncurso;
        id_docente = _ido;
        nombre_p = np;
        bloque = _bloque;
}
int Cursos::getID_profe(){
        return id_docente;
}
bool Cursos::cursos_inf(string id){
        bool Es_inf = false;
        size_t encontrar_INF = id.find("INF");
        if (encontrar_INF!=string::npos)
        {
                Es_inf = true;
        }
        return Es_inf;
}

void Cursos::cursos_mostrar(){
        cout<< codigo_cursos << " " << nombre_curso << " "<< id_docente<< " " << bloque << endl;
}
Cursos::~Cursos()
{
        //destructor
}

bool operator<(Cursos &s1, Cursos &s2){
        return s1.getID_profe()< s2.getID_profe();
}

//CLASE 3: HORARIO(Archivo final)
/*void Horario::crear_formato(lxw_worksheet *hoja, lxw_workbook *archivo){
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
*/
