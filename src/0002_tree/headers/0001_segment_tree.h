#pragma once

#include<vector>

using namespace std;
using ll = long long;

namespace dsa::segment_tree
{
	class SegmentTree
	{
	private:
		ll n;
		vector<int> arr;
		vector<int> segTree;
		void buildSegmentTree(int node, int start, int end);
		int querySegmentTree(int node, int start, int end, int left, int right);
		void updateSegmentTree(int node, int start, int end, int index, int value);
	public:
		SegmentTree(vector<int>& arr);
		int query(int left, int right);
		void update(int index, int value);
	};
}