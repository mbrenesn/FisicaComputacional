#include <iostream>

class Rectangle
{
  public:
    float width; // Atributos
    float height;
    float area(); // Declaración de una función miembro
};

float Rectangle::area(){ // Implementación de la función miembro

  return width * height;
}

int main(){

  Rectangle a;

  Rectangle &c = a; // "c" es una referencia a "a"

  a.width = 5.0; // Acceso y modifico atributos
  a.height = 2.0;

  std::cout << a.area() << std::endl;

  c.width = 12.0; // Modificar "c" modifica "a"
                  // Nótese que usamos el operador "." en lugar de "->"
  std::cout << a.area() << std::endl; // Modificar "c" modifica "a"
  
  return 0;
}


