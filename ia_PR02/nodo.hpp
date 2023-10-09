/**
 * @file nodo.h
 * @author Alejandro M. L. (alu0101443126@ull.edu.es)
 * @brief Declaración de la clase Nodo, que es responsable de almacenar el coste
 * y adicionalmente, el nodo adyacente. Por ende, la estructura de la clase
 * sería: Nodo = {costo, siguiente nodo}, donde siguiente nodo pudiera ser Null
 * si no existe adyacencia.
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Alejandro M.L (c) 2022
 *
 */

#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <utility>
#include <vector>
#include "maze.hpp"

class Maze;
class Nodo {
public:
  Nodo(int coord_i, int coord_j) : coord_i_{coord_i}, coord_j_{coord_j}, funcion_movimiento_{0}, nodopadre_{NULL}, hijos_{NULL}  {}
  Nodo() = default;
  void SetPadre(Nodo *nodoprev) { nodopadre_ = nodoprev; }
  Nodo *GetPadre() { return nodopadre_; }
  void obtener_fn(const Maze& lab, bool is_diag);

private:
  int funcion_movimiento_; // f(n) y valor identificativo del nodo
  std::vector<Nodo *> hijos_; //Dentro del árbol, los hijos del nodo
  Nodo *nodopadre_; //Nodo Padre
  int coord_i_, coord_j_;
  bool is_diag;
};

#endif