#include <iostream>
#include "square.hpp"

Square::Square(){
  std::cout << "Square default constructor" << std::endl;
}

Square::Square(float a){
  std::cout << "Square custom constructor" << std::endl;
  width = a;
  height = a;
}

Square::~Square(){
  std::cout << "Square destructor" << std::endl;
}

float Square::inscribed_area(){
  
  return 3.1416 * width * width / 4.0;
}
