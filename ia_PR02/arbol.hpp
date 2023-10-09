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

#ifndef ARBOL_HPP
#define ARBOL_HPP
#include "nodo.hpp"

class Arbol {
  public:
    Arbol() = default;
    void set_padre(Nodo* newnodo) { rey_ = newnodo; }
    Nodo* get_padre() { return rey_; }
    
  private:
    Nodo* rey_;
};
#endif
