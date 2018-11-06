#ifndef BLOQUE_H
#define BLOQUE_H

#include <iostream>

namespace CyA {

class Bloque {
private:
  unsigned int valor_;

public:
  Bloque() = default;
  Bloque(unsigned int valor) : valor_(valor) {}

  ~Bloque() = default;

  unsigned int getValor();
  void setValor(unsigned int valor);

  operator int() const { return valor_; }

  void imprimir(std::ostream& salida) const;

};

}

std::ostream& operator<<(std::ostream& salida, const CyA::Bloque& bloque);

#endif // BLOQUE_H
