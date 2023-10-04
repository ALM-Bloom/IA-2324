/**
 * @file grafo.h
 * @author Alejandro M. L. (alu0101443126@ull.edu.es)
 * @brief Declaración de la clase Grafo, almacena un vector de objetos tipo
 * "Nodo" y realiza operaciones de búsqueda, inserción o eliminación.
 * @version 0.1
 * @date 2023-05-16
 *
 * @copyright Alejandro M.L (c) 2022
 *
 */

#ifndef GRAFO_H
#define GRAFO_H

#include "nodo.h"
#include <iostream>
#include <stack>
#include <vector>

class Grafo {
public:
  Grafo(const Nodo &newnodo, const unsigned total_nodos, const unsigned total_aristas, const float newcoste);
  Grafo() = default;
  void BusquedaDfs(const int id_origen, const int id_destino); // Busqueda en profundidad a partir de un nodo de entrada
  bool Insercion(Nodo *novonodo); // Inserción de un Nodo nuevo al grafo.
  void BusquedaBfs(const int id_origen, const int id_destino); // Búsqueda en amplitud a partir de un nodo de entrada
  void set_aristas(const unsigned aristas) { total_aristas_ = aristas; }
  void set_nodos(const unsigned nodos) { total_nodos_ = nodos; }
  unsigned GetNodos() { return total_nodos_; }
  std::vector<Nodo *> GetGrafo() { return vecgrafo; }
  void SetArista(const int contnodo, const int nextnodo, const float arista);
  void RandomBFS(int id_origen, const int id_destino);
  void Escritura(const std::vector<int> &visitados, const std::vector<int> &generados, std::stack<int> &camino, const float coste);

private:
  std::vector<Nodo *> vecgrafo; //Vector que contiene todos los nodos
  unsigned total_nodos_;   //Número total de nodos en el grafo (equivalente a vecgrafo.size)
  unsigned total_aristas_; //Número total de aristas en el grafo (no usado)
};

#endif