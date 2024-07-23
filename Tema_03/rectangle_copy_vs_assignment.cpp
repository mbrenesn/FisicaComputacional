#include <iostream>

class Rectangle
{
  public:
    Rectangle(float a, float b); // Constructor personalizado
    Rectangle(const Rectangle &obj); // CONSTRUCTOR COPIA
    Rectangle &operator=(const Rectangle &obj); // OPERADOR ASIGNACIÓN
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

// Operador asignación
// Mucho ojo aquí que esto puede ser confuso
// El retorno de esta función es una referencia al objeto como tal
// Por eso usamos Rectangle &Rectangle...
// El puntero 'this' apunta a la referencia del objeto, por lo tanto,
// debemos dereferenciarlo para obtener la referencia del objeto
Rectangle &Rectangle::operator=(const Rectangle &obj){
  std::cout << "Assignment operator invoked!" << std::endl;

  width = obj.width;
  height = obj.height;

  return *this;
}

float Rectangle::area(){ // Implementación de la función miembro

  return width * height;
}

int main(){

  Rectangle a(5.0, 2.0);
  Rectangle b(1.0, 2.0);

  Rectangle c = a; // Esto llama al constructor de copia
  b = a; // Esto llama al operator de asignación

  return 0;
}


