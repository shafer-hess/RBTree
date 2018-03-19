#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "SimpleHTMLParser.h"
#include "RBTree.h"

using namespace std;

vector<string> toVector(string text) {

	istringstream sin(text);
	vector<string> words;
	
	string word;
	while(sin >> word) {
		words.push_back(word);
	}

	/*	
	for(vector<string>::iterator it = words.begin(); it != words.end(); it++) {
		cout << *it << endl;
	}
	*/

	return words;

}
// Output stream operator overload for node elements
ostream& operator<<(ostream& out, const vector<pair<string, int>>& e);

int main(int argc, char** argv) {
	// Implement your scan code here

	if(argc > 3) { 
		cout << "Too many Arguments" << endl;
		return 0;
	}
	
	//Gather Arguments from command line
	string arg1 = argv[1]; //filein
	string arg2 = argv[2]; //fileout

	ifstream fin;
	fin.open(arg1);
	if(!fin.good()) { cout << "No File" << endl; return 0; }	


	ofstream fout;
	fout.open(arg2);
	if(!fout.good()) { cout << "No OutFile" << endl; return 0; }

	SimpleHTMLParser * html = new SimpleHTMLParser();	
	RBTree<string, vector<pair<string,int>>> * tree = new RBTree<string, vector<pair<string, int>>>();

	int numLines;
	fin >> numLines;
	//cout << numLines << endl;
	
	string catchBlank;
	getline(fin, catchBlank);
	
	string line;
	while(getline(fin, line)) {
		//cout << lines << endl;
		html->parse(line);
		string text = html->getText();
		//cout << text << endl;
		vector<string> words = toVector(text);
		
		for(vector<string>::iterator it = words.begin(); it != words.end(); it++) {
			Node<string, vector<pair<string,int>>> * node = tree->search(*it);

			if(node == NULL) {
				//Create vector with url and word frequency
				vector<pair<string,int>> list;
				pair<string,int> frequency = make_pair(line, 1);
				//cout << line << endl;
				//cout << frequency.first << " " << frequency.second << endl;
				list.push_back(frequency);
				
				//Create node with key = current word and element = list vector
				node = new Node<string, vector<pair<string,int>>>();
				node->setKey(*it);
				node->setElement(list);
				tree->insert(node->getKey(), node->getElement());
			}	
		
			else {
				vector<pair<string,int>>& element = node->getElement();
				//cout << element[0].first << " " << element[0].second << endl;
				
				int found = 0;
				for(int i = 0; i < element.size(); i++) {
					if(element[i].first == line) {
						element[i].second = element[i].second + 1;
						found = 1;
					}
				}
				if(!found) {
					pair<string,int> newUrl = make_pair(line, 1);
					element.push_back(newUrl);
				}	
			}	
		}		
		//tree->inorder(cout);
	}

	fout << *tree;
	fout << endl;
	//tree->inorder(cout);

	return 0;
}


// This function overloads the output stream operator for Node
// elements. It has been provided to you and does not need to be
// altered.
ostream& operator<<(ostream& out, const vector<pair<string, int>>& e) {
	// Write the number of elements in the vector
	out << e.size() << endl;
	for (auto& uf : e)
		// Write each member of each pair the vector stores
		out << uf.first << " " << uf.second << endl;
	return out;
}
