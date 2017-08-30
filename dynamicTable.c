#include "headers.h"

void init(dt* temp,double incrFact, double decrFact)
{
	temp->maxSize=5; //defualt size is 5.
	temp->curSize=0;
	temp->arrPointer = (int*)malloc(sizeof(int)*temp->maxSize);
	temp->incrFact=incrFact;
	temp->decrFact=decrFact;
}

void push(dt* temp,int ele)
{
	if((temp->curSize)<0)
		temp->curSize = 0; //for the case where one element is pushed, then popped and then another pushed again.

	if(((temp->curSize) <= (temp->maxSize)-1) && (temp->curSize)>=0)
	{
		temp->arrPointer[temp->curSize] = ele;
		(temp->curSize)++;
	}
	else
	{
		// New array created and copying happens here.
		int *newTemp = (int*)malloc(ceil(sizeof(int)*(temp->incrFact)*(temp->maxSize)));
		int i;
		for(i=0;i<(temp->maxSize);i++)
		{
			newTemp[i]=(temp->arrPointer[i]); //copying old elements into the newly created array.
		}
		newTemp[i]=ele;

		free(temp->arrPointer);
		
		temp->arrPointer = newTemp;
		temp->maxSize=ceil((temp->incrFact)*(temp->maxSize));
		(temp->curSize)++;
		newTemp=NULL;
	}
}

int pop(dt* temp)
{
	if(temp->curSize >0)
	{
		int ele=temp->arrPointer[temp->curSize];
		(temp->curSize)--;
		return ele;
	}
	else
	{
		return;
	}
	if(temp->maxSize != 0 && temp->curSize >0)
	{
		// Realloc used to decrease the array size once it passes a certain size.
		double checkSize = ceil((temp->maxSize)/(temp->decrFact));
		double ipart;
		double frac = modf(checkSize, &ipart); // get only the decimal part of checkSize, this is done because, if the number isn't divisible by a fractional number, then I can get to know that. This is done to assign a value to max sign.
		if(frac == 0)
		{
			if((temp->curSize)-1 == checkSize)
				temp->maxSize = (int)checkSize;
			temp->arrPointer = (int*)realloc(temp->arrPointer,sizeof(int)*(temp->maxSize));
		}
		else
		{
			if(temp->curSize == checkSize)
				temp->maxSize = (int)checkSize;
			temp->arrPointer = (int*)realloc(temp->arrPointer,sizeof(int)*(temp->maxSize));
		}
	}
}

//Strictly to be used for debugging purposes only.
void display(dt* temp)
{
	for(int i=(temp->curSize)-1;i>=0;i--)
	{
		printf("i:%d,ele:%d\n",i, temp->arrPointer[i]);
	}
}