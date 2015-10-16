import re

HalfSize=16

def PrintAndClause(andClause):
	i=0
	neg=""
	while (andClause>0):
		if (i==16):
			neg="n"
			i=0
			
		
		if (andClause%2 == 1):
			print ("%sa%d"%(neg,i)),
		
		andClause= andClause/2

		i=i+1


s= raw_input()
andClauses= re.findall(r'\d+', s)

i=0
for andClause in andClauses:
	andClause= long(andClause) #turn in into an integer
	print ("(define-const F%d (AndClause) (bvor"%i),
	PrintAndClause(andClause)
	print("))")
	i=i+1

