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

#include "matrix_t.hpp"
#include "maze.hpp"
#include "nodo.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  std::string infile = argv[1];
  matrix_t<int> camino;
  int cont_line = 0, num_fil, num_col, lec_fila = 1, lec_col = 1;
  std::ifstream file(infile);
  std::string lectura;
  Maze laberinto;
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
        camino.at(lec_fila, lec_col) = lectura[0] - '0';
        if (lectura[0] - '0' == 3) {
          laberinto.set_entrada(lec_fila, lec_col);
        }
        if (lectura[0] - '0' == 4) {
          laberinto.set_entrada(lec_fila, lec_col);
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
  laberinto.set_matrix(camino);
  std::cout << laberinto.get_laberinto() << std::endl;
}