#include "grafo.h"
#include "nodo.h"
#include <fstream>
#include <iostream>
#include <vector>


int main(int argc, char *argv[]) {
 bool inicio = true;
 int aristas = 0, contnodo = 1, contnodoconexion = 2;
 Grafo grafismo;
 std::string infile = argv[1];
 std::ifstream file(infile);
 std::string lectura;
 if (file.is_open()) {
   while (file >> lectura) {
     if (inicio) {
       grafismo.set_nodos(std::stoi(lectura));
       for (unsigned i = 1; i <= std::stoi(lectura); i++) { // Bucle de construcción del Grafo
         Nodo newnodo{i, grafismo.GetNodos() - 1};
         grafismo.Insercion(newnodo);
       }
       inicio = false;
     } else { // Si existe camino
       std::cout << lectura << std::endl;
       float arista = std::stof(lectura);
       grafismo.GetGrafo()[contnodo].InsertarArista(grafismo.GetGrafo()[contnodoconexion], arista);
       grafismo.GetGrafo()[contnodoconexion].InsertarArista(grafismo.GetGrafo()[contnodo], arista);
       contnodoconexion++;
     }
     if (contnodoconexion == grafismo.GetNodos() - 1) {
       contnodo++;
       contnodoconexion = contnodo + 1;
     }
   }
 }
 return 0;
}
