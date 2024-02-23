#include <iostream>
 
// Nótese que esta función toma como argumento una referencia y no tiene valor de retorno!
// Comparar con pasar_por_valor.cpp
void square(int &rNumber){
  
  std::cout <<  "Dentro de la función square(): " << &rNumber << std::endl;  // Una referencia de memoria
  rNumber *= rNumber;  // Dereferenciación implícita
                       // Recordemos que accesar rNumber no accesa la referencia, sino su valor
                       // La diferencia con pasar_por_valor.cpp es que en esta función estamos
                       // usando la referencia del argumento, no su valor!
}

int main(){
  
  int number = 8;
  std::cout <<  "Dentro de main(): " << &number << std::endl;  // Una referencia de memoria
                                                               // La misma que existe dentro de la función
                                                               // square()
  std::cout << number << std::endl;   // El valor de la referencia: 8
  square(number);           // Referencia implícita de number
                            // La función toma la referencia del argumento, no su valor!
                            // Aquí hay que tener cuidado. Las referencias se inicializan durante 
                            // la declaración.
                            // En el caso de la función square(), la referencia se inicia cuando la función
                            // es invocada, con la referencia del argumento de la función
                            // Esto puede ser confuso. square(&number) resulta en un error!
                            // Esto se debe a que la referenciación y dereferenciación 
                            // ocurren de manera implícita
  std::cout << number << std::endl;   // 64

  return 0;
}
 

