#include <iostream>

class MyClass
{
  public:
    int a;
  private:
    int b;
};

int main(){

  MyClass m;

  m.a = 4; // Esto está bien
  m.b = 3; // Error de compilación: b es privado

  return 0;
}


