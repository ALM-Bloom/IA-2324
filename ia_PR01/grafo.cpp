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
#include <stack>
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
  std::vector<int> inspect, generados;
  std::stack<int> camino;
  std::queue<int> cola_no_visitados;
  float coste_total = 0;
  generados.emplace_back(id_origen);
  cola_no_visitados.push(id_origen);
  vecgrafo[id_origen - 1]->SetPadre(nullptr);
  while (!cola_no_visitados.empty()) {
    int iterator = cola_no_visitados.front() - 1;
    if (cola_no_visitados.front() == id_destino) {
      Nodo *nodo = vecgrafo[iterator];
      while (nodo->GetPadre() != nullptr) {
        camino.push(nodo->GetId());
        nodo = nodo->GetPadre();
      }
      camino.push(id_origen);
      Escritura(inspect, generados, camino);
    }
    std::cout << "Nodo inspeccionado: " << iterator + 1 << std::endl;
    vecgrafo[iterator]->set_visitado(true);
    inspect.emplace_back(cola_no_visitados.front());
    inspect.emplace_back(iterator);
    for (int i = 0; i < vecgrafo[iterator]->GetVector().size(); i++) {
      if (!vecgrafo[iterator]->GetVector()[i].first->is_visitado()) {
        vecgrafo[iterator]->GetVector()[i].first->SetPadre(vecgrafo[iterator]);
        generados.emplace_back(vecgrafo[iterator]->GetVector()[i].first->GetId());
    //  vecgrafo[iterator]->GetVector()[i].first->set_visitado(true);
        cola_no_visitados.push(vecgrafo[iterator]->GetVector()[i].first->GetId());
        vecgrafo[iterator]->GetVector()[i].first->SetPadre(vecgrafo[iterator]);
      }
    }
    cola_no_visitados.pop();
  }
  std::cerr << "No se ha encontrado solución" << std::endl;
}

void Grafo::BusquedaDfs(const int id_origen, const int id_destino) {
  std::vector<int> inspect, generados;
  std::stack<int> camino;
  std::stack<int> cola_no_visitados;
  float coste_total = 0;
  generados.emplace_back(id_origen);
  cola_no_visitados.push(id_origen);
  vecgrafo[id_origen - 1]->SetPadre(nullptr);
  while (!cola_no_visitados.empty()) {
    int iterator = cola_no_visitados.top() - 1;
    if (cola_no_visitados.top() == id_destino) {
      Nodo *nodo = vecgrafo[iterator];
      while (nodo->GetPadre() != nullptr) {
        camino.push(nodo->GetId());
        nodo = nodo->GetPadre();
      }
      camino.push(id_origen);
      Escritura(inspect, generados, camino);
    }
    std::cout << "Nodo inspeccionado: " << iterator + 1 << std::endl;
    vecgrafo[iterator]->set_visitado(true);
    inspect.emplace_back(cola_no_visitados.top());
    inspect.emplace_back(iterator);
    cola_no_visitados.pop();
    for (int i = 0; i < vecgrafo[iterator]->GetVector().size(); i++) {
      if (!vecgrafo[iterator]->GetVector()[i].first->is_visitado()) {
        vecgrafo[iterator]->GetVector()[i].first->SetPadre(vecgrafo[iterator]);
        generados.emplace_back(vecgrafo[iterator]->GetVector()[i].first->GetId());
        //  vecgrafo[iterator]->GetVector()[i].first->set_visitado(true);
        cola_no_visitados.push(vecgrafo[iterator]->GetVector()[i].first->GetId());
        vecgrafo[iterator]->GetVector()[i].first->SetPadre(vecgrafo[iterator]);
      }
    }
  }
  std::cerr << "No se ha encontrado solución" << std::endl;
}

void Grafo::Escritura(const std::vector<int> &visitados, const std::vector<int> &generados, std::stack<int> &camino, const float coste) {
  std::ofstream fichero;
  fichero.open("solucion.txt", std::ios::out);
  fichero << "Camino: ";
  while (!camino.empty()) {
    fichero << camino.top();
    if (camino.size() != 1) {
      fichero << ", ";
    }
    camino.pop();
  }
  fichero << std::endl;
}