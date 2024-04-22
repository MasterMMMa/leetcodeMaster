//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
//
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
//
//
//
//Example 1:
//
//Input: s = "anagram", t = "nagaram"
//Output : true

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
//?? %26 ?? ASCII ??
//ASCII Mapping : In the ASCII encoding scheme, lowercase letters 'a' to 'z' are represented by consecutive ASCII codes from 97 to 122. 
// Using the modulo operator % 26, we can map each lowercase letter to a unique number from 0 to 25.

class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        for (auto& i : s) {
            //arr[i - 'a']++;
            arr[i % 26]++;
        }

        for (auto& i : t) {
            arr[i % 26]--;
        }
        for (auto& i : arr) {
            if (i != 0) return false;
        }
        return true;

    }
};