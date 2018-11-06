#include <iostream>
#include "include/Muro.h"

int main(int argc, char* argv[]) {

  unsigned int filas, columnas, bloque_uno, bloque_dos;

  std::cout << "Filas: "; std::cin >> filas;
  std::cout << "Columnas: "; std::cin >> columnas;
  std::cout << "Tamaño bloque 1: "; std::cin >> bloque_uno;
  std::cout << "Tamaño bloque 2: "; std::cin >> bloque_dos;

  std::cout << "\nResultado: \n";

  CyA::Muro muro(filas, columnas, bloque_uno, bloque_dos);

  muro.GenerarMurosPosibles();


}
