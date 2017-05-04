from sys import exit 
import random
import ex45a

class Scene(object):
	
	def enter(self):
		print "This scene is not yet configured. Subclass it and implement enter()."
		exit(1)
		
		
class Math(Scene):
	
	# simple math problems. Need to get 5 right to move to next room.
	def enter(self):
		print "You get invited to your friend's child's birthday party."
		print "The theme of the event is 'School'. Geez this kid is lame."
		print "Then you think about the parents and it makes a lot more sense."
		print "In order to win you must go through multiple rooms without losing."
		print "You are currently in the math room. You must answer five math problems"
		print "in order to go to the next room. All winners gets a surprise."
		
		guesses = 0
		
		while guesses <5:
			first = random.randint(0,9)
			second = random.randint(0,9)
			mult = first * second
			print "What is %d * %d?" % (first, second)
			answer = raw_input("> ")
			if int(float(answer)) == mult:
				print "Correct!"
				guesses += 1
			else:
				print "Wrong! You lose! The correct answer was %d." % mult 
				return 'death'
				
		return 'translate'
		
		
class Translate(Scene):

	#import function that picks random word to translate
	def enter(self):
		print "You made it into the Translate room where you will have to translate"
		print "three words from Italian into English."
		
		guesses = 0
		
		while guesses < 3:
			word = ex45a.translator(ex45a.words)
			print word
		
			answer = raw_input("> ")
		
			if answer == ex45a.words[word]:
				print "Correct!"
				guesses += 1
			else:
				print "Wrong! You lose! The correct answer was %s" % ex45a.words[word]
				return 'death'
				
		return 'history'
			
			
class History(Scene):
		
	#import function that picks random dictionary key and answer is the value
	def enter(self):
		print "You made it into the History room. You will need to list the decade"
		print "that a given event occurred. It should look like '1970's' as an answer."
		print "Get four answers correct to win."
		
		guesses = 0
		
		while guesses < 4:
			date = ex45a.history(ex45a.decades)
			print "What decade was the %s?" % date
			
			answer = raw_input("> ")
			
			if answer == ex45a.decades[date]:
				print "Correct!"
				guesses += 1 
			else:
				print "Wrong! You lose! The correct answer was %s" % ex45a.decades[date]
				return 'death'
				
		return 'finished'
			
class Death(Scene):

	# scene when someone fails
	quips = [
		"This game is made for children... you are stupid!",
		"Maybe you need to go back to elementary school!",
		"Good thing this wasn't for money!",
		"What an idiot! Try again if you can figure out how!"
	]
	
	def enter(self):
		print Death.quips[random.randint(0,len(self.quips)-1)]
		exit(1)
		
		
		
class Finished(Scene):

	def enter(self):
		print "Congrats! You won! You get a piece of cake."
		return 'finished'

		
class Engine(object):
	
	def __init__(self, scene_map):
		self.scene_map = scene_map
		
	def play(self):
		current_scene = self.scene_map.opening_scene()
		last_scene = self.scene_map.next_scene('finished')
		
		while current_scene != last_scene:
			next_scene_name = current_scene.enter()
			current_scene = self.scene_map.next_scene(next_scene_name)
			
		# don't forget to print out the last scene
		current_scene.enter()
		
		
class Map(object):

	scenes = {
		'death': Death(),
		'finished': Finished(),
		'math': Math(),
		'history': History(),
		'translate': Translate()
	}
	
	def __init__(self, start_scene):
		self.start_scene = start_scene
		
	def next_scene(self, scene_name):
		val = Map.scenes.get(scene_name)
		return val 
		
	def opening_scene(self):
		return self.next_scene(self.start_scene)
		
	
a_map = Map('math')
a_game = Engine(a_map)
a_game.play()