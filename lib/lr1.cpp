#include "lr1.h"
#include <iostream>


Res countAndSum(const std::vector<int>& array) {
    Res output;
    int size = array.size();
    int half;
    int mod;
    if (size > 1) {
        half = size / 2;
        mod = size % half; //1-0
    }
    else {
        half = 0;
        mod = 0;
        output.min = NULL;
    }
  
    for (int i = 0; i < half+mod; ++i) {
        int pos = half + i + mod;
        int sum = INT_MAX;
        if (mod == 1 && half == i) {
           sum = array[i] * 2;
           output.result.push_back(sum);
        }
        else {
            sum = array[i] + array[pos];
            output.result.push_back(sum);
        }
        if (output.min > sum) {
            output.min = sum;
        }
    }
    return output;
}