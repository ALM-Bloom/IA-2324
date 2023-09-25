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
#include <queue>
#include <vector>
#include <climits>
#include <fstream>
#include <algorithm>
#include <utility>

void Grafo::SetArista(const int contnodo, const int nextnodo, const float arista) {
  vecgrafo[contnodo]->InsertarArista(vecgrafo[nextnodo], arista);
  vecgrafo[nextnodo]->InsertarArista(vecgrafo[contnodo], arista);
}

bool Grafo::Insercion(Nodo *novonodo) {
  vecgrafo.emplace_back(novonodo);
  return true;
}

void Grafo::BusquedaBfs(const int id_origen, const int id_destino) {
  std::vector<bool> visitados(total_nodos_, false);
  std::queue<int> cola_no_visitados;
  
}


void Grafo::BusquedaDfs(const int id_origen, const int id_destino) {}

void Grafo::Escritura(const std::vector<Nodo*> &camino, const float coste_total) {
    if (camino.empty()) {
        std::cout << "No se encontró un camino desde el nodo origen hasta el nodo destino." << std::endl;
        return;
    }
    std::cout << "Caminos desde el nodo origen hasta el nodo destino:" << std::endl;
    for (int i = 0; i < camino.size(); ++i) {
        std::cout << "Nodo " << camino[i]->GetId();
        if (i < camino.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
    std::cout << "Coste total del camino: " << coste_total << std::endl;
}