#include <iostream>
#include <mpi.h>

int main(){

  int size, rank;
  int buff;

  int tag = 0;

  MPI_Init(NULL, NULL);

  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  buff = rank;
  MPI_Status stat;

  if(size != 2) MPI_Abort(MPI_COMM_WORLD, 1);

  int peer = (rank == 0) ? 1 : 0;

  // Implemente el Send-Recv "in-place": MPI_Sendrecv_replace
  // Su código aquí

  std::cout << "I'm: " << rank << " and my recv is: " << buff << std::endl;

  MPI_Finalize();

  return 0;
}
