#include "../include/Fila.h"


namespace CyA {

Fila::Fila(std::initializer_list<std::pair<int,Bloque>> lista) {
  for (auto& par : lista) {
    for (int i = 0; i < par.first; ++i) {
      bloques_.push_back(par.second);
    }
  }
}

void Fila::imprimir(std::ostream& out) const {
  out << '|';
  for (const Bloque& bloque : bloques_) {
    out << bloque << '|';
  }
}

}

std::ostream& operator<<(std::ostream& salida, const CyA::Fila& fila) {
  fila.imprimir(salida);
  return salida;
}
