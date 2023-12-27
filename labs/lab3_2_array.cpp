
//------------------------------------------------------ #2 ------------------------------------------------------

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool Duplicate(const vector<int>& nums, int indexDiff, int valueDiff) {
    int N = nums.size();

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N && j <= i + indexDiff; ++j) {
            if (abs(nums[i] - nums[j]) <= valueDiff) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<int> nums = { 4, 7, 3, 2, 9, 1 };
    int indexDiff = 2;
    int valueDiff = 3;

    if (Duplicate(nums, indexDiff, valueDiff)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}
