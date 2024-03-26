#include <iostream>

class Rectangle
{
  public:
    Rectangle(float a, float b); // Constructor personalizado
    Rectangle(const Rectangle &obj); // CONSTRUCTOR COPIA
    float width; // Atributos
    float height;
    float area(); // Declaración de una función miembro

  private:
    Rectangle(); // El constructor base puede ser escondido como
                 // privado, de manera tal que no se pueda construir
                 // un rectángulo sin dimensiones
};

Rectangle::Rectangle(float a, float b){
  width = a;
  height = b;
}

Rectangle::Rectangle(){ // El constructor base se deja vacío

}

// Constructor copia
Rectangle::Rectangle(const Rectangle &obj){
  std::cout << "Copy constructor invoked!" << std::endl;

  width = obj.width;
  height = obj.height;
}

float Rectangle::area(){ // Implementación de la función miembro

  return width * height;
}

int main(){

  Rectangle a(5.0, 2.0);

  Rectangle b = Rectangle(a); // Esto invoca el constructor copia
  Rectangle c = a; // Esto también

  std::cout << a.area() << std::endl;
  std::cout << b.area() << std::endl;
  std::cout << c.area() << std::endl;
  
  return 0;
}


