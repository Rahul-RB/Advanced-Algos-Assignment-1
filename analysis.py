# incr:  2, 3, 1.75, 1.5, 1.25
# decr:  0.25, 0.5, 0.75.
# incrFor2=[]
# incrFor3=[]
# incrFor75=[]
# incrFor5=[]
# incrFor25=[]

# decrFor25=[]
# decrFor5=[]
# decrFor75=[]


import sys
import subprocess
from matplotlib import pyplot as plt
# result=subprocess.check_output(['./a.out','incr','2'])
result=subprocess.check_output(['./a.out',sys.argv[1],sys.argv[2]])
# print(sys.argv[3])
l=result.decode('utf-8')
k=l.split('\n')
push=[]
pop=[]

# print(k)
for ele in k:
	string=ele[0:3]
	# print(string)
	if(string=='pus'):
		push.append(ele[3:])
	else:
		pop.append(ele[3:])

# for e in pop:
# 	pop.append(float(e))
pop.remove('')
# push.remove('')
push=[float(e) for e in push]
pop=[float(e) for e in pop]
allList = push+pop

print("PUSH MAX:",max(push))
print("POP MAX:",max(pop))

print("PUSH AVG:",round(sum(push)/len(push),6))
print("POP AVG:",round(sum(pop)/len(pop),6))

print("ALL AVG:",round(sum(allList)/len(allList),6))


plt.plot(push,label="push",color="red")
plt.ylabel("Time taken in Milliseconds")
plt.xlabel("i-th push")
plt.title("Time taken v/s Ith Push Operation")
plt.legend()
# plt.savefig('/home/rahul/Desktop/PESU/PESU-5THSEM/AA/AA-ASSIGNMENT1/PLOTS/1MILPLOTS/'+sys.argv[3]+'/push.png')
plt.show()

plt.plot(pop,label="pop",color="blue")
plt.ylabel("Time taken in Milliseconds")
plt.xlabel("i-th pop")
plt.title("Time taken v/s Ith Pop Operation")
plt.legend()
# plt.savefig('/home/rahul/Desktop/PESU/PESU-5THSEM/AA/AA-ASSIGNMENT1/PLOTS/1MILPLOTS/'+sys.argv[3]+'/pop.png')
plt.show()

plt.plot(push,label="push",color="red")
plt.plot(pop,label="pop",color="blue")
plt.ylabel("Time taken in Milliseconds")
plt.xlabel("i-th push and pop")
plt.title("Time taken v/s Ith Push/Pop Operation")
plt.legend()
# plt.savefig('/home/rahul/Desktop/PESU/PESU-5THSEM/AA/AA-ASSIGNMENT1/PLOTS/1MILPLOTS/'+sys.argv[3]+'/push-pop.png')
plt.show()
