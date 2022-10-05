#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  
      bool canJump(vector<int>& nums) {
          int lastPositionToReach = nums.size() - 1;
          
          for(int i = nums.size() - 1; i >= 0; i--) {
              if(nums[i] >= (lastPositionToReach - i)) {
                  lastPositionToReach = i;
              } else continue;
          }
          
          return lastPositionToReach == 0;
      }
    
};
