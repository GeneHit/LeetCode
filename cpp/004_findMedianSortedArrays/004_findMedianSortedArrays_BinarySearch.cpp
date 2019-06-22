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
        unsigned int len1 = nums1.size();
        unsigned int len2 = nums2.size();
        bool even= ((len1+len2)%2==0);
        unsigned int left=0, right = len1;
        unsigned int half= (len1+len2)/2;
        unsigned int i = 0,j=0;
        if(len1>len2)
            return findMedianSortedArrays(nums2,nums1);;	
        if(len1==0){
        	if (len2==0)
        		return 0.0;
        	else if(len2==1)
        		return nums2[len2/2];
        	else if(even)
        		return (double)( nums2[len2/2-1] + nums2[len2/2] )/2;
        	else
        		return (double)nums2[len2/2];
		}
		if(nums1[len1-1] <= nums2[0]){	
			if(even){
				if(len1 == len2)
					return (double) (nums1[len1-1]+nums2[0])/2.0;
				else
					return (double) (nums2[half-len1-1]+nums2[half-len1])/2.0;
			}	
			else
				return (double) nums2[half-len1];
		}
		else if(nums2[len2-1] <= nums1[0]){
			if(even){
				if(len1 == len2)
					return (double) (nums2[len2-1]+nums1[0])/2.0;
				else
					return (double) (nums2[half-1]+nums2[half])/2.0;
			}	
			else
				return (double) nums2[half];
		}
		else{
			if(len1==1 ){
	        	if (len2==1)
	        		return (double)( nums1[len2/2] + nums2[len2/2] )/2;
	        	else if(len2==2){
					return (double)(nums1[0]+nums2[0]+nums2[1]-min( min(nums1[0],nums2[0]), nums2[1])-max( max(nums1[0],nums2[0]), nums2[1]));
				}
				else {
		    		i = 1;
		    		j = half - i;
					if (even)
						if(nums1[0]<nums2[j-1])
							return (double)(nums2[j-1]+nums2[j])/2.0;
						else if(nums1[0]<nums2[j+1])
							return (double)(nums1[0]+nums2[j])/2.0;
						else
							return (double)(nums2[j]+nums2[j+1])/2.0;
					else
						return (double)(nums1[0]+nums2[j]+nums2[j+1]-min( min(nums1[0],nums2[j]), nums2[j+1])-max( max(nums1[0],nums2[j]), nums2[j+1])); 
				}
	        }
	        while ( (left+1) < right){
	            i = ((left + right+1) / 2);
	            j = half - i;
				//if A_max_left <= B_min_right and B_max_left <= A_min_right:
	            if(nums1[i-1] <= nums2[j] && nums2[j-1] <= nums1[i]){
	            	if(even){
		            	return (double)( max(nums1[i-1],nums2[j-1]) + min(nums1[i],nums2[j]) )/2.0;
		        	}else{//odd
			            return (double) min( nums1[i],nums2[j] );
		        	}
				}
	            else if (nums1[i-1] > nums2[j])
	            	right = i ;
	            else
	                left = i ;
	        }
	        if(even){
	        	if(len2==2){
		        	if(nums1[i]<nums2[j]) 
		        		return (double)(nums1[i-1]+nums1[i]+nums2[j-1]-min( nums1[i-1],min(nums1[i],nums2[j-1])))/2.0;
		        	else if(nums1[i]>=nums2[j]) 
		        		return (double)(nums1[i-1]+nums2[j-1]+nums2[j]-min( nums1[i-1],min(nums2[j-1],nums2[j])))/2.0;
	        	}else{
	        		vector<int> nums3 {nums1[i-1],nums1[i],nums2[j-2],nums2[j-1],nums2[j],nums2[j+1]};
		        	nth_element (nums3.begin(), nums3.begin()+2, nums3.end());
		        	int num1=nums3[2];
		        	nth_element (nums3.begin(), nums3.begin()+3, nums3.end());
		        	return (double)(num1+nums3[3])/2.0;
				}
	        }else{//odd
	        	vector<int> nums3 {nums1[i-1],nums1[i],nums2[j-1],nums2[j],nums2[j+1]};
	        	nth_element (nums3.begin(), nums3.begin()+nums3.size()/2, nums3.end());
	        	return (double)nums3[nums3.size()/2];
	        }
			
		}
		return 0.0;
			
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
