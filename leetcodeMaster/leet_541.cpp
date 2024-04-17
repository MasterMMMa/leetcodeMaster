//Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
//
//If there are fewer than k characters left, reverse all of them.If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.
//
//
//
//Example 1:
//
//Input: s = "abcdefg", k = 2
//Output : "bacdfeg"
//Example 2 :
//
//	Input : s = "abcd", k = 2
//	Output : "bacd"

#include<vector>
#include<iostream>
#include<string>
using namespace std;

class solution {
public:
	string reverseStr(string s, int k) {
		if (s.size() == 0 && s.size() == 1) return s;
		int size = s.size();
		int start = 0;
		while (start < size) {
			if (start + k <= size) {
				s = swapInstring(s, start, start + k - 1);
			}
			else {
				s = swapInstring(s, start, size - 1);
			}
			start += 2 * k;
		}
		return s;

	}

	string swapInstring(string s, int i, int j) {
		while (j > i) {
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++;
			j--;
		}
		return s;
	}
};



	//int main() {
	//	solution sol;
	//	string s = "abcdefghijk";
	//	int k = 2;
	//	cout << sol.reverseStr(s, k) << endl;
	//	return 0;
	//}

