/*PROYECTO PARALELA*/
/*Integrantes:
* Marco Garrido M.
* Sebastián Olivares P.
* Amada Quinteros V.
*/
/* Librerias */
#include <iostream>
#include <fstream>
using namespace std;

int main(){

  //nombre de un archivo prueba.csv
  ifstream ip("prueba.csv"); //ifstream : clase de flujo de entrada para operar en archivos.
  if(!ip.is_open()){ //La condición es que si el archivo prueba.csv no abre mande un mensaje de error
    cout << "ERROR: No se pudo abrir el archivo" << '\n';
  }

  string nombre;
  string apellido;
  string edad;
  string peso;

  while(ip.good()){ //Mientras el archivo esté abierto, muestre los datos por pantalla

    //getline: Extrae caracteres y las almacena en str.
    //Obtención de datos en el excel
    getline(ip,nombre,',');
    getline(ip,apellido,',');
    getline(ip,edad,',');
    getline(ip,peso,'\n');

    cout << "Nombre: "<<nombre << '\n';
    cout << "Apellido: "<<apellido << '\n';
    cout << "Edad: "<<edad << '\n';
    cout << "Peso: "<<peso << '\n';
    cout << "-------------------" << '\n';
  }

  ip.close(); //Cierre de archivo
}
