# main file 

def convert_number(s):
	try:
		return int(s)
	except ValueError:
		return None 

def scan(word):
	""" breaks down directions into a list of tuples."""
	directions = ['north', 'south', 'east', 'west', 'down', 'up', 'left', 'right', 'back']
	verbs = ['go', 'stop', 'kill', 'eat']
	stop_words = ['the', 'in', 'of', 'from', 'at', 'it']
	nouns = ['door', 'bear', 'princess', 'cabinet']
	words = word.split()
	result = []
	for each in words:
		if each.lower() in directions:
			result.append(('direction', each))
		elif each.lower() in verbs:
			result.append(('verb', each))
		elif each.lower() in stop_words:
			result.append(('stop', each))
		elif each.lower() in nouns:
			result. append(('noun', each))
		elif convert_number(each):
			result.append(('number', convert_number(each)))
		else:
			result.append(('error', each))
	return result 
	