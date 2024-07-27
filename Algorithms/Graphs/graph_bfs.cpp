// https://www.programiz.com/dsa/graph-bfs

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
  // members
  list<int> *adjLists;
  int numOfVectors;
  bool *visited;
  public:
  Graph(int n){
    numOfVectors = n;
    adjLists = new list<int>[n];
    visited = new bool[n];
  }
  void addEdge(int src, int dest){
    adjLists[src].push_front(dest);
    adjLists[dest].push_front(src);
  }
  void BFS(int start){
    queue<int> q;
    q.push(start);
    list<int>::iterator itr;

    while(!q.empty()){
      int vertex = q.front();
      q.pop();
      visited[vertex] = true;
      cout<<vertex<<" ";
      for(itr = adjLists[vertex].begin(); itr != adjLists[vertex].end(); itr++){
        if(!visited[*itr]){
        q.push(*itr);
        visited[*itr] = true;
        }
      }
    }
    cout<<endl;
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

  g.BFS(0);

  return 0;
  }
