#include <iostream>
#include <vector>
#include <sys/time.h>

#include "mkl.h" // El header de la biblioteca MKL
                 // en la cual se encuentra gran parte de su funcionalidad

double seconds()
{
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  
  return sec;
}

int main(int argc, char* argv[]){

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

  std::cout << "Calculando multiplicación..." << std::endl;
  // Ya no es necesario implementar nuestro propio algoritmo
  // Podemos utilizar la funcionalidad de MKL que incluye rutinas para multiplicar matrices
  // que incluye procedimientos de optimización dedicados y dinámicos al tipo y tamaño de matrices que
  // utilicemos.
  // Para utilizar estas rutinas, *las matrices deben ser representadas como arreglos 1D en ]
  // memoria contigua*.
  double time_1 = seconds();
  cblas_dgemm( CblasRowMajor, // El orden de la matriz va sobre filas primero
               CblasNoTrans,  // No queremos transponer A
               CblasNoTrans,  // No queremos transponer B
               l,             // El número de filas de A y de C
               m,             // El número de columnas de B y de C
               n,             // El número de columnas de A y filas de B
               1.0,           // El valor de alpha
               &A[0],         // La dirección en memoria del primer elemento de A
               n,             // La dimensión horizontal de A, en este caso, columnas de A (row major)
               &B[0],         // La dirección en memoria del primer elemento de B
               m,             // La dimensión horizontal de B, en estre caso, columnas de B (row major)
               0.0,           // El valor de beta
               &C[0],         // La dirección en memoria del primer elemento de C
               m );           // La dimensión horizontal de C, en estre caso, columnas de C (row major)
  double time_2 = seconds();

  std::cout << "# Time: " << time_2 - time_1 << std::endl;

  return 0;
}
