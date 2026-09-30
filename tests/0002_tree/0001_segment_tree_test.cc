#include<gtest/gtest.h>
#include "0001_segment_tree.h"

namespace dsa::segment_tree
{
	TEST(SegmentTreeTest, ArrayWithMoreThanOneElements)
	{
		// Arrange
		vector<int> data = { 1,2,3,4,5,6,7,8,9,10 };
		SegmentTree segmentTree(data);

		// Act
		int queryResult = segmentTree.query(1, 6);

		// Assert
		ASSERT_EQ(queryResult, 27);
	}

	TEST(SegmentTreeTest, UpdateValueAtIndexK)
	{
		// Arrange
		vector<int> data = { 1,2,3,4,5,6,7,8,9,10 };
		SegmentTree segmentTree(data);

		// Act
		int queryResult01 = segmentTree.query(1, 6);
		segmentTree.update(4, 6);
		int queryResult02 = segmentTree.query(1, 6);

		// Assert
		ASSERT_EQ(queryResult01, 27);
		ASSERT_EQ(queryResult02, 28);
	}


	// 1. Normal Cases: Array with a single element
	TEST(SegmentTreeTest, SingleElementArray) {
		std::vector<int> data = { 42 };
		SegmentTree segmentTree(data);

		ASSERT_EQ(segmentTree.query(0, 0), 42);

		segmentTree.update(0, 10);
		ASSERT_EQ(segmentTree.query(0, 0), 10);
	}

	// 2. Normal Cases: Querying a single exact element (L == R)
	TEST(SegmentTreeTest, QuerySingleElement) {
		std::vector<int> data = { 1, 2, 3, 4, 5 };
		SegmentTree segmentTree(data);

		ASSERT_EQ(segmentTree.query(2, 2), 3);
		ASSERT_EQ(segmentTree.query(4, 4), 5);
	}

	// 3. Normal Cases: Handling negative numbers and zeroes
	TEST(SegmentTreeTest, NegativeAndZeroValues) {
		std::vector<int> data = { -5, 0, 10, -2, 7 };
		SegmentTree segmentTree(data);

		ASSERT_EQ(segmentTree.query(0, 4), 10); // -5 + 0 + 10 - 2 + 7
		ASSERT_EQ(segmentTree.query(0, 1), -5);
		ASSERT_EQ(segmentTree.query(1, 3), 8);  // 0 + 10 - 2
	}

	// 4. Normal Cases: Multiple sequential updates
	TEST(SegmentTreeTest, MultipleUpdates) {
		std::vector<int> data = { 1, 1, 1, 1, 1 };
		SegmentTree segmentTree(data);

		ASSERT_EQ(segmentTree.query(0, 4), 5);

		segmentTree.update(0, 5);
		segmentTree.update(4, 10);
		segmentTree.update(2, 0);

		// Array is now: {5, 1, 0, 1, 10}
		ASSERT_EQ(segmentTree.query(0, 4), 17);
		ASSERT_EQ(segmentTree.query(1, 3), 2);
	}

	// 5. Edge Cases: Total range overlap exactly on bounds
	TEST(SegmentTreeTest, ExactBoundsQuery) {
		std::vector<int> data = { 5, 10, 15, 20 };
		SegmentTree segmentTree(data);

		// Querying exactly the first half
		ASSERT_EQ(segmentTree.query(0, 1), 15);
		// Querying exactly the second half
		ASSERT_EQ(segmentTree.query(2, 3), 35);
		// Querying the full array
		ASSERT_EQ(segmentTree.query(0, 3), 50);
	}
}