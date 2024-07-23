#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle
{
  public:
    float width, height;
    float area();
    ~Rectangle(); // Destructor
    Rectangle(float a, float b); // Custom constructor
    Rectangle(const Rectangle &obj); // Copy constructor
    Rectangle &operator=(const Rectangle &obj); // Assignment operator
  protected:
    Rectangle(); // Visible para clases derivadas, pero no fuera de la clase
};
#endif
