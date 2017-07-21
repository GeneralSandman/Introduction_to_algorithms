test:trie_tree.o test.o
	g++ -o test trie_tree.o test.o

trie_tree.o:trie_tree.cc
	g++ -std=c++11 -c trie_tree.cc

test.o:test.cc
	g++ -std=c++11 -c test.cc

clean:
	rm *.o
	rm test