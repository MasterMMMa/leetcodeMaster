//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
//Input: n = 3
//Output : [[1, 2, 3], [8, 9, 4], [7, 6, 5]]

#include <vector>
#include <iostream>
using namespace std;

//一开始做这道题的时候总是想找到一个整体填充每个值的pattern，可以系统的更新，结果一直没有想出来。
//一个经验教训是，假设没有一些比较巧妙的思路，就尽可能先用可以想到的brute froce去尝试解决，之后再思考可能优化的空间

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 1) return { {1} };
        vector<vector<int>> solution(n, vector<int>(n, 0));
        int sqr = n * n, counter = 1;
        int start_x = 0, start_y = 0, end_x = n - 1, end_y = n - 1;
        while (sqr > counter) { // 之前写成了sqr >= counter，没有考虑到n为奇数的情况以及处理boundary的问题，导致infinity loop,不会退出
            for (int i = start_x; i < end_x; i++) {
                solution[start_y][i] = counter++;
            }
            for (int j = start_y; j < end_y; j++) {
                solution[j][end_x] = counter++;
            }
            for (int i = end_x; i > start_x; i--) {
                solution[end_y][i] = counter++;
            }
            for (int j = end_y; j > start_y; j--) {
                solution[j][start_x] = counter++;
            }
            start_x++;
            start_y++;
            end_x--;
            end_y--;
        }
        if (n % 2 == 1) {
            solution[n / 2][n / 2] = n * n;
        }
        return solution;

    }

};

//int main() {
//	Solution s;
//	vector<vector<int>> v = s.generateMatrix(3);
//    for (auto i : v) {
//        for (auto j : i) {
//			cout << j << " ";
//		}
//		cout << endl;
//	}
//}   