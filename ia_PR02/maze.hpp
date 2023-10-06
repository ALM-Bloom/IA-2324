/**
 * @file main.cpp
 * @author Alejandro M. L. (alu0101443126@ull.edu.es)
 * @brief Declaración de la función main principal
 * @version 0.1
 * @date 2023-10-04
 *
 * @copyright Alejandro M.L (c) 2022
 *
 */

#ifndef MAZE_HPP
#define MAZE_HPP
#include "matrix_t.hpp"
#include "nodo.hpp"
#include <utility>

class Maze {
public:
  Maze(const matrix_t<int> &laberinto) : laberinto_{laberinto} {}
  Maze() = default;
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
  int función_manhattan();
  void encontrar_camino();

private:
  int coste_acumulado_;  //g(n)
  matrix_t<int> laberinto_; //Matriz con el laberinto
  std::pair<int, int> entrada_; // Coordenadas de la entrada (first = i_fila, second = j_col)
  std::pair<int, int> salida_;  // Coordenadas de la salida (first = i_fila, second = j_Col)
};
#endif