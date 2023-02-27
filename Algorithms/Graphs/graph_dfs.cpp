// dfs and Graph implementation using linked lists for adjlist

#include <iostream>
#include <list>
using namespace std;

class Graph{
    int numOfVerticies;
    list<int> *adjLists; // array of doubly linked lists
    bool *visited; // array of visited
    public:
    // constructor
    Graph(int V){
        numOfVerticies = V;
        adjLists = new list<int>[V];
        visited = new bool[V];
    }
    // add edges
    void addEdge(int src, int dest){
        adjLists[src].push_front(dest);
        // adjLists[dest].push_front(src); for non directed
    }
    // dfs
    void DFS(int startVertex){
        visited[startVertex] = true;
        cout<< startVertex << " ";

        list<int>::iterator i;
        for(i = adjLists[startVertex].begin(); i != adjLists[startVertex].end(); ++i){
            if(!visited[*i]){
                DFS(*i);
            }
        }
    }
};

int main() {
  Graph g(11);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3,4);
  g.addEdge(3,7);
  g.addEdge(2,5);
  g.addEdge(2,6);
  g.addEdge(6,9);
  g.addEdge(8,10);
  g.addEdge(6,8);

  g.DFS(0);

  return 0;
  }
