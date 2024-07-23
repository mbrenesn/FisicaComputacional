#include <iostream>

class Rectangle
{
  public:
    Rectangle(float a, float b); // Constructor personalizado
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

float Rectangle::area(){ // Implementación de la función miembro

  return width * height;
}

int main(){

  Rectangle a(5.0, 2.0);
  std::cout << a.area() << std::endl;

  // Rectangle b; // Esto no compila, el constructor base es privado
  
  return 0;
}


