#include "0001_segment_tree.h"

namespace dsa::segment_tree
{
	void SegmentTree::buildSegmentTree(int node, int start, int end)
	{
		if (start == end)
		{
			segTree[node] = arr[start];
			return;
		}

		int mid = (end + start) >> 1;
		this->buildSegmentTree(node << 1, start, mid);
		this->buildSegmentTree(node << 1 | 1, mid + 1, end);
		segTree[node] = segTree[node << 1] + segTree[node << 1 | 1];
	}

	int SegmentTree::querySegmentTree(int node, int start, int end, int left, int right)
	{
		// Case 1: TOtal overlap (current segment is completely inside query range)
		if (left <= start && end <= right)
		{
			return segTree[node];
		}

		// Case 2: No overlap (current segment is outside query range)
		if (right < start || end < left)
		{
			return 0;
		}

		// Case 3: Partial overlap (split query down both branches)
		int mid = (end + start) >> 1;
		ll leftResult = this->querySegmentTree(node << 1, start, mid, left, right);
		ll rightResult = this->querySegmentTree(node << 1 | 1, mid + 1, end, left, right);

		return leftResult + rightResult;
	}

	void SegmentTree::updateSegmentTree(int node, int start, int end, int index, int value)
	{
		if (start == end)
		{
			segTree[node] = value;
			return;
		}

		int mid = (end + start) >> 1;
		if (index <= mid)
		{
			this->updateSegmentTree(node << 1, start, mid, index, value);
		}
		else
		{
			this->updateSegmentTree(node << 1 | 1, mid + 1, end, index, value);
		}

		segTree[node] = segTree[node << 1] + segTree[node << 1 | 1];
	}

	SegmentTree::SegmentTree(vector<int>& arr) : arr(arr)
	{
		n = arr.size();
		segTree.resize(n << 2, 0);
		this->buildSegmentTree(1, 0, n - 1);
	}

	int SegmentTree::query(int left, int right)
	{
		if (left > right)
		{
			return 0;
		}
		return this->querySegmentTree(1, 0, n - 1, left, right);
	}

	void SegmentTree::update(int index, int value)
	{
		this->updateSegmentTree(1, 0, n - 1, index, value);
	}
}