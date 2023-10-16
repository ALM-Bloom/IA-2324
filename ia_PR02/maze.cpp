/**
 * @file maze.cpp
 * @author Alejandro M. L. (alu0101443126@ull.edu.es)
 * @brief Definición de la Clase Maze que representa la solución al problema del
 * laberinto
 * @version 0.1
 * @date 2023-10-05
 *
 * @copyright Alejandro M.L (c) 2022
 *
 */

#include "maze.hpp"
#include "arbol.hpp"
#include "matrix_t.hpp"
#include "nodo.hpp"
#include <queue>

void Maze::encontrar_camino() {
  int movimiento_i, movimiento_j; // Coordenadas desde las que se estudian los posibles movimientos
  Arbol arbol_informado;
  int dep = 0;
  std::priority_queue<Nodo*, std::vector<Nodo*>, std::less<Nodo*>> nodos_abiertos;
  std::vector<Nodo*> nodos_cerrados;
  Nodo* nodo_partida = new Nodo{entrada_.first, entrada_.second, 2};
  nodo_partida->obtener_fn(*this);
  nodos_abiertos.push(nodo_partida);
  while (!nodos_abiertos.empty()) { // Mientras la lista de nodos abiertas no esté vacía  
    Nodo* iterator_nodo = nodos_abiertos.top();
    nodos_abiertos.pop();
    //Cambio de Marcha
    movimiento_i = iterator_nodo->get_coord_i();
    movimiento_j = iterator_nodo->get_coord_j();
    for (int mov_horiz = -1; mov_horiz <= 1; mov_horiz++) { // Bucle de movimiento (izquierda, derecha)
      for (int mov_vert = -1; mov_vert <= 1; mov_vert++) { // Bucle de movimiento (arriba, abajo)
        if (movimiento_i + mov_vert < laberinto_.get_m() && // Condicional para no salir de los lím. del laberinto
            movimiento_i + mov_vert > 0 && movimiento_j + mov_horiz < laberinto_.get_n() && movimiento_j + mov_horiz > 0) {
          if (laberinto_.at(movimiento_i + mov_vert, movimiento_j + mov_horiz) == 0) { // Si se encuentra camino
            if ((mov_horiz == 1 && mov_vert == 1) ||
                (mov_horiz == 1 && mov_vert == -1) ||
                (mov_horiz == -1 && mov_vert == 1) || (mov_horiz == -1 && mov_vert == -1)) { //Para averiguar si es diagonal
                  Nodo* newnodo = new Nodo{movimiento_i + mov_vert, movimiento_j + mov_horiz, 1};
                  newnodo->obtener_fn(*this);
                  newnodo->SetPadre(iterator_nodo);
                  if (!encontrar_nodo_cerrado(nodos_cerrados, newnodo)) {
                    nodos_abiertos.push(newnodo);
                  }
                  encontrar_nodo_abierto(nodos_abiertos, newnodo);
            } else {
                Nodo* newnodo = new Nodo{movimiento_i + mov_vert, movimiento_j + mov_horiz, 0};
                newnodo->obtener_fn(*this);
                newnodo->SetPadre(iterator_nodo);
                  if (!encontrar_nodo_cerrado(nodos_cerrados, newnodo)) {
                    nodos_abiertos.push(newnodo);
                  }
                  encontrar_nodo_abierto(nodos_abiertos, newnodo);
            }
          }
        }
      }
    }
    if (dep == 15) {
      throw;
    }
    std::cout << nodos_abiertos.top()->get_fn() << std::endl;
    coste_acumulado_ += iterator_nodo->get_gn();
    nodos_cerrados.emplace_back(iterator_nodo);
    dep++;
  }
}

bool Maze::encontrar_nodo_abierto(std::priority_queue<Nodo*, std::vector<Nodo*>, std::less<Nodo*>>& nodos_abiertos_, Nodo* swap_node) {
  std::vector<Nodo*> copy_vec;
  bool repetido = false;
  while (!nodos_abiertos_.empty()) {
    if (nodos_abiertos_.top()->get_coord_i() == swap_node->get_coord_i() && nodos_abiertos_.top()->get_coord_j() == swap_node->get_coord_j()) {
      if (nodos_abiertos_.top()->get_gn() < swap_node->get_gn()) {
        copy_vec.emplace_back(swap_node);
        repetido = true;
      }
    } else {
      copy_vec.emplace_back(nodos_abiertos_.top());
    }
    nodos_abiertos_.pop();
  }
  for (int i = 0; i < copy_vec.size(); i++) {
    nodos_abiertos_.push(copy_vec[i]);
  }
  return repetido;
}

  bool Maze::encontrar_nodo_cerrado(std::vector<Nodo*>& nodos_cerrados, Nodo* find_nodo) {
    for (int i = 0; i < nodos_cerrados.size(); i++) {
      if (nodos_cerrados[i]->get_coord_i() == find_nodo->get_coord_i() && nodos_cerrados[i]->get_coord_j() == find_nodo->get_coord_j()) {
        return true;
      }
    }
    return false;
  }