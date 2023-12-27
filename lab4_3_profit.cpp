
//------------------------------------------------------ #6 ------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }

    vector<int> profitBefore(n, 0);
    vector<int> profitAfter(n, 0);

    // до
    int minPrice = prices[0];
    for (int i = 1; i < n; ++i) {
        minPrice = min(minPrice, prices[i]);
        profitBefore[i] = max(profitBefore[i - 1], prices[i] - minPrice);
    }

    // после
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxPrice = max(maxPrice, prices[i]);
        profitAfter[i] = max(profitAfter[i + 1], maxPrice - prices[i]);
    }

    // разница
    int maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        maxProfit = max(maxProfit, profitBefore[i] + profitAfter[i]);
    }

    return maxProfit;
}

int main() {

    vector<int> prices1 = { 3, 3, 5, 0, 0, 3, 1, 4 };
    vector<int> prices2 = { 1, 2, 3, 4, 5 };
    vector<int> prices3 = { 7, 6, 4, 3, 1 };

    int result1 = maxProfit(prices1); 
    int result2 = maxProfit(prices2); 
    int result3 = maxProfit(prices3); 

    cout << result1 << endl;
    cout << result2 << endl;
    cout << result3 << endl;

    return 0;
}
