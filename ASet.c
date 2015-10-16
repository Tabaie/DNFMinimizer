#include "ASet.h"
#include <stdio.h>

int Contains(ASet *a, ASet *b)
{
	if (*a==*b)	//IF THEY ARE EQUAL, FAVOR a, THE ONE ALREADY IN THE CHAIN
		return -1;

	if ( (*a^*b) == (*a-*b))
		return 1;
	
	if ( (*a^*b) == (*b-*a) )
		return -1;

	return 0;
}

void Add(ASet *a, int itemIndex)
{
	*a|= 1<< itemIndex;
}

void Remove(ASet *a, int itemIndex)
{
	*a&= -1 ^ (1<<itemIndex);
}
 
void Clear(ASet *a)
{
	*a=0;
}

void Union(ASet *a, ASet *b)
{
	*a= *a | *b;
}


int SetOnlyDifference(ASet a, ASet b)
{
  int i;
  int twoPow;
  
  if (a==b)
  	return -1;	//they are not different at all
  
  twoPow=1;
  for (i=0; (a & twoPow) == ( b & twoPow) ; i++)
  {
  	twoPow*=2;
  }
  
  // A difference is found now, there should be equal from AFTER that point
  i++;
  
  
  if ((a >> i) != (b >> i))
  	return -1;	//they are still different from this point on.
  	
  return i;
}


void PrintSet(ASet a)
{
	int i;
	for (i=0; i< sizeof(ASet)*8; i++)
	{
		if (a%2)
			printf("_%d", i);
			
		a/=2;
	}
	
	printf(" ");
}

void PrintSet_IncNeg(ASet a)	//Print a set with negated literals
{
	int i;
	for (i=0; i< sizeof(ASet)*4; i++)
	{
		if (a%2)
			printf("_%d", i);
			
		a/=2;
	}

	for (i=0; i< sizeof(ASet)*4; i++)
	{
		if (a%2)
			printf("_~%d", i);
			
		a/=2;
	}

	
	printf(" ");

}
