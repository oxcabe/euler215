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
  Bloque bloque_uno_, bloque_dos_;
  void GenerarFilas(std::vector<Fila>& filas);

  void CombinarFilasEnMuro(std::vector<Fila> filasGeneradas);
  void CombinarFilasEnMuro(unsigned int profundidad, unsigned int posicion, std::vector<Fila> filasGeneradas);

  bool LadrillosCoinciden(Fila& fila1, Fila& fila2) const;

public:
  Muro() : filas_(), anchura_(0), altura_(0), bloque_uno_(2), bloque_dos_(3) {}
  Muro(unsigned int anchura, unsigned int altura) : filas_(),
    anchura_(anchura), altura_(altura), bloque_uno_(2), bloque_dos_(3) {}
  Muro(unsigned int anchura, unsigned int altura, unsigned int bloque_uno, unsigned int bloque_dos) :
    filas_(), anchura_(anchura), altura_(altura), bloque_uno_(bloque_uno), bloque_dos_(bloque_dos) {}

  ~Muro() = default;

  void GenerarMurosPosibles();
  void GenerarMurosPosibles(unsigned int anchura, unsigned int altura);

  void imprimir(std::ostream& salida) const;

};

}

std::ostream& operator<<(std::ostream& salida, const CyA::Muro& muro);

#endif // MURO_H
