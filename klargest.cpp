#include <vector>
#include <cmath>
#include <queue> 
#include <iostream>
using namespace std; 

int kth_largest(vector<int> values, int k){
    priority_queue<int> queue (values.begin(), values.end());
    for (int i=0; i<k-1; i++){
        queue.pop();
    }

    return queue.top();
}
/*
int main(){

    std::vector<int> values;
    values = {1,2,3,4,5,6};
    std::cout<<kth_largest(values, 3);
    return 0;
}
*/