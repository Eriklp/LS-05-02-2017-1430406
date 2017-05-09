#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int i, sum, sumTotal, upToVal;
	int size, rank;
	MPI_Status Stat;

	upToVal = 10000;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

		int cs = upToVal/size;
    	sum = 0;
    	for(i=(cs*rank) + 1; i<= cs * (rank + 1); i++){
    		sum = sum +i;
    	}
	printf("%d %d \n", rank , sum);
	
	MPI_Reduce(&sum, &sumTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if(rank == 0){
		printf ("\nTotal: %d\n",sumTotal);
	}
	MPI_Finalize();
	
	return 0;
}

