# Take a weighted graph representing a social network where the weight
# between two nodes is the "love" between them.  In this "feel the
# love of a path" problem, we want to find the best path from node `i`
# and node `j` where the score for a path is the maximum love of an
# edge on this path. If there is no path from `i` to `j` return
# `None`.  The returned path doesn't need to be simple, ie it can
# contain cycles or repeated vertices.
#
# Devise and implement an algorithm for this problem.
#

def path(G,v1,v2):
    # uses breadth first search
    if v1 == v2:
        return [v1]
    path_from_start = {}
    open_list = [v1]
    path_from_start[v1] = [v1]
    while len(open_list) > 0:
        current = open_list[0]
        del open_list[0]
        for neighbor in G[current].keys():
            if neighbor not in path_from_start:
                path_from_start[neighbor] = path_from_start[current] + [neighbor]
                if neighbor == v2:
                    return path_from_start[v2]
                open_list.append(neighbor)
    return False


def feel_the_love(G, i, j):
    # return a path (a list of nodes) between `i` and `j`,
    # with `i` as the first node and `j` as the last node,
    # or None if no path exists
    discovered = []
    open_list = [i]
    max_score = 0
    max_score_edge = []
    while len(open_list) > 0:
        current = open_list[0]
        discovered.append(current)
        del open_list[0]
        for neighbor in G[current].keys():
            # to find the max score edge
            if neighbor not in discovered:
                open_list.append(neighbor)
                if G[current][neighbor] >= max_score:
                    max_score = G[current][neighbor]
                    max_score_edge = [current,neighbor]
    # if no path from i to j exists then return None
    if j not in discovered:
        return None
    return path(G, i, max_score_edge[0]) + path(G, max_score_edge[1], j)

#########
#
# Test

def score_of_path(G, path):
    max_love = -float('inf')
    for n1, n2 in zip(path[:-1], path[1:]):
        love = G[n1][n2]
        if love > max_love:
            max_love = love
    return max_love

def test():
    G = {'a':{'c':1},
         'b':{'c':1},
         'c':{'a':1, 'b':1, 'e':1, 'd':1},
         'e':{'c':1, 'd':2},
         'd':{'e':2, 'c':1},
         'f':{}}
    path = feel_the_love(G, 'a', 'b')
    assert score_of_path(G, path) == 2

    path = feel_the_love(G, 'a', 'f')
    assert path == None