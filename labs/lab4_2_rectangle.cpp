
//------------------------------------------------------ #2 ------------------------------------------------------

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        }

        stack<int> st;
        for (int j = 0; j <= cols; ++j) {
            while (!st.empty() && (j == cols || heights[st.top()] > heights[j])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? j : j - 1 - st.top();
                maxArea = max(maxArea, height * width);
            }
            st.push(j);
        }
    }

    return maxArea;
}

int main() {

    vector<vector<char>> matrix1 = { {'1','0','1','0','0'},
                                    {'1','0','1','1','1'},
                                    {'1','1','1','1','1'},
                                    {'1','0','0','1','0'} };
    cout << maximalRectangle(matrix1) << endl; 

    vector<vector<char>> matrix2 = { {'0'} };
    cout << maximalRectangle(matrix2) << endl; 

    vector<vector<char>> matrix3 = { {'1'} };
    cout << maximalRectangle(matrix3) << endl; 

    return 0;
}
