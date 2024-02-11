#pragma once

#include <vector>

struct Res {
	std::vector<int> result;
	int min=INT_MAX;
};

Res countAndSum(const std::vector<int>& array);