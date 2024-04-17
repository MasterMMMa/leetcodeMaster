//Assume you are an awesome parent and want to give your children some cookies.But, you should give each child at most one cookie.
//
//Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j].If s[j] >= g[i],
//  we can assign the cookie j to the child i, and the child i will be content.Your goal is to maximize the number of your content children and output the maximum number.

//Example 1:
//
//Input: g = [1, 2, 3], s = [1, 1]
//Output : 1
//Explanation : You have 3 children and 2 cookies.The greed factors of 3 children are 1, 2, 3.
//And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
//You need to output 1.

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        quicksort(g, 0, g.size() - 1);
        quicksort(s, 0, s.size() - 1);
        int i{ 0 }, j{ 0 }, counter{0};
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                i++;
                j++;
                counter++;
            }
            else {
                j++;
            }
        }
        return counter;
    }

    void quicksort(vector<int>& v, int l, int h) {
        if (l >= h) return;
        int j = partition(v, l, h);
        quicksort(v, l, j - 1);
        quicksort(v, j + 1, h);
    }

    int partition(vector<int>& v, int l, int h) {
        int pivot = v[l];
        int i{l+1}, j{ h };
        while (i <= j) {
            while (i <= j && v[i] <= pivot) i++;
            while (i <= j && v[j] >= pivot) j--;
            if (i < j) swap(v[i], v[j]);
        }
        swap(v[l], v[j]);
        return j;
    }
};

//int main() {
//	Solution sol;
//	vector<int> g = { 1, 2, 3, 5 , 3, 2, 1 };
//	vector<int> s = { 1, 1 ,7, 7, 10 ,8, 6, 2};
//	//test case for quick sort
//    cout << "Test case for quick sort: " << endl;
//    sol.quicksort(g, 0, g.size() - 1);
//    sol.quicksort(s, 0, s.size() - 1);
//    //print the sorted arrays
//    for (int i = 0; i < g.size(); i++) {
//		cout << g[i] << " ";
//	}
//    cout << endl;
//    for (int i = 0; i < s.size(); i++) {
//        cout << s[i] << " ";
//    }
//
//    //test case 1
//    cout << "Test case 1: " << sol.findContentChildren(g, s) << endl;
//
//
//	return 0;
//}