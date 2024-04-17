//Given an input string s, reverse the order of the words.
//
//A word is defined as a sequence of non - space characters.The words in s will be separated by at least one space.
//
//Return a string of the words in reverse order concatenated by a single space.
//
//Note that s may contain leading or trailing spaces or multiple spaces between two words.The returned string should only have a single space separating the words.Do not include any extra spaces.
//
//
//
//Example 1:
//
//Input: s = "the sky is blue"
//Output : "blue is sky the"
//Example 2 :
//
//	Input : s = "  hello world  "
//	Output : "world hello"
//	Explanation : Your reversed string should not contain leading or trailing spaces.
//	Example 3 :
//
//	Input : s = "a good   example"
//	Output : "example good a"
//	Explanation : You need to reduce multiple spaces between two words to a single space in the reversed string.

#include <string>
#include <iostream>

class Solution {
public:
    std::string reverseWords(std::string s) {
        removeSpace(s);
        reverse(s, 0 , s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ' ) {
                reverse(s, start, i - 1);
                start = i + 1;
                
            }

        }
        return s;

    }

    void removeSpace(std::string& s) {
        //remove space from start, end and make sure each word only have one space
        int index = s.size() - 1;
        int start = 0;
        while (index >= start) {
            if (s[start] == ' '  && s[start + 1] == s[start]) {
                s.erase(start, 1);
                index--;
            }
            else {
                start++;
            }
        }
        if (!s.empty() && s[0] == ' ') {
            s.erase(0, 1);
        }
        if (!s.empty() && s[s.size() - 1] == ' ') {
            s.erase(s.size() - 1, 1);
        }
    }

    void reverse(std::string& s, int start , int end) {
        while (end > start)
        {
            std::swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

    //int main() {
    //    Solution s;
    //    std::string str = "      hi are you ok                          ";
    //    ////std::string reverd = s.reverseWords(str);
    //    //s.removeSpace(str);
    //    //std::cout << "output is :" << str <<"*******"<<std::endl;
    //    //s.reverse(str, 0 , str.size() - 1);
    //    //std::cout << "output2 is :" << str << "*******" << std::endl;
    //    std::string solution = s.reverseWords(str);
    //    std::cout << "final output is :" << solution << "*******";
    //    return 0;
    //}