#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "rectangle.hpp" // Debemos incluir la clase pariente!!

// En este caso no vamos a seguir la regla de 3 dado que la clase no maneja un recurso
// Sin embargo, en general, deberíamos hacerlo.
// La herencia en este caso se realiza para tener acceso a los miembros height y width; y al método
// area()

class Square : public Rectangle
{
  public:
    Square(float a);
    ~Square();
    float inscribed_area();
  private:
    Square();
};
#endif
