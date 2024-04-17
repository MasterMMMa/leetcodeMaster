//You are given an integer array cost where cost[i] is the cost of ith step on a staircase.Once you pay the cost, you can either climb one or two steps.
//
//You can either start from the step with index 0, or the step with index 1.
//
//Return the minimum cost to reach the top of the floor.
//Example 1:
//
//Input: cost = [10, 15, 20]
//Output : 15
//Explanation : You will start at index 1.
//- Pay 15 and climb two steps to reach the top.
//The total cost is 15.
//Example 2 :
//
//    Input : cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
//    Output : 6
//    Explanation : You will start at index 0.
//    - Pay 1 and climb two steps to reach index 2.
//    - Pay 1 and climb two steps to reach index 4.
//    - Pay 1 and climb two steps to reach index 6.
//    - Pay 1 and climb one step to reach index 7.
//    - Pay 1 and climb two steps to reach index 9.
//    - Pay 1 and climb one step to reach the top.
//    The total cost is 6.

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> sum(size + 1);
        sum[0] = 0;
        sum[1] = 0;
        for (int i = 2; i <= size; i++) {
            //print the vector sum
            cout << "i: " << i << endl;
            sum[i] = min(sum[i - 2] + cost[i - 2], sum[i - 1] + cost[i - 1]);
            cout << "sum[i]: " << sum[i] << endl;
        }
        return min(sum[size - 2] + cost[size - 2], sum[size - 1] + cost[size - 1]);
    }
};
//
//int main() {
//    //test
//    vector<int> cost = { 10, 15, 20 };
//    Solution sol;
//    cout << sol.minCostClimbingStairs(cost) << endl;
//    return 0;
//}