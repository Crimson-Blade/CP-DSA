#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
  int numOfVertices;
  list<int> *adjLists;
  public:
  Graph(int n){
    numOfVertices = n;
    adjLists = new list<int>[n];
  }
  void add_edge(int u, int v){
    adjLists[u].push_back(v);
  }
  void reccursive_helper(int &index, bool visited[], stack<int> &stk){
    visited[index] = true;
    
    for(int i:adjLists[index]){
      if(!visited[i])
      reccursive_helper(i,visited,stk);
    }
    stk.push(index);
  }
  void topological_sort(){
    stack<int> stk;
    string topo;
    bool visited[numOfVertices] = {false};
    for(int i=0;i<numOfVertices;i++){
      if(!visited[i]){
        reccursive_helper(i,visited,stk);
      }
    }
    // generate string
    string res="";
    while(!stk.empty()){
      cout<<stk.top()<<' ';
      stk.pop();
    }
  }
};

int main(){
  Graph g(6);
    g.add_edge(5, 2);
    g.add_edge(5, 0);
    g.add_edge(4, 0);
    g.add_edge(4, 1);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
    cout << "Following is a Topological Sort of the given graph \n"<<g.topological_sort();
    // cout<<"\nStep count is "<<c;
    return 0;
}