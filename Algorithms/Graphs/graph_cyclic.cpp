// dfs and Graph implementation using linked lists for adjlist

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
  int numOfVerticies;
  list<int> *adjLists; // array of doubly linked lists
public:
  // constructor
  Graph(int V)
  {
    numOfVerticies = V;
    adjLists = new list<int>[V];
  }
  // add edges
  void addEdge(int src, int dest)
  {
    adjLists[src].push_front(dest);
    // adjLists[dest].push_front(src); for non directed
  }
  // dfs iterative
  bool DFS_I(int startVertex)
  {
    bool *visited = new bool[numOfVerticies];
    visited[startVertex] = true;
    stack<int> s;
    s.push(startVertex);
    list<int>::iterator i;
    while (!s.empty())
    {
      int vertex = s.top();
      s.pop();
      // cout << vertex << " ";
      for (i = adjLists[vertex].begin(); i != adjLists[vertex].end(); ++i)
      {
        if (!visited[*i])
        {
          s.push(*i);
          visited[*i] = true;
        }
        if(*i == startVertex) return true; //! THIS IS THE ONLY LINE TO INCLUDE
      }
    }
    return false;
  }
};

int main()
{
  //   Graph g(11);
  //   g.addEdge(0, 1);
  //   g.addEdge(1, 2);
  //   g.addEdge(2, 3);
  //   g.addEdge(3,4);
  //   g.addEdge(3,7);
  //   g.addEdge(2,5);
  //   g.addEdge(2,6);
  //   g.addEdge(6,9);
  //   g.addEdge(8,10);
  //   g.addEdge(6,8);
  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(3, 4);
  // g.addEdge(4, 1);
  g.addEdge(6, 4);
  g.addEdge(5, 6);
  g.addEdge(5, 2);
  g.addEdge(6, 0);
  bool checker = false;
  for(int i=0;i<7;i++){
    checker = checker || g.DFS_I(i);
  }
  // g.DFS_R(5);
  cout<<checker;
  return 0;
}
