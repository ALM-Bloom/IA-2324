/**
 * @file matrix.hpp
 * @author Alejandro M.L (alu0101443126@ull.edu.es)
 * @brief Definición de la clase Matrix y sus métodos. Este código ya ha sido utilizado en la asignatura
 *         "Algoritmos y Estructura de Datos"
 * @version 0.1
 * @date 2023-10-15
 *
 * @copyright Alejandro M.L (c) 2022
 *
 */

#pragma once
#include "vector_t.hpp"
#include <cassert>
#include <iostream>
using namespace std;

template <class T> class matrix_t {
public:
  matrix_t(const int = 0, const int = 0);
  ~matrix_t();

  void resize(const int, const int);

  // getters
  int get_m(void) const;
  int get_n(void) const;
  vector_t<T> get_row(const int) const; // copia una fila completa
  vector_t<T> get_col(const int) const; // copia una columna completa

  // getters-setters
  T &at(const int, const int);
  T &operator()(const int, const int);

  // getters constantes
  const T &at(const int, const int) const;
  const T &operator()(const int, const int) const;

  // operaciones y operadores
  void multiply(const matrix_t<T> &, const matrix_t<T> &);

  void write(ostream & = cout) const;
  void read(istream & = cin);

private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;

  int pos(const int, const int) const;
};

template <class T> matrix_t<T>::matrix_t(const int m, const int n) {
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}

template <class T> matrix_t<T>::~matrix_t() {}

template <class T> void matrix_t<T>::resize(const int m, const int n) {
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}

template <class T> inline int matrix_t<T>::get_m() const { return m_; }

template <class T> inline int matrix_t<T>::get_n() const { return n_; }

template <class T> vector_t<T> matrix_t<T>::get_row(const int i) const {
  assert(i > 0 && i <= get_m());
  vector_t<T> v(get_n());
  for (int j = 1; j <= get_n(); ++j)
    v[j - 1] = at(i, j);
  return v;
}

template <class T> vector_t<T> matrix_t<T>::get_col(const int j) const {
  assert(j > 0 && j <= get_n());
  vector_t<T> v(get_m());
  for (int i = 1; i <= get_m(); ++i)
    v[i - 1] = at(i, j);
  return v;
}

template <class T> T &matrix_t<T>::at(const int i, const int j) {
  return v_[pos(i, j)];
}

template <class T> T &matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}

template <class T> const T &matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}

template <class T>
const T &matrix_t<T>::operator()(const int i, const int j) const {
  return at(i, j);
}

template <class T> void matrix_t<T>::write(ostream &os) const {
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << " ";
    os << endl;
  }
  os << endl;
}

template <class T> void matrix_t<T>::read(istream &is) {
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}

template <class T> inline int matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}

template <class T>
void matrix_t<T>::multiply(const matrix_t<T> &A, const matrix_t<T> &B) {
  assert(A.get_n() == B.get_m());
  resize(A.get_m(), B.get_n());
  for (int i = 1; i <= A.get_m(); ++i)
    for (int j = 1; j <= B.get_n(); ++j) {
      at(i, j) = 0;
      for (int k = 1; k <= A.get_n(); ++k)
        at(i, j) = at(i, j) + A(i, k) * B(k, j);
    }
}

template <class T> ostream &operator<<(ostream &os, const matrix_t<T> &m) {
  m.write(os);
  return os;
}

template <class T> istream &operator>>(istream &is, matrix_t<T> &m) {
  m.read(is);
  return is;
}
