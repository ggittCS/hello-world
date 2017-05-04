from nose.tools import *
from gothonweb.map import *

def test_room():
	gold = Room("GoldRoom", 
						"""This room has gold in it you can grab. There's a
						door to the north.""")
	assert_equal(gold.name, "GoldRoom")
	assert_equal(gold.paths, {})
	
def test_room_paths():
	center = Room("Center", "Test room in the center.")
	north = Room("North", "Test room in the north.")
	south = Room("South", "Test room in the south.")
	
	center.add_paths({'north': north, 'south': south})
	assert_equal(center.go('north'), north)
	assert_equal(center.go('south'), south)
	
def test_map():
	start = Room("Start", "You can go west and down a hole.")
	west = Room("Trees", "There are trees here, you can go east.")
	down = Room("Dungeon", "It's dark down here, you can go up.")
	
	start.add_paths({'west': west, 'down': down})
	west.add_paths({'east': start})
	down.add_paths({'up': start})
	
	assert_equal(start.go('west'), west)
	assert_equal(start.go('west').go('east'), start)
	assert_equal(start.go('down').go('up'), start)

def test_gothon_game_map():
	assert_equal(START.go('shoot!'), cc_shoot_death)
	assert_equal(START.go('dodge!'), cc_dodge_death)
	
	room = START.go('tell a joke')
	assert_equal(room, laser_weapon_armory)
	
	room2 = laser_weapon_armory.go('0132')
	assert_equal(room2, the_bridge)
	assert_equal(laser_weapon_armory.go('*'), lwa_death)
	
	room3 = the_bridge.go('slowly place the bomb')
	assert_equal(room3, escape_pod)
	assert_equal(the_bridge.go('throw the bomb'), bridge_death)
	
	room4 = escape_pod.go('2')
	assert_equal(room4, the_end_winner)
	assert_equal(escape_pod.go('*'), the_end_loser)