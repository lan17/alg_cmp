// program to perform autocomplete and word selection akin to t9word for a given prefix string in O(largestwordlength)
// should be easy to include freqency data.
// adding a new word currently requires recompiling the list.
// John Buether (darkteal@gmail.com)

#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iterator>
using namespace std;

const char* KMAP[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
const unsigned short KNO = sizeof(KMAP);
unsigned short bindex[256];

void buildbindex(){
	for (int i = 0; i < sizeof(KMAP)/sizeof(char*); i++){
		int j = 0;
		for (char c = KMAP[i][0]; c!=0; c = KMAP[i][j++]){ //should be okay.
			bindex[(int)toupper(c)] = i;
			bindex[(int)tolower(c)] = i;
		}
	}
}

struct Node {
	int list;
	unsigned int length;
	unsigned int mylength;
	Node* children[KNO];
};

struct BuildNode{
	BuildNode(){
		final = new Node();
		for (int i =0; i < KNO; i++){
			final->children[i] = 0;
			children[i] = 0;
		}
		final->length = 0;
		final->mylength = 0;
	}
	vector<string> words;
	BuildNode* children[KNO];
	Node* final;
};

BuildNode* getNextBNode ( BuildNode* node, char c){
	node->final->length++;
	if ( node->children[bindex[c]] == 0 ){
		node->children[bindex[c]] = new BuildNode();
		node->final->children[bindex[c]] = node->children[bindex[c]]->final;
	}
	node->final->length++;
	return node->children[bindex[c]];
}

//statefull insert can be done in ammortized N time on a prealphabetized list so long as the character mappings are grouped aphabetically, but I am lazy.
void insert(string word, BuildNode* node){
	for (int i = 0; i < word.size(); i++)
		node = getNextBNode(node,word[i]);
	node->words.push_back(word);
	node->final->length++;
}

Node* find (string query, Node* node){
	if (!node) return 0;
	for(int i = 0; i < query.size(); i++){
		char c = query[i];
		if (!node->children[bindex[c]])
			return 0;
		node = node->children[bindex[c]];
	}
	return node;
}

main(int argc, char** argv){
	vector<string> masterlist;
	BuildNode* broot = new BuildNode();
	Node* root = broot->final;
	
	buildbindex();

	cout << "building prefix tree..." << endl;
	
	//build builder tree from dictionary file
	//probably can't deduce the correct
	ifstream file(argv[1]);
	istream_iterator<string> eos;
	istream_iterator<string> words(file);
	while(words!=eos)
		insert(*(words++),broot);

	cout << "colapsing prefix tree into bindex..." << endl;
		
	//collapse builder tree and write master list
	stack<pair<BuildNode*,int> > tree;
	tree.push(make_pair(broot, 0) );
	while(!tree.empty()){	
		int& child = tree.top().second;
		BuildNode* node = tree.top().first;
		if ( child >= KNO ){
			delete tree.top().first;
			tree.pop();
			continue;
		}
		BuildNode* next = node->children[child++]; // make sure this updates the one in thte stack
		if (next == NULL)
			continue;
		for(int i = 0; i < next->words.size(); i++)
			masterlist.push_back(next->words[i]);
		next->final->list = masterlist.size() - next->words.size(); //THIS MAY CREATE BAD bindexES FOR THE LAST NODE
		next->final->mylength = next->words.size();
		tree.push(make_pair(next,0));
	}
	
	cout << "preview master list?";
	char yn;
	cin >> yn;
	if (tolower(yn) == 'y')
		for (int i = 0; i < masterlist.size(); i++)
			cout << masterlist[i] << endl;


	cout << "ready for queries." << endl;	
		
	//take queries
	while (1){
		string query;
		cin >> query;
		Node* result = find (query, root);
		if (!result || !result->length)
			cout << "no results found" << endl;
		else{
			printf("%i results found, %i with this prefix, first of which is: %s\n", result->mylength, result->length, masterlist[result->list].c_str());
		}
	}		
}
