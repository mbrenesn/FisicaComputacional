#include <iostream>
#include <vector> // Puede no ser necesario, depende de la biblioteca instalada

int main(){

  std::vector<double> a;
  
  a.push_back(7.0);
  std::cout << "a: size " << a.size() << " capacity " << a.capacity() << std::endl;

  a.push_back(8.0);
  std::cout << "a: size " << a.size() << " capacity " << a.capacity() << std::endl;

  std::vector<double> b;
  b.reserve(8);
  std::cout << "b: size " << b.size() << " capacity " << b.capacity() << std::endl;

  std::vector<double> c(5); // constructor con tamaño en inicialización
  std::cout << "c: size " << c.size() << " capacity " << c.capacity() << std::endl;

  return 0;
}


