#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100010

vector < vector < int > > tree;
int p[MAX_N]; // El padre inmediato de cada nodo
int h[MAX_N]; // La latura de cada nodo
int ssize[MAX_N]; // El tamano del subarbol, sirve para hld
int fo[MAX_N]; // Indice de la primer ocurrencia de cada nodo en ocurrences
vector < int > ocurrences;

int dfs(int u , int alt = 0) // O(n)
{
    fo[u] = ocurrences.size();
    ocurrences.push_back(u);
    h[u] = alt;
    int v;
    ssize[u] = 1;
    for(int i = 0 ; i < tree[u].size() ; ++i)
    {
        v = tree[u][i];
        if(p[u] == v)    continue;
        p[v] = u;
        ssize[u] += dfs(v , alt + 1);
        ocurrences.push_back(u);
    }
    return ssize[u];
}

vector < vector < int > > st_lca;

void build_lca(vector < int > &arr) // O(nlog(n))
{
    int columns = floor(log2(arr.size())) + 1;
    st_lca.assign(arr.size() , vector < int >(columns , -2));
    for(int i = 0 ; i < arr.size() ; ++i) st_lca[i][0] = arr[i];
    for(int j = 1 ; j < columns ; ++j)
        for(int i = 0 ; i < arr.size() && i + (1 << j) - 1 < arr.size() ; ++i)
        {
            st_lca[i][j] = st_lca[i][j-1];
            if(h[ st_lca[i + (1 << (j - 1))][j-1] ] < h[ st_lca[i][j] ])
                st_lca[i][j] = st_lca[i + (1 << (j - 1))][j-1];
        }
}

int lca_query(int i , int j) // O(1)
{
    if(i > j) swap(i , j);
    int len = j - i + 1;
    int k = floor(log2(len));
    int ans = st_lca[i][k];
    if(h[st_lca[i + len - (1 << k)][k]] < h[ans])
        ans = st_lca[i + len - (1 << k)][k];
    return ans;
}

int query(int u , int v)
{
    return lca_query(fo[u] , fo[v]);
}

void addEdge(int u , int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}

int main() // O(nlog(n) preprocess , O(1) query)
{
    dfs(0);
    build_lca(ocurrences);
    return 0;
}
