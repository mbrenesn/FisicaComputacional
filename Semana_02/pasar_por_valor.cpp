#include <iostream>
 
int square(int n){
  
  std::cout <<  "Dentro de la función square(): " << &n << std::endl;  // Referencia de memoria
  n *= n;  // Esta expresión no tiene que ver con punteros. El operador * es de multiplicación
           // Esta expresión es una forma compacta de escribir n = n * n
           // Esto significa: multiplicar n por si mismo, y asignarlo a n
           // En este scope, n es una copia del argumento!!!
 
  return n; // El valor de n se retorna por valor.
}

int main(){

  int number = 8;
   
  std::cout <<  "Dentro de main(): " << &number << std::endl;  // Referencia de memoria
  std::cout << number << std::endl;         // 8
  std::cout << square(number) << std::endl; // 64
  std::cout << number << std::endl;         // 8 - number no cambia porque la función usa una copia 
                                            // y la retorna!
  return 0;
}


