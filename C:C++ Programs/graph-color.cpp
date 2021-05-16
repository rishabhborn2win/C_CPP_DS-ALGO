//C++ Program for graph coloring

#include <bits/stdc++.h>
using namespace std;
int graph[50][50];
int V;

bool isSafe(int v, int color[], int c)
{
   for (int i = 0; i < V; i++)
   {
      if (graph[v][i] && c == color[i])
         return false;
   }
   return true;
}

bool graphColoring(int m, int color[], int v)
{
   if (v == V)
      return true;

   for (int c = 1; c <= m; c++)
   {
      if (isSafe(v, color, c))
      {
         color[v] = c;
         if (graphColoring(m, color, v + 1))
            return true;

         color[v] = 0;
      }
   }
   return false;
}

int main()
{
   int m;
   cout << "Enter Number of Vertices: ";
   cin >> V;
   cout << "Enter Number of Colors: ";
   cin >> m;
   memset(graph, 0, sizeof(graph));

   int e;
   cout << "Enter Number of Edges: ";
   cin >> e;

   int u, v;
   cout << "Enter Source-Destination of each edge:\n";
   
   
   while (e--)
   {
      cin >> u >> v;
      graph[u][v] = 1;
      graph[v][u] = 1;
   }

   int color[V];
   memset(color, 0, sizeof(color));

   if (graphColoring(m, color, 0))
   {
      cout << "Solution Exists:\nFollowing are the assigned colors : \n";
      for (int i = 0; i < V; i++)
         cout << color[i] << " ";
      cout << endl;
   }
   else
   {
      cout << "Solution does not exist" << endl;
   }
}
