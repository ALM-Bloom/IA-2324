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

#include "nodo.h"
#include <iostream>
#include <utility>

void Nodo::InsertarArista(Nodo *newnodo, const float arista) {
  vecaristas.emplace_back(std::pair<Nodo *, float>(newnodo, arista));
}