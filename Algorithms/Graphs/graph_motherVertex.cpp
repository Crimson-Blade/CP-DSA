#include <iostream>
#include <list>
#include <stack>
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
    // dfs
    int DFS(int startVertex){
      bool *visited = new bool[numOfVerticies];
      visited[startVertex] = true;
      stack<int> s;
      s.push(startVertex);
      list<int>::iterator i;
      int noTraversed = 1;
      // iterative over each node
      while(!s.empty()){
        int vertex = s.top();
        s.pop();
        // cout<<vertex<<" ";
        for(i = adjLists[vertex].begin(); i != adjLists[vertex].end(); ++i){
          if(!visited[*i]){
            s.push(*i);
            visited[*i] = true;
            noTraversed++;
          }
        }
      }    
      return noTraversed;
    }
    // find mother vertex
    void getMother(){
      for(int i=0; i<numOfVerticies; i++){
        if(DFS(i) == numOfVerticies){
          cout<<"Mother: "<<i;
          return;
        }
      }
    }

};

int main() {
  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(4, 1);
  g.addEdge(6, 4);
  g.addEdge(5, 6);
  g.addEdge(5, 2);
  g.addEdge(6, 0);

  // g.DFS(5);
  g.getMother();

  return 0;
}
