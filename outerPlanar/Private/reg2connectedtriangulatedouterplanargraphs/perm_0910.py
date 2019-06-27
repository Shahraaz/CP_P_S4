                 #***********PROGRAM TO GENERATE CONSTRAINTS FOR A GRAPH FOR WHICH THE COGRAPH DIMENSION IS TO BE CHECKED**********#
                                       #Input is a graph as a txt file in the format given below:
                                            #<|Vertices|>
                                            #<Dimension>
                                            #<Edges> e.g 01 12
                                            #            02 05

#run using "python"command to include itertools!
from itertools import permutations 
import re
import shutil

#from outerplanar_partition import inp_file
#globals
global edges
edges= []
global ids
ids=1

def reverse(term):
	t=term.split('_')
	return t[1][-2:]+t[1][:2]

#Generate edge constraints
def edge_constraints(E,x,literals):
	edge_sat=open('edge_sat.txt','a')
	for e in E:
		#print x+'_'+e[0]+e[1]
		edge_sat.write(str(literals[x+'_'+e[0]+e[1]])+' 0\n')
	edge_sat.close()
	
def generate(x,k):
	global ids
	global edges
	permute=permutations(elem,k)	
	# File to write the constraints acc to the permutation
	con=open("constraints.txt",'w') 
    	for index in permute: 
		p_list=[i for i in index]
		for i in range(len(p_list)-1):
			con.write('~'+x+'_'+ "%02d"%p_list[i]+ "%02d"%p_list[i+1]+' '+'|'+' ')
        		#con.write('~'+x+'_'+ str(p_list[i])+ str(p_list[i+1])+' '+'|'+' ')
    		con.write(x+'_'+ "%02d"%p_list[0]+ "%02d"%p_list[2]+' '+'|'+' ')
    		con.write(x+'_'+ "%02d"%p_list[0]+ "%02d"%p_list[3]+' '+'|'+' ')
    		con.write(x+'_'+ "%02d"%p_list[1]+ "%02d"%p_list[3]+' '+'&')
    		con.write('\n')
	con.close()

	#Constraints as per the input format of lingeling SAT solver
	con = open("constraints.txt", "r")
	#creating table to store id to corr literals
	literals={}
	equation=con.read().split('&')
	for clause in equation:
		terms=clause.split('|')[:-1]
		for t in terms:
			t=t.replace("~","")
			t=t.replace("\n","")
			t=t.replace(" ","")
			tdash=t.split('_')
        	        tdash=x+'_'+reverse(t)
			#print t,tdash
			#raw_input()
			if t not in literals and t!='':
				literals[t]=ids
				literals[tdash]=ids
				ids+=1
				
        #print('\n\n'+ str(literals)+'\n')
	constr = open("constraints.txt", "r")
	text=constr.read().split('\n')
	for line in text[:-1]:
		#line=line.replace(' ','')
		lit_ids=[str(literals[lit]) for lit in [(i.strip().replace('~','')).replace(' &','') for i in line.split('|')]]
		lit_ids=['-'+lit_ids[i] if i<3 else lit_ids[i] for i in range(len(lit_ids))]
		line=' '.join(lit_ids)+' 0'
		sat.write(line+'\n')
	
	con.close()
	edge_constraints(edges,x,literals)
	return literals

edge_sat=open('edge_sat.txt','w')
edge_sat.close()

#read the input graph from file
Graph = open(raw_input("Enter Filename of the input : "),'r')
#Graph = open(inp_file,'r')
#print Graph
vertices=int(Graph.readline())
dim=int(Graph.readline())
for line in Graph:
	if line not in ['\n', '\r\n']:
		line=line.split()
        else:
		break
        edges.append(line)
Graph.close()
#label the vertices from 1 to n
elem=range(1,vertices+1)

#generate the k length permutations of V(G) and write to file
#k=input("Permute over-k: ")
k=4
permute=list(permutations(elem,k))
LitTable=open("LitTable.txt",'w') 
#LitTable.write(str(permute))

#file to write chord constraints
sat=open("sat_const.txt", "w")

#Generate G_i(i.e x0,x1..) acc to the dimension
print '\nGenerating constraints...'
lit_tab={}
for i in range(dim):
	lit_tab[i]=generate('G'+str(i),k)
#LitTable.write("The total number of variables is " + str(ids-1)+ '\n')
for i in range(dim):
	for lit in lit_tab[i]:
		LitTable.write(str(lit)+':')
		LitTable.write(str(lit_tab[i][lit])+'\n')
LitTable.close()
#visited stores the variables corr to the graph edges
visited=[]
for e in edges:
	visited.extend(['G'+str(j)+'_'+e[0]+e[1] for j in range(dim)])
	visited.extend(['G'+str(j)+'_'+reverse('G'+str(j)+'_'+e[0]+e[1]) for j in range(dim)])

#generate constraints for intersection
intersec=open('intersection.txt','w')
for index in permute: 
	p_list=[i for i in index]
	for i in range(len(p_list)-1):
		eq=''
		lit=''
		t=False
		for j in range(dim):
			lit='G'+str(j)+'_'+ "%02d"%p_list[i]+ "%02d"%p_list[i+1]
			tdash='G'+str(j)+'_'+reverse(lit)
			if lit not in visited:
				eq=eq+'-'+str(lit_tab[j][lit])+' '
				visited.append(lit)
				visited.append(tdash)
			else:
				t=True
				break
		if not t:
			eq=eq+' 0'
			intersec.write(eq+'\n')
			t=False
intersec.close()
sat.close()



files=['sat_const.txt','intersection.txt','edge_sat.txt']
fin_sat=open('final_sat.txt','w')
fin_sat.write("p cnf " + str(ids-1)+ ' \n')
linecnt=0
for fil in files:
	for line in open(fil):
             if not line.isspace():
		fin_sat.write(line)
		linecnt+=1
fin_sat.close()

print str(linecnt) + " SAT constraints written to final_sat.txt\nRun lingeling to check the satisfiability.\nTo draw the graph from lingeling output, please run graph_0910.py.\n The dimension to be checked is set as 3 by default. Please change the dimension if reqd in graph_0910.py\nTo visualize the intersection graphs, use cytoscape."

old=open('final_sat.txt').read().split('\n')
old[0]=old[0]+str(linecnt)
fp=open('final_sat.txt','w')
fp.write(old[0])
[fp.write('\n'+line)for line in old[1:]]
#line.strip()
fp.close()
