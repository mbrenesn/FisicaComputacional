#include <iostream>
#include <mpi.h>

int main(){

  int size;
  int rank;

  MPI_Init(NULL, NULL);

  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  std::cout << "Hello from process: " << rank << " of size: " << size << std::endl;

  MPI_Finalize();

  return 0;
}
