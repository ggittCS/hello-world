def find_eulerian_tour(graph):
    # your code here
    tour = []
    new = graph
    visited = []
    visited.append(graph[0])
    tour.append(graph[0][0])
    tour.append(graph[0][1])
    current = graph[0][1]
    while len(visited) != len(graph):
        for tup in graph:
            if tup not in visited:
                if tup[0] == current:
                    tour.append(tup[1])
                    visited.append(tup)
                if tup[1] == current:
                    tour.append(tup[0])
                    visited.append(tup)
                if tup[0] == current:
                    current = tup[1]
                else:
                    if tup[1] == current:
                        current = tup[0]
    return tour
    



def next_node(edge, current):
    return edge[0] if current == edge[1] else edge[1]

def remove_edge(raw_list, discard):
    return [item for item in raw_list if item != discard]

def find_eulerian_tour(graph):
    search = [[[], graph[0][0], graph]]
    while search:
        path, node, unexplore = search.pop()
        path += [node]

        if not unexplore:
            return path

        for edge in unexplore:
            if node in edge:
                search += [[path, next_node(edge, node), remove_edge(unexplore, edge)]]
                
                
SUCCESS: Test case input: [(1, 2), (2, 3), (3, 1)]


SUCCESS: Test case input: [(0, 1), (1, 5), (1, 7), (4, 5),
(4, 8), (1, 6), (3, 7), (5, 9),
(2, 4), (0, 4), (2, 5), (3, 6), (8, 9)]


SUCCESS: Test case input: [(1, 13), (1, 6), (6, 11), (3, 13),
(8, 13), (0, 6), (8, 9),(5, 9), (2, 6), (6, 10), (7, 9),
(1, 12), (4, 12), (5, 14), (0, 1),  (2, 3), (4, 11), (6, 9),
(7, 14),  (10, 13)]


SUCCESS: Test case input: [(8, 16), (8, 18), (16, 17), (18, 19),
(3, 17), (13, 17), (5, 13),(3, 4), (0, 18), (3, 14), (11, 14),
(1, 8), (1, 9), (4, 12), (2, 19),(1, 10), (7, 9), (13, 15),
(6, 12), (0, 1), (2, 11), (3, 18), (5, 6), (7, 15), (8, 13), (10, 17)]