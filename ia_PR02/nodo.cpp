/**
 * @file nodo.cpp
 * @author Alejandro M.L (alu0101443126@ull.edu.es)
 * @brief Definición de la clase Nodo y sus métodos. Tales como comprobar si su
 * adyacencia es nula o realizar el recorrido en amplitud.
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Alejandro M.L (c) 2022
 *
 */

#include "nodo.hpp"
#include "maze.hpp"
#include <iostream>
#include <utility>

void Nodo::obtener_fn(const Maze &lab, const int acumulado_previo) {
  int h_n = 0, g_n = 0;
  // std::cout << "Coordenadas del nodo: " << coord_i_ << "," << coord_j_ << std::endl;
  if (lab.salida_.first > coord_i_) {
    for (int i = coord_i_; i < lab.salida_.first; i++) {
      h_n += 3;
    }
  } else if (lab.salida_.first < coord_i_) {
    for (int i = coord_i_; i > lab.salida_.first; i--) {
      h_n += 3;
    }
  }
  if (lab.salida_.second > coord_j_) {
    for (int i = coord_j_; i < lab.salida_.second; i++) {
      h_n += 3;
    }
  } else if (lab.salida_.second < coord_j_) {
    for (int i = coord_j_; i > lab.salida_.second; i--) {
      h_n += 3;
    }
  }
  if (is_diag_ == 1) {
    g_n = acumulado_previo + 7;
  } else if (is_diag_ == 0) {
    g_n = acumulado_previo + 5;
  }
  acumulado_propio_ = g_n;
  funcion_movimiento_ = h_n + g_n;
  // std::cout << "Encontrada h(n) con valor: " << h_n << std::endl;
  // std::cout << "Encontrada g(n) con valor: " << g_n << std::endl;
  // std::cout << "F(n) es " << funcion_movimiento_ << std::endl;
}
