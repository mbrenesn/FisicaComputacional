#include <iostream>
 
// Nótese que esta función toma como argumento un puntero y no tiene valor de retorno!
// Comparar con pasar_por_valor.cpp
void square(int *pNumber){
  
  std::cout <<  "Dentro de la función square(): " << pNumber << std::endl;  // Una referencia de memoria
  *pNumber *= *pNumber;  // Mucho ojo con esta expresión
                         // Primero, dereferenciamos el puntero con el operador *
                         // Luego, multiplicamos el valor por si mismo
                         // Por último, asignamos el valor al cual la referencia apunta a este último valor:
                         // el resultado de la multiplicación
}

int main(){
  
  int number = 8;
  std::cout <<  "Dentro de main(): " << &number << std::endl;  // Una referencia de memoria
                                                               // La misma que existe dentro de la función
                                                               // square()
  std::cout << number << std::endl;   // El valor de la referencia: 8
  square(&number);          // Referencia explícita de number
                            // Nótese que la función square espera una referencia de memoria,
                            // no un valor
  std::cout << number << std::endl;   // 64

  return 0;
}
 
