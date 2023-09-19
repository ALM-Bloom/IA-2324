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

Grafo::Grafo(const Nodo &newnodo, const unsigned total_nodos, const unsigned total_aristas, const float newcoste) {
  // total_nodos_ = total_nodos;
  // total_aristas_ = total_aristas;
  // vecgrafo.resize(total_nodos_);
  // vecgrafo[newnodo.GetNodo()].push_back(std::make_pair(newnodo, newcoste));
  //*****************************************************************************

}

void Grafo::SetArista(const int contnodo, const int nextnodo, const float arista) {
       vecgrafo[contnodo].InsertarArista(vecgrafo[nextnodo], arista);
       vecgrafo[nextnodo].InsertarArista(vecgrafo[contnodo], arista);
}

bool Grafo::Insercion(const Nodo &novonodo) {
  // vecgrafo.resize(vecgrafo.size() + 1);
  // vecgrafo[novonodo.GetNodo()].push_back(std::make_pair(novonodo, coste));
  //*****************************************************************************
  vecgrafo.emplace_back(novonodo);
  return true;
}

bool Grafo::BusquedaBfs(const Nodo &nodoamplio) {}

bool Grafo::BusquedaDfs(const Nodo &nodobusq) {}

void Grafo::PrintGrafo() {
  // for (int i = 0; i < vecgrafo.size(); i++) {
  //   for (int j = 0; j < vecgrafo[i].size(); j++) {
  //     std::cout << "Camino desde nodo " << vecgrafo[i][j].first.GetNodo() << " hasta el nodo ";
  //     if (i != vecgrafo.size() - 1) {
  //       std::cout << vecgrafo[i + 1][j].first.GetNodo() << " con coste " << vecgrafo[i][j].second << std::endl;
  //     }
  //   }
  // }
}