#include <iostream>
#include "rectangle.hpp"
#include "square.hpp" // Nótese que incluir square, incluye rectangle

int main(){

  Rectangle a(5.0, 2.0);
  Rectangle b(1.0, 2.0);

  // Llama al constructor copia de rectangle
  Rectangle c = a;
  // LLama al assignment operator de rectangle
  b = a;

  // Llama al constructor de square
  Square d(4.0);
  Square e(6.0);
  // Llama al constructor copia de rectangle, ya que Square no tiene uno definido
  Square f = d;
  // Igual con el assignment
  e = d;

  std::cout << "Después de esto se empiezan a llamar los destructores" << std::endl;

  return 0;
}
