#include <iostream>

int main(){

  int i = 5;
  int a = 3;

  std::cout << "i before loop: " << i << 
    " a before loop: " << a << std::endl; 

  for(int i = 0; i < 10; ++i){
    {
      int a = 7;
      int b = 3;
      std::cout << "i inside loop: " << i << " a inside loop: " << a << std::endl; 
    }
  }
  std::cout << "i after loop: " << i << " a after loop: " << a << std::endl;
  // std::cout << b << std::endl; <--- b es invisible en este scope
  
  return 0;
}
