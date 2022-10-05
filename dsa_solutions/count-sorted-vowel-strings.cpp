#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> helper(int n) {
        if(n == 0) {
            vector<int> v(5, 1);
            return v;
        }
        
        vector<int> smallOutput = helper(n - 1);
        vector<int> output(5, 0);
        
        output[output.size() - 1] = 1;
        
        for(int i = output.size() - 2; i >= 0; i--) {
            output[i] = output[i + 1] + smallOutput[i];
        }
        
        return output;
    }
    
    int countVowelStrings(int n) {
        vector<int> output = helper(n);
        return output[0];
    }
};
