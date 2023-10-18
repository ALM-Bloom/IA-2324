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

/// @brief Método que implementa el algoritmo A*
/// @param euclides Booleano que identifica si se ha seleccionado la heurística alternativa (true)
void Maze::encontrar_camino(const bool& euclides) {
  int movimiento_i, movimiento_j, it = 1; // Coordenadas desde las que se estudian los posibles movimientos
  Arbol arbol_informado;
  std::vector<Nodo*> visitados;
  std::priority_queue<Nodo*, std::vector<Nodo*>, Nodo> nodos_abiertos;
  std::vector<Nodo*> nodos_cerrados;
  Nodo* nodo_partida = new Nodo{entrada_.first, entrada_.second, 2};
  if (euclides == true) {
    nodo_partida->obtener_fn_alternativo(*this, nodo_partida->get_gn());
  } else {
    nodo_partida->obtener_fn(*this, nodo_partida->get_gn());
  }
  nodos_abiertos.push(nodo_partida);
  while (!nodos_abiertos.empty()) { // Mientras la lista de nodos abiertas no esté vacía  
    Nodo* iterator_nodo = nodos_abiertos.top();
    visitados.emplace_back(iterator_nodo); //Para mostrar los nodos visitados en la tabla de resultados
    // std::cout << "Nodo siendo analizado: " << iterator_nodo->get_coord_i() << "," << iterator_nodo->get_coord_j() << std::endl;
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
                  if (euclides == true) {
                    newnodo->obtener_fn_alternativo(*this, iterator_nodo->get_gn());
                  } else {
                    newnodo->obtener_fn(*this, iterator_nodo->get_gn());
                  }
                  newnodo->SetPadre(iterator_nodo);
                  if (!encontrar_nodo_cerrado(nodos_cerrados, newnodo) && !abiertos_repetido(nodos_abiertos, newnodo)) {
                    nodos_abiertos.push(newnodo);
                  }
                if (abiertos_repetido(nodos_abiertos, newnodo)) {
                encontrar_nodo_abierto(nodos_abiertos, newnodo);
                } 
            } else {
                Nodo* newnodo = new Nodo{movimiento_i + mov_vert, movimiento_j + mov_horiz, 0};
                if (euclides == true) {
                  newnodo->obtener_fn_alternativo(*this, iterator_nodo->get_gn());
                } else {
                  newnodo->obtener_fn(*this, iterator_nodo->get_gn());
                }
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
//---------Herramientas de Depuración------------------------------------
    // std::cout << "IT " << it << std::endl;
    //  imprimir_nodos_abiertos(nodos_abiertos);
    //  std::cout << std::endl;
    // std::cout << nodos_abiertos.top()->get_fn() << std::endl;
    // std::cout << nodos_abiertos.size() << std::endl;
    // it++;
//------------------------------------------------------------------------
    nodos_cerrados.emplace_back(iterator_nodo);
  }
  vuelta_atrás(nodos_cerrados);
}

/// @brief Método que busca el camino generado estudiando los padres desde la salida hasta la entrada
/// @param nodos_cerrados La lista de nodos cerrados donde se encuentra la solución
void Maze::vuelta_atrás(const std::vector<Nodo*> nodos_cerrados) {
  Nodo* nodo_salida = nullptr;
  int coste_camino = 0;
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
    std::cout << "Coste camino = " << nodo_actual->get_gn() << std::endl;
    while (nodo_actual != nullptr) {
        int i = nodo_actual->get_coord_i();
        int j = nodo_actual->get_coord_j();
        laberinto_.at(i, j) = 5;
        // Si el padre es nullptr, hemos llegado al nodo de entrada
        if (nodo_actual->get_padre() == nullptr) {
            std::cout << "Llegamos al nodo de entrada." << std::endl;
            break;
        }
        coste_camino += nodo_actual->get_fn();
        // Avanza al nodo padre
        nodo_actual = nodo_actual->get_padre();
    }
    laberinto_.at(entrada_.first, entrada_.second) = 3;
    laberinto_.at(salida_.first, salida_.second) = 4;
}

/// @brief Método para imprimir por pantalla la lista de nodos abiertos, usado en la depuración del programa
/// @param nodos_abiertos_ La cola de prioridad de nodos abiertos 
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

/// @brief Método para controlar si el nodo generado ya ha sido insertado en la lista de nodos abiertos
/// @param nodos_abiertos_ Cola de prioridad de nodos abiertos donde se buscará el nodo generado si existe
/// @param busq_nodo El nodo que se pretende encontrar en la lista significando que ya ha sido generado anteriormente   
/// @return booleano que identifica mediante true si el nodo se encuentra en la lista o false en otro caso
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

/// @brief Método en el que si ya ha sido insertado en la lista de nodos abiertos, se comprueba si se debe actualizar el g(n) del nodo
/// @param nodos_abiertos_ La cola de prioridad donde se encuentra el nodo que se pretende actualizar 
/// @param swap_node El nodo con distinto g(n) pero mismas coordenadas que se va a utilizar para la comparación y que pudiera ser sustituto
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

  /// @brief Método para controlar si un nodo ya ha sido insertado en la lista de nodos cerrads
  /// @param nodos_cerrados El vector que contiene la lista de nodos cerrados
  /// @param find_nodo El nodo que se pretende comprobar si ya existe en la lista de nodos cerrados
  /// @return Booleano que identifica con true si el nodo ya se encuentra en la lista de nodos cerrados y false en otro caso.
  bool Maze::encontrar_nodo_cerrado(std::vector<Nodo*>& nodos_cerrados, Nodo* find_nodo) {
    for (int i = 0; i < nodos_cerrados.size(); i++) {
      if (nodos_cerrados[i]->get_coord_i() == find_nodo->get_coord_i() && nodos_cerrados[i]->get_coord_j() == find_nodo->get_coord_j()) {
        return true;
      }
    }
    return false;
  }
