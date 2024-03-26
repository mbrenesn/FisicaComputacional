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

  Rectangle a, *b, *c; // "b" y "c" son punteros a objectos de tipo Rectangle

  a.width = 5.0; // Acceso y modifico atributos
  a.height = 2.0;

  c = &a; // "c" apunta a "a"

  b = new Rectangle; // "b" apunta a un nuevo objecto creado en el heap
                     // sus miembros se accesan con un operador distinto: ->
  b->width = 2.0;
  b->height = 4.0;

  std::cout << a.area() << std::endl;
  std::cout << b->area() << std::endl;

  c->width = 12.0;
  std::cout << a.area() << std::endl; // Modificar "c" modifica "a"
  
  delete b; // "b" debe borrado del heap

  return 0;
}


