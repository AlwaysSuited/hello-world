//THIS PROGRAM WAS CREATED BY DEVIN BROWN



using namespace std;
#include <fstream>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

class ShortestPathTree {
public:
	/* Node class/struct */
	struct Node {
		Node(string s, int c=0, Node* n=0) {
			name = s;
			cost = c;
			next = n;
			active = true;
		}
		string name;
		int cost;
		Node* next;
		bool active;
	};

	// typedefs
	typedef pair<int, Node*> vertex;
	typedef pair<vector<int>, vector<Node*> > dList;

	/* builds the adjacency list */
	void buildList(ifstream & in) {
		string start, end;
		int cost;
		while (in >> start >> end >> cost) { // read line
			bool exists1 = false, exists2 = false;
			for (int i = 0; i < list.size(); i++) {
				if (list[i]->name == start) {
					exists1 = true;
					list[i]->next = new Node(end, cost, list[i]->next);
				}
				if (list[i]->name == end) {
					exists2 = true;
					list[i]->next = new Node(start, cost, list[i]->next);
				}
			}
			if (!exists1) {
				Node* tmp = new Node(start);
				list.push_back(tmp);
				tmp->next = new Node(end, cost, tmp->next);
			}
			if (!exists2) {
				Node* tmp = new Node(end);
				list.push_back(tmp);
				tmp->next = new Node(start, cost, tmp->next);
			}
		}
	}

	/* method to find the index of a city */
	int findIndex(string name) {
		for (int i = 0; i < list.size(); i++)
			if (list[i]->name == name)
				return i;
		return -1;
	}

	/* method to run dijkstra's algorithm on an adjacency list */
	dList dijkstra(string sourcename) {
		vector<int> dist(list.size(), INT_MAX);
		vector<Node*> prev(list.size(), NULL);
		dList distList = make_pair(dist, prev);
		int src = findIndex(sourcename);

		priority_queue<vertex, vector <vertex>, greater<vertex> > heap;
		heap.push(make_pair(0, list[src]));
		distList.first[src] = 0;
		
		while (!heap.empty()) {
			string uname = heap.top().second->name;
			int u = findIndex(uname);
			heap.pop(); // extract min
			for (Node* tmp = list[u]; tmp != NULL; tmp = tmp->next) {
				if (tmp->active) {
					string vname = tmp->name;
					int v = findIndex(vname);
					int weight = tmp->cost;
					int alt = distList.first[u] + weight;
					if (distList.first[v] > alt) {
						distList.first[v] = alt; // update distance
						distList.second[v] = list[u]; // update path
						heap.push(make_pair(distList.first[v], list[v]));
					}
				}
			}
		}
		return distList;
	}

	/* method to find the amount a cost can increase by */
	int incrementAmount(string source, dList origList, vector<Node*> stack, int i) {
		Node* tmp;
		for (tmp = list[findIndex(stack[i]->name)]; tmp != NULL; tmp = tmp->next) {
			if (tmp->name == stack[i-1]->name) {
				tmp->active = false;
				break;
			}
		}
		
		dList tmplist = dijkstra(source);
		int incre = tmplist.first[findIndex(stack[i-1]->name)] - origList.first[findIndex(stack[i-1]->name)];
		tmp->active = true;
		return incre;
	}

	/* method to output the shortest path */
	void output(string source, string destination) {
		dList distList = dijkstra(source);
		int index;
		int finalIndex = index = findIndex(destination);
		Node* tmp = list[finalIndex];
		vector<Node*> stack; // shortest path as a list
		while (tmp != NULL)	{
			stack.push_back(tmp);
			if (tmp->name == source)
				break;
			tmp = distList.second[index];
			index = findIndex(tmp->name);
		}

		cout << "The shortest path from " << source << " to " << destination << " costs: " << distList.first[finalIndex];
		cout << " and the path is:" << endl;
		for (int i = stack.size() - 1; i > 0; i--) {
			// print the cost of the edge
			cout << stack[i]->name << " to " << stack[i-1]->name << " costs ";
			int dist1 = distList.first[findIndex(stack[i-1]->name)];
			int dist2 =  distList.first[findIndex(stack[i]->name)];
			int dist = dist1 - dist2;
			cout << dist << " and can increase by ";

			// remove an element and re-ren algorithm
			int incre = incrementAmount(source, distList, stack, i);
			cout << incre << " and still be on the shortest path" << endl;
		}
	}

private:
	// global vector
	vector<Node*> list;
};

/* main method */
int main(int argc, char *argv[]) {

	// error checking
	if (argc != 3) {
		cout << "Usage: encode 1.txt 2.txt" << endl;
		return -1;
	}
	
	// create the object to perform all operations
	ShortestPathTree sp;

	// build the adjacency list
	ifstream in(argv[1]);
	sp.buildList(in);

	// output the shortest paths
	ifstream in2(argv[2]);
	string sourcename, destname;
	in2 >> sourcename;
	in2 >> sourcename;
	while (in2 >> destname) {
		sp.output(sourcename, destname);
		cout << endl;
	}
}