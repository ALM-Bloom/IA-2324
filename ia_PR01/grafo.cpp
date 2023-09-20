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


void Grafo::SetArista(const int contnodo, const int nextnodo, const float arista) {
   vecgrafo[contnodo]->InsertarArista(vecgrafo[nextnodo], arista);
   vecgrafo[nextnodo]->InsertarArista(vecgrafo[contnodo], arista);
}

bool Grafo::Insercion(Nodo *novonodo) {
  vecgrafo.emplace_back(novonodo);
  return true;
}

void Grafo::BusquedaBfs() {
  
}

void BusquedaDfs(const int id_origen, const int id_destino) {
  
}
