#include "grafo.h"
#include "nodo.h"
#include <fstream>
#include <iostream>
#include <vector>


int main(int argc, char *argv[]) {
 bool inicio = true;
 int aristas = 0, contnodo = 0, contnodoconexion = 1, option, id_origen, id_destino;
 Grafo grafismo;
 std::string infile = argv[1];
 std::ifstream file(infile);
 std::string lectura;
 if (file.is_open()) {
   while (file >> lectura) {
     if (inicio == true) {
       grafismo.set_nodos(std::stoi(lectura));
       for (unsigned i = 1; i <= std::stoi(lectura); i++) { // Bucle de construcción del Grafo
         grafismo.Insercion(new Nodo{i});
       }
       inicio = false;
     } else { // Si existe camino
       float arista = std::stof(lectura);
       grafismo.SetArista(contnodo, contnodoconexion, arista);
       contnodoconexion++;
     }
     if (contnodoconexion == grafismo.GetNodos()) {
       contnodo++;
       contnodoconexion = contnodo + 1;
     }
   }
 }
 switch (option)
 {
 case 0:
  std::cout << "Nodo de origen: ";
  std::cin >> id_origen;
  std::cout << std::endl;
  std::cout << "Nodo de destino: ";
  std::cin >> id_destino;
  std::cout << std::endl;
  grafismo.BusquedaDfs(id_origen, id_destino);
  break;

 case 1:
  std::cout << "Nodo de origen: ";
  std::cin >> id_origen;
  std::cout << std::endl;
  std::cout << "Nodo de destino: ";
  std::cin >> id_destino;
  std::cout << std::endl;
  break;
 default:
  break;
 }
 return 0;
}
