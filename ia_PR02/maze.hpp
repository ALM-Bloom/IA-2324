/**
 * @file maze.hpp
 * @author Alejandro M. L. (alu0101443126@ull.edu.es)
 * @brief Declaración de los métodos de la Clase Maze, que implementa el algoritmo A*
 * @version 0.1
 * @date 2023-10-15
 *
 * @copyright Alejandro M.L (c) 2022
 *
 */

#ifndef MAZE_HPP
#define MAZE_HPP
#include "matrix_t.hpp"
#include "nodo.hpp"
#include <utility>
#include <queue>
#include <set>

class Nodo;
/// @brief Clase Maze que implementa el laberinto, almacenando la matriz con el laberinto, las coordenads de entrada 
///        y salida, e implementa el algoritmo A* mediante su método "encontrar_camino"
class Maze {
public:
  Maze() = default;
  Maze( matrix_t<int> &laberinto) : laberinto_{laberinto} {}
  void set_matrix(const matrix_t<int> &matriz) { laberinto_ = matriz; }
  void set_entrada(const int i, const int j) {
    entrada_.first = i;
    entrada_.second = j;
  }
  void set_salida(const int i, const int j) {
    salida_.first = i;
    salida_.second = j;
  }
  matrix_t<int>& get_laberinto() { return laberinto_; }
  void encontrar_camino(const bool& euclides);
  void vuelta_atras(const std::vector<Nodo*> nodos_cerrados);
  void encontrar_nodo_abierto(std::priority_queue<Nodo*, std::vector<Nodo*>, Nodo>& nodos_abiertos_, Nodo* swapnode);
  bool encontrar_nodo_cerrado(std::vector<Nodo*>& nodos_cerrados, Nodo* find_nodo);
  bool abiertos_repetido(std::priority_queue<Nodo*, std::vector<Nodo*>, Nodo>& nodos_abiertos_, Nodo* busq_nodo);
  void imprimir_nodos_abiertos(std::priority_queue<Nodo*, std::vector<Nodo*>, Nodo> nodos_abiertos_);
  void escritura_a_fichero(const std::vector<Nodo*> nodos_visitados, const std::vector<Nodo*> nodos_generados);
  //Atributos en público para poder ser directamente accedidos por los nodos
  std::pair<int, int> entrada_; // Coordenadas de la entrada (first = i_fila, second = j_col)
  std::pair<int, int> salida_;  // Coordenadas de la salida (first = i_fila, second = j_Col)

private:
  matrix_t<int> laberinto_; //Matriz con el laberinto
  std::queue<Nodo*> camino;
  int coste_total = 0;
};


#endif