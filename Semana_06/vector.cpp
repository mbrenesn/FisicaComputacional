#include <iostream>
#include <vector>
#include <sys/time.h>

#include <omp.h>

// Esta función se utiliza para calcular el tiempo que tarda
// la ejecución de ciertas funciones
// Está basada en el uso de una función primitiva que evalúa al tiempo
// transcurrido desde cierto valor de referencia
double seconds()
{
  struct timeval tmp;
  double sec;
  gettimeofday( &tmp, (struct timezone *)0 );
  sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
  
  return sec;
}

int main(){

  int n = 500000000;

  std::vector<double> a(n, 1.0);
  std::vector<double> b(n, 3.5);
  std::vector<double> c(n, 0.0);

  int num_procs;
  double time_1 = seconds();
  #pragma omp parallel
  {
    num_procs = omp_get_num_threads();
    #pragma omp for
    for(int i = 0; i < n; ++i){
      c[i] = a[i] + b[i];
    }
  }
  double time_2 = seconds();

  std::cout << "Number of Threads: " << num_procs << std::endl;
  std::cout << "Time to complete loop: " << time_2 - time_1 << std::endl;

  return 0;
}
