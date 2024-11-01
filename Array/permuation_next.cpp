#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = -1;   
        
        // Step 1: Finding the first decreasing element from the right
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){        //pointing 7
                index = i;                  
                break;
            }
        }
        
        // Step 2: Finding the smallest element greater than nums[index]
        for(int i=n-1; i>=index && index != -1; i--){
            if(nums[i] > nums[index]){          //swap 8,6
                swap(nums[i], nums[index]);   
                break;
            }
        }
        
        // Step 3: Reversing the elements to the right of index
        reverse(nums.begin() + index + 1, nums.end());   //reverse from index +1
    }
};

int main(){
    vector<int> arr={9,7,8,6};
    Solution sol;
    cout<<"Next Permutation : "<<endl;
    sol.nextPermutation(arr);
    for(auto it:arr){
        cout<<it<<" ";
    }
    
}
