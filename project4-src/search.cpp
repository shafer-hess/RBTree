#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <locale>

#include "Node.h"
#include "RBTree.h"
using namespace std;

string toLower(string &text) {
	for(int i = 0; i < text.length(); i++) {
		if(text[i] <= 'Z' && text[i] >= 'A') {
			text[i] -= ('Z' - 'z');
		}
	}
	return text;
}
/*
bool compareURL(pair<string,int> URL1, pair<string,int> URL2) {
	return URL1.first < URL2.first;
}

bool compareFrequencies(pair<string,int> freq1, pair<string,int> freq2) {
	return freq1.second > freq2.second;
}
*/
// Input stream operator overload for node elements
istream& operator>>(istream& in, vector<pair<string, int>>& e);
bool compareURL(pair<string,int> URL1, pair<string,int> URL2);
bool compareFrequencies(pair<string,int> freq1, pair<string,int> freq2);

int main(int argc, char** argv) {
	// Implement your search code here
	if(argc < 3 || argc > 7) { cout << "Invalid Syntax" << endl; return 0; }
	
	//Capture file name, open file, check file status
	string inFile = argv[1];	
	ifstream fin;
	fin.open(inFile);
	if(!fin.good()) { cout << "Invalid File" << endl; return 0; }
	
	//Create and load RBTree from file
	RBTree<string,vector<pair<string,int>>> tree;
	fin >> tree;

	//Cycle through all search terms and add to vector as lowercase strings
	int numWords = argc;
	vector<string> queries;
	for(int i = 2; i < numWords; i++) {
		string word = argv[i];
		word = toLower(word);
		queries.push_back(word);
	}
	
	//Print Captured Queries
	/*	
	cout << "CAPTURED QUERIES:" << endl;
	for(int i = 0; i < queries.size(); i++) {
		cout << i+1 << ": " << queries[i] << endl;
	}
	*/	

	//Search tree for word
	vector<vector<pair<string,int>>> foundWords;
	vector<pair<string,int>> element;
	for(int i = 0; i < queries.size(); i++) {
		Node<string,vector<pair<string,int>>> * node = tree.search(queries[i]);
		//if(node == NULL) { cout << "NULL" << endl; }
		if(node == NULL) {
			foundWords.push_back({});
		}
		else {
			element = node->getElement();
			foundWords.push_back(element);
		}
	}

	//if(foundWords.size() == 0) { cout << "Not found" << endl; return 0;}
	
	//cout << "FOUND WORD: " << foundWords.size() << endl;
		
	vector<pair<string,int>> intersections;
	while(foundWords.size() > 1) {
		vector<pair<string,int>> v1 = foundWords.back();
		foundWords.pop_back();
		vector<pair<string,int>> v2 = foundWords.back();
		foundWords.pop_back();

		vector<pair<string,int>> list;

		sort(v1.begin(), v1.end(), compareURL);
		sort(v2.begin(), v2.end(), compareURL);

		int i = 0;
		int j = 0;
		while(i < v1.size() && j < v2.size()) {
			//cout << "reached" << endl;
			if(v1.at(i).first < v2.at(j).first) {
				i++;
			}
			else if(v1.at(i).first > v2.at(j).first) {
				j++;
			}
			else if(v1.at(i).first == v2.at(j).first) {
				//cout << "reached" << endl;
				int frequency = v1.at(i).second + v2.at(j).second;
				pair<string,int> pair = make_pair(v1.at(i).first, frequency);
				list.push_back(pair);
				i++;
				j++;
			}
		}
		foundWords.push_back(list);
	}
	
	intersections = foundWords.back();
	foundWords.pop_back();	

	sort(intersections.begin(), intersections.end(), compareURL);
	sort(intersections.begin(), intersections.end(), compareFrequencies);
	
	if(intersections.size() == 0) { cout << "Not found" << endl; }
	
	else {
		for(int i = 0; i < intersections.size(); i++) {
			cout << intersections[i].first << " " << intersections[i].second << endl;
		}
	}
	
	return 0;
}
bool compareURL(pair<string,int> URL1, pair<string,int> URL2) {
	return URL1.first < URL2.first;
}

bool compareFrequencies(pair<string,int> freq1, pair<string,int> freq2) {
	return freq1.second > freq2.second;
}

// This function overloads the input stream operator for Node
// elements. It has been provided to you and does not need to be
// altered.
istream& operator>>(istream& in, vector<pair<string, int>>& e) {
	// Clear any existing contents
	e.clear();

	// Read the number of elements
	size_t n;
	in >> n;
	for (int i = 0; i < n; i++) {
		// Read each member of each pair the vector stores
		string u;
		in >> u;
		int f;
		in >> f;
		// Add to vector
		e.push_back(make_pair(u, f));
	}

	return in;
}
