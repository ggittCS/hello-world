# Removing tags to only be left with a list of words

def remove_tag(string):
    start = string.find('<')
    while start != -1:
        end = string.find('>',start)
        string = string[:start] + " " + string[end + 1:]
        start = string.find('<')
    return string.split()