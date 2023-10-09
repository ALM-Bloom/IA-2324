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

void Nodo::obtener_fn(const Maze& lab, bool is_diag) { 
  int h_n = 0, g_n = 0;
  std::cout << "Coordenadas del nodo: " << coord_i_ << "," << coord_j_ << std::endl;
  std::cout << "Coordenadas destino: " << lab.salida_.first << "," << lab.salida_.second << std::endl;
  if (lab.salida_.first > coord_i_) {
  for (int i = coord_i_; i < lab.salida_.first; i++) {
      h_n += 3;
  }
  } else if (lab.salida_.first < coord_i_) {
  for (int i = coord_i_; i < lab.salida_.first; i--) {
      h_n += 3;
  }
  }
  if (lab.salida_.second > coord_j_) {
  for (int i = coord_j_; i < lab.salida_.second; i++) {
      h_n += 3;
  }
  }
  else if (lab.salida_.second < coord_j_) {
  for (int i = coord_j_; i < lab.salida_.second; i--) {
      h_n += 3;
  }
}
  if (is_diag == true) {
    g_n = lab.coste_acumulado_ + 7;
  } else {
    g_n = lab.coste_acumulado_ + 5;
  }
  std::cout << "Encontrada h(n) con valor: " << h_n << std::endl;
  std::cout << "Encontrada g(n) con valor: " << g_n << std::endl;
  funcion_movimiento_ = h_n + g_n;
  std::cout << "F(n) es " << funcion_movimiento_ << std::endl;
}