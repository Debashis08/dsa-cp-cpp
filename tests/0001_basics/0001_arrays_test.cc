#include <gtest/gtest.h>
#include "../../src/0001_basics/headers/0001_arrays.h"
#include "../0000_common/unit_test_helper.h"

namespace dsa::arrays
{
	UnitTestHelper unitTestHelper;

	// Test 1: k = 3
	TEST(arraysTests, 0001_arrayRotation_KLessThanNumsSize)
	{
		Basics basics;
		vector<int> nums = { 1,2,3,4,5,6,7,8 };
		vector<int> expected = { 6,7,8,1,2,3,4,5 };
		int k = 3;
		vector<int> actual = basics.rotateArrayKTimes(nums, k);

		ASSERT_EQ(expected, actual);
	}

	// Test 2: k = 0 (No rotation should occur)
	TEST(arraysTests, 0002_arrayRotation_ZeroK)
	{
		Basics basics;
		vector<int> nums = { 1, 2, 3, 4, 5 };
		vector<int> expected = { 1, 2, 3, 4, 5 };
		int k = 0;
		vector<int> actual = basics.rotateArrayKTimes(nums, k);

		ASSERT_EQ(expected, actual);
	}

	// Test 3: k == n (Rotating by the exact size of the array yields the original array)
	TEST(arraysTests, 0003_arrayRotation_KEqualsSize)
	{
		Basics basics;
		vector<int> nums = { 10, 20, 30, 40 };
		vector<int> expected = { 10, 20, 30, 40 };
		int k = 4;
		vector<int> actual = basics.rotateArrayKTimes(nums, k);

		ASSERT_EQ(expected, actual);
	}

	// Test 4: k > n (Testing the modulo arithmetic: k = 7 on size 5 is equivalent to k = 2)
	TEST(arraysTests, 0004_arrayRotation_KGreaterThanSize)
	{
		Basics basics;
		vector<int> nums = { 1, 2, 3, 4, 5 };
		vector<int> expected = { 4, 5, 1, 2, 3 };
		int k = 7;
		vector<int> actual = basics.rotateArrayKTimes(nums, k);

		ASSERT_EQ(expected, actual);
	}

	// Test 5: Single element array (Should not crash or alter the element)
	TEST(arraysTests, 0005_arrayRotation_SingleElement)
	{
		Basics basics;
		vector<int> nums = { 99 };
		vector<int> expected = { 99 };
		int k = 5;
		vector<int> actual = basics.rotateArrayKTimes(nums, k);

		ASSERT_EQ(expected, actual);
	}

	// Test 6: Empty array (Should handle gracefully without out-of-bounds segmentation faults)
	TEST(arraysTests, 0006_arrayRotation_EmptyArray)
	{
		Basics basics;
		vector<int> nums = {};
		vector<int> expected = {};
		int k = 3;
		vector<int> actual = basics.rotateArrayKTimes(nums, k);

		ASSERT_EQ(expected, actual);
	}

	// Test 7: Large K with Large Array Elements
	TEST(arraysTests, 0007_arrayRotation_LargeK)
	{
		Basics basics;
		vector<int> nums = { -100, -200, 300, 400 };
		vector<int> expected = { 300, 400, -100, -200 };
		int k = 1000002; // k % 4 == 2
		vector<int> actual = basics.rotateArrayKTimes(nums, k);

		ASSERT_EQ(expected, actual);
	}
}