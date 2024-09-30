#include <iostream>
#include <vector>

// Porqué pongo la firma de esta función al inicio?
void print_mat(std::vector<double> &mat, int &rows, int &cols);

int main(int argc, char* argv[]){

  std::cout << "Multiplicación de matrices!" << std::endl;
  std::cout << "La idea es calcular C = A * B" << std::endl;
  std::cout << "A y B son matrices con valores predefinidos." << std::endl;
  std::cout << "Para esta evaluación requerimos poner en práctica" << std::endl;
  std::cout << "el concepto de memoria contigua." << std::endl;
  std::cout << "En general, este algoritmo depende mucho de la estructura de datos" << std::endl;
  std::cout << "usada para representar las matrices." << std::endl;
  std::cout << "Fun fact: los algoritmos para mejorar la eficiencia de multiplicación" << std::endl;
  std::cout << "de matrices es un campo de investigación aún abierto, dado que" << std::endl;
  std::cout << "existe una infinidad de algoritmos que dependen de esta operación" << std::endl;

  // Definamos la dimensión de las matrices mediante argumentos de la terminal
  if(argc != 7){
    std::cerr << "Usage: " << argv[0] << " --l [filas de A] --m [columnas de B] --n [columnas de A/filas de B]" << std::endl;
    exit(1);
  }
  // Ahora leemos las dimensiones
  int l, m, n;
  l = atoi(argv[2]);
  m = atoi(argv[4]);
  n = atoi(argv[6]);

  // Definamos nuestras matrices de entrada
  std::vector<double> A(l * n, 0.0); // Inicialización a 0.0
  std::vector<double> B(n * m, 0.0);
  std::vector<double> C(l * m, 0.0);

  // Inicialización de A
  for(int i = 0; i < l; ++i){
    for(int j = 0; j < n; ++j){
      A[(i * n) + j] = i;
    }
  }
  // Inicialización de B
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      B[(i * m) + j] = j;
    }
  }

  std::cout << "Matrix A = " << std::endl;
  print_mat(A, l, n);
  std::cout << "Matrix B = " << std::endl;
  print_mat(B, n, m);

  std::cout << "Calculando multiplicación..." << std::endl;
  // C ya se encuentra inicializada en 0!
  // Eso significa que podemos hacer la suma parcial en cada uno de sus elementos
  // LABORATORIO: COMPLETAR la multiplicación de las matrices
  for(int i = 0; i < l; ++i){
    for(int j = 0; j < m; ++j){
      for(int k = 0; k < n; ++k){
        // Su código aquí
      }
    }
  }
  std::cout << "Resultado C = " << std::endl;
  print_mat(C, l, m);

  return 0;
}

// Porqué la firma de esta función usa & para sus argumentos?
void print_mat(std::vector<double> &mat, int &rows, int &cols){
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << mat[(i * cols) + j] << " ";
    }
    std::cout << std::endl;
  }
}
