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
#include <vector>

class Grafo {
public:
  Grafo(const Nodo& newnodo, const unsigned total_nodos, const unsigned total_aristas, const float newcoste);
  Grafo() = default;
  bool BusquedaDfs(const Nodo &nodobusq); // Busqueda en profundidad a partir de un nodo de entrada
  bool Insercion(const Nodo &novonodo); // Inserción de un Nodo nuevo al grafo. Usado iterativamente en la lectura del fichero que contiene el grafo.
  bool BusquedaBfs(const Nodo &nodoamplio); // Búsqueda en amplitud a partir de un nodo de entrada
  void PrintGrafo();
  void set_aristas(const unsigned aristas) { total_aristas_ = aristas; }
  void set_nodos(const unsigned nodos) { total_nodos_ = nodos; }
  unsigned GetNodos() { return total_nodos_; }
  std::vector<Nodo> GetGrafo() { return vecgrafo; }

private:
  std::vector<Nodo> vecgrafo; // es el vector de vértices que representa el grafo.
  unsigned total_nodos_;    // Conjunto de nodos del grafo
  unsigned total_aristas_; // Conjunto de aristas del grafo
};

#endif