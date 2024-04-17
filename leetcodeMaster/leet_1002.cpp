#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Given a string array words, return an array of all characters that show up in all strings within the words(including duplicates).You may return the answer in any order.
//
//
//
//Example 1:
//
//Input: words = ["bella", "label", "roller"]
//Output : ["e", "l", "l"]
//Example 2 :
//
//    Input : words = ["cool", "lock", "cook"]
//    Output : ["c", "o"]


class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        if (words.size() == 0) return words;
        vector<string> solution;
        int size = words.size(); // how many words in vector
        unordered_map<char, int> unmap;
        for (auto cha : words[0]) {
            unmap[cha] += 1;
        }
        for (auto i : words) {
            unordered_map<char, int> temp_map;
            for (auto cha : i ) {
                temp_map[cha] += 1;
            }
            for (auto &c : unmap) {
                if (temp_map.find(c.first) == temp_map.end()) {//element not exsits
                    c.second = 0;
                }
                else {
                    c.second = min(c.second, temp_map[c.first]);
                }
            }
        }
        for (auto i : unmap) {
            while (i.second > 0) {
                solution.push_back(string(1, i.first));
                i.second--;
            }
        }
        return solution;

    }
};

//int main() {
//    Solution s;
//    vector<string> words = { "bella", "label", "roller" };
//    vector<string> words2 = { "cool", "lock", "cook" };
//    cout << "Example 1: " << endl;
//    for (auto i : s.commonChars(words)) {
//		cout << i << " ";
//	}
//    cout << endl;
//	cout << "Example 2: " << endl;
//    for (auto i : s.commonChars(words2)) {
//		cout << i << " ";
//	}
//}