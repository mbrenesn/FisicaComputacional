#include <iostream>

void func(std::string name){

  std::cout << "Hello, " << name << "!" << std::endl;
}

int main(){

  std::string my_name = "Marlon";

  func(my_name);

  return 0;
}
