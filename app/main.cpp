#include <iostream>
#include <xlnt/xlnt.hpp>

using namespace std;

const char *Docentes = "./Archivos/Docentes.xlsx";
const char *Salas = "./Archivos/Salas.xlsx";
const char *Cursos = "./Archivos/Cursos.xlsx";

int main(int argc, const char **argv)/*Se pasan los argumentos. El primer argumento de la función argc nos indica el número total de parámetros.
Mediante el segundo argumento argv, podemos acceder a los valores de los parámetros pasados al programa, siempre el primer parámetro,
 es decir argv[0] contiene el nombre del programa.*/
{
    if (argc >= 3){ /*En esta función especifica a que si no se pasan los tres archivos Salas.xlsx Docentes.xlsx Cursos.xlsx no los leerá*/
      argv[1]=Docentes; //El vector 1 corresponde a Docentes.
      argv[2]=Salas; //El vector 2 corresponde a Salas.
      argv[3]=Cursos; //El vector 3 corresponde a Cursos.
    }
      else{
      printf("No se ingresaron los 3 archivos .xlsx correspondientes (Salas.xlsx, Docentes.xlsx y Cursos.xlsx\n");
      return 1;
      }
    xlnt::workbook wb_Docentes;
    xlnt::workbook wb_Salas;
    xlnt::workbook wb_Cursos;

    /*Se procede a cargar los archivos correspondientes*/
    wb_Docentes.load(Docentes);
    wb_Salas.load(Salas);
    wb_Cursos.load(Cursos);

    auto ws = wb_Docentes.active_sheet();

    cout << "Processing spread sheet" << endl;
    for (auto row : ws.rows(false))
    {
        for (auto cell : row)
    {
        clog << cell.to_string() << endl;
    }
    }
    cout << "Processing complete" << endl;
    return 0;
}
