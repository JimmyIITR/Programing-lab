#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include "../../lab-1/Array.cpp"

using namespace std;

class ArrayBFSDFS {
public:
    Array<int> ArrBFS;
    Array<int> ArrDFS;
	unordered_map<int, bool> visited;
	unordered_map<int, vector<int>> adj;
	void addEdge(int v, int w){
        adj[v].push_back(w);
    }
	void DFS(int v){
        visited[v] = true;
	    ArrDFS.push_back(v);
	    vector<int>::iterator i;
	    for (i = adj[v].begin(); i != adj[v].end(); ++i)
		    if (!visited[*i])
			    DFS(*i);
    }
    void BFS(int s){
        queue<int> queue;
        visited[s] = true;
        queue.push(s);

        while (!queue.empty()) {
            s = queue.front();
	        ArrBFS.push_back(s);
            queue.pop();

            for (auto adjacent : adj[s]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    queue.push(adjacent);
                }
            }
        }
    }
    void printDFS(){
        for(int i=0;i<ArrDFS.n();i++){
            cout<<ArrDFS.access(i);
        }
    }
    void printBFS(){
        for(int i=0;i<ArrBFS.n();i++){
            cout<<ArrBFS.access(i);
        }
    }
};

int main()
{
	ArrayBFSDFS newg;
	newg.addEdge(0, 1);
	newg.addEdge(0, 2);
	newg.addEdge(1, 2);
	newg.addEdge(2, 0);
	newg.addEdge(2, 3);
	newg.addEdge(3, 3);
	newg.DFS(2);
    newg.printDFS();
	newg.BFS(2);
    newg.printBFS();

	return 0;
}
