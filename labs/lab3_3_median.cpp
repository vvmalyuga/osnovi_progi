
//------------------------------------------------------ #3 ------------------------------------------------------

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();

        if (minHeap.size() < maxHeap.size()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian() {
        if (minHeap.size() > maxHeap.size()) {
            return static_cast<double>(minHeap.top());
        }
        else {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
    }

private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
};

int main() {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    cout << medianFinder.findMedian() << endl; 
    medianFinder.addNum(3);
    cout << medianFinder.findMedian() << endl; 

    return 0;
}
