#pragma once

#include <vector>
using namespace std;

namespace dsa::bfs
{
    class Graph
    {
    private:
    public:
        vector<int> bfsDistance(vector<vector<int>>& adjMat, int n, int source);
    };
}