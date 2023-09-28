#include "grafo.h"
#include "nodo.h"
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  bool inicio = true;
  int aristas = 0, contnodo = 0, contnodoconexion = 1, option, id_origen,
      id_destino;
  Grafo grafismo;
  std::string infile = argv[1];
  std::ifstream file(infile);
  std::string lectura;
  if (file.is_open()) {
    while (file >> lectura) {
      if (inicio == true) {
        grafismo.set_nodos(std::stoi(lectura));
        for (unsigned i = 1; i <= std::stoi(lectura);
             i++) { // Bucle de construcción del Grafo
          grafismo.Insercion(new Nodo{i});
        }
        inicio = false;
      } else { // Si existe camino
        if (std::stoi(lectura) != -1) {
          float arista = std::stof(lectura);
          grafismo.SetArista(contnodo, contnodoconexion, arista);
        }
        contnodoconexion++;
      }
      if (contnodoconexion == grafismo.GetNodos()) {
        contnodo++;
        contnodoconexion = contnodo + 1;
      }
    }
  }
  // for (int i = 0; i < grafismo.GetGrafo().size(); i++) {
  //   std::cout << "adyacencia del Nodo: " << grafismo.GetGrafo()[i]->GetId() << std::endl; for (int j = 0; j <
  //   grafismo.GetGrafo()[i]->GetVector().size(); j++) {
  //     std::cout << "Conecta con el Nodo: " <<
  //     grafismo.GetGrafo()[i]->GetVector()[j].first->GetId(); std::cout << "  con arista coste: " << grafismo.GetGrafo()[i]->GetVector()[j].second << std::endl;
  //   }
  // }
  std::cout << "Selecciona una opción (0) BFS (1) DFS" << std::endl;
  std::cin >> option;
  switch (option) {
  case 0:
    std::cout << "Nodo de origen: ";
    std::cin >> id_origen;
    std::cout << std::endl;
    std::cout << "Nodo de destino: ";
    std::cin >> id_destino;
    std::cout << std::endl;
    grafismo.BusquedaBfs(id_origen, id_destino);
    break;

  case 1:
    std::cout << "Nodo de origen: ";
    std::cin >> id_origen;
    std::cout << std::endl;
    std::cout << "Nodo de destino: ";
    std::cin >> id_destino;
    std::cout << std::endl;
    grafismo.BusquedaDfs(id_origen, id_destino);
    break;
  default:
    break;
  }
  return 0;
}
