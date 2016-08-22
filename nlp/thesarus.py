import sys
import random

from nltk.corpus import wordnet
from nltk import word_tokenize, pos_tag

class Thesarus:

	def synset_2_word(self, synset):
		return synset.lemmas()[0].name()

	def traverse_synset(self, synset, level=1, max_level=3):
		next_level = synset.hyponyms()
		if (next_level is None or \
			level == max_level or \
			len(next_level) == 0):
			return self.synset_2_word(synset)

		next_syn_set = next_level[random.randrange(
			0, 
			len(next_level))]
		return self.traverse_synset(next_syn_set, level + 1)


	def traverse_word(self, word):
		synsets = wordnet.synsets(word)

		return self.traverse_synset(synsets[random.randrange(0, len(synsets))])
	
	def process_sentence(self, sentence):
		ret = ""
		words = pos_tag(word_tokenize(sentence))
		print words
		for word in words:
			if word[1] == 'NN' or word[1] == 'NNS':
				print word[0]
				ret += self.traverse_word(word[0])
			else:
				ret += " %s " % word[0]
		return ret



if __name__ == '__main__':
	thesarus = Thesarus()

	print thesarus.process_sentence(sys.argv[1])

