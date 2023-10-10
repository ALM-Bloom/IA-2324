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
  int movimiento_i = entrada_.first, movimiento_j = entrada_.second; // Se parte de la posición de la entrada
  Arbol arbol_informado;
  std::priority_queue<Nodo, std::vector<Nodo>, std::greater<Nodo>> nodos_abiertos;
  std::vector<Nodo> nodos_cerrados;
  Nodo nodo_partida{movimiento_i, movimiento_j, 2};
  nodo_partida.obtener_fn(*this);
  while (laberinto_.at(movimiento_i, movimiento_j) != 4) { // Mientras no se encuentre la salida  
    for (int mov_horiz = -1; mov_horiz <= 1; mov_horiz++) { // Bucle de movimiento (izquierda, derecha)
      for (int mov_vert = -1; mov_vert <= 1; mov_vert++) { // Bucle de movimiento (arriba, abajo)
        if (movimiento_i + mov_vert < laberinto_.get_m() && // Condicional para no salir de los lím. del laberinto
            movimiento_i + mov_vert > 0 && movimiento_j + mov_horiz < laberinto_.get_n() && movimiento_j + mov_horiz > 0) {
          if (laberinto_.at(movimiento_i + mov_vert, movimiento_j + mov_horiz) == 0) { // Si se encuentra camino
            if ((mov_horiz == 1 && mov_vert == 1) ||
                (mov_horiz == 1 && mov_vert == -1) ||
                (mov_horiz == -1 && mov_vert == 1) || (mov_horiz == -1 && mov_vert == -1)) { //Para averiguar si es diagonal
                  Nodo newnodo{movimiento_i + mov_vert, movimiento_j + mov_horiz, 1};
                  newnodo.obtener_fn(*this);
                  nodos_abiertos.push(newnodo);
            } else {
                Nodo newnodo{movimiento_i + mov_vert, movimiento_j + mov_horiz, 0};
                newnodo.obtener_fn(*this);
                nodos_abiertos.push(newnodo);
            }
          }
        }
      }
    }
    std::cout << "El nodo con menor fn es de " << nodos_abiertos.top().get_fn() << std::endl;
              throw;
  }
}
