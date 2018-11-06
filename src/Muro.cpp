#include "../include/Muro.h"

namespace CyA {

void Muro::GenerarFilas(std::vector<Fila>& filas) {

  for (unsigned int i = 0; i * bloque_uno_ <= anchura_; ++i) {
    for (unsigned int j = 0; ((j * bloque_dos_) + (i * bloque_uno_)) <= anchura_; ++j) {
      // std::cout << "Bloques de tres: " << i << ", Bloques de dos: " << j << ".\n";
      if ((j * bloque_dos_) + (i * bloque_uno_) == anchura_) {

        Fila helper = {std::pair<int, Bloque>(i, bloque_uno_), std::pair<int, Bloque>(j, bloque_dos_)};
        do {
          filas.push_back(helper);
        } while (std::next_permutation(helper.begin(), helper.end()));
      }
    }
  }

}


void Muro::CombinarFilasEnMuro(std::vector<Fila> filasGeneradas) {

  CombinarFilasEnMuro(0, 0, filasGeneradas);

}

void Muro::CombinarFilasEnMuro(unsigned int profundidad, unsigned int posicion,
  std::vector<Fila> filasGeneradas) {

  if (profundidad == altura_) {
    std::cout << *this << '\n';
  } else {
    for (unsigned int i = 0; i < filasGeneradas.size(); ++i) {
      if (filas_.empty()) {
        filas_.push_back(filasGeneradas[i]);
        CombinarFilasEnMuro(profundidad + 1, i, filasGeneradas);
        filas_.pop_back();
      } else {
        if (!LadrillosCoinciden(filas_.back(), filasGeneradas[i])) {
          filas_.push_back(filasGeneradas[i]);
          CombinarFilasEnMuro(profundidad + 1, i, filasGeneradas);
          filas_.pop_back();
        } else {

        }
      }
    }
  }

}

bool Muro::LadrillosCoinciden(Fila& fila1, Fila& fila2) const {

  std::vector<Bloque>::iterator fila1_it = fila1.begin();
  std::vector<Bloque>::iterator fila2_it = fila2.begin();

  unsigned int fila1_acumulador = (*fila1_it), fila2_acumulador = (*fila2_it);

  while (fila1_acumulador != anchura_ || fila2_acumulador != anchura_) {

    if (fila1_acumulador > fila2_acumulador) {
      ++fila2_it;
      fila2_acumulador += (*fila2_it);
    } else if (fila1_acumulador < fila2_acumulador) {
      ++fila1_it;
      fila1_acumulador += (*fila1_it);
    } else {
      return true;
    }
  }
  return false;
}


void Muro::GenerarMurosPosibles() {
  std::vector<Fila> filasGeneradas;

  GenerarFilas(filasGeneradas);
  CombinarFilasEnMuro(filasGeneradas);

}

void Muro::GenerarMurosPosibles(unsigned int anchura, unsigned int altura) {
  anchura_ = anchura;
  altura_ = altura;

  GenerarMurosPosibles();
}

void Muro::imprimir(std::ostream& salida) const {
  for (const Fila& fila : filas_) {
    salida << fila << '\n';
  }
}

}

std::ostream& operator<<(std::ostream& salida, const CyA::Muro& muro) {
  muro.imprimir(salida);
  return salida;
}
