#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
int src,dest,wt;
};

void bellmanFord(node *edges,int v,int e,int src){ int *distance = new int[v+1];

for(int i=0;i<=v;i++)
distance[i] = INT_MAX;
distance[src] = 0;
for(int i=1;i<=v-1;i++){
for (int j=0;j<e;j++){
int u = edges[j].src;
int v = edges[j].dest;
int w = edges[j].wt;
if(distance[u]!=INT_MAX && distance[u]+w<distance[v])
distance[v] = distance[u]+w;
}
}

for(int i=1;i<=v;i++){

cout << "Distance from node " << src << " to node " << i << ": "; if(distance[i]==INT_MAX)
cout << "INF" << endl;
else
cout << distance[i] << endl;
}
cout<< endl;
}
int main(){
int v,e;
cout << "Enter number of nodes: ";
cin >> v;
cout << "Enter number of links: ";

cin >> e;
node *edges = new node[e];

cout << "Enter source and destination nodes of an edge with its weight: " << endl;
for(int i=0;i<e;i++)

cin >> edges[i].src >> edges[i].dest >> edges[i].wt; for(int i=1;i<=v;i++)
bellmanFord(edges,v,e,i);
}
