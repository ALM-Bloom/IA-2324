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
  bool Insercion(Nodo *novonodo); // Inserción de un Nodo nuevo al grafo. Usado iterativamente en la lectura del fichero
  //que contiene el grafo.
  void BusquedaBfs(const int id_origen, const int id_destino); // Búsqueda en amplitud a partir de un nodo de entrada
  void set_aristas(const unsigned aristas) { total_aristas_ = aristas; }
  void set_nodos(const unsigned nodos) { total_nodos_ = nodos; }
  unsigned GetNodos() { return total_nodos_; }
  std::vector<Nodo *> GetGrafo() { return vecgrafo; }
  void SetArista(const int contnodo, const int nextnodo, const float arista);
  void Escritura(const std::vector<int> &visitados, const std::vector<int> &generados, std::stack<int> &camino);

private:
  std::vector<Nodo *> vecgrafo; // es el vector de vértices que representa el grafo.
  unsigned total_nodos_;   // Conjunto de nodos del grafos
  unsigned total_aristas_; // Conjunto de aristas del grafo
};

#endif