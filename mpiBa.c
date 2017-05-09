#include <stdio.h>
#include "mpi.h"
void myBcast(void *data, int numEl, MPI_Datatype datatype, int root, MPI_Comm communicator){
	int size, rank;
	MPI_Status Stat;	
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
		if(rank != root){
			MPI_Recv(data, numEl, datatype, root, 1, communicator, &Stat);
		}else{
			for(int j = 0; j < size; j++){
			if(j != root){
				MPI_Send(data, numEl, datatype, j, 1, communicator);
				}
			}
		}
}

int main(int argc,char *argv[]){
	int mensaje = 950504;
	int size, rank;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	myBcast(&mensaje, 1, MPI_INT, 4, MPI_COMM_WORLD);
	printf("rank: %d \n mensaje: %d", rank, mensaje);	

	MPI_Finalize();
	return 0;
}
