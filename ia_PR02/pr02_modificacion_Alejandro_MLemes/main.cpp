/**
 * @file main.cpp
 * @author Alejandro M. L. (alu0101443126@ull.edu.es)
 * @brief Declaración de la función main principal
 * @version 0.1
 * @date 2023-10-18
 *
 * @copyright Alejandro M.L (c) 2022
 *
 */

#include "matrix_t.hpp"
#include "nodo.hpp"
#include "maze.hpp"
#include <fstream>
#include <iostream>
#include <utility>

int main(int argc, char *argv[]) {
  std::string infile = argv[1];
  matrix_t<int> camino;
  int cont_line = 0, num_fil, num_col, lec_fila = 1, lec_col = 1, opcion;
  int lec_entrada, lec_salida;
  bool indicar_teclado = false, euclides = false;
  std::ifstream file(infile);
  std::string lectura;
  Maze laberinto;
  std::cout << "¿Desea indicar la salida y entrada del laberinto por teclado? (1) Sí (2) No" << std::endl;
  std::cin >> opcion;
  if (opcion == 1) {
    indicar_teclado = true;
  }
  if (file.is_open()) {
    while (file >> lectura) {
      if (cont_line == 0) {
        num_fil = std::stoi(lectura);
      } else if (cont_line == 1) {
        num_col = std::stoi(lectura);
      } else if (cont_line == 2) {
        camino.resize(num_fil, num_col);
      }
      if (cont_line > 1) {
        if (lectura[0] - '0' == 3 && indicar_teclado == false) {
          laberinto.set_entrada(lec_fila, lec_col);
          camino.at(lec_fila, lec_col) = lectura[0] - '0';
        }
        if (lectura[0] - '0' == 4 && indicar_teclado == false) {
          laberinto.set_salida(lec_fila, lec_col);
          camino.at(lec_fila, lec_col) = lectura[0] - '0';
        }
        if (lectura[0] - '0' != 3 && lectura[0] - '0' != 4) {
          camino.at(lec_fila, lec_col) = lectura[0] - '0';
        }
        if (lectura[0] - '0' == 3 && indicar_teclado == true) {
          camino.at(lec_fila, lec_col) = 1;
        } 
        if (lectura[0] - '0' == 4 && indicar_teclado == true) {
          camino.at(lec_fila, lec_col) = 1;
        }
        lec_col++;
        if (lec_col > num_col) {
          lec_col = 1;
          lec_fila++;
        }
      }
      cont_line++;
    }
  }
  if (opcion == 1) {
    std::cout << "Introduzca las coordenadas de la entrada" << std::endl;
    std::cin >> lec_entrada;
    std::cin >> lec_salida;
    laberinto.set_entrada(lec_entrada, lec_salida);
    camino.at(lec_entrada, lec_salida) = 3;
    std::cout << "Introduzca las coordenadas de la salida" << std::endl;
    std::cin >> lec_entrada;
    std::cin >> lec_salida;
    laberinto.set_salida(lec_entrada, lec_salida);
    camino.at(lec_entrada, lec_salida) = 4;
  }
  laberinto.set_matrix(camino);
  std::cout << laberinto.get_laberinto();
  std::cout << "Desea usar la heurística de Euclides (1) o heurística de Manhattan (2): ";
  std::cin >> opcion;
  if (opcion == 1) {
    euclides = true;
    laberinto.encontrar_camino(euclides);
  } else {
    laberinto.encontrar_camino(euclides);
  }
  std::cout << laberinto.get_laberinto() << std::endl;
}