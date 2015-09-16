import itertools
N = input()
ar = map(int, raw_input().split(" "))
ar.sort()
big_arr = []
for x in ar:
	big_arr.append(x)
print big_arr
	
	
for x in ar:
	
	no = N/x
	
	for i in range(no-1):
		big_arr.append(x)

print big_arr
big_arr.sort()
ultimate = set([])
count = 0

for i in range(1,N/ar[0] +1 ):
	print i
	all_comb =  set(itertools.combinations(big_arr, i))

	#print all_comb
	for x in all_comb:
		print x 
		if sum(x) == N:
			y = list(x)
			y.sort()
			ultimate.add(tuple(y))
			
			
print len(ultimate)