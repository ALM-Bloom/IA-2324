/**
 * @file grafo.cpp
 * @author Alejandro M. L. (alu0101443126@ull.edu.es)
 * @brief Definición de la clase Grafo, almacena un vector de objetos tipo
 * "Nodo" y realiza operaciones de búsqueda, inserción o eliminación.
 * @version 0.1
 * @date 2023-05-16
 *
 * @copyright Alejandro M.L (c) 2022
 *
 */

#include "grafo.h"
#include "nodo.h"
#include <iostream>
#include <utility>
#include <vector>
#include <stack>


void Grafo::SetArista(const int contnodo, const int nextnodo, const float arista) {
   vecgrafo[contnodo]->InsertarArista(vecgrafo[nextnodo], arista);
   vecgrafo[nextnodo]->InsertarArista(vecgrafo[contnodo], arista);
}

bool Grafo::Insercion(Nodo *novonodo) {
  vecgrafo.emplace_back(novonodo);
  return true;
}

void Grafo::BusquedaBfs(const int id_origen, const int id_destino) {
  std::vector<int> visitados;
  std::stack<int> cola;
  int iterator = vecgrafo[id_origen - 1]->GetId();
  while (iterator != id_destino) {
    for (int i = 0; i <= vecgrafo[iterator]->GetVector().size(); i++) {
      cola.push(vecgrafo[iterator]->GetVector()[i].first->GetId());
    }
    visitados.emplace_back(vecgrafo[iterator]->GetId());
    for (int i = 0; i <= visitados.size(); i++) {
      if (visitados[i] == cola.top()) {
        cola.pop();
      }
    }
    iterator = cola.top();
        std::cout << "iterator es " << iterator << std::endl;
    cola.pop();
  } 
}

void Grafo::BusquedaDfs(const int id_origen, const int id_destino) {

}
