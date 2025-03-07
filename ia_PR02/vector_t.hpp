/**
 * @file matrix.hpp
 * @author Alejandro M.L (alu0101443126@ull.edu.es)
 * @brief Definición de la clase Vector y sus métodos. Este código ya ha sido utilizado en la asignatura
 *         "Algoritmos y Estructura de Datos"
 * @version 0.1
 * @date 2023-10-15
 *
 * @copyright Alejandro M.L (c) 2022
 *
 */

#pragma once
#include <cassert>
#include <iostream>
using namespace std;

template <class T> class vector_t {
public:
  vector_t(const int = 0);
  vector_t(const vector_t &);                  // constructor de copia
  vector_t<T> &operator=(const vector_t<T> &); // operador de asignación
  ~vector_t();

  void resize(const int);

  // getters
  T get_val(const int) const;
  int get_size(void) const;

  // setters
  void set_val(const int, const T);

  // getters-setters
  T &at(const int);
  T &operator[](const int);

  // getters constantes
  const T &at(const int) const;
  const T &operator[](const int) const;

  void write(ostream & = cout) const;
  void read(istream & = cin);

private:
  T *v_;
  int sz_;

  void build(void);
  void destroy(void);
};

template <class T> vector_t<T>::vector_t(const int n) : v_(NULL), sz_(n) {
  build();
}

// constructor de copia
template <class T> vector_t<T>::vector_t(const vector_t<T> &w) { *this = w; }

// operador de asignación
template <class T> vector_t<T> &vector_t<T>::operator=(const vector_t<T> &w) {
  resize(w.get_size());
  for (int i = 0; i < get_size(); ++i)
    at(i) = w.at(i);

  return *this;
}

template <class T> vector_t<T>::~vector_t() { destroy(); }

template <class T> void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

template <class T> void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

template <class T> void vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}

template <class T> inline T vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T> inline int vector_t<T>::get_size() const { return sz_; }

template <class T> void vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

template <class T> T &vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T> T &vector_t<T>::operator[](const int i) { return at(i); }

template <class T> const T &vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

template <class T> const T &vector_t<T>::operator[](const int i) const {
  return at(i);
}

template <class T> void vector_t<T>::write(ostream &os) const {
  os << get_size() << ": [ ";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << (i != get_size() - 1 ? "\t" : "");
  os << " ]" << endl;
}

template <class T> void vector_t<T>::read(istream &is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}

template <class T> ostream &operator<<(ostream &os, const vector_t<T> &v) {
  v.write(os);
  return os;
}

template <class T> istream &operator>>(istream &is, vector_t<T> &v) {
  v.read(is);
  return is;
}