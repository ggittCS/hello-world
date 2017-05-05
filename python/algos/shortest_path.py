# Actual shortest path (converted from formula above)
def path(G,v1,v2):
    distance_from_start = {}
    open_list = [v1]
    distance_from_start[v1] = [v1]
    while len(open_list) > 0:
        current = open_list[0]
        del open_list[0]
        for neighbor in G[current].keys():
            if neighbor not in distance_from_start:
                distance_from_start[neighbor] = distance_from_start[current] + [neighbor]
                if neighbor == v2: return distance_from_start[v2]
                open_list.append(neighbor)
    return False