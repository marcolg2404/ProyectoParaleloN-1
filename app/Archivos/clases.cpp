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
  vector<string> bloques;// 0 no esta disponible 1 si tiene el bloque disponible
public://metodos de la clase
  Profesor(string,string, vector<string> );//constructor
  void mostrar();
/*  void set_id_profesor(int);
  void set_nombre(string, string); //nombre y apellido
  void set_bloques(int);*/
};
//declaracion de los metodos
Profesor::Profesor(string _id, string _nombre,vector<string> _bloques){
  id_profe = _id;
  nombre = _nombre;
  bloques = _bloques;
}
void Profesor::mostrar(){
  cout << id_profe <<" "<< nombre << endl;
  for (int i=0 ;i<bloques.size();i++)
  {
    cout << bloques[i] << "\t";
  }
cout << endl;
}


int main(int argc, char const *argv[]) {
  int aux=0;
  vector<string> VectorAux;
  vector<Profesor> v;
  vector<string> b;
  string id_p,nombre_p;
  xlnt::workbook wb;
  wb.load("/home/sebastian/Escritorio/ProyectoParaleloN-1/app/Archivos/Docentes.xlsx");
  auto ws = wb.active_sheet();
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
    Profesor aux(id_p,nombre_p,b);
    v.push_back(Profesor(aux));
    b.clear();
    }

    for(int j=0; j< v.size();j++){
      v[j].mostrar();
    }


  return 0;
}
