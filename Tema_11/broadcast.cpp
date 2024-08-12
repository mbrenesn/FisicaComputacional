#include <iostream>
#include <mpi.h>

int main(){

  int size;
  int rank;
  int imesg;

  MPI_Init(NULL, NULL);

  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  imesg = rank;
  std::cout << "Before BCAST I'm: " << rank << " and my message content is: " << imesg << std::endl;

  MPI_Bcast(&imesg, 1, MPI_INT, 0, MPI_COMM_WORLD);
  
  std::cout << "After BCAST I'm: " << rank << " and my message content is: " << imesg << std::endl;

  MPI_Finalize();

  return 0;
}
