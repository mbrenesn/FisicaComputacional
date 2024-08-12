#include <iostream>
 
int main(){
  
  int number1 = 88, number2 = 22;
 
  // Crear un puntero que apunta a number1
  std::cout << "Punteros" << std::endl;
  int *pNumber1 = &number1;  // Referenciación explícita
  *pNumber1 = 99;            // Dereferenciación explícita
  std::cout << *pNumber1 << std::endl;  // 99
  std::cout << &number1 << std::endl;   // Una dirección en memoria
  std::cout << pNumber1 << std::endl;   // La misma dirección en memoria
  std::cout << &pNumber1 << std::endl;  // La dirección en memoria DEL PUNTERO
  pNumber1 = &number2;      // El puntero se puede asignar a otra referencia
  
  // Crear una referencia a number1
  std::cout << "Referencias" << std::endl;
  int &refNumber1 = number1;  // Referencia implícita (NO SE PUEDE USAR &number1)
  refNumber1 = 11;            // Dereferenciación implícita (NO SE USA *refNumber1)
  std::cout << refNumber1 << std::endl;  // 11
  std::cout << &number1 << std::endl;    // Una dirección en memoria
  std::cout << &refNumber1 << std::endl; // La misma dirección en memoria
  //refNumber1 = &number2;   // Error! Las referencias no se pueden reasignar!
                             // error: conversión inválida de 'int*' a 'int'
  // Cuidado aquí!
  refNumber1 = number2;      // refNumber1 sigue siendo una referencia a number1!!!
                             // Esto asigna el valor de number2 (22) a refNumber1 y number1!
  number2++;   
  std::cout << refNumber1 << std::endl;  // 22
  std::cout << number1 << std::endl;     // 22
  std::cout << number2 << std::endl;     // 23

  return 0;
}
