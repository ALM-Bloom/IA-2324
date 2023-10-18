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
#include <cmath>

/// @brief Método que calcula el h(n) {Manhattan} y g(n) de un nodo y obtiene el f(n) asociándolo al atributo del nodo
/// @param lab El propio laberinto que contiene las coordenadas de la entrada y salida cruciales para el cálculo de h(n)
/// @param acumulado_previo El g(n) del nodo padre
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
}

/// @brief Método que obtiene el f(n) mediante la suma de g(n) y h(n) {Euclides} mediante la relación triangular
/// @param lab El propio laberinto del que se sacan las coordenadas del destino (la salida)
/// @param acumulado_previo El g(n) del nodo padre
void Nodo::obtener_fn_alternativo(const Maze& lab, const int acumulado_previo) {
  int h_n = 0, g_n = 0;
  int i1 = coord_i_;
  int j1 = coord_j_;
  int i2 = lab.salida_.first;
  int j2 = lab.salida_.second;
  // Cálculo de la distancia euclidiana entre el nodo actual y el nodo objetivo
  h_n = std::sqrt((i2 - i1) * (i2 - i1) + (j2 - j1) * (j2 - j1));
  if (is_diag_ == 1) {
    g_n = acumulado_previo + 7;
  } else if (is_diag_ == 0) {
    g_n = acumulado_previo + 5;
  }
  acumulado_propio_ = g_n;
  funcion_movimiento_ = h_n + g_n;
}