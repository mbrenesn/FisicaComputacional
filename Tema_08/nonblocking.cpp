#include <iostream>
#include <mpi.h>

int main(){

  int size, rank;
  int sendbuff, recvbuff;

  int tag = 0;

  MPI_Init(NULL, NULL);

  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  sendbuff = rank;
  MPI_Status stat;

  if(size != 2) MPI_Abort(MPI_COMM_WORLD, 1);

  MPI_Request request[2];
  if(rank == 0){
    MPI_Isend(&sendbuff, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &request[0]);
    MPI_Irecv(&recvbuff, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &request[1]);
    // Aquí podemos hacer más cosas con proceso 0!
    // ...
    // Por supuesto, sería poco prudente usar recvbuff a este punto porque no sabemos si se ha recibido!
  }
  else if(rank == 1){
    // Ahora el orden no importa...
    MPI_Send(&sendbuff, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
    MPI_Recv(&recvbuff, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &stat);
  }
  // ...porque podemos esperar aquí antes de usar los espacios de memoria
  if(rank == 0){
    MPI_Wait(&request[0], MPI_STATUS_IGNORE);
    MPI_Wait(&request[1], MPI_STATUS_IGNORE);
  }

  std::cout << "I'm: " << rank << " and my recv is: " << recvbuff << std::endl;

  MPI_Finalize();

  return 0;
}
