#include <iostream>
#include "myvector.hpp"

int main(){

  MyVector a(2);
  for(int i = 0; i < a.get_n(); ++i){
    a.data[i] = 1.0;
  }

  std::cout << a.norm() << std::endl;

  return 0;
}
