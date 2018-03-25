#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>

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
void sortVectorFrequencies(vector<pair<string,int>> &vector) {
	for(int i = 0; i < vector.size(); i++) {
		for(int j = i + 1; j < vector.size() - 1; j++) {
			if(vector[i].second < vector[j].second) {
				//Swap
				string temp = vector[i].first;
				int frequency = vector[i].second;
				
				vector[i].first = vector[j].first;
				vector[i].second = vector[j].second;
	
				vector[j].first = temp;
				vector[j].second = frequency;
			}
		}
	}
}

void sortVectorURL(vector<pair<string,int>>& vector) {
	for(int i = 0; i < vector.size(); i++) {
		for(int j = i + 1; j < vector.size() - 1; j++) {
			if(strcmp(vector[i].first.c_str(), vector[j].first.c_str()) > 0) {
				//Swap
				cout << "REACHED" << endl;
				string temp = vector[i].first;
				int frequency = vector[i].second;
				
				vector[i].first = vector[j].first;
				vector[i].second = vector[j].second;
	
				vector[j].first = temp;
				vector[j].second = frequency;
			}	
		}
	}
}
*/

vector<pair<string,int>> format(vector<vector<pair<string,int>>> list) {
	vector<pair<string,int>> vec;
	for(int i = 0; i < list.size(); i++) {
		vector<pair<string,int>> inner = list[i];
		for(int j = 0; j < inner.size(); j++) {
			vec.push_back(inner[j]);
		}
	}

	return vec;
}

vector<pair<string,int>> findIntersections(vector<pair<string,int>> vec) {
	vector<pair<string,int>> intersections;
	for(int i = 0; i < vec.size(); i++) {
		int offset = 1;
		for(int j = i  + offset; j < vec.size(); j++) {
			if(vec[i].first == vec[j].first) {
				pair<string,int> combine = make_pair(vec[i].first, vec[i].second + vec[j].second);
				intersections.push_back(combine);
			}
			offset++;	
		}
	}
	return intersections;
}

bool compareURL(pair<string,int> URL1, pair<string,int> URL2) { return strcmp(URL1.first.c_str(),URL2.first.c_str()) < 0; }

bool compareFrequencies(pair<string,int> freq1, pair<string,int> freq2) {
	if(freq1.second == freq2.second) {
		return compareURL(freq1,freq2);
	}

	return freq1.second > freq2.second;
}

void sortFrequencies(vector<pair<string,int>>& vector) {
	sort(vector.begin(), vector.end(), compareFrequencies);
}

void sortURL(vector<pair<string,int>>& vector) {
	sort(vector.begin(), vector.end(), compareURL);
}

// Input stream operator overload for node elements
istream& operator>>(istream& in, vector<pair<string, int>>& e);

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
	for(int i = 0; i < queries.size(); i++) {
		Node<string,vector<pair<string,int>>> * node = tree.search(queries[i]);
		//if(node == NULL) { cout << "NULL" << endl; }
		if(node != NULL) {
			vector<pair<string,int>> element = node->getElement();
			foundWords.push_back(element);
		}
		/*
		if(node == NULL) {
			vector<pair<string,int>> blankElement;
			foundWords.push_back(blankElement);
		}
		*/	
	}

	if(foundWords.size() == 0) { cout << "Not found" << endl;}
	
	vector<pair<string,int>> allPairs;
	allPairs = format(foundWords);	

	//cout << "FOUND WORD: " << foundWords.size() << endl;
	//cout << "ALL PAIRS: " << allPairs.size() << endl;
	
	vector<pair<string,int>> intersections = findIntersections(allPairs);
	//cout << "INTERSECTION SIZE: " << intersections.size() << endl;
	
	if(intersections.size() == 0) {
		for(int i = 0; i < allPairs.size(); i++) {
			cout << allPairs[i].first << " " << allPairs[i].second << endl;
		}
	}
	
	else {
		sortFrequencies(intersections);
		for(int i = 0; i < intersections.size(); i++) {
			cout << intersections[i].first << " " << intersections[i].second << endl;
		}
	}
	
	return 0;
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
