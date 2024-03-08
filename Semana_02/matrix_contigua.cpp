#include <iostream>
#include <vector>

int main(){

  int rows = 4; // Número de filas
  int cols = 3; // Número de columnas

  // La matrix va a ser un arreglo contiguo en memoria
  // i.e., un arreglo 1-dimensional con rows*cols elementos
  std::vector<double> matrix(rows * cols, 0.0);
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      matrix[(i * cols) + j] = (i * cols) + j; // Ojo con este acceso
    }
  }

  // Podemos visualizar la matrix de la siguiente forma
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << matrix[(i * cols) + j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}


