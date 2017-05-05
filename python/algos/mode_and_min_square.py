def mode(L):
    # your code here
    dic_list = {}
    for num in L:
        if num not in dic_list:
            dic_list[num] = 1
        if num in dic_list:
            dic_list[num] += 1
    x = max(dic_list.values())
    for elem in dic_list.keys():
        if dic_list[elem] == x:
            return elem
    return None
    

# Given a list of numbers, L, find a number, x, that
# minimizes the sum of the square of the difference
# between each element in L and x: SUM_{i=0}^{n-1} (L[i] - x)^2
# 
# Your code should run in Theta(n) time
# 


def minimize_square(L):
    x = sum(L)
    return (x+0.0)/len(L)