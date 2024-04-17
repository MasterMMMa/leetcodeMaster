//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//
//Each letter in magazine can only be used once in ransomNote.
//
//
//
//Example 1:
//
//Input: ransomNote = "a", magazine = "b"
//Output : false
//Example 2 :
//
//	Input : ransomNote = "aa", magazine = "ab"
//	Output : false
//	Example 3 :
//
//	Input : ransomNote = "aa", magazine = "aab"
//	Output : true
//
//
//	Constraints :
//
//	1 <= ransomNote.length, magazine.length <= 105
//	ransomNote and magazine consist of lowercase English letters.

#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (char c : magazine) {
            if (map.find(c) != map.end()) {
                map[c] += 1;
            }
            else {
				map[c] = 1;
			}
        }
        for (auto c : ransomNote) {
            if (map.find(c) == map.end()) { // can not find the letter in magzine
                return false;
            }
            else {
                if (map[c] == 0) return false;
                else {
                    map[c] -= 1;
                }
            }
        }
        return true;
    }
};

//int main() {
//    Solution s;
//    cout << s.canConstruct("a", "b") << endl;
//    cout << s.canConstruct("aa", "ab") << endl;
//    cout << s.canConstruct("aa", "aab") << endl;
//    return 0;
//
//}