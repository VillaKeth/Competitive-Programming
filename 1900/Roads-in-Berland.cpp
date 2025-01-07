#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <fstream> 
#include <numeric>
#define ll long long
#define ld long double
#define pb push_back
#define cin std::cin
#define cout std::cout
#define endl '\n'
#define vector std::vector
#define pair std::pair
#define hewwo cout << "hewwo" << endl;
const ll MODDY = 1e9+7;
const ll MODDY2 = 998244353;
const ll MODDY3 = 1e8;

// roads in berland
void floyd(vector<vector<ll>>& matrix, ll& distance, ll node)
{
    for(int j = 0; j < matrix.size(); j++)
    {
        if(j == node)
        {
            continue;
        }
        for(int k = 0; k < matrix.size(); k++)
        {
            if(matrix[j][node]+matrix[node][k] < matrix[j][k])
            {
                if(k > j)
                {
                    distance -= matrix[j][k];
                    distance += matrix[j][node]+matrix[node][k];
                }
                matrix[j][k] = matrix[j][node]+matrix[node][k];
                
            }
        }
    }
}

int main()
{
    ll n, k, u, v, w, distance(0);
    cin >> n;
    vector<vector<ll>> matrix(n, vector<ll>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            if(j > i)
            {
                distance += matrix[i][j];
            }
        }
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> u >> v >> w;
        u--;
        v--;
        if(w < matrix[u][v])
        {
            distance -= matrix[u][v];
            distance += w;
            matrix[u][v] = w;
            matrix[v][u] = w;
        }
        floyd(matrix, distance, u);
        floyd(matrix, distance, v);
        cout << distance << ' ';
    }
    return 0;
}
