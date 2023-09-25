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
#include <fstream>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

void Grafo::SetArista(const int contnodo, const int nextnodo, const float arista) {
  vecgrafo[contnodo]->InsertarArista(vecgrafo[nextnodo], arista);
  vecgrafo[nextnodo]->InsertarArista(vecgrafo[contnodo], arista);
}

bool Grafo::Insercion(Nodo *novonodo) {
  vecgrafo.emplace_back(novonodo);
  return true;
}

void Grafo::BusquedaBfs(const int id_origen, const int id_destino) {
  std::vector<int> inspect, generados, camino;
  std::queue<int> cola_no_visitados;
  float coste_total = 0;
  generados.emplace_back(id_origen);
  camino.emplace_back(id_origen);
  cola_no_visitados.push(id_origen);
  while (!cola_no_visitados.empty()) {
    if (cola_no_visitados.front() == id_destino) {
      return;
    }
    int iterator = cola_no_visitados.front() - 1;
    std::cout << "Nodo inspeccionado: " << iterator + 1 << std::endl;
    vecgrafo[iterator]->set_visitado(true);
    inspect.emplace_back(cola_no_visitados.front());
    inspect.emplace_back(iterator);
    for (int i = 0; i < vecgrafo[iterator]->GetVector().size(); i++) {
      if (!vecgrafo[iterator]->GetVector()[i].first->is_visitado()) {
        generados.emplace_back(vecgrafo[iterator]->GetVector()[i].first->GetId());
        vecgrafo[iterator]->GetVector()[i].first->set_visitado(true);
        cola_no_visitados.push(vecgrafo[iterator]->GetVector()[i].first->GetId());
      }
    }
    cola_no_visitados.pop();
  }
}

void Grafo::BusquedaDfs(const int id_origen, const int id_destino) {}

void Grafo::Escritura(const std::vector<Nodo *> &camino, const float coste_total) {

}