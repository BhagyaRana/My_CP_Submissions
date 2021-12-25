#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define endl 	"\n"

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// A class that represents an undirected graph 
class Graph 
{ 
    int V;    // No. of vertices 
    list<int> *adj;    // A dynamic array of adjacency lists 
public: 
    // Constructor and destructor 
    Graph(int V)   { this->V = V; adj = new list<int>[V]; } 
    ~Graph()       { delete [] adj; } 
  
    // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // Prints greedy coloring of the vertices 
    void greedyColoring(); 
}; 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v);  // Note: the graph is undirected 
} 
  
// Assigns colors (starting from 0) to all vertices and prints 
// the assignment of colors 
void Graph::greedyColoring() 
{ 
    int result[V]; 
  
    // Assign the first color to first vertex 
    result[0]  = 0; 
  
    // Initialize remaining V-1 vertices as unassigned 
    for (int u = 1; u < V; u++) 
        result[u] = -1;  // no color is assigned to u 
  
    // A temporary array to store the available colors. True 
    // value of available[cr] would mean that the color cr is 
    // assigned to one of its adjacent vertices 
    bool available[V]; 
    for (int cr = 0; cr < V; cr++) 
        available[cr] = false; 
  
    // Assign colors to remaining V-1 vertices 
    for (int u = 1; u < V; u++) 
    { 
        // Process all adjacent vertices and flag their colors 
        // as unavailable 
        list<int>::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (result[*i] != -1) 
                available[result[*i]] = true; 
  
        // Find the first available color 
        int cr; 
        for (cr = 0; cr < V; cr++) 
            if (available[cr] == false) 
                break; 
  
        result[u] = cr; // Assign the found color 
  
        // Reset the values back to false for the next iteration 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
            if (result[*i] != -1) 
                available[result[*i]] = false; 
    }

    map<int,int> mp;
    // color -> count

    // print the result 
    for (int u = 0; u < V; u++) 
    {
        cout << "Vertex " << u+1 << " --->  Color "
             << result[u] << endl;
        auto itr = mp.find(result[u]);
        if(itr==mp.end())
            mp.insert(pair<int,int>(result[u],1));
        else
        {
            mp[result[u]]++;
        }
    }
         

    

} 


int main()
{
    b_v_r();
    int n,m;
    cin >> n;
    Graph g1(n);
    m = n - 1;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin >> u >> v;
        g1.addEdge(u-1,v-1);
    } 
    cout << "Coloring of graph 1 \n"; 
    g1.greedyColoring(); 
    
        
    return 0;
}
