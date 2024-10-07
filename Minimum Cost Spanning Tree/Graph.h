#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Graph {
private:
	int* inArray;
	int* outArray;
	int SIZE;
	bool* visited;
	int edgeCount;

public:
	Graph() {}
	Graph(int s) {
		SIZE = s;
		inArray = new int[SIZE * SIZE];
		outArray = new int[SIZE * SIZE];
		visited = new bool[SIZE];
		edgeCount = 0;
	}

	void readIn(string fName) {
		fstream myfile;
		myfile.open(fName);
		int temp;
		
		for (int i = 0; i < (SIZE); i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				
				myfile >> temp;
				inArray[(SIZE * i) + j] = temp;
				if (temp != 0)
					edgeCount++;
			}
		}

		myfile.close();
		edgeCount /= 2;
	}

	void readOut(string fName, int no, int ver) {
		fstream myfile;
		myfile.open(fName);
		int temp;
		
		myfile << "MST " << no << " starting at vertex " << ver << ":" << endl;

		for (int i = 0; i < (SIZE); i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				myfile << outArray[(SIZE * i) + j];
				myfile << " ";
			}
			myfile << endl;
		}

		myfile.close();
	}

	void print() {
		cout << "Number of vertices: " << SIZE << endl;
		cout << "Number of edges: " << edgeCount << endl;
		cout << "Matrix: " << endl;
		
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				cout << inArray[(SIZE * i) + j] << " ";
			}
			cout << endl;
		}
	}

	void printOutput() {
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				cout << outArray[(SIZE * i) + j] << " ";
			}
			cout << endl;
		}
	}

	void createMST(int pos) {
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
		visited[pos] = true;

		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				outArray[(SIZE * i) + j] = 0;
			}
		}

		int nearest;
		int origin;

		

		for (int i = 0; i < (SIZE-1); i++)
		{
			findNearest(nearest, origin);
			outArray[(origin * SIZE) + nearest] = inArray[(origin * SIZE) + nearest];
			outArray[(nearest * SIZE) + origin] = inArray[(nearest * SIZE) + origin];
			cout << "Add edge " << nearest << " to " << origin << endl;
			visited[nearest] = true;
		}

	}

	void findNearest(int &nearest, int &origin) {
		//loop through rows as vertice
		int minimum = 100;

		for (int i = 0; i < SIZE; i++)
		{
			if (visited[i] == true)
			{
				//loop through columns
				for (int j = 0; j < SIZE; j++)
				{
					if ((inArray[(SIZE * i) + j] != 0) && (inArray[(SIZE * i) + j] < minimum) && (visited[j] != true))
					{
						nearest = j;
						origin = i;
						minimum = inArray[(SIZE * i) + j];
					}
				}
			}
		}
	}
};