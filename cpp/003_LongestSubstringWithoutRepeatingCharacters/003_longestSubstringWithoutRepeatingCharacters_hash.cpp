// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Yongqiang Yu
// Date   : 2019-06-14 
//********************************************************************************** 
//* Design Solution class and implement a lengthOfLongestSubstring function.
//* idea:using Hash(key-value map)
//* input:"abcabcbb" 
//*        
//*output:3
//**********************************************************************************
#include <iostream>
#include <string>
#include <assert.h>
#include <unordered_map>
#include <sstream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t maxLen = 0,start=0,length=0;
        length=s.size();
        std::unordered_map<char,size_t> str_pos_hash;
        for(int i=0;i<length;i++){
        	auto find=str_pos_hash.find(s[i]);
        	if(find != str_pos_hash.end() && find->second >= start){
        		maxLen=max(maxLen,i-start);
        		start=find->second + 1;
			}
			str_pos_hash[s[i]] = i;
		}
        return max(maxLen,length-start);
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
