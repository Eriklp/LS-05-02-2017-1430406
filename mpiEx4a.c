#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int i, sum, sumTotal, upToVal;
	int start, end, size, rank;
	MPI_Status Stat;

	upToVal = 10000;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// Defina aqui el segmento que debe procesar una tarea
	// El inicio del segmento en la variable 'start', el fin del segmento
	// la variable 'end'
		int cs = 10000/size;
    	sum = 0;
    	for(i=(cs*rank) + 1; i<= cs * (rank + 1); i++){
    		sum = sum +i;
    	}
	printf("%d %d \n", rank , sum);
	if(rank == 0){
		for(i = 1; i < size; i++){
			MPI_Recv(&sumTotal, 1, MPI_INT, i, 1, MPI_COMM_WORLD, &Stat);
			sum += sumTotal;
		}
		printf ("\nTotal: %d\n",sum);
	}else {MPI_Send(&sum, 1, MPI_INT, 0, 1, MPI_COMM_WORLD); }
	// Utilice la funcion 'MPI_Reduce' para guardar en la variable 
	// 'sumTotal' la suma parcial de todos las tareas 
	

	MPI_Finalize();
	
	return 0;
}

