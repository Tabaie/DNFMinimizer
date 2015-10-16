#include <stdio.h>
#include "ADNF.h"

int main()
{
	int i;
	ADNFClause eq, lt, t1, t2;
	AAndClause *clauseI;
	ASet andClause;
		
	InitAndClauseLinkedList(&lt);
	InitAndClauseLinkedList(&eq);
	InitAndClauseLinkedList(&t1);
	InitAndClauseLinkedList(&t2);

	//initialize eq:
	andClause=0;	//0 is ALWAYS TRUE
	AddClause(eq, andClause);
	
	andClause=-1;	//-1 is ALWAYS FALSE
	AddClause(lt, andClause);
	
	for (i=0; i<4; i++)
	{
		ClearDNFClause(t1);

		SET_CLEAR(andClause);
		SET_ADD(andClause,i);	//A_i . B_i
		SET_ADD(andClause,i+4);
		AddClause(t1, andClause);
		
		SET_CLEAR(andClause);
		SET_ADD(andClause, SET_INDEX_NEGATE(i  ));	//not(A_i) . not(B_i)
		SET_ADD(andClause, SET_INDEX_NEGATE(i+4));
		AddClause(t1, andClause);

		AND(eq, t1); // eq_i = (a_i.b_i + ~a_i.~b_i).eq_{i-1}
		
		AND(lt, t1);
		SET_CLEAR(andClause);
		SET_ADD(andClause, SET_INDEX_NEGATE(i));	//~a_i
		SET_ADD(andClause, i+4);	//b_i
		AddClause(lt, andClause);	//lt_i = (a_i.b_i + ~a_i.~b_i).lt_{i-1} + ~a_i.b_i
		
		
		printf("%dbLt:\n", i+1);
		PrintDNFClause(lt);
		
//		printf("%dbEq:\n", i+1);
//		PrintDNFClause(eq);
	}

//Adding BCD DON'T CARE!!
	ClearDNFClause(t1);
	
	SET_CLEAR(andClause);
	SET_ADD(andClause, 3); //a_3
	SET_ADD(andClause, SET_INDEX_NEGATE(2)); //~a_2
	SET_ADD(andClause, 1); //a_1
	AddClause(t1, andClause); //a= 1010 or 1011
	
	SET_CLEAR(andClause);
	SET_ADD(andClause, 3); //a_3
	SET_ADD(andClause, 2); //a_2
	AddClause(t1, andClause);	//a>= 1100

	SET_CLEAR(andClause);
	SET_ADD(andClause, 7); //b_3
	SET_ADD(andClause, SET_INDEX_NEGATE(6)); //~b_2
	SET_ADD(andClause, 5); //b_1
	AddClause(t1, andClause); //b= 1010 or 1011
	
	SET_CLEAR(andClause);
	SET_ADD(andClause, 7); //b_3
	SET_ADD(andClause, 6); //b_2
	AddClause(t1, andClause);	//b>= 1100

	printf("Don't care= ");
	PrintDNFClause(t1);
	
	AddDontCare(eq, t1);
	printf("BCDEq:\n");
	PrintDNFClause(eq);
	
	AddDontCare(lt, t1);
	printf("BDCLt:\n");
	PrintDNFClause(lt);
	return 0;
}
