#!/usr/bin/python
#this piece of code checks how consensus is reached among the agents in a naming game. "dim" defines the number of agents taking part, and "ran" is the maximum times two of them will be randomly selected to play the naming game. The game is like this: each have a word for some object in the beginning, and since the words are random, we may assume they are unique. Now two are chosen in random, one reads out the vocabulary to the other. If they find they call the thing by the same name, they remove all other words from their vocabulary and keeps that one. If it is not so, they collect all the words in both their vocabularies and use the new collection as their vocabulary. Next time, again two random agents are chosen and the game is played. This goes on until (a) consensus has been reached or (b) maximum limit of choosing two agents is reached.
#variables to be varied: 1. dim : number of agents in the system, 2. ran: maximum number of times two random agents will play the game.
from random import *
from math import *
from string import *
c1=1	#just two integers
c2=1
aList = []	#the list of agents
tempList = []	#temporary list to contain the modifications
dim = 1000 #number of agents in the system
ran = 100000 # How many times two randomly selected agents converse
#generate random array for the object
for i in xrange(dim):
    aList.append([]) #adding a list of for each agent
    n=int(floor(2+3*random()))	#selecting the word size for the agent, with the words being minimum 2 and max 5 letters
    aList[i].append("".join(sample(ascii_lowercase*n,n))) #populating the vocabulary of the agent with one word, with all small letters
#comparison algo
#calculating total number of different words for the same thing right in the beginning
fList = [] #total different words list
for i in xrange(dim):		#selecting an agent
    pcounter = len(aList[i]) #obtaining the length of vocabulary of the agent
    for j in xrange(pcounter):	
    	fList.append(aList[i][j])	#putting the vocabulary of the agent in the list of all different words
fList=list(set(fList)) #removing duplicates, if any (chances are pretty less...)
wordsize = len(fList)		#size of the list
print '-1', wordsize
excounter=0 #a counter, usage will be explained later
for l in xrange(ran): #agents begin to talk
    i = int(floor(dim*random())) #two agents are randomly selected
    j = int(floor(dim*random())) 
    l1 = len(aList[i])	#their vocabulary sizes are determined
    l2 = len(aList[j])
    match = False	#it is assumed that they don't call the same thing by the same word at all
    for c1 in xrange(l1):	#word per word comparison is done
        str1 = aList[i][c1]
	counter = 0
       # print str1
        for c2 in xrange(l2):
            if str1 == aList[j][c2]:
                match = True	#in case we find they have the same word for the thing, we quit both loops
                str2 = str1
		break
		break
            else:
                tempList.append(aList[j][c2])	#otherwise we add both items in a new list
		if counter == 0 :
		    tempList.append(str1) #we try to add "str1" only once to tempList, so as to avoid duplicates
		    counter = 1
    tempList = list(set(tempList))	#we make sure the new list does not contain the same item multiple times
    if match == True: #for a match, we update the vocabularies of both agents with the same word only
         aList[i]=aList[j]=[str2]
    else:	#else, we update the vocabularies of both agents with the collection of their vocabularies
        aList[i]=aList[j]=tempList
    tempList=[]	#we blank the temporary space
    #aList[i]=list(set(aList[i]))
    #aList[j]=list(set(aList[j]))
    #this part is again obtaining the number of different words present in the vocabulary after 2 random agents have talked.
    fList = []
    for m in xrange(dim):
        pcounter = len(aList[m])
        for q in xrange(pcounter):
            fList.append(aList[m][q])
    fList=list(set(fList))
    wordsize = len(fList)
    print l, wordsize #prints the number of different words in the system after l runs.
    if wordsize == 1: #when we have one word in the vocabulary, we increase the counter by 1 for each run (runs dont modify when we have consensus)
    	excounter+=1
    if excounter == 10: #this is the case when the loop stops executing unnecessarily
    	break
    

#for i in xrange(dim): #after we have made them talk enough, we see what remains of the vocabularies of the agents.
#	print aList[i]
#print aList
