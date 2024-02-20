#pragma once

#include <vector>
#include <string>
#include <climits>

struct Res
{
	std::vector<int> result;
	int min = INT_MAX;
	std::vector<std::string> errors;
};

const std::string oversized = "oversized";
const std::string overflow = "overflow";
const std::string underflow = "underflow";

Res countAndSum(const std::vector<int> &array);