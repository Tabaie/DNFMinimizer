
typedef unsigned long long ASet;

#define ASET_SIZE_HALF (sizeof(ASet)* 8 /2)

#define SET_CONTAINS(a,b) (	((a)==(b))?		(-1):		((a)^(b) == (a)-(b))?			(1):			((a)^(b) == (b)-(a))?				(-1):0)
														
int Contains(ASet *a, ASet *b);	//1: a contains b, 0: none, -1 b contains a

#define SET_ADD(a,itemIndex) {(a)|= 1<<(itemIndex);}
void Add(ASet *a, int itemIndex);

#define SET_REMOVE(a,itemIndex) {	(a)&= -1 ^ (1<<(itemIndex));}
void Remove(ASet *a, int itemIndex);

#define SET_CLEAR(a) { (a)=0;}
void Clear(ASet *a);

#define SET_UNION(a,b) ((a)|(b))
void Union(ASet *a, ASet *b);

#define SET_INTERSECTION(a,b) ((a)&(b))

#define SET_ISFALSE(a) (((a)>> ASET_SIZE_HALF) & (a) )	//MAKE SURE SHIFT RIGHT IS NOT CIRCULAR

#define SET_UPPERHALF(a) ((a)>> ASET_SIZE_HALF)
#define SET_LOWERHALF(a) ((a) & ((1<< ASET_SIZE_HALF)-1))

#define SET_ALL_ATOMS(a) (SET_UPPERHALF(a) | SET_LOWERHALF(a) )

#define SET_NEGATE_ALL(a) ((a)<< ASET_SIZE_HALF)	//MAKE SURE SHIFT LEFT IS CIRCULAR. THIS IS NOT EQUIVALENT TO A NOT OPERATION ON AN AND CLAUSE

#define SET_INDEX_NEGATE(a) ((a)+ ASET_SIZE_HALF)

int SetOnlyDifference(ASet a, ASet b);	//If they are different in only one bit, its index is returned, -1 otherwise

void PrintSet_IncNeg(ASet);	//Print a set with negated literals
