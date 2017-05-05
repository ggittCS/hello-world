def is_reciprocal_link(graph, source, destination, k):
    if k == 0:
        if destination == source:
            return True
        return False
    if source in graph[destination]:
        return True
    for node in graph[destination]:
        if is_reciprocal_link(graph, source, node, k-1):
            return True
    return False