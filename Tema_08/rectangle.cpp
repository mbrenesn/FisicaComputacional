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

  Rectangle a; // Construcción por defecto

  a.width = 5.0; // Acceso y modifico atributos
  a.height = 2.0;

  std::cout << a.area() << std::endl; // Invocación de la función miembro

  return 0;
}


