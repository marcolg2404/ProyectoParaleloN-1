/*Para el uso de las funciones es necesario que llame a otras funciones para su ejecución*/
#include "Clases.h"
#include "funciones.h"
/*Librerias propias de C++*/
#include <iostream>
#include <wchar.h>
#include <string>
#include <vector>
#include <algorithm>
/*Cabeceras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos
#include "xlsxwriter.h"//Para escribir archivo final

using namespace std;
using namespace xlnt;

// 1. FUNCION PARA LA CREACION DEL FORMATO DEL ARCHIVO
void crear_formato(lxw_worksheet *hoja, lxw_workbook *archivo){
        lxw_format *formato = workbook_add_format(archivo);
	/*Tipos de estilos*/
        format_set_bold(formato);
        format_set_align(formato, LXW_ALIGN_CENTER);
        format_set_bottom(formato,LXW_BORDER_THIN);
        format_set_top(formato,LXW_BORDER_THIN);
        format_set_left(formato,LXW_BORDER_THIN);
        format_set_right(formato,LXW_BORDER_THIN);
	/* Hoja - Fila - Columna - Dato - Formato*/
	/* Datos en forma horizontal*/
        worksheet_write_string(hoja, 0, 0, "Periodo", formato);
        worksheet_write_string(hoja, 0, 1, "Lunes", formato);
        worksheet_write_string(hoja, 0, 2, "Martes", formato);
        worksheet_write_string(hoja, 0, 3, "Miércoles", formato);
        worksheet_write_string(hoja, 0, 4, "Jueves", formato);
        worksheet_write_string(hoja, 0, 5, "Viernes", formato);
        worksheet_write_string(hoja, 0, 6, "Sábado", formato);
	/*Horario según bloques, vertical */
        worksheet_write_number(hoja, 1, 0, 1, formato);
        worksheet_write_number(hoja, 2, 0, 2, formato);
        worksheet_write_number(hoja, 3, 0, 3, formato);
        worksheet_write_number(hoja, 4, 0, 4, formato);
        worksheet_write_number(hoja, 5, 0, 5, formato);
        worksheet_write_number(hoja, 6, 0, 6, formato);
        worksheet_write_number(hoja, 7, 0, 7, formato);
}
/*2. Función de tipo vector, que toma la información de Docentes y va llenando la matriz
con los cursos según disponibilidad y cantidad de bloques de estos, se llenan todos los bloques de ser posible */
vector<Profesor> asignacion_profesores(string Archivo){
        int id_p,aux=0;
        vector<Profesor> v;
        vector<string> VectorAux; /*Vector para la clase profesor*/
        vector<string> b;
        int *dia_s;
        workbook wb;
        /*Al abrir el archivo, se llena el vector con días*/
        vector<string> dias = {"Lunes","Martes","Miércoles","Jueves","Viernes"};
        /*Carga de archivo*/
        wb.load(Archivo);
        for(int h=0; h< dias.size(); h++) {
                auto ws = wb.sheet_by_title(dias[h]);
                for(auto row : ws.rows(false))
                {
                        for (auto cell:row)
                        {
                                aux++;
                                if(aux>10) { /*Se salta los bloques de descripción*/
                                        VectorAux.push_back(cell.to_string()); /*A un vector auxiliar le estamos dando todos los datos*/
                                }
                        }
                }
                for(int i=0; i<VectorAux.size(); i=i+10)/*Se aumentan 10 celdas ya que se salta las líneas de cabeceras del xlsx*/
                {

                        if(h==0) {//Lunes
                                id_p =stoi(VectorAux[i]);
                                b = {VectorAux[i+3],VectorAux[i+4],VectorAux[i+5],VectorAux[i+6],VectorAux[i+7],VectorAux[i+8],VectorAux[i+9]};
                                dia_s=StringtoBool(b);

                                Profesor _nuevo(id_p); /*Le damos los parametros a un objeto auxiliar*/

                                _nuevo.set_lunes(dia_s);
                                v.push_back(Profesor(_nuevo));/*Agregamos el objeto a un vector de objetos*/
                                b.clear(); /*Limpiamos el contenido del vector que indica la disponibilidad del horario*/

                        }
                        if (h==1) {//Martes
                                b = {VectorAux[i+3],VectorAux[i+4],VectorAux[i+5],VectorAux[i+6],VectorAux[i+7],VectorAux[i+8],VectorAux[i+9]};
                                dia_s=StringtoBool(b);
                                v[i/10].set_martes(dia_s);/*El i/10 es para sacar el identificador del vector de profesores*/
                                b.clear();


                        }
                        if(h==2) {//Miércoles
                                b = {VectorAux[i+3],VectorAux[i+4],VectorAux[i+5],VectorAux[i+6],VectorAux[i+7],VectorAux[i+8],VectorAux[i+9]};
                                dia_s=StringtoBool(b);
                                v[i/10].set_miercoles(dia_s);/*El i/10 es para sacar el identificador del vector de profesores*/
                                b.clear();

                        }
                        if(h==3) {//Jueves
                                b = {VectorAux[i+3],VectorAux[i+4],VectorAux[i+5],VectorAux[i+6],VectorAux[i+7],VectorAux[i+8],VectorAux[i+9]};
                                dia_s=StringtoBool(b);
                                v[i/10].set_jueves(dia_s);/*El i/10 es para sacar el identificador del vector de profesores*/
                                b.clear();

                        }
                        if(h==4) {//Viernes
                                b = {VectorAux[i+3],VectorAux[i+4],VectorAux[i+5],VectorAux[i+6],VectorAux[i+7],VectorAux[i+8],VectorAux[i+9]};
                                dia_s=StringtoBool(b);
                                v[i/10].set_viernes(dia_s);/*El i/10 es para sacar el identificador del vector de profesores*/
                                b.clear();
                        }
                }
                VectorAux.clear();/*Se limpia el vector auxiliar para la siguiente iteración*/
                aux=0;/*Se limpia el contador auxiliar para evitar tomar las cabeceras de los títulos*/
                dia_s=NULL;
        }

        return v;
}
/*3. Función de tipo vector que obtiene la información del archivo cursos
sean estos el código del curso, ID y cantidad de bloques en horas pedagógicas */
vector<Cursos> rescatando_cursos(string Archivo){
        int id_p,n_bloques,aux=0;
        vector<Cursos> v;
        Cursos temp;
        vector<string> VectorAux;/*Vector para la clase profesor*/
        string cod;
        workbook wb;
        wb.load(Archivo);
        auto ws = wb.sheet_by_title("Secciones");
        for(auto row : ws.rows(false))
        {
                for (auto cell:row)
                {
                        aux++;
                        if(aux>6) { /*Se salta los bloques de descripción*/
                                VectorAux.push_back(cell.to_string()); /*A un vector axiliar le estamos dando todos los datos*/
                        }
                }
        }
        for(int i=0; i<VectorAux.size(); i=i+6) {
                id_p = stoi(VectorAux[i+2]);
                cod = VectorAux[i];
                n_bloques= stoi(VectorAux[i+5]);
                if(n_bloques%2!= 0){
                  n_bloques=n_bloques +1;
                }
                temp.set_Cursos(cod,id_p, n_bloques);
                v.push_back(temp);

        }
        return v;
}
/*4. Función de tipo vector, en el cual busca a un profesor en particular de acuerdo a su ID*/
vector<Cursos> encuentra_cp(Profesor pro, vector<Cursos> vec){
        int id = pro.get_id();
        int l=0;
        int r= vec.size();
        vector<Cursos> aux;
        while (l <= r) {
                int m = l + (r - l) / 2;
                if (vec[m].getID_profe() == id)
                        aux.push_back(vec[m]);
                if (vec[m].getID_profe() < id)
                        l = m + 1;
                else
                        r = m - 1;
        }
        return aux;
}
/*5. Función de tipo vector que recibe el dato de sala y crea la matriz*/
vector<Sala> Matrices_salas(vector<string>salas){
        vector<Sala> v;
        string aula;
        for(int i=0; i<salas.size(); i++)
        {
                aula = salas[i];
                Sala aux(aula);
                aux.iniciar_matriz();
                v.push_back(aux);
                aula.clear();
        }
        return v;
}
/*6.Función en la cual genera el horario correspondiente, según la disponibilidad del profesor y cantidad de bloques a considerar
en donde según sea la disponibilidad del profe, cambia de disponible a no disponible y además filtra los Labs, una vez
llena las celdas, se verifica si queda algún espacio disponible, de no ser así, se dirige a la siguiente hoja*/
void Generar_Horario(vector<Cursos> &cursos, vector<Sala> &salas,vector<Sala> &labs, Profesor &profe,int &sala_recorrida, int &lab_recorrido){

        string curso_asignado;
        string **salax = salas[sala_recorrida].get_sala();
        string **labsx = labs[lab_recorrido].get_sala();
        vector<Cursos> Cursos_encontrados = encuentra_cp(profe,cursos);

        for(int curso_recorrido=0; curso_recorrido<Cursos_encontrados.size(); curso_recorrido++) {

                int horas_necesarias = Cursos_encontrados[curso_recorrido].get_horas();//cantidad de horas que se deben realizar por curso
                int **Horario_profesor = profe.get_horario();//horario del profesor
                bool vuelta_completa=false;
                if(Es_inf(Cursos_encontrados[curso_recorrido].getcodigo_curso())) {
                        for(int columna=0; columna<6; columna++)                 //columna
                        {
                                for(int fila=0; fila<7; fila++) {                 //fila

                                        if ((Horario_profesor[fila][columna]==1) && (salax[fila][columna]==" ") && (horas_necesarias>0)) {
                                                curso_asignado=(Cursos_encontrados[curso_recorrido].getcodigo_curso() + "-" + (to_string(Cursos_encontrados[curso_recorrido].getID_profe())));
                                                labsx[fila][columna]=curso_asignado;
                                                horas_necesarias=horas_necesarias-2;
                                                Cursos_encontrados[curso_recorrido].Resta_hora();
                                                Horario_profesor[fila][columna]==0;
                                                profe.cambiar_disponibilidad(fila,columna);
                                                labs[lab_recorrido].cambiar_seccion(fila,columna,curso_asignado);

                                        }

                                        if(columna==5 && fila ==6) {

                                                vuelta_completa=true;

                                        }
                                        if(vuelta_completa==true && horas_necesarias>0) {/*Si ya no hay espacios disponibles luego de haber recorrido la matriz completa, se procede a la siguiente sala*/

                                                lab_recorrido++;
                                                delete [] labsx;
                                                string **labsx = labs[lab_recorrido].get_sala();
                                        }
                                }

                        }

                }
                else{
                        for(int columna=0; columna<6; columna++)                 //columna
                        {
                                for(int fila=0; fila<7; fila++) {                 //fila

                                        if ((Horario_profesor[fila][columna]==1) && (salax[fila][columna]==" ") && (horas_necesarias>1)) {
                                                curso_asignado=(Cursos_encontrados[curso_recorrido].getcodigo_curso() + "-" + (to_string(Cursos_encontrados[curso_recorrido].getID_profe())));
                                                salax[fila][columna]=curso_asignado;
                                                horas_necesarias=horas_necesarias-2;
                                                Cursos_encontrados[curso_recorrido].Resta_hora();
                                                Horario_profesor[fila][columna]==0;
                                                profe.cambiar_disponibilidad(fila,columna);
                                                salas[sala_recorrida].cambiar_seccion(fila,columna,curso_asignado);
                                        }

                                        if(columna==5 && fila ==6) {

                                                vuelta_completa=true;

                                        }
                                        if(vuelta_completa==true && horas_necesarias>1) { /*Si ya no hay espacios disponibles luego de haber recorrido la matriz completa, se procede a la siguiente sala*/
                                                sala_recorrida++;
                                                delete [] salax;
                                                string **salax = salas[sala_recorrida].get_sala();
                                        }
                                }

                        }

                }
              }                /*Cont de profesores completados*/
}
/*7. Función en la cual el día sabado se asigna de diferente manera, ya que no debe llenar todas las celdas como
se llenan los demás días ya que son permitidos sólo cuatro bloques*/
void asignacion_sabado(vector<Profesor> &v,string Archivo){
        int aux=0;
        vector<string> VectorAux,sabado;/*Vector para la clase profesor*/
        int *dia_s;
        workbook wb;
        wb.load(Archivo);
        auto ws = wb.sheet_by_title("Sábado");
        for(auto row : ws.rows(false))
        {
                for (auto cell:row)
                {
                        aux++;
                        if(aux>7) {/*Se salta los bloques de descripción*/
                                VectorAux.push_back(cell.to_string()); /*A un vector auxiliar le estamos dando todos los datos*/
                        }
                }
        }
        for(int i=0; i<VectorAux.size(); i=i+7) {
                sabado = {VectorAux[i+3],VectorAux[i+4],VectorAux[i+5],VectorAux[i+6]};
                dia_s=StringtoBool(sabado);
                v[i/7].set_sabado(dia_s);
        }
}
/*8. Función que toma un string y lo convierte a entero para crear una matriz */
int *StringtoBool(vector<string> vec){
        static int aux[6];
        for(int i=0; i<vec.size(); i++) {
                if(vec[i]=="DISPONIBLE") {
                        aux[i] = 1;
                }
                else{aux[i]=0;}
        }
        return aux;
}
/*9. Función para obtener el argumento del archivo Docentes.xlsx */
char* obtener_docentes(char** matriz, int largo) {
        char* archivo = NULL;
        int i = 0, k = 0;

        if (largo > 0) {
                for (i = 0; i < largo; i++) {
                        if (strcmp("-d", matriz[i]) == 0) {
                                k = i + 1;
                                archivo = (char *) calloc(strlen(matriz[k]) + 1, sizeof (char));

                                snprintf(archivo, strlen(matriz[k]) + 1, "%s", matriz[k]);
                                break;
                        }
                }
        }

        return archivo;
}
/*10. Función para obtener el argumento del archivo Cursos.xlsx */
char* obtener_cursos(char** matriz, int largo) {
        char* archivo = NULL;
        int i = 0, k = 0;

        if (largo > 0) {
                for (i = 0; i < largo; i++) {
                        if (strcmp("-c", matriz[i]) == 0) {
                                k = i + 1;
                                archivo = (char *) calloc(strlen(matriz[k]) + 1, sizeof (char));

                                snprintf(archivo, strlen(matriz[k]) + 1, "%s", matriz[k]);
                                break;
                        }
                }
        }

        return archivo;
}
/*11. Función para obtener el argumento del archivo salas.xlsx */
char* obtener_salas(char** matriz, int largo) {
        char* archivo = NULL;
        int i = 0, k = 0;

        if (largo > 0) {
                for (i = 0; i < largo; i++) {
                        if (strcmp("-s", matriz[i]) == 0) {
                                k = i + 1;
                                archivo = (char *) calloc(strlen(matriz[k]) + 1, sizeof (char));

                                snprintf(archivo, strlen(matriz[k]) + 1, "%s", matriz[k]);
                                break;
                        }
                }
        }

        return archivo;
}
/*12. Función de tipo boleana, que filtra los cursos de acuerdo a las iniciales del código
para este caso, el filtro de tipo INF es sólo para que estos cursos se registren en los laboratorios */
bool Es_inf(string id){
        bool Es_inf = false;
        size_t encontrar_INF = id.find("INF");
        if (encontrar_INF!=string::npos)
        {
                Es_inf = true;
        }
        return Es_inf;
}
/*13. Función de tipo boleana, en el cual filtra las salas, buscando sólo aquellas que inicien con LAB*/
bool Es_lab (string id){
        bool Es_lab = false;
        size_t encontrar_INF = id.find("LAB");
        if (encontrar_INF!=string::npos)
        {
                Es_lab = true;
        }
        return Es_lab;
}
/*14. Función en donde al momento de escribir los datos en la matriz
y pasar a la siguiente sala, guarda la información que se escribió */
void guardar_salas(string archivo,vector<Sala> &vector_salas,vector<Sala> &vector_labs){
        int aux=0;
        workbook wb_salas;
	      /*Carga el archivo*/
        wb_salas.load(archivo);
        auto ws = wb_salas.active_sheet();
        string sala;
        vector<string>vectorCursos_filas;
        for (auto fila : ws.rows(false)) //row=fila
        {
                for (auto celda : fila) //cell=celda
                {
                        aux++;
                        if(aux>2) { //Se omiten las cabeceras del excel
                                vectorCursos_filas.push_back(celda.to_string());
                        }
                }
        }

        for(int i=0; i<vectorCursos_filas.size(); i=i+2)
        {       if(Es_lab(vectorCursos_filas[i])==true) {
                        Sala salax (vectorCursos_filas[i]+"-"+vectorCursos_filas[i+1]);
                        salax.iniciar_matriz();
                        vector_labs.push_back(salax);
                }
                else{
                        Sala salax(vectorCursos_filas[i]+"-"+vectorCursos_filas[i+1]);
                        salax.iniciar_matriz();
                        vector_salas.push_back(salax);
                }}

        vectorCursos_filas.clear();
}
/*15. Función de tipo void, que al momento de escrito los datos en todas las salas, guarda el archivo
para que este después de forma anexa se pueda abrir */
void Guardar_archivo(vector<Sala> &salas,vector<Sala> &labs,lxw_workbook *archivo ){
        salas.insert(salas.end(), labs.begin(), labs.end());
        labs.clear();

        for(int b=0; b<salas.size(); b++) {
                string **salax = salas[b].get_sala();
                const char* char_sala = (salas[b].get_nombre_sala()).c_str();
                 /*(wb_salas,char_sala); Agregar hoja con título de la sala*/
                lxw_worksheet *hoja = workbook_add_worksheet (archivo, char_sala);
                crear_formato(hoja,archivo);

                for(int fila=0; fila<7; fila++) {

                        for(int columna=0; columna<6; columna++) {
                                const char *dato =  salax[fila][columna].c_str();
                                worksheet_write_string (hoja, fila+1, columna+1,dato, NULL);
                        }
                }
                delete [] salax;
        }
        workbook_close(archivo);
}
