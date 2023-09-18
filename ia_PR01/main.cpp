/**
 * @file grafo.cpp
 * @author Alejandro Melián Lemes (alu0101443126@ull.edu.es)
 * @brief Código consistente en la lectura del fichero de texto, el almacenamiento en una matriz
 * contenedora de objetos Nodos y la aplicación de la búsqueda de amplitud.
 * @version 0.1
 * @date 2022-10-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "nodo.h"
#include "grafo.h"
#include <vector>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
  int cont = 0, aristas = 0, contnodo = 1;
  Grafo grafismo;
  std::string infile = argv[1];
  std::ifstream file(infile);
  std::string lectura;
  if (file.is_open()) {
    while (file >> lectura) {
      if (cont == 0) {
        grafismo.set_nodos(std::stoi(lectura));
        for (unsigned i = 1; i <= std::stoi(lectura); i++) {
          Nodo newnodo{i, grafismo.GetNodos() - 1};
          grafismo.Insercion(newnodo);
        }
      } else if (lectura[0] == '-') {
        
      }
      else {
        float arista = std::stof(lectura);
        grafismo.GetGrafo(
      }
      cont++;
    }
  }
  return 0;
}