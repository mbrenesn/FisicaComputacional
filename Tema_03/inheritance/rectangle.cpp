#include <iostream>
#include "rectangle.hpp"

Rectangle::Rectangle(){
  std::cout << "Rectangle default constructor" << std::endl;
}

Rectangle::Rectangle(float a, float b){
  std::cout << "Rectangle custom constructor" << std::endl;
  width = a;
  height = b;
}

Rectangle::~Rectangle(){
  std::cout << "Rectangle destructor" << std::endl;
}

Rectangle::Rectangle(const Rectangle &obj){
  std::cout << "Rectangle copy constructor" << std::endl;
  width = obj.width;
  height = obj.height;
}

Rectangle &Rectangle::operator=(const Rectangle &obj){
  std::cout << "Rectangle assignment operator" << std::endl;
  width = obj.width;
  height = obj.height;

  return *this;
}

float Rectangle::area(){
  
  return width * height;
}
