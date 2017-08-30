#include "headers.h"
#include "opsArray.h"

int main(int argc, char* argv[])
{
	struct timespec start = {0,0};
	struct timespec end = {0,0};
	
	double factor;	

	int opsArray[]=ARRAY; //macro defined in opsArray.h
	long double time;
	
	unsigned long i;
	dt table;

	sscanf(argv[2],"%lf",&factor); //used to get the factor

	if(strcmp(argv[1],"incr")==0)
	{
		init(&table,factor,factor);
	}
	else if(strcmp(argv[1],"decr")==0)
	{
		init(&table,1/factor,1/factor);
	}
	else
	{
		printf("Enter correct arguments please!\n");
		exit(-1);
	}

	//------------------------use below loops for 3:2 ratio----------------------------	
	for(i=0;i<1000000;i++){
		if(opsArray[i]==1){ //push
			clock_gettime(CLOCK_MONOTONIC,&start);
			push(&table,i);
		    clock_gettime(CLOCK_MONOTONIC, &end);
			time=((long double)end.tv_sec + 1.0e-9*end.tv_nsec) - ((long double)start.tv_sec + 1.0e-9*start.tv_nsec);
			time*=1000;
			printf("pus%.6Lf\n",time);
		}
		else
		{					//pop
			clock_gettime(CLOCK_MONOTONIC,&start);
			pop(&table);
		    clock_gettime(CLOCK_MONOTONIC, &end);
			time=((long double)end.tv_sec + 1.0e-9*end.tv_nsec) - ((long double)start.tv_sec + 1.0e-9*start.tv_nsec);
			time*=1000;
			printf("pop%.6Lf\n",time);
		}
	}
	
	//------------------------use below loops for 4:2 ratio----------------------------
	// for(i=0;i<999996;i++){
	// 	if(opsArray[i]==1){ //push
	// 		clock_gettime(CLOCK_MONOTONIC,&start);
	// 		push(&table,i);
	// 	    clock_gettime(CLOCK_MONOTONIC, &end);
	// 		time=((long double)end.tv_sec + 1.0e-9*end.tv_nsec) - ((long double)start.tv_sec + 1.0e-9*start.tv_nsec);
	// 		time*=1000;
	// 		printf("pus%.6Lf\n",time);
	// 	}
	// 	else
	// 	{					//pop
	// 		clock_gettime(CLOCK_MONOTONIC,&start);
	// 		pop(&table);
	// 	    clock_gettime(CLOCK_MONOTONIC, &end);
	// 		time=((long double)end.tv_sec + 1.0e-9*end.tv_nsec) - ((long double)start.tv_sec + 1.0e-9*start.tv_nsec);
	// 		time*=1000;
	// 		printf("pop%.6Lf\n",time);
	// 	}
	// }



	//------------------------use below loops for 1:1 consecutive 1 million insertions.-----------------------------
	// for(i=0;i<1000000;i++){
	// 		clock_gettime(CLOCK_MONOTONIC,&start);
	// 		push(&table,i);
	// 	    clock_gettime(CLOCK_MONOTONIC, &end);
	// 		time=((long double)end.tv_sec + 1.0e-9*end.tv_nsec) - ((long double)start.tv_sec + 1.0e-9*start.tv_nsec);
	// 		time*=1000;
	// 		printf("pus%.6Lf\n",time);
	// }
	
	// for(i=0;i<1000000;i++){
	// 		clock_gettime(CLOCK_MONOTONIC,&start);
	// 		pop(&table);
	// 	    clock_gettime(CLOCK_MONOTONIC, &end);
	// 		time=((long double)end.tv_sec + 1.0e-9*end.tv_nsec) - ((long double)start.tv_sec + 1.0e-9*start.tv_nsec);
	// 		time*=1000;
	// 		printf("pop%.6Lf\n",time);
	// 	}
}