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
  std::priority_queue<Nodo*, std::vector<Nodo*>, Nodo> nodos_abiertos;
  std::vector<Nodo*> nodos_cerrados;
  Nodo* nodo_partida = new Nodo{entrada_.first, entrada_.second, 2};
  nodo_partida->obtener_fn(*this, nodo_partida->get_gn());
  nodos_abiertos.push(nodo_partida);
  while (!nodos_abiertos.empty()) { // Mientras la lista de nodos abiertas no esté vacía  
    Nodo* iterator_nodo = nodos_abiertos.top();
    std::cout << "Nodo siendo analizado: " << iterator_nodo->get_coord_i() << "," << iterator_nodo->get_coord_j() << std::endl;
    //Cambio de Marcha
    movimiento_i = iterator_nodo->get_coord_i();
    movimiento_j = iterator_nodo->get_coord_j();
    for (int mov_horiz = -1; mov_horiz <= 1; mov_horiz++) { // Bucle de movimiento (izquierda, derecha)
      for (int mov_vert = -1; mov_vert <= 1; mov_vert++) { // Bucle de movimiento (arriba, abajo)
        if (movimiento_i + mov_vert <= laberinto_.get_m() && // Condicional para no salir de los lím. del laberinto
            movimiento_i + mov_vert > 0 && movimiento_j + mov_horiz <= laberinto_.get_n() && movimiento_j + mov_horiz > 0) {
          if (laberinto_.at(movimiento_i + mov_vert, movimiento_j + mov_horiz) == 0 || 
          laberinto_.at(movimiento_i + mov_vert, movimiento_j + mov_horiz) == 4) { // Si se encuentra camino
            if ((mov_horiz == 1 && mov_vert == 1) ||
                (mov_horiz == 1 && mov_vert == -1) ||
                (mov_horiz == -1 && mov_vert == 1) || (mov_horiz == -1 && mov_vert == -1)) { //Para averiguar si es diagonal
                  Nodo* newnodo = new Nodo{movimiento_i + mov_vert, movimiento_j + mov_horiz, 1};
                  newnodo->obtener_fn(*this, iterator_nodo->get_gn());
                  newnodo->SetPadre(iterator_nodo);
                  if (!encontrar_nodo_cerrado(nodos_cerrados, newnodo) && !abiertos_repetido(nodos_abiertos, newnodo)) {
                    nodos_abiertos.push(newnodo);
                  }
                if (abiertos_repetido(nodos_abiertos, newnodo)) {
                encontrar_nodo_abierto(nodos_abiertos, newnodo);
                } 
            } else {
                Nodo* newnodo = new Nodo{movimiento_i + mov_vert, movimiento_j + mov_horiz, 0};
                newnodo->obtener_fn(*this, iterator_nodo->get_gn());
                newnodo->SetPadre(iterator_nodo);
                  if (!encontrar_nodo_cerrado(nodos_cerrados, newnodo) && !abiertos_repetido(nodos_abiertos, newnodo)) {
                    nodos_abiertos.push(newnodo);
                  }
                if (abiertos_repetido(nodos_abiertos, newnodo)) {
                encontrar_nodo_abierto(nodos_abiertos, newnodo);
                }
            }
          }
        }
      }
    }
    nodos_abiertos.pop();
    // imprimir_nodos_abiertos(nodos_abiertos);
    // std::cout << nodos_abiertos.top()->get_fn() << std::endl;
    // std::cout << nodos_abiertos.size() << std::endl;
    nodos_cerrados.emplace_back(iterator_nodo);
  }
  vuelta_atrás(nodos_cerrados);
}

void Maze::vuelta_atrás(const std::vector<Nodo*> nodos_cerrados) {
  Nodo* nodo_salida = nullptr;
  for (int i = 0; i < nodos_cerrados.size(); i++) {
    if (nodos_cerrados[i]->get_coord_i() == salida_.first && nodos_cerrados[i]->get_coord_j() == salida_.second) {
      nodo_salida = nodos_cerrados[i];
      break;
    }
  }
    if (nodo_salida == nullptr) {
        std::cout << "No se encontró el nodo de salida en los nodos cerrados." << std::endl;
        return;
    }
    // Recorre los padres desde el nodo de salida hasta el nodo de entrada
    Nodo* nodo_actual = nodo_salida;
    while (nodo_actual != nullptr) {
        int i = nodo_actual->get_coord_i();
        int j = nodo_actual->get_coord_j();
        laberinto_.at(i, j) = 8;
        // Si el padre es nullptr, hemos llegado al nodo de entrada
        if (nodo_actual->get_padre() == nullptr) {
            std::cout << "Llegamos al nodo de entrada." << std::endl;
            break;
        }

        // Avanza al nodo padre
        nodo_actual = nodo_actual->get_padre();
    }
    laberinto_.at(entrada_.first, entrada_.second) = 3;
    laberinto_.at(salida_.first, salida_.second) = 4;
}
void Maze::imprimir_nodos_abiertos(std::priority_queue<Nodo*, std::vector<Nodo*>, Nodo> nodos_abiertos_) {
    // Creamos una copia temporal de la cola de prioridad para no modificar la original
    std::priority_queue<Nodo*, std::vector<Nodo*>, Nodo> temp_queue = nodos_abiertos_;

    while (!temp_queue.empty()) {
        Nodo* top_node = temp_queue.top();
        temp_queue.pop();
        // Imprimimos las coordenadas y el valor de g(n) del nodo
        std::cout << "Coordenadas (" << top_node->get_coord_i() << ", " << top_node->get_coord_j() << "), f(n) = " << top_node->get_fn() << " g(n) = " << top_node->get_gn() << std::endl;
    }
}

bool Maze::abiertos_repetido(std::priority_queue<Nodo*, std::vector<Nodo*>, Nodo>& nodos_abiertos_, Nodo* busq_nodo) {
    // Creamos una copia temporal de la cola de prioridad para buscar el nodo
    std::priority_queue<Nodo*, std::vector<Nodo*>, Nodo> temp_queue = nodos_abiertos_;
    while (!temp_queue.empty()) {
        Nodo* top_node = temp_queue.top();
        temp_queue.pop();

        // Si encontramos un nodo con las mismas coordenadas
        if (top_node->get_coord_i() == busq_nodo->get_coord_i() && top_node->get_coord_j() == busq_nodo->get_coord_j()) {
            // El nodo busq_nodo existe en la cola
            return true;
        }
    }
    // Si no se encuentra el nodo, devuelve false
    return false;
}

void Maze::encontrar_nodo_abierto(std::priority_queue<Nodo*, std::vector<Nodo*>, Nodo>& nodos_abiertos_, Nodo* swap_node) {
    // Creamos una copia temporal de la cola de prioridad para buscar y actualizar el nodo
    std::priority_queue<Nodo*, std::vector<Nodo*>, Nodo> temp_queue;
    while (!nodos_abiertos_.empty()) {
        Nodo* top_node = nodos_abiertos_.top();
        nodos_abiertos_.pop();
        // Si encontramos un nodo con las mismas coordenadas
        if (top_node->get_coord_i() == swap_node->get_coord_i() && top_node->get_coord_j() == swap_node->get_coord_j()) {
            // Comparamos los valores de g(n)
            if (top_node->get_gn() > swap_node->get_gn()) {
                // Sustituimos el nodo por swapnode
                temp_queue.push(swap_node);
            } else {
                // Mantenemos el nodo original
                temp_queue.push(top_node);
            }
        } else {
            // Si las coordenadas no coinciden, simplemente agregamos el nodo a la cola temporal
            temp_queue.push(top_node);
        }
    }

    // Restauramos la cola de prioridad original con los nodos actualizados
    nodos_abiertos_ = temp_queue;
}

  bool Maze::encontrar_nodo_cerrado(std::vector<Nodo*>& nodos_cerrados, Nodo* find_nodo) {
    for (int i = 0; i < nodos_cerrados.size(); i++) {
      if (nodos_cerrados[i]->get_coord_i() == find_nodo->get_coord_i() && nodos_cerrados[i]->get_coord_j() == find_nodo->get_coord_j()) {
        return true;
      }
    }
    return false;
  }