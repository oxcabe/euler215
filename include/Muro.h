#ifndef MURO_H
#define MURO_H

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "Fila.h"

namespace CyA {

class Muro {
private:
  std::vector<Fila> filas_;
  unsigned int anchura_, altura_;
  void GenerarFilas(std::vector<Fila>& filas);

  void CombinarFilasEnMuro(std::vector<Fila> filasGeneradas);
  void CombinarFilasEnMuro(unsigned int profundidad, unsigned int posicion, std::vector<Fila> filasGeneradas);

  bool LadrillosCoinciden(Fila& fila1, Fila& fila2) const;

public:
  Muro() : filas_(), anchura_(0), altura_(0) {}
  Muro(unsigned int anchura, unsigned int altura) : filas_(),
    anchura_(anchura), altura_(altura) {}

  ~Muro() = default;

  void MeterFila(Fila& fila) { filas_.push_back(fila); }
  void VaciarMuro() { filas_.clear(); }

  void GenerarMurosPosibles();
  void GenerarMurosPosibles(unsigned int anchura, unsigned int altura);

  void imprimir(std::ostream& salida) const;

};

}

std::ostream& operator<<(std::ostream& salida, const CyA::Muro& muro);

#endif // MURO_H
