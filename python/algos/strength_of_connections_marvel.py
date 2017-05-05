#using marvel_characters file on my computer

def make_link(G, node1, node2):
    if node1 not in G:
        G[node1] = {}
    if node2 not in G[node1]:
        (G[node1])[node2] = 0
    (G[node1])[node2] += 1
    if node2 not in G:
        G[node2] = {}
    if node1 not in G[node2]:
        (G[node2])[node1] = 0
    (G[node2])[node1] += 1
    return G


def read_graph2(filename):
    tsv = open(filename, 'r')
    G = {}
    for line in tsv:
      line = line.strip('\n')
      line = line.replace('"','')
      (node1,node2) = line.rsplit('\t')
      make_link(G, node1, node2)
    return G
    
def read_characters(filename):
    tsv = open(filename, 'r')
    char = []
    for line in tsv:
      line = line.strip('\n')
      line = line.replace('"','')
      (node1,node2) = line.rsplit('\t')
      if node1 not in char:
        char.append(node1)
    return char
    
marvelG = read_graph2('file2.py')
characters = read_characters('file2.py')

marvelCharG = {}
for char1 in characters:
  for book in marvelG[char1]:
    for char2 in marvelG[book]:
      if char1 < char2:
        make_link(marvelCharG,char1,char2)

highest = (-1, 'none', 'none')
for char1 in marvelCharG:
    for char2 in marvelCharG[char1]:
        if char1 < char2:
            link = (marvelCharG[char1][char2], char1, char2)
            if link > highest:
                highest = link
print highest