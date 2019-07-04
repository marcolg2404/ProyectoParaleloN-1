/*Llama al archivo Clases, para la ejecución de las funciones*/
#include "Clases.h"
/*Librerías propias de C++*/
#include <iostream>
#include <string>
#include <vector>

/*Cabeceras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos

using namespace std;
using namespace xlnt;

/*Declaracion de los métodos*/

//CLASE 1: PROFESOR
/*1. Constructor en el cual sólo obtiene la ID del profesor*/
Profesor::Profesor(int _id)
{
        id_profe = _id;

}

/*2. Función para mostrar el contenido de cada objeto como matriz*/
void Profesor::mostrar()
{
        cout << id_profe << endl;
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
/*3. Función que creará la matriz para el horario en donde irán los datos (ID CURSO - ID PROFE)*/
void Profesor::iniciar_matriz(){
        for(int x=0; x<7; x++) // Filas
        {
                for(int y=0; y<6; y++) // Columnas
                {
                        horario[x][y]=0; //Crea matriz horario
                }
        }
}


/*Las siguientes funciones definen la posición de los días en la matriz horario*/
/*4. Función para el día Lunes*/
void Profesor::set_lunes(int *_lu){
        horario[0][0]=_lu[0];
        horario[1][0]=_lu[1];
        horario[2][0]=_lu[2];
        horario[3][0]=_lu[3];
        horario[4][0]=_lu[4];
        horario[5][0]=_lu[5];
        horario[6][0]=_lu[6];
}
/*5. Función para el día Martes*/
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
/*6. Función para el día Miércoles*/
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
/*7. Función para el día Jueves*/
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
/*8. Función para el día Viernes*/
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
/*9. Función para el día Sábado*/
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
/*10. Función que ve la disponibilidad del profesor, en el caso que esté disponible se cambia a no disponible*/
void Profesor::cambiar_disponibilidad(int fila,int columna){
        horario[fila][columna]==0;
}
/*11. Función que obtiene la ID del profesor y la retorna*/
int Profesor::get_id(){
        return id_profe;
}
/*12. Función copia de matriz a través de puntero de punteros*/
int **Profesor::get_horario(){
        int** aux=new int*[7];
        for(int x=0; x<7; x++) /*Filas*/
        {
                aux[x]=new int[6];
                for(int y=0; y<6; y++) /*Columnas*/
                {
                        aux[x][y]=horario[x][y];
                }
        }
        return aux;
}

/*13. Función boleana que ordena las ID's de los profesores de menor a mayor*/
bool operator<(Profesor &s1, Profesor &s2){
        if(s1.get_id() < s2.get_id()) {
                return true;
        }
        else{
                return false;
        }
}


//CLASE 2: CURSOS
/*0. */
Cursos::Cursos(){

}
/*1. Constructor*/
/* Se obtendrán datos como:
* Código de cursos
* ID de cursos
* ID de Docentes
* Bloques u horas pedagógicas */
void Cursos::set_Cursos(string _codigo,  int _ido,  int _bloque){
        codigo_cursos = _codigo;
        id_docente = _ido;
        bloque = _bloque;
}
/*2. Función que retorna la cantidad de horas pedagógicas*/
int Cursos::get_horas(){
        return bloque;
}
/*3. Función de tipo entero que obtiene y retorna la ID de los profesores*/
int Cursos::getID_profe(){
        return id_docente;
}
/*4. Función que obtiene el código de curso*/
string Cursos::getcodigo_curso(){
        return codigo_cursos;
}
/*5. Resta las horas de los bloques según las horas pedagógicas*/
void Cursos::Resta_hora(){
  bloque=bloque-2;

}
/*6. Función que muestra la información de Cursos, en este caso, código del curso, ID del curso y Bloques de horas pedagógicas*/
void Cursos::cursos_mostrar(){
        cout<< codigo_cursos << " " <<  id_docente<< " " << bloque << endl;
}
Cursos::~Cursos()
{
        //destructor
}


/*7. Función boleana que ordena los cursos según ID del profesor, de menor a mayor*/
bool operator<(Cursos &s1, Cursos &s2){
        return s1.getID_profe()< s2.getID_profe();
}
/*8. Función boleana que verifica según la ID del profesor si tiene o no más más cursos asignados*/
bool operator== (Cursos &n1, Cursos &n2)
{
        return n1.getID_profe() == n2.getID_profe();
}

//CLASE 3: SALAS
/*1. Constructor/Obtiene el código de cursos*/
Sala::Sala (string codigo) {
        _sala = codigo;
}
/*2. Función que creará la matriz para el horario en donde irán los datos (ID CURSO - ID PROFE)*/
void Sala::iniciar_matriz(){
        for(int x=0; x<7; x++)
        {
                for(int y=0; y<6; y++)
                {
                        matriz[x][y]= " ";
                }
        }
}
/*3. Función para mostrar el contenido de cada objeto como matriz*/
void Sala::mostrar_sala()
{
        for(int x=0; x<7; x++)
        {
                for(int y=0; y<6; y++)
                {
                        cout<<matriz[x][y]; /*Muestra el actual*/
                }
                cout<<endl; /*Cuando el loop de dentro termina se salta una línea*/
        }
        cout <<endl;
}
/*4. Función que llena la matriz vacía del horario con el código del curso*/
void Sala::cambiar_seccion(int fila, int columna, string codigo){
        matriz[fila][columna]=codigo;
}
/*5. Función que consigue una copia de la matriz original */
string **Sala::get_sala(){
        string** aux=new string*[7];
        for(int x=0; x<7; x++)
        {
                aux[x]=new string[6];
                for(int y=0; y<6; y++)
                {
                        aux[x][y]=matriz[x][y];
                }
        }
        return aux;
}
/*6. Función que da nombre a las salas existentes*/
string Sala::get_nombre_sala(){
        return _sala;
}
/*Destructor*/
Sala::~Sala()
{
        //destructor
}
