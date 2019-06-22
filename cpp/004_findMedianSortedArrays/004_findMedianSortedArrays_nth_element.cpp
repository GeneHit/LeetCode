// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Yongqiang Yu
// Date   : 2019-06-18 
//********************************************************************************** 
//* Design Solution class and implement a lengthOfLongestSubstring function.
//* idea:using Binary Search
//* input:[1,3] 
//*       [2]      
//*	output:2
//**********************************************************************************
#include <iostream>
#include <sstream>
#include<algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	   	vector<int> nums3;
        nums3.reserve(nums1.size()+nums2.size());
        nums3=nums1;
        nums3.insert(nums3.end(),nums2.begin(),nums2.end());
        nth_element (nums3.begin(), nums3.begin()+nums3.size()/2, nums3.end());  
        double md=nums3[nums3.size()/2];
        if(nums3.size()%2==0)
        {
            nth_element (nums3.begin(), nums3.begin()+(nums3.size()-1)/2, nums3.end()); 
            md+=nums3[(nums3.size()-1)/2];
            md/=2;
        }
        return md;	
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        
        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
