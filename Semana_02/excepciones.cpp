#include <iostream>

double division(int a, int b){

  if(b == 0){
    throw "Division by zero condition!";
  }

  return (a / b); // Aquí está ocurriendo un cast interno de tipos de variables
}

int main(){

  int x = 50;
  int y = 0;
  double z = 0;

  try{
    z = division(x, y);
    std::cout << z << std::endl;
  }catch(const char* msg){ // const es una expresión que denota que "algo" es constante y no se puede cambiar
                           // dentro de la función. La función catch toma una hilera de caracteres constantes
                           // como variable
    std::cerr << msg << std::endl;
  }

  return 0;
}


