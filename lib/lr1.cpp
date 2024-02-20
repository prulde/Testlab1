#include "lr1.h"
#include <iostream>


Res countAndSum(const std::vector<int>& array) {
    Res output;
    int size = array.size();
    int half;
    int mod;
    if (size > 1024) {
        output.errors.push_back(oversized);
        return output;
    }
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
        if (half == i) {
           long long c = (long long)array[i] * 2;
           if (c > INT_MAX) {
               
               output.errors.push_back(overflow);
               return output;
           }
           if (c < INT_MIN) {
               output.errors.push_back(underflow);
               return output;
           }
           sum = array[i] * 2;
           output.result.push_back(sum);
        }
        else {
            long long c = (long long)array[i] + array[pos];
            if (c > INT_MAX) {
                output.errors.push_back(overflow);
                return output;
            }
            if (c < INT_MIN) {
                output.errors.push_back(underflow);
                return output;
            }
            sum = array[i] + array[pos];
            output.result.push_back(sum);
        }
        if (output.min > sum) {
            output.min = sum;
        }
    }
    return output;
}