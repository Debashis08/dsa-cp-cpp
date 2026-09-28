#include "0001_arrays.h"

namespace dsa::arrays
{
	// This below implementation of rotate array k times is using O(1) extra space,
	// utilizing the classic algorithmic trick called 'Array Rotation by Reversal'.
	vector<int> Basics::rotateArrayKTimes(vector<int>& nums, int k)
	{
		// if k == 0 or the given array is empty, then return the given array.
		if (!k || nums.empty())
		{
			return nums;
		}
		
		int n = nums.size();

		// Rotating the array n times means no change all.
		// Get the effective number of rotations.
		k = k % n;

		// Lambda to rotate the given array, starting from index i to index j.
		auto shift = [&](int i, int j)
			{
				while (i < j)
				{
					swap(nums[i], nums[j]);
					i++;
					j--;
				}
			};
		// This 3 below rotate calls are the main trick to implement the array rotation.
		// Reverse the entire array.
		shift(0, n - 1);
		
		// Reverse the first k elements.
		shift(0, k - 1);

		// Reverse the remaining elements.
		shift(k, n - 1);

		return nums;
	}
}
