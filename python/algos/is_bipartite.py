# Write a function, `bipartite` that
# takes as input a graph, `G` and tries
# to divide G into two sets where 
# there are no edges between elements of the
# the same set - only between elements in
# different sets.
# If two sets exists, return one of them
# or `None` otherwise
# Assume G is connected
#

def bipartite(G):
    # your code here
    # return a set
    items = G.keys()
    s1 = []
    s2 = []
    s1_options = []
    s2_options = []
    start = items[0]
    s1_options.append(start)
    while len(s1) + len(s2) < len(G):
        if len(s1_options) > 0:
            x = s1_options.pop()
            s1.append(x)
        for each in G[x]:
            if each not in s2 and each not in s2_options:
                s2_options.append(each)
        if len(s2_options) > 0:
            y = s2_options.pop()
            s2.append(y)
        for every in G[y]:
            if every not in s1 and every not in s1_options:
                s1_options.append(every)
    for node1 in s1:
        for node2 in s2:
            if node1 == node2:
                return None
    return set(s1)
            
        


########
#
# Test

def make_link(G, node1, node2, weight=1):
    if node1 not in G:
        G[node1] = {}
    (G[node1])[node2] = weight
    if node2 not in G:
        G[node2] = {}
    (G[node2])[node1] = weight
    return G


def test():
    edges = [(1, 2), (2, 3), (1, 4), (2, 5),
             (3, 8), (5, 6)]
    G = {}
    for n1, n2 in edges:
        make_link(G, n1, n2)
    g1 = bipartite(G)
    assert (g1 == set([1, 3, 5]) or
            g1 == set([2, 4, 6, 8]))
    edges = [(1, 2), (1, 3), (2, 3)]
    G = {}
    for n1, n2 in edges:
        make_link(G, n1, n2)
    g1 = bipartite(G)
    assert g1 == None
    
print test()