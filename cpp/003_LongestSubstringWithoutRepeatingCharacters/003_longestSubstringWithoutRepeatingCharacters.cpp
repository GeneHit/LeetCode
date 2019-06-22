// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Yongqiang Yu
// Date   : 2019-06-14 
//********************************************************************************** 
//* Design Solution class and implement a lengthOfLongestSubstring function.
//* input:"abcabcbb" 
//*        
//*output:3
//**********************************************************************************
#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int MAX_CHARS = 256;
        int m[MAX_CHARS];
        memset(m, -1, sizeof(m));

        int maxLen = 0;
        int lastRepeatPos = -1;
        for(int i=0; i<s.size(); i++){
            if (m[s[i]]!=-1 && lastRepeatPos < m[s[i]]) {
                lastRepeatPos = m[s[i]];
            }
            if ( i - lastRepeatPos > maxLen ){
                maxLen = i - lastRepeatPos;
            }
            m[s[i]] = i;
        }
        return maxLen;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
