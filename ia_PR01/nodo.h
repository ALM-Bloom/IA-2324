/**
 * @file nodo.h
 * @author Alejandro M. L. (alu0101443126@ull.edu.es)
 * @brief Declaración de la clase Nodo, que es responsable de almacenar el coste
 * y adicionalmente, el nodo adyacente. Por ende, la estructura de la clase
 * sería: Nodo = {costo, siguiente nodo}, donde siguiente nodo pudiera ser Null
 * si no existe adyacencia.
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Alejandro M.L (c) 2022
 *
 */

#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <utility>
#include <vector>

class Nodo {
public:
  Nodo(const unsigned id) : id_{id}, visitado_{false} {}
  Nodo() = default;
  void InsertarArista(Nodo *newnodo, const float arista);
  unsigned GetId() const { return id_; }
  Nodo *GetNodo(const int posicion) { return vecaristas[posicion].first; }
  std::vector<std::pair<Nodo *, float>> GetVector() { return vecaristas; }
  bool is_visitado() { return visitado_; }
  void set_visitado(bool visitado) { visitado_ = visitado; }
  void SetPadre(Nodo *nodoprev) { nodoprev_ = nodoprev; }
  Nodo *GetPadre() { return nodoprev_; }
  float buscar_arista(const int id);
    
private:
  std::vector<std::pair<Nodo *, float>> vecaristas;
  unsigned id_;
  Nodo *nodoprev_;
  bool visitado_;
};

#endif