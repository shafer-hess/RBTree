#include <iostream>
#include <vector>
using namespace std;

// Output stream operator overload for node elements
ostream& operator<<(ostream& out, const vector<pair<string, int>>& e);

int main(int argc, char** argv) {
	// Implement your scan code here

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
