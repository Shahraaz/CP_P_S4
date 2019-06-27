from itertools import combinations
import random

global inp_file
for g in range(1,2):
	n= random.randint(7,20)
	#n=10
	#File to write the input to the constraint generation program
	inp_file="2ConnOutPlanar/2Conn_"+str(n)+".txt"  
	inp=open(inp_file,'w')
	#print inp
	#Dimension to be checked for G
	dim=3
	print '\nGenerating 2 connected outerplanar graph with '+str(n)+' vertices'
	print 'Input to the constraint generation program is written in 2ConnOutPlanar/2Conn_'+str(n)+'.txt\n'
	inp.write(str(n)+'\n')
	inp.write(str(dim)+'\n')
	#Generate the edges of the hamiltonian cycle 
	edges=[]
	for i in range(1,n):
		edges.append((i,i+1))
		inp.write("%02d "%i+"%02d"%(i+1)+'\n')
	edges.append((1,n))
	inp.write("%02d "%1+"%02d"%n+'\n')	
	
	#print edges
	#label the vertices from 1 to n
	elem=range(1,n+1)
	#print elem
	perm=list(combinations(elem,2))
	#print perm
	#List down all possible chords of G 
	chords=[x for x in perm if x not in edges]
	#print chords
	#List to store the selected chords	
	select=[]
	#Randomly update the permissible chords and remove the crossing chords
	try:	
		while(len(chords)!=0):
			rand_index=random.randint(0,len(chords)-1)
			#print"Rand index"+str(rand_index)
			sel=chords[rand_index]	
			select.append(sel)
			inp.write("%02d "%sel[0]+"%02d"%sel[1]+'\n')
			chords.remove(sel)
			for c in chords[:]:
				#print 'c[0] ' +str(c[0])
				#print 'c[1] ' +str(c[1])
				cond1=[c[0]<=sel[0],c[1]>=sel[1] or c[1]<=sel[0]]
				cond2=[c[0]>=sel[0],c[1]<=sel[1]]
				cond3=[c[0]>=sel[1],c[1]<=n]
				conds=[all(cond1),all(cond2),all(cond3)]
				if not any(conds):
					#print 'removed'+ str(c)				
					chords.remove(c)
			#print "Chords "+str(chords)
		inp.close()
		print 'Selected chords: ' + str(select)
	except:
		print "The selected index of the chord is out of range"

		exit()

