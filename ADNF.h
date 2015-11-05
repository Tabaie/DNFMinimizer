#include "ASet.h"

//#define LOG_ALL


#ifdef LOG_ALL
	#define LOG_LINKEDLIST
	#define LOG_STACK
	#define LOG_CROSSBAR
#endif

typedef struct AAndClause
{
//Linked List Stuff
	struct AAndClause *prev;
	struct AAndClause *next;
	
//The set itself
	ASet set;
	
} AAndClause;


typedef AAndClause * ADNFClause;

//THE CROSSBAR

// AND CLAUSES IN A LINKED LIST

AAndClause * RemoveClause(AAndClause *a); //Returns the pointer to the PREVIOUS record
void InitAndClauseLinkedList(ADNFClause *);
int AddClause(ADNFClause dnf, ASet clause); //returns 1 if the formula is complicated further in result, 0 if nothing has changed, -1 if the formula has been simplified
void PrintDNFClause(ADNFClause dnf);
void AddDontCare(ADNFClause dst, ADNFClause src);
void ClearDNFClause(ADNFClause dnf);

//ASSEMBLY LIKE INSTRUCIONS FOR DNF

void CPYTO(ADNFClause dst, ADNFClause src);	//Both are considered HEADS
ADNFClause CPY(ADNFClause src);
void AND( ADNFClause dst, ADNFClause src);
void OR ( ADNFClause dst, ADNFClause src);
void NOT( ADNFClause dst);
void freeDNFClause(ADNFClause dnf);
