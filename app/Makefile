CXX = g++
CXXFLAGS = -std=c++14
#MKDIR = mkdir -p

#LDFLAGS = -lxlsxwriter -Ixlnt/include -lxlnt
#Las librerias usadas son:
# - lxnt : Libreria para leer archivos.
# - lxlsxwriter : Libreria para escribir archivos.
LIBS =  -lxlsxwriter -Ixlnt/include -lxlnt

#Se crean los directorios para la función principal, clases y funciones, además se crea un directorio para que su ejecución sea llamada "ProyectoParalela"
PRINCIPAL = main.cpp
CLASES = Clases.cpp
FUNCIONES = funciones.cpp
PROYECTO = ProyectoParalela

#Archivos excel
XLSX = Cursos.xlsx Docentes.xlsx Salas.xlsx

#El directorio Proyecto usará como principal el main del proyecto
#Se compila
Proyecto: main.cpp
#g++ main.cpp Clases.cpp funciones.cpp -o ProyectoParalela -std=c++14 -lxlsxwriter -Ixlnt/include -lxlnt
	$(CXX) $(PRINCIPAL) $(CLASES) $(FUNCIONES) -o $(PROYECTO) $(CXXFLAGS) $(LIBS)
#Destruye el archivo creado
	clear
	./$(PROYECTO) $(XLSX)

#Mostrará el archivo en ejecución
#./ProyectoParalela Cursos.xlsx Docentes.xlsx Salas.xlsx
Ejecucion:
	clear
	./$(PROYECTO) $(XLSX)
#Destruye la salida creada
clear:
	rm -fr *.o a.out $(ProyectoParalela)
