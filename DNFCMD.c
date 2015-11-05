//Defining functions to have DNFs work with each other
#include "ADNF.h"
#include <stdlib.h>

void CPYTO(ADNFClause dst, ADNFClause src)	//Both are considered HEADS
{

	src=src->next;

	while (src)
	{
		//dst to catch up with src
		dst-> next= malloc(sizeof(AAndClause));
		dst-> next-> prev= dst;
		dst= dst->next;
		
		//The actual copying
		dst->set= src->set;

		//src move on
		src= src->next;

	}	

}


ADNFClause CPY(ADNFClause src)
{
	ADNFClause dst;
	
	dst= malloc(sizeof(AAndClause));
	dst->prev=0;
	
	CPYTO(dst, src);
	
	return dst;
}

//ADNFClause AND( ASet dst, ADNFClause src)	//Returns a linked list of length>=1 "WITHOUT A HEAD"
//{
//	ADNFClause 
//}

void AND( ADNFClause dst, ADNFClause src)
{
	ADNFClause newChainEnd;	//the CURRENT tail of the new chain of and clauses
	ADNFClause oldChainI;	//old chain iterator
//	ADNFClause oldCur;
	ADNFClause srcI; //source iterator
	ADNFClause t;	//temp!
	
	oldChainI=dst->next;	//to read the original and clauses from the original linked list
	newChainEnd=dst;	//the head
	newChainEnd->next=0;//empty list for now
	
	while (oldChainI)
	{
		
		for (srcI= src->next; srcI; srcI= srcI->next)	//traverse the other operand to and all the and clauses!
		{
			t=AddClause( newChainEnd, srcI->set | oldChainI->set);	//if it's not added, t=0!
			//Orring two sets means their union, therefore ANDing the and clauses
			
			newChainEnd= (t)? (Last(t)): (newChainEnd);	//if the new clause is not added, it has not deleted anything either
		}
		

		t= oldChainI->next;
		free(oldChainI);
		oldChainI= t;
	}	
	
}

void OR ( ADNFClause dst, ADNFClause src)
{
	for (src=src->next; src; src=src->next)
		AddClause(dst, src->set);
}

void NOT( ADNFClause dst)
{
	ADNFClause oldChainHead;
	ADNFClause newORClause;	//each previously AND clause becomes an OR clause
	int i;

	oldChainHead->next= dst->next;
	oldChainHead->prev= 0;
	
	dst->next=0;
	InitAndClauseLinkedList(&newORClause);
	
	for (oldChainHead= oldChainHead->next; oldChainHead; oldChainHead= oldChainHead->next)
	{
		for (i=0; i<ASET_SIZE; i++)
			if (SET_MEMBER(oldChainHead->set, i))
				AddClause(newORClause, SET_ADDE(0, SET_INDEX_NEGATE(i)));

		AND(dst, newORClause);
		ClearDNFClause(newORClause);
	}
}
