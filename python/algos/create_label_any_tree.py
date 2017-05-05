# This is the same problem as "Distance Oracle I" except that instead of
# only having to deal with binary trees, the assignment asks you to
# create labels for all tree graphs.
#
# In the shortest-path oracle described in Andrew Goldberg's
# interview, each node has a label, which is a list of some other
# nodes in the network and their distance to these nodes.  These lists
# have the property that
#
#  (1) for any pair of nodes (x,y) in the network, their lists will
#  have at least one node z in common
#
#  (2) the shortest path from x to y will go through z.
# 
# Given a graph G that is a tree, preprocess the graph to
# create such labels for each node.  Note that the size of the list in
# each label should not be larger than log n for a graph of size n.
#

#
# create_labels takes in a tree and returns a dictionary, mapping each
# node to its label
#
# a label is a dictionary mapping another node and the distance to
# that node
#

import heapq
from collections import deque

def bfs_fast(G, start):
    to_visit = deque()
    to_visit.append(start)
    dist = {start: True}
    last = None
    while to_visit:
        u = to_visit.popleft()
        last = u
        for v in G[u]:
            if v not in dist:
                dist[v] = True
                to_visit.append(v)
    return last
    
def bfs_parent(G, start):
    to_visit = deque()
    to_visit.append(start)
    dists = {start:0}
    parents = {start:None}
    last = None
    while to_visit:
        u = to_visit.popleft()
        last = u
        for v in G[u]:
            if v not in dists:
                dists[v] = dists[u] + 1
                parents[v] = u
                to_visit.append(v)
    return last, dists, parents
    
def dijkstra_with_labels(G,start,labels):
    H = [(0,start)]
    heapq.heapify(H)
    distances = {start:0}
    while H:
        val, w = heapq.heappop(H)
        labels[w][start] = val
        for x in G[w]:
            newdist = val + G[w][x]
            if x not in distances:
                distances[x] = newdist
                heapq.heappush(H, (newdist,x))
                
def find_tree_center(G,start):
    last = bfs_fast(G,start)
    last, dists, parents = bfs_parent(G,last)
    center_dist = (dists[last] + 1) // 2 
    center = last
    while dists[center] != center_dist:
        center = parents[center]
    return center
    
def create_labels(treeG):
    labels = {}
    # your code here
    for u in treeG:
        labels[u] = {}
    broken_links = deque()
    to_visit = deque()
    to_visit.append(next(iter(treeG.keys())))
    while to_visit:
        node = to_visit.pop()
        center = find_tree_center(treeG, node)
        dijkstra_with_labels(treeG,center,labels)
        for u in list(treeG[center]):
            if len(treeG[u]) > 1:  # only enqueue branches that are not leaves
                to_visit.append(u)
                broken_links.append((center, u, treeG[center][u]))
                del treeG[center][u]
                del treeG[u][center]
            else: # leaf, only add distance to itself
                labels[u][u] = 0
    while broken_links:
        u, v, w = broken_links.pop()
        treeG[u][v] = w
        treeG[v][u] = w
    return labels


#######
# Testing
#


def get_distances(G, labels):
    # labels = {a:{b: distance from a to b,
    #              c: distance from a to c}}
    # create a mapping of all distances for
    # all nodes
    distances = {}
    for start in G:
        # get all the labels for my starting node
        label_node = labels[start]
        s_distances = {}
        for destination in G:
            shortest = float('inf')
            # get all the labels for the destination node
            label_dest = labels[destination]
            # and then merge them together, saving the
            # shortest distance
            for intermediate_node, dist in label_node.iteritems():
                # see if intermediate_node is our destination
                # if it is we can stop - we know that is
                # the shortest path
                if intermediate_node == destination:
                    shortest = dist
                    break
                other_dist = label_dest.get(intermediate_node)
                if other_dist is None:
                    continue
                if other_dist + dist < shortest:
                    shortest = other_dist + dist
            s_distances[destination] = shortest
        distances[start] = s_distances
    return distances

def make_link(G, node1, node2, weight=1):
    if node1 not in G:
        G[node1] = {}
    (G[node1])[node2] = weight
    if node2 not in G:
        G[node2] = {}
    (G[node2])[node1] = weight
    return G

def test():
    edges = [(1, 2), (1, 3), (2, 4), (2, 5), (3, 6), (3, 7),
             (4, 8), (4, 9), (5, 10), (5, 11), (6, 12), (6, 13)]
    tree = {}
    for n1, n2 in edges:
        make_link(tree, n1, n2)
    labels = create_labels(tree)
    distances = get_distances(tree, labels)
    assert distances[1][2] == 1
    assert distances[1][4] == 2
    