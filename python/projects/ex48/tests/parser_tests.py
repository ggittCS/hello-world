# parser tests

from nose.tools import *
from ex48.parser import *

def test_sentence_class():
	# test each part of the sentence
	sent = Sentence(('noun', 'princess'), ('verb', 'eats'), ('noun', 'cake'))
	assert_equal(sent.subject, 'princess')
	assert_equal(sent.verb, 'eats')
	assert_equal(sent.object, 'cake')
	
def test_peek():
	# test when there are multiple words and no words to cover all scenarios.
	word_list = [('noun', 'princess'), ('verb', 'eats'), ('noun', 'cake')]
	word = peek(word_list)
	no_word = peek([])
	assert_equal(word, 'noun')
	assert_equal(no_word, None)
	
def test_match():
	# three scenarios are the first word matches the 'expecting', doesn't match 
	# expecting, and there are no words at all to match.
	word_list = [('noun', 'princess'), ('verb', 'eats'), ('noun', 'cake')]
	word_list2 = [('noun', 'princess'), ('verb', 'eats'), ('noun', 'cake')]
	word_right = match(word_list, 'noun')
	word_wrong = match(word_list2, 'verb')
	no_word = match([], 'noun')
	assert_equal(word_right, ('noun', 'princess'))
	assert_equal(word_wrong, None)
	assert_equal(no_word, None)
	assert_equal(word_list, [('verb', 'eats'), ('noun', 'cake')])
	
def test_skip():
	# test scenario with a skip and without a skip to see if word_list changed
	word_list = [('noun', 'princess'), ('verb', 'eats'), ('noun', 'cake')]
	word_list2 = [('noun', 'princess'), ('verb', 'eats'), ('noun', 'cake')]
	skip(word_list, 'noun')
	skip(word_list2, 'verb')
	assert_equal(word_list, [('verb', 'eats'), ('noun', 'cake')])
	assert_equal(word_list2, [('noun', 'princess'), ('verb', 'eats'), ('noun', 'cake')])
	
	
def test_parse_verb():
	# check to make sure its skips over "stops", check to make sure it presents
	# an error when it should, and check to make sure it returns a verb when it should
	# also make sure it removes the word from the list. 
	word_list = [('stop', 'the'), ('noun', 'princess'), ('verb', 'eats'), ('noun', 'cake')]
	word_list2 = [('stop', 'the'), ('verb', 'eats'), ('noun', 'cake')]
	right_word = parse_verb(word_list2)
	assert_equal(word_list2, [('noun', 'cake')])
	assert_equal(right_word, ('verb', 'eats'))
	assert_raises(ParserError, parse_verb, word_list)
	
def test_parse_object():
	# check if it skips over "stop" words. Check if it works for both nouns and directions
	# raise an assertion error for wrong words.
	word_list = [('stop', 'the'), ('noun', 'princess'), ('verb', 'eats'), ('noun', 'cake')]
	word_list2 = [('stop', 'the'), ('verb', 'eats'), ('noun', 'cake')]
	word_list3 = [('stop', 'the'), ('direction', 'west'), ('verb', 'eats'), ('noun', 'cake')]
	right_word = parse_object(word_list)
	right_word2 = parse_object(word_list3)
	assert_equal(word_list, [('verb', 'eats'), ('noun', 'cake')])
	assert_equal(right_word, ('noun', 'princess'))
	assert_equal(right_word2, ('direction', 'west'))
	assert_raises(ParserError, parse_object, word_list2)
	
def test_parse_subject():
	# check if it skip over "stop" words. Check if it works for nouns or a verb is next.
	# check that it raises an assertion error on other words.
	word_list = [('stop', 'the'), ('noun', 'princess'), ('verb', 'eats'), ('noun', 'cake')]
	word_list2 = [('stop', 'the'), ('verb', 'eats'), ('noun', 'cake')]
	word_list3 = [('stop', 'the'), ('direction', 'west'), ('verb', 'eats'), ('noun', 'cake')]
	right_word = parse_subject(word_list)
	right_word2 = parse_subject(word_list2)
	assert_equal(word_list, [('verb', 'eats'), ('noun', 'cake')])
	assert_equal(right_word, ('noun', 'princess'))
	assert_equal(right_word2, ('noun', 'player'))
	assert_raises(ParserError, parse_subject, word_list3)
	
def test_parse_sentence():
	# check that it gives back an instance of a Sentence class. Make sure it gives
	# an error at the right times when the sentence makes no sense.
	word_list = [('stop', 'the'), ('noun', 'princess'), ('verb', 'eats'), ('stop', 'the'), ('noun', 'cake')]
	word_list2 = [('stop', 'the'), ('verb', 'eats'), ('noun', 'cake')]
	word_list3 = [('stop', 'the'), ('direction', 'west'), ('verb', 'eats'), ('noun', 'cake')]
	word_list4 = [('stop', 'the'), ('noun', 'princess'), ('verb', 'eats'), ('stop', 'the'), ('verb', 'take')]
	sent = parse_sentence(word_list)
	sent2 = parse_sentence(word_list2)
	assert_equal(sent.subject, 'princess')
	assert_equal(sent.verb, 'eats')
	assert_equal(sent.object, 'cake')
	assert_equal(sent2.subject, 'player')
	assert_equal(sent2.verb, 'eats')
	assert_equal(sent2.object, 'cake')
	assert_raises(ParserError, parse_sentence, word_list3)
	assert_raises(ParserError, parse_sentence, word_list4)
	
	
	
	
	
	
