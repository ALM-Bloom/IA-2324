#include "grafo.h"
#include "nodo.h"
#include <fstream>
#include <iostream>
#include <vector>


int main(int argc, char *argv[]) {
 bool inicio = true;
 int aristas = 0, contnodo = 0, contnodoconexion = 1, dep = 0;
 Grafo grafismo;
 std::string infile = argv[1];
 std::ifstream file(infile);
 std::string lectura;
 if (file.is_open()) {
   while (file >> lectura) {
     if (inicio == true) {
       grafismo.set_nodos(std::stoi(lectura));
       for (unsigned i = 1; i <= std::stoi(lectura); i++) { // Bucle de construcción del Grafo
         Nodo newnodo{i};
         grafismo.Insercion(newnodo);
       }
       inicio = false;
     } else { // Si existe camino
       float arista = std::stof(lectura);
       grafismo.SetArista(contnodo, contnodoconexion, arista);
       contnodoconexion++;
       std::cout << "Para el nodo " << contnodo << " su tamaño es: " << grafismo.GetGrafo()[contnodo].GetVector().size() << " Contador: " << dep;
       dep++;
     }
     if (contnodoconexion == grafismo.GetNodos()) {
       contnodo++;
       contnodoconexion = contnodo + 1;
     }
   }
 }
 return 0;
}
