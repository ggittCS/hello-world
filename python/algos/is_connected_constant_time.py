# Design and implement an algorithm that can preprocess a
# graph and then answer the question "is x connected to y in the
# graph" for any x and y in constant time Theta(1).
#

#
# `process_graph` will be called only once on each graph.  If you want,
# you can store whatever information you need for `is_connected` in
# global variables
#

processedG = {}

def bfs(G,root):
    open_list = [root]
    set_root = [root]
    while len(open_list) > 0:
        current = open_list[0]
        del open_list[0]
        for neighbor in G[current].keys():
            if neighbor not in set_root:
                open_list.append(neighbor)
                set_root.append(neighbor)
    return set_root

def process_graph(G):
    # your code here
    nodes = G.keys()
    color = 0
    while nodes:
        root = nodes.pop()
        nodes.append(root)
        set_root = bfs(G,root)
        for reach in set_root:
            processedG[reach] = color
            del nodes[nodes.index(reach)]
        color += 1
    pass


#
# When being graded, `is_connected` will be called
# many times so this routine needs to be quick
#
def is_connected(i, j):
    # your code here
    return processedG[i] == processedG[j]

#######
# Testing
#
def test():
    G = {'a':{'b':1},
         'b':{'a':1},
         'c':{'d':1},
         'd':{'c':1},
         'e':{}}
    process_graph(G)
    assert is_connected('a', 'b') == True
    assert is_connected('a', 'c') == False

    G = {'a':{'b':1, 'c':1},
         'b':{'a':1},
         'c':{'d':1, 'a':1},
         'd':{'c':1},
         'e':{}}
    process_graph(G)
    assert is_connected('a', 'b') == True
    assert is_connected('a', 'c') == True
    assert is_connected('a', 'e') == False