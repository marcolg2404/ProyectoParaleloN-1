#include <iostream>
#include <string>
#include <vector>


/*Cabezeras para manejos de archivos .xlsx*/
#include <xlnt/xlnt.hpp>//Para leer archivos
using namespace std;
using namespace xlnt;

class Profesor{
private://atributos de la clase
  string id_profe;
  string nombre;
  vector<string> lunes;// disponible o no disponible 0-6 //0-7
  vector<string> martes;
  vector<string> miercoles;
  vector<string> jueves;
  vector<string> viernes;
  vector<string> sabado;
public://metodos de la clase
  Profesor(string,string, vector<string> );//constructor
  void mostrar( );
  void set_martes(vector<string> );
  void set_miercoles(vector<string> );
  void set_jueves(vector<string> );
  void set_viernes(vector<string> );
  void set_sabado(vector<string> );

};
//declaracion de los metodos
Profesor::Profesor(string _id, string _nombre,vector<string> _bloques){
  id_profe = _id;
  nombre = _nombre;
  lunes = _bloques;
  martes = _bloques;
  miercoles = _bloques;
  jueves = _bloques;
  viernes = _bloques;
  sabado = _bloques;

}
void Profesor::mostrar(){ // funcion para mostrar el contenido de cada objeto
  cout << id_profe <<" "<< nombre << endl;
  for (int i=0 ;i<lunes.size();i++)
  {
    cout << lunes[i] << "\t";
  }
cout << endl;
}
void Profesor::set_martes(vector<string> _ma){
    martes=_ma;
}
void Profesor::set_miercoles(vector<string>_mi ){
    miercoles = _mi;
}
void Profesor::set_jueves(vector<string> _ju){
  jueves= _ju;
}
void Profesor::set_viernes(vector<string> _vi){
  viernes = _vi;
}
void Profesor::set_sabado(vector<string> _sa){
  sabado=_sa;
}
class Curso{ // declaracion clase curso;
private:
  string id_curso;
  string nombre_curso;
  int horas;
  string id_doc;
public:
  Curso(string,string, int, string);//constructor
  void mostrar_curso();
};

Curso::Curso(string _id,string _nombre_c, int _horas, string _id_doc){
  id_curso =_id;
  nombre_curso = _nombre_c;
  horas = _horas;
  id_doc =_id_doc;
}




int main(int argc, char const *argv[]) {
  int aux=0;
  vector<string> VectorAux;//vevtor para la clase profesor
  vector<string> VectorAux_cursos;
  vector<Profesor> v;
  vector<string> b;
  string id_p,nombre_p;
  int contador=0;
  workbook wb;
  vector<string> dias = {"Lunes","Martes","Miércoles","Jueves","Viernes","Sábado"};
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
    for(int i=0; i<=VectorAux.size(); i=i+10)

    {

      id_p =VectorAux[i];
      nombre_p =VectorAux[i+1] +" "+ VectorAux[i+2];
      b.push_back(VectorAux[i+3]);
      b.push_back(VectorAux[i+4]);
      b.push_back(VectorAux[i+5]);
      b.push_back(VectorAux[i+6]);
      b.push_back(VectorAux[i+7]);
      b.push_back(VectorAux[i+8]);
      b.push_back(VectorAux[i+9]);
      Profesor aux(id_p,nombre_p,b);// le damos los parametros a un objeto auxiliar
      v.push_back(Profesor(aux));// agregamos el objeto a un vector de objetos
      b.clear(); //limpiamos el contenido del vector que indica la disponibilidad del horario
      contador++;


      }
    }
    for(int j=0; j< v.size();j++){
      v[j].mostrar();
    }


  return 0;
}
