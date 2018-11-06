#include "../include/Bloque.h"

namespace CyA {

unsigned int Bloque::getValor() {
  return valor_;
}

void Bloque::setValor(unsigned int valor) {
  valor_ = valor;
}

void Bloque::imprimir(std::ostream& salida) const {
  for (unsigned int i = 0; i < valor_; ++i) {
    salida << 'x';
  }
}

}

std::ostream& operator<<(std::ostream& salida, const CyA::Bloque& bloque) {
  bloque.imprimir(salida);
  return salida;
}
