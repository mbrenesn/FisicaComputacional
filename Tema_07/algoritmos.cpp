#include <iostream>
#include <algorithm>
#include <vector>

void print(int i){
  std::cout << " " << i;
}

int main(){

  std::vector<int> a;
  for(int i = 0; i < 5; ++i) a.push_back(5 - i);

  std::vector<int>::iterator it;
  it = std::find(a.begin(), a.end(), 3); // El rango de búsqueda y el elemento

  if( it != a.end())
    std::cout << "Element found in vector: " << *it << std::endl;
  else
    std::cout << "Element not found" << std::endl;

  // Recordar que end() no debe ser dereferenciado
  for(it = a.begin(); it < a.end(); ++it) std::cout << *it << " ";
  std::cout << std::endl;

  // Clasificación parcial
  std::sort(a.begin(), a.begin() + 3);
  for(it = a.begin(); it < a.end(); ++it) std::cout << *it << " ";
  std::cout << std::endl;

  // for_each
  std::cout << "Printing with for_each" << std::endl;
  for_each(a.begin(), a.end(), print);
  std::cout << std::endl;

  return 0;
}


