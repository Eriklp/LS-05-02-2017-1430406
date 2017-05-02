#include <stdio.h>
#include <mpi.h>
#include <string.h>

int main(int argc, char **argv){
	int rank, size;

	MPI_Init(&argc, &argv);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);	
	if(rank == 0){
		printf("Yo soy el maestro %d! \n", rank);
		printf("procesos corriendo: %d", size);
	}
	else{
		printf("soy un proceso con identificador %d! \n", rank);
	}

	

	MPI_Finalize();
	return 0;
}
