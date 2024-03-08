#include <iostream>
#include <iterator>

int main(){

  std::vector<double> a(5, 0.0);
  for(int i = 0; i < 5; ++i) a[i] = static_cast<double>(i); // Conversión de tipos

  std::vector<double>::iterator myIt;
  for(myIt = a.begin(); myIt != a.end(); ++myIt) 
  // El puntero se asigna al inicio y se itera hasta que se llega al final
    std::cout << *myIt << std::endl; // Dereferenciación
  std::cout << std::endl;

  a.erase(a.begin(), a.begin() + 2); // Borramos un rango del arreglo
  for(myIt = a.begin(); myIt != a.end(); ++myIt) 
    std::cout << *myIt << std::endl;
  std::cout << std::endl;

  myIt = a.begin() + 1;
  std::cout << *(myIt + 2) << std::endl;
  std::cout << myIt[2] << std::endl;

  return 0;
}


