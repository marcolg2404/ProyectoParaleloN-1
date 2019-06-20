#include "Clases.h"
#include "funciones.h"
#include <iostream>
#include <wchar.h>
#include <string>
#include <vector>
/*Cabezeras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos
#include "xlsxwriter.h"//Para escribir archivo final

using namespace std;
using namespace xlnt;

// 1. FUNCION PARA LA CREACION DEL FORMATO DEL ARCHIVO
/*Se pasan los argumentos. El primer argumento de la función argc nos indica el número total de parámetros.
  Mediante el segundo argumento argv, podemos acceder a los valores de los parámetros pasados al programa,
  siempre el primer parámetro,es decir argv[0] contiene el nombre del programa.*/

/*void funcion_formato()
{
/*En esta función especifica a que si no se
pasan los tres archivos Salas.xlsx Docentes.xlsx
Cursos.xlsx no los leerá*/

        /*if (argc >= 7) {

                workbook wb_Docentes; //woorkbook=archivo, worksheet=hoja
                workbook wb_Salas;
                workbook wb_Cursos;


                for (int j = 1; j < argc; j=j+2) {
                        char *argumento = argv[j];
                        if(argumento[1]=='c') {
                                wb_Cursos.load(argv[j+1]);
                        }
                        if(argumento[1]=='d') {
                                wb_Docentes.load(argv[j+1]);
                        }
                        if(argumento[1]=='s') {
                                wb_Salas.load(argv[j+1]);
                        }
                }
                auto ws = wb_Salas.active_sheet();

                /* Como conocer las hojas dentro del archivo
                vector<string>prueba=wb_Salas.sheet_titles();
                for(int i;i<prueba.size();i++){
                cout<<prueba[i]<<endl;

                } */

              /*  cout << "Procesando Salas" << endl;
                int aux=0;
                string sala;

                vector<string>vectorCursos_filas;
                for (auto fila : ws.rows(false)) //row=fila
                {
                        for (auto celda : fila) //cell=celda
                        {
                          aux++;
                          if(aux>2){ //Se omiten las cabeceras del excel
                          vectorCursos_filas.push_back(celda.to_string());
                        }
                      }
                }

                lxw_workbook *workbook=workbook_new("Horarios.xlsx");

                for(int i=0;i<vectorCursos_filas.size();i=i+2)
                {
                    sala=(vectorCursos_filas[i]+"-"+vectorCursos_filas[i+1]);
                    /*se pasa el string sala a char*/
                     /* n= sala.length()+1;
                    char Sala_char[n]; //Hacer funcion string a char
                    for(int k=0; k<sala.length(); k++){
                      Sala_char[k] = sala[k];
                    }
                    lxw_worksheet *worksheet = workbook_add_worksheet(workbook,Sala_char); //Se crea una nueva hoja con el titulo de la sala
                    Crear_formato(worksheet, workbook);

                }
                workbook_close(workbook); //Se guarda el archivo
                cout << "Proceso completado" << endl;

              }

        else{
                printf("No se ingresaron los 3 archivos .xlsx correspondientes (-s Salas.xlsx, -c Cursos.xlsx y -d Docentes.xlsx)\n");
        }
} */

// 2. FUNCION PARA HORARIO
vector<Profesor> asignacion_profesores(){
  int id_p,aux=0;
  vector<Profesor> v;
  vector<string> VectorAux;//vevtor para la clase profesor
  vector<string> b;
  int *cat;
  string nombre_p;
  workbook wb;
  vector<string> dias = {"Lunes","Martes","Miércoles","Jueves","Viernes"};// aca la idea esque cuando abra el archivo lleanr este vector
  wb.load("./Archivos/Docentes.xlsx");
  for(int h=0;h< dias.size();h++){
    auto ws = wb.sheet_by_title(dias[h]);
    for(auto row : ws.rows(false))
    {
      for (auto cell:row)
      {
        aux++;
        if(aux>10){// se salta los bloques de descripcion
          VectorAux.push_back(cell.to_string()); //a un vector axiliar le estamos dando todos los datos
        }
      }
    }
    for(int i=0; i<VectorAux.size(); i=i+10)//se aumentan 10 celdas ya que
    {

      if(h==0){//Lunes
      id_p =stoi(VectorAux[i]);
      nombre_p =VectorAux[i+1] +" "+ VectorAux[i+2];// dejamos el nombre y apellido juntos
      b = {VectorAux[i+3],VectorAux[i+4],VectorAux[i+5],VectorAux[i+6],VectorAux[i+7],VectorAux[i+8],VectorAux[i+9]};
      cat=StringtoBool(b);

      Profesor _nuevo(id_p,nombre_p);// le damos los parametros a un objeto auxiliar

      _nuevo.set_lunes(cat);
      v.push_back(Profesor(_nuevo));// agregamos el objeto a un vector de objetos
      b.clear(); //limpiamos el contenido del vector que indica la disponibilidad del horario

     }
      if (h==1){//martes
        b = {VectorAux[i+3],VectorAux[i+4],VectorAux[i+5],VectorAux[i+6],VectorAux[i+7],VectorAux[i+8],VectorAux[i+9]};
        cat=StringtoBool(b);
        v[i/10].set_martes(cat);// el i/10 es para sacar el identificador del vector de profesores
        b.clear();


      }
      if(h==2){//miercoles
        b = {VectorAux[i+3],VectorAux[i+4],VectorAux[i+5],VectorAux[i+6],VectorAux[i+7],VectorAux[i+8],VectorAux[i+9]};
        cat=StringtoBool(b);
        v[i/10].set_miercoles(cat);// el i/10 es para sacar el identificador del vector de profesores
        b.clear();

      }
      if(h==3){//jueves
        b = {VectorAux[i+3],VectorAux[i+4],VectorAux[i+5],VectorAux[i+6],VectorAux[i+7],VectorAux[i+8],VectorAux[i+9]};
        cat=StringtoBool(b);
        v[i/10].set_jueves(cat);// el i/10 es para sacar el identificador del vector de profesores
        b.clear();

      }
      if(h==4){//viernes
        b = {VectorAux[i+3],VectorAux[i+4],VectorAux[i+5],VectorAux[i+6],VectorAux[i+7],VectorAux[i+8],VectorAux[i+9]};
        cat=StringtoBool(b);
        v[i/10].set_viernes(cat);// el i/10 es para sacar el identificador del vector de profesores
        b.clear();
      }
    }
      VectorAux.clear();// se limpia el vector axuliar para la siguiente iteracion
      aux=0;//se limpia el contador axiliar para evitar tomar las cabeceras de los titulos
      cat=NULL;
  }

  return v;
}


void asignacion_sabado(vector<Profesor> &v){
  int aux=0;
  vector<string> VectorAux,sabado;//vevtor para la clase profesor
  int *cat;
  workbook wb;
  wb.load("./Archivos/Docentes.xlsx");
  auto ws = wb.sheet_by_title("Sábado");
  for(auto row : ws.rows(false))
  {
    for (auto cell:row)
    {
      aux++;
      if(aux>7){// se salta los bloques de descripcion
        VectorAux.push_back(cell.to_string()); //a un vector axiliar le estamos dando todos los datos
      }
    }
  }
  for(int i=0; i<VectorAux.size(); i=i+7){
    sabado = {VectorAux[i+3],VectorAux[i+4],VectorAux[i+5],VectorAux[i+6]};
    cat=StringtoBool(sabado);
    v[i/7].set_sabado(cat);
  }
}


vector<Cursos> rescatando_cursos(){
    int id_p,n_bloques,aux=0;
    vector<Cursos> v;
    Cursos temp;
    vector<string> VectorAux;//vevtor para la clase profesor
    string nombre_p,nombre_c, cod;
    workbook wb;
    wb.load("./Archivos/Cursos.xlsx");
      auto ws = wb.sheet_by_title("Secciones");
      for(auto row : ws.rows(false))
      {
        for (auto cell:row)
        {
          aux++;
          if(aux>6){// se salta los bloques de descripcion
            VectorAux.push_back(cell.to_string()); //a un vector axiliar le estamos dando todos los datos
          }
        }
      }
      for(int i=0;i<VectorAux.size(); i=i+6){
        id_p = stoi(VectorAux[i+2]);
        nombre_c = VectorAux[i+1];
        cod = VectorAux[i];
        n_bloques= stoi(VectorAux[i+5]);
        nombre_p = VectorAux[i+3]+" "+VectorAux[i+4];
        temp.set_Cursos(cod,nombre_c,id_p,nombre_p, n_bloques);
        v.push_back(temp);

      }
      return v;
    }

//prototipos de funcion para escribir//
int *StringtoBool(vector<string> vec){
  static int aux[6];
  if(vec.size()>3)
  {
    for(int i=0; i<vec.size();i++){
      if(vec[i]=="DISPONIBLE"){
        aux[i] = 1;
      }
      else{aux[i]=0;}
    }
  }
  else{
    for(int i=0;i<vec.size();i++){
      if(vec[i]=="DISPONIBLE"){
        aux[i]=1;
      }
      else{
        aux[i]=0;
      }
    }
  }

  return aux;
}
