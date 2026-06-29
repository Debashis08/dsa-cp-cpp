#include <gtest/gtest.h>
#include <string>
#include "../../src/0003_graph/headers/0001_bfs.h"
#include "../0000_common/unit_test_helper.h"

namespace dsa::bfs
{
    UnitTestHelper unitTestHelper;
    TEST(bfsDistanceTest, 0001_simple_graph)
    {
        Graph graph;
        int n = 6;
        int source = 0;
        vector<vector<int>> adjMat =
        {
            {1, 2},
            {0, 3},
            {0, 3},
            {1, 2, 4, 5},
            {3},
            {3}
        };
        vector<int> distances = graph.bfsDistance(adjMat, n, source);
        string result = unitTestHelper.serializeVectorToString(distances);
        string expected = "0 1 1 2 3 3";
        EXPECT_EQ(result, expected);
    }
    TEST(bfsDistanceTest, 0002_simple_graph)
    {
        Graph graph;
        int n = 7;
        int source = 0;
        vector<vector<int>> adjMat =
        {
            {1, 2},
            {0, 3, 4},
            {0, 5, 6},
            {1},
            {1},
            {2},
            {2}
        };
        vector<int> distances = graph.bfsDistance(adjMat, n, source);
        string result = unitTestHelper.serializeVectorToString(distances);
        string expected = "0 1 1 2 2 2 2";
        EXPECT_EQ(result, expected);
    }
    TEST(bfsDistanceTest, 0003_single_node)
    {
        Graph graph;
        int n = 1;
        int source = 0;
        vector<vector<int>> adjMat =
        {
            {}
        };
        vector<int> distances = graph.bfsDistance(adjMat, n, source);
        string result = unitTestHelper.serializeVectorToString(distances);
        string expected = "0";
        EXPECT_EQ(result, expected);
    }
    TEST(bfsDistanceTest, 0004_disconnected_graph)
    {
        Graph graph;
        int n = 6;
        int source = 0;
        vector<vector<int>> adjMat =
        {
            {1},
            {0},
            {},
            {4},
            {3},
            {}
        };
        vector<int> distances = graph.bfsDistance(adjMat, n, source);
        string result = unitTestHelper.serializeVectorToString(distances);
        string expected = "0 1 -1 -1 -1 -1";
        EXPECT_EQ(result, expected);
    }
}