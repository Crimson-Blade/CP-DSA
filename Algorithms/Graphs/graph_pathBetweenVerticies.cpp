#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class Graph{
  int numOfVerticies;
  list<int> *adjLists; // array of doubly linked lists
  public:
  // constructor
  Graph(int V){
      // only initilizing 
      numOfVerticies = V;
      adjLists = new list<int>[V];
  }
  // add edges
  void addEdge(int src, int dest){
      adjLists[src].push_front(dest);
  }
  // finding path using bfs
  vector<int> findPath(int src, int dest){
    bool *visited = new bool[numOfVerticies];
    queue<vector<int>> q;
    q.push({src});
    visited[src] = true;
    list<int>::iterator itr;

    while(!q.empty()){
      vector<int> path = q.front();
      q.pop();
      // get the last vertex in the path
      int last_vertex = path[path.size()-1];
      // if the last vertex is the destination vertex, return the path
      if (last_vertex == dest) {
          return path;
      }
      // otherwise, continue BFS traversal
      for (list<int>::iterator i = adjLists[last_vertex].begin(); i != adjLists[last_vertex].end(); i++) {
          if (!visited[*i]) {
              visited[*i] = true;
              vector<int> new_path = path;
              new_path.push_back(*i);
              q.push(new_path);
          }
      }
  }}
  // find path
  
};

int main() {
  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(4, 1);
  g.addEdge(6, 4);
  g.addEdge(6, 1);
  g.addEdge(6, 2);
  g.addEdge(5, 6);
  g.addEdge(5, 2);
  g.addEdge(6, 0);

  for(auto i:g.findPath(5,3)){
    cout<<i<<" ";
  }

  return 0;
}
