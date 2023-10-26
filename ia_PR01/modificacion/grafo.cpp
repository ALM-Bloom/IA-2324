/**
 * @file grafo.cpp
 * @author Alejandro M. L. (alu0101443126@ull.edu.es)
 * @brief Definición de la clase Grafo, almacena un vector de objetos tipo
 * "Nodo" y realiza operaciones de búsqueda, inserción o eliminación.
 * @version 0.1
 * @date 2023-05-16
 *
 * @copyright Alejandro M.L (c) 2022
 *
 */

#include "grafo.h"
#include "nodo.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <random>
#include <stdlib.h>
#include <chrono>
#include <time.h>

static bool parar_random = false;

void Grafo::SetArista(const int contnodo, const int nextnodo, const float arista) {
  vecgrafo[contnodo]->InsertarArista(vecgrafo[nextnodo], arista);
  vecgrafo[nextnodo]->InsertarArista(vecgrafo[contnodo], arista);
}

bool Grafo::Insercion(Nodo *novonodo) {
  vecgrafo.emplace_back(novonodo);
  return true;
}

void Grafo::RandomBFS(int id_origen, const int id_destino) {
  static int cont_random = 0;
  cont_random++;
  int randNum = rand() % 4;
  std::cout << "Nodo Random elegido: " << randNum << std::endl;
  // BusquedaBfs(vecgrafo[id_origen]->GetVector()[randNum].first->GetId(), id_destino);
  // if (cont_random == 10) {
  //   std::cerr << "No existe camino" << std::endl;
  //   return;
  // }
  RandomBFS(id_origen, id_destino);
}
void Grafo::BusquedaBfs(const int id_origen, const int id_destino) {
  //Declaración de los vectores generadores del resultado
  std::vector<int> generados;
  static std::vector<int> inspect;
  std::stack<int> camino;
  //Declaración de la cola
  std::queue<int> cola_no_visitados;
  //Acumulador del coste.
  float coste_total = 0;
  static int padre_original = id_origen;
  generados.emplace_back(id_origen);
  cola_no_visitados.push(id_origen);
  //Se establece al nodo origen el padre NULL
  vecgrafo[id_origen - 1]->SetPadre(nullptr);
  while (!cola_no_visitados.empty()) { //Mientras la cola no esté vacía
    int iterator = cola_no_visitados.front() - 1; //El iterator funciona a -1 del id del Nodo para acceder correctamente al vector
    inspect.emplace_back(vecgrafo[iterator]->GetId()); //Se inserta el nodo en el vector de visitados.
    if (cola_no_visitados.front() == id_destino) { //Si el valor sacado de la cola es el nodo destino
      Nodo *nodo = vecgrafo[iterator]; 
      while (nodo->GetPadre() != nullptr) { //Mientras el nodo previo al actual no apunte a NULL
        camino.push(nodo->GetId()); //Se añade el nodo al camino
        coste_total += nodo->buscar_arista(nodo->GetPadre()->GetId()); //Búsqueda de la arista que conecta al nodo previo y el actual
        nodo = nodo->GetPadre(); //Puntero cambia al nodo previo
      }
      camino.push(id_origen); //El nodo de partida pertenece al camino de base
      Escritura(inspect, generados, camino, coste_total); //Envío de los datos al método de escritura
      return; //EOF
    }
    vecgrafo[iterator]->set_visitado(true); //Se establece el nodo que se está estudiando como visitado
    for (int i = 0; i < vecgrafo[iterator]->GetVector().size(); i++) { //Recorrido de la adyacencia del nodo
      if (!vecgrafo[iterator]->GetVector()[i].first->is_visitado()) { //Si el nodo adyacente no ha sido visitado
        vecgrafo[iterator]->GetVector()[i].first->SetPadre(vecgrafo[iterator]); //Se establece como nodo previo el nodo que se está estudiando
        generados.emplace_back(vecgrafo[iterator]->GetVector()[i].first->GetId());  //El nodo adyacente se ha generado
    //  vecgrafo[iterator]->GetVector()[i].first->set_visitado(true); 
        cola_no_visitados.push(vecgrafo[iterator]->GetVector()[i].first->GetId()); //Se mete en la cola el nodo generado
      }
    }
    cola_no_visitados.pop(); //Se extrae el nodo estudiado de la cola
  }
  std::cerr << "No encontrado en esta pasada" << std::endl;
  Escritura(inspect, generados, camino, coste_total); //Envío de los datos al método de escritura
}

void Grafo::BusquedaDfs(const int id_origen, const int id_destino) {
  //Declaración de los vectores/ generadores del resultado
  std::vector<int> inspect, generados;
  std::stack<int> camino;
  //Declaración de la pila
  std::stack<int> cola_no_visitados;
  //Acumulador del coste total
  float coste_total = 0; 
  generados.emplace_back(id_origen); //El nodo de origen cuenta como generado
  cola_no_visitados.push(id_origen); //Se introduce en la pila el nodo de partida
  vecgrafo[id_origen - 1]->SetPadre(nullptr); //Se establece como nodo previo del origen NULL, ya que es el nodo raíz
  while (!cola_no_visitados.empty()) { //Mientras la pila no esté vacía
    int iterator = cola_no_visitados.top() - 1; //El iterador funciona a -1 del id del Nodo
    inspect.emplace_back(vecgrafo[iterator]->GetId()); //Se introduce en visitados el nodo que se estudia
    if (cola_no_visitados.top() == id_destino) { //Si se ha extraído de la pila el nodo destino
      Nodo *nodo = vecgrafo[iterator]; //Se establece el nodo iterador como el nodo destino para la "vuelta atrás"
      while (nodo->GetPadre() != nullptr) { //Hasta que se encuentre el nodo que apunta a NULL
        camino.push(nodo->GetId()); //Se introduce el nodo en la pila de camino
        coste_total += nodo->buscar_arista(nodo->GetPadre()->GetId()); //Se encuentra la arista y se suma al acumulador
        nodo = nodo->GetPadre(); //El nodo iterador apunta al nodo previo de éste
      }
      camino.push(id_origen); //El nodo de origen va a formar parte del camino
      Escritura(inspect, generados, camino, coste_total); //Llamada al método de Escritura
      return; //EOF
    }
    vecgrafo[iterator]->set_visitado(true); //Se establece como visitado el nodo estudiado
    cola_no_visitados.pop(); //Se extrae el nodo estudiado de la pila
    for (int i = 0; i < vecgrafo[iterator]->GetVector().size(); i++) { //Bucle de estudio de la adyacencia
      if (!vecgrafo[iterator]->GetVector()[i].first->is_visitado()) { //Si el nodo vecino no ha sido estudiado
        vecgrafo[iterator]->GetVector()[i].first->SetPadre(vecgrafo[iterator]);
        generados.emplace_back(vecgrafo[iterator]->GetVector()[i].first->GetId());
        //  vecgrafo[iterator]->GetVector()[i].first->set_visitado(true);
        cola_no_visitados.push(vecgrafo[iterator]->GetVector()[i].first->GetId());
      }
    }
  }
  std::cerr << "No se ha encontrado solución" << std::endl; //Si se finaliza el algoritmo entonces no se ha encontrado camino
  Escritura(inspect, generados, camino, coste_total); //Envío de los datos al método de escritura
}

void Grafo::Escritura(const std::vector<int> &visitados, const std::vector<int> &generados, std::stack<int> &camino, const float coste) {
  std::ofstream fichero;
  fichero.open("solucion.txt", std::ios::out);
  fichero << "Camino: ";
  if (camino.empty()) {
    fichero << "No existe camino";
  }
  while (!camino.empty()) {
    fichero << camino.top();
    if (camino.size() != 1) {
      fichero << ", ";
    }
    camino.pop();
  }
    fichero << std::endl;
  fichero << "Generados: ";
  for (int i = 0; i < generados.size(); i++) {
    fichero << generados[i];
    if (i != generados.size() - 1) {
      fichero << ", ";
    }
  }
  fichero << std::endl;
  fichero << "Visitados: ";
  for (int i = 0; i < visitados.size(); i++) {
    fichero << visitados[i];
    if (i != visitados.size() - 1) {
      fichero << ", ";
    }
  }
    fichero << std::endl;
  fichero << "Coste: " << coste;
  fichero << std::endl;
  return;
}