#include <vector>
#include <cmath>
#include <queue> 
using namespace std; 

int kth_largest(vector<int> values, int k){
    priority_queue<int> queue (values.begin(), values.end());
    for (int i=0; i<k; i++){
        queue.pop();
    }

    return queue.top();
}