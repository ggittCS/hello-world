import csv

#first, construct the weighted graph
#a version of make_link that increments that 
#value of the link if we make multiple nodes
#For the marvel graph, this will be used to count
# how many times character1 is in the same comic
# as character2

def make_link(G, node1, node2, weight):
	if node1 not in G:
		G[node1] = {}
	if node2 not in G[node1]:
		(G[node1])[node2] = weight
	if weight < G[node1][node2]:
		G[node1][node2] = weight
	if node2 not in G:
		G[node2] = {}
	if node1 not in G[node2]:
		(G[node2])[node1] = weight
	if weight < G[node1][node2]:
		G[node2][node1] = weight
	return G 
	
# Reads the graph in CSV format. Each line is an edge
# Keeps a list of characters
tsv = csv.reader(open("imdb-1.txt"), delimiter = '\t')
tsv2 = csv.reader(open("imdb-weights.txt"), delimiter = '\t')

# loop through the raw data creating a bipartite graph
ActMovie = {}
actors = set()
for (act, movie, year) in tsv:
	if act not in actors:
		actors.add(act)
	make_link(ActMovie, act, movie + " " + year, 0)
	
MovieWeights = {}
movies = set()
for (movie, year, weight) in tsv2:
	if movie not in movies:
		movies.add(movie)
	make_link(MovieWeights, movie + " " + year, weight, 0)
	
ActG = {}
for act in actors:
	for movie in ActMovie[act]:
		for act2 in ActMovie[movie]:
			if act < act2:
				make_link(ActG, act, act2, MovieWeights[movie])
			
def val(pair): return pair[0]

def id(pair): return pair[1]

def get_parent(pair): return pair[2]

# modified dijkstra to minimize
# the obscurity instead of distance

import heapq
def dijkstra_min(G,v):
	first_entry = [0, v, None]
	heap = [first_entry]
	obs_so_far = {v:first_entry}
	final_obs = {}
	while len(final_obs) < len(G):
		# find the closest un-explored node
		while True:
			w = heapq.heappop(heap)
			# grab the relevant parts of w 
			node = id(w)
			obscurity = val(w)
			parent = get_parent(w)
			if node != 'REMOVED':
				del obs_so_far[node]
				break
				
		# lock it down!
		final_obs[node] = [obscurity, node, parent]
		# look at its neighbors
		for x in G[node]:
			# but only those that haven't been locked down
			if x not in final_obs:
				# instead of adding obscurities, we set the new distance to the
				# maximum obscurity seen so far
				new_obscurity = max(obscurity, G[node][x])
				new_entry = [new_obscurity, x, node]
				if x not in obs_so_far:
					# we haven't seen this yet
					# so add to the heap and the dictionary
					obs_so_far[x] = new_entry
					heapq.heappush(heap, new_entry)
				elif new_obscurity < val(obs_so_far[x]):
					# the new distance is less than the best known
					# Instead of removing it from the heap
					# which could be expensive, mark it
					obs_so_far[x][1] = "REMOVED"
					# and then add a new entry
					# for this node
					obs_so_far[x] = new_entry
					heapq.heappush(heap, new_entry)
	return final_obs
	
# returns the obscurity score of the
# least obscure score between two actors
def least_obscure(actor1, actor2):
	all_obs = dijkstra_min(ActG, actor1)
	return all_obs[actor2][0]
	
# this might be considered an abuse of defaultdict
# create a defaultdict, where the factory creates another
# defaultdict. The factor of this defaultdict creates entries
# with a MAX_WEIGHT value.
# This has the effect of giving every character to character mapping
# a default value of MAX_WEIGHT 
from collections import defaultdict
MAX_WEIGHT = 1000
def new_entry():
	return defaultdict(lambda:MAX_WEIGHT)
	
actorG = defaultdict(new_entry)

# create a graph with links between actors
# using the least obscure movie between the two of
# them as the weight between the two

answer = {(u'Boone Junior, Mark', u'Del Toro, Benicio'): None,
          (u'Braine, Richard', u'Coogan, Will'): None,
          (u'Byrne, Michael (I)', u'Quinn, Al (I)'): None,
          (u'Cartwright, Veronica', u'Edelstein, Lisa'): None,
          (u'Curry, Jon (II)', u'Wise, Ray (I)'): None,
          (u'Di Benedetto, John', u'Hallgrey, Johnathan'): None,
          (u'Hochendoner, Jeff', u'Cross, Kendall'): None,
          (u'Izquierdo, Ty', u'Kimball, Donna'): None,
          (u'Jace, Michael', u'Snell, Don'): None,
          (u'James, Charity', u'Tuerpe, Paul'): None,
          (u'Kay, Dominic Scott', u'Cathey, Reg E.'): None,
          (u'McCabe, Richard', u'Washington, Denzel'): None,
          (u'Reid, Kevin (I)', u'Affleck, Rab'): None,
          (u'Reid, R.D.', u'Boston, David (IV)'): None,
          (u'Restivo, Steve', u'Preston, Carrie (I)'): None,
          (u'Rodriguez, Ramon (II)', u'Mulrooney, Kelsey'): None,
          (u'Rooker, Michael (I)', u'Grady, Kevin (I)'): None,
          (u'Ruscoe, Alan', u'Thornton, Cooper'): None,
          (u'Sloan, Tina', u'Dever, James D.'): None,
          (u'Wasserman, Jerry', u'Sizemore, Tom'): None}
		  
answer_list = answer.keys()

for (char1, char2) in answer_list:
	print char1, char2, least_obscure(char1, char2), "\n"

#print least_obscure('Boone Junior, Mark', 'Del Toro, Benicio')
#print least_obscure('Braine, Richard', 'Coogan, Will')
#print least_obscure('Byrne, Michael (I)', 'Quinn, Al (I)')
#print least_obscure('Cartwright, Veronica', 'Edelstein, Lisa')
#print least_obscure('Boone Junior, Mark', 'Del Toro, Benicio')