#include <iostream>
#include <vector>

int main(){

  std::vector< std::vector<int> > vec; // Se necesitan espacios entre los <>
  
  for(int i = 0; i < 0; ++i){
    std::vector<int> row; // Crea una fila vacía
    for(int j = 0; j < 20; ++j){
      row.push_back(i * j); // Añade un elemento a la fila 
    }
    vec.push_back(row); // Añade la fila al vector principal (matriz)
  }

  // También se puede declarar en construcción
  // Igual se puede modificar su tamaño
  std::vector< std::vector<int> > vec_2(4, std::vector<int>(4)); 

  return 0;
}


