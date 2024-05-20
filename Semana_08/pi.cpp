#include <iostream>
#include <mpi.h>

int main(int argc, char* argv[]){

  // Número de iteraciones se lee como entrada de la aplicación
  // Se desea que el número de argumentos sean dos:
  // El nombre del programa y el número de iteraciones
  if(argc != 3){
    std::cerr << "Usage: " << argv[0] << " --n [iterations]" << std::endl;
    exit(1);
  }
  // Ahora leemos el número de iteraciones
  int n;
  n = atoi(argv[2]);

  // Inicialización del ambiente MPI
  int size, rank;
  MPI_Init(&argc, &argv);
 
  double time_1 = MPI_Wtime();
  // Tamaño y rango
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  // Subdivisión del rango de trabajo
  // Las siguientes operaciones se encargan de balancear la carga
  // en caso de que "n" no sea un múltiplo de del número de procesos
  int nlocal = n / size;
  int rest = n % size;

  if(rest && (rank < rest)) nlocal++;

  int start = rank * nlocal;
  if(rest && (rank >= rest)) start += rest;

  int end = start + nlocal; 

  // Cálculo de la integral
  double local_sum = 0.0;
  double w = 1.0 / n;
  // Subdividimos el for loop en secciones más pequeñas que cada proceso realiza
  for(int i = start; i < end; ++i){
    double x = w * (i - 0.5);
    local_sum += 4.0 / (1.0 + (x * x));
  }
  // sum es una suma parcial de cada proceso!
  // Debemos realizar una operación de reducción para colectar los resultados
  // intermedios.
  // Vamos a usar el proceso de rango 0 para coleccionar los resultados intermedios
  double global_sum;
  MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  double time_2 = MPI_Wtime();
  // Ahora el rango 0 contiene la suma total
  if(rank == 0){
    double pi_approx = global_sum * w;
    std::cout.precision(10);
    std::cout << "Número de procesos: " << size << std::endl;
    std::cout << "Tiempo: " << time_2 - time_1 << std::endl;
    std::cout << "Valor approximado de pi:" << std::endl;
    std::cout << pi_approx << std::endl;
  }

  return 0;
}
