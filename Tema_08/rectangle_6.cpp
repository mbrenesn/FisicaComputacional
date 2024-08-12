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

// Nótese que esta función no tiene el decorador Rectangle::
// Esta función NO es un método de la clase Rectangle,
// es una función global común y corriente
void print_info(Rectangle a){
  std::cout << "Width: " << a.width << " height: " << a.height << std::endl;
}

int main(){

  Rectangle a(5.0, 2.0);

  // El objeto "a" de tipo Rectangle se pasa a esta función por valor!
  // Es decir, print_info hace una copia local de "a" en el stack
  // y, por ende, el constructor copia es invocado
  print_info(a);
  
  return 0;
}


