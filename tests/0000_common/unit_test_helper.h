#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class UnitTestHelper
{
public:
	template<typename T>
	string serializeVectorToString(vector<T> vector)
	{
		string result = "";
		for (auto& iterator : vector)
		{
			result += to_string(iterator) + " ";
		}
		result.pop_back();
		return result;
	}

	template<typename T>
	string serializeVectorToString(vector<pair<T,T>> vector)
	{
		string result = "";
		for (auto& iterator : vector)
		{
			result += to_string(iterator.first) + "(" + to_string(iterator.second) + ")" + " ";
		}

		if (!result.empty())
		{
			result.pop_back();
		}
		return result;
	}
	
	template<typename T>
	string serializeVectorToString(vector<pair<T, pair<T, T>>> vector)
	{
		string result = "";
		for (auto& iterator : vector)
		{
			result += to_string(iterator.first) + "(" + to_string(iterator.second.first) + "," + to_string(iterator.second.second) + ")" + " ";
		}

		if (!result.empty())
		{
			result.pop_back();
		}
		return result;
	}

	template<typename T>
	string serializeVectorToString(vector<vector<T>> vector)
	{
		string result = "";
		for (auto& iterator : vector)
		{
			result += "[";
			for (auto& it : iterator)
			{
				result += to_string(it) + " ";
			}
			if (!result.empty())
			{
				result.pop_back();
			}
			result += "]";
		}
		return result;
	}

	// this helper method is used to sort the vector of vectors of a particular typename.
	// each inner vector is sorted first.
	// then each of them are sorted by their first element, in increasing order.
	template<typename T>
	vector<vector<T>> sortVectorOfVectors(vector<vector<T>> data)
	{
		// step 1: sorting each inner vectors.
		for (auto& innerVector : data)
		{
			sort(innerVector.begin(), innerVector.end());
		}

		// step 2: sorting all the vectors by their first element, in increasing order.
		sort(data.begin(), data.end(), [](const vector<T>& a, const vector<T>& b)
			{
				// checking if both inner vectors are empty to prevent out-of-bounds access.
				if (a.empty() && b.empty())
					return false;

				// considering empty vector as less than non-empty vector.
				if (a.empty())
					return true;

				// considering non-empty vector as greater than empty vector.
				if (b.empty())
					return false;

				// comparing the first elements of each vector.
				return (a[0] < b[0]);
			});

		return data;
	}

	template<typename T>
	bool normalizeCyclesAndCompare(vector<T> data1, vector<T> data2)
	{
		if (data1.size() != data2.size())
		{
			return false;
		}
		
		// normalized rotation of cycle 1
		vector<T> normalizedCycle1(data1);
		auto minIterator1 = min_element(normalizedCycle1.begin(), normalizedCycle1.end());
		rotate(normalizedCycle1.begin(), minIterator1, normalizedCycle1.end());

		// normalized rotation of cycle 2
		vector<T> normalizedCycle2(data2);
		auto minIterator2 = min_element(normalizedCycle2.begin(), normalizedCycle2.end());
		rotate(normalizedCycle2.begin(), minIterator2, normalizedCycle2.end());

		// check clock wise
		if (normalizedCycle1 == normalizedCycle2)
		{
			return true;
		}

		// check counter clock wise
		reverse(normalizedCycle2.begin() + 1, normalizedCycle2.end());
		return (normalizedCycle1 == normalizedCycle2);
	}

	template<typename T>
	vector<pair<pair<T, T>, T>> sortVectorOfPair(vector<pair<pair<T, T>, T>> data)
	{
		for (auto& iterator : data)
		{
			if (iterator.first.first > iterator.first.second)
			{
				swap(iterator.first.first, iterator.first.second);
			}
		}

		sort(data.begin(), data.end(), [](const pair<pair<T, T>, T>& pairA, const pair<pair<T, T>, T>& pairB)
			{
				if (pairA.second == pairB.second)
				{
					return pairA.first.first < pairB.first.first;
				}
				return pairA.second < pairB.second;
			});
		return data;
	}

	template<typename T1, typename T2>
	string sortVectorOfPairAndSerialize(vector<pair<T1, T2>> data)
	{
		// sorting the vector in non-decreasing order on typename T1
		sort(data.begin(), data.end(), [](const pair<T1, T2>& pair1, const pair<T1, T2>& pair2)
			{
				return pair1.first < pair2.first;
			});

		// serializing the vector to string
		string result = "";
		for (auto& iterator : data)
		{
			result += iterator.first + "(" + to_string(iterator.second) + ")" + " ";
		}

		if (!result.empty())
		{
			result.pop_back();
		}
		return result;
	}
};