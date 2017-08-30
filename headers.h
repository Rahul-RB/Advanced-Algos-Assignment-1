#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <string.h>


typedef struct dynamicTable
{
	int* arrPointer;
	int maxSize;
	int curSize;
	double incrFact;
	double decrFact;
}dt;


void init(dt*,double,double);
void push(dt*,int);
int pop(dt*);
void display(dt*); //Strictly to be used for debugging purposes only! 