#pragma once

#include <vector>
#include <iostream>

// sort array odd and even 

void SortArray(std::vector<int>& array)
{
	int left = 0;
	int right = array.size() - 1;

	while (left < right)
	{
		while (array[left] % 2 != 0 && left < right)
		{
			left++;
		}

		while (array[right] % 2 == 0 && left < right)
		{
			right--;
		}

		if (left < right)
		{
			std::swap(array[left], array[right]);
			left++;
			right--;
		}
	}
}