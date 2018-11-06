#ifndef FILA_H
#define FILA_H

#include <vector>
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include "Bloque.h"

namespace CyA {

class Fila {

private:
  std::vector<Bloque> bloques_;

public:
  Fila() : bloques_(10) {}
  Fila(unsigned int size) : bloques_(size) {}
  Fila(std::initializer_list<Bloque> lista) : bloques_(lista) {}
  Fila(std::initializer_list<std::pair<int,Bloque>> lista);

  ~Fila() = default;

  std::vector<Bloque>::iterator begin() { return bloques_.begin(); }
  std::vector<Bloque>::iterator end() { return bloques_.end(); }

  void imprimir(std::ostream& salida) const;

};


}
// Sobrecarga inserción
std::ostream& operator<<(std::ostream& salida, const CyA::Fila& fila);

#endif // FILA_H

/** 9 * 3:
* 128 muros generados
* de los cuales, 8 válidos
*/
