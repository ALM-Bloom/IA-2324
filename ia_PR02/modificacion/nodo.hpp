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
/// @brief Clase Nodo que refiere a cada casilla dentro del laberinto y que calcula su f(n)
class Nodo {
public:
  Nodo(int coord_i, int coord_j, int is_diag) : coord_i_{coord_i}, coord_j_{coord_j}, is_diag_{is_diag}, funcion_movimiento_{0}, acumulado_propio_{0}, nodopadre_{NULL} {}
  Nodo() = default;
  void SetPadre(Nodo *nodoprev) { nodopadre_ = nodoprev; }
  Nodo *get_padre() { return nodopadre_; }
  void obtener_fn(const Maze& lab, const int acumulado_previo);
  void obtener_fn_alternativo(const Maze& lab, const int acumulado_previo);
  int get_fn() const { return funcion_movimiento_; }
  int get_gn() { return acumulado_propio_; }
  int get_coord_i() { return coord_i_;}
  int get_coord_j() { return coord_j_;}
  bool operator()(Nodo* other, Nodo* other_node)  { return other->get_fn() > other_node->get_fn();}

private:
  int funcion_movimiento_; // f(n) y valor identificativo del nodo
  Nodo *nodopadre_; //Nodo Padre
  int coord_i_, coord_j_; //Coordenadas del nodo en el laberinto
  int is_diag_; //Entero para comprobar si el nodo ha sido accedido diagonalmente (0 no, 1 diagonal)
  int acumulado_propio_; //g(n) coste acumulado del nodo
};


#endif