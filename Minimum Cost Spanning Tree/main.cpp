// Global Variables

#include <iostream>
#include "Graph.h"

using namespace std;

int SIZE = 6;
string IN_FILE = "input.txt";
string OUT_FILE_1 = "output1.txt";
string OUT_FILE_2 = "output2.txt";
string OUT_FILE_3 = "output3.txt";

int main() {

	Graph graph(SIZE);

	graph.readIn(IN_FILE);
	graph.print();
	cout << endl << endl;

	cout << "Begin MST 1 starting at Vertex 0" << endl;
	graph.createMST(0);
	cout << endl;
	graph.printOutput();
	cout << "End of MST 1";
	graph.readOut(OUT_FILE_1, 1, 0);
	cout << endl << endl;

	cout << "Begin MST 2 starting at Vertex 3" << endl;
	graph.createMST(3);
	cout << endl;
	graph.printOutput();
	cout << "End of MST 2";
	graph.readOut(OUT_FILE_2, 2, 3);
	cout << endl << endl;

	cout << "Begin MST 3 starting at Vertex 5" << endl;
	graph.createMST(5);
	cout << endl;
	graph.printOutput();
	cout << "End of MST 3";
	graph.readOut(OUT_FILE_3, 3, 5);
	cout << endl << endl;
}
