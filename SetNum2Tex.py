half_size=16

names=["a_0", "a_1", "a_2", "a_3", "b_0", "b_1", "b_2", "b_3"]

r= input()

while (r!=-1):
	if (r==-1):
		break
			
	for i in xrange(half_size):
		if (r%2 ==1):
			print names[i],
		
		r=r/2
	
	for i in xrange(half_size):
		if (r%2 ==1):
			print "\overline{%s}"%names[i],
		
		r=r/2

	print ""	
	
	r= input()
