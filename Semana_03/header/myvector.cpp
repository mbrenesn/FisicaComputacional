#include <iostream>

// Debemos incluir el archivo de declaración
#include "myvector.hpp"

MyVector::MyVector(int n){
  m_n = n;
  data = new float[m_n];
}

MyVector::~MyVector(){
  delete [] data;
}

int MyVector::get_n(){
  return m_n;
}

float MyVector::norm(){
  float sum = 0.0;
  for(int i = 0; i < m_n; ++i){
    sum += data[i] * data[i];
  }

  return std::sqrt(sum);
}
