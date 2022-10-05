class Solution {
public:
    
    // O(N)
    int* calculateFactorial(int n) {
        int* output = new int[n];
        
        output[0] = 1; // 0!
        
        for(int i = 1; i < n; i++) {
            output[i] = i * output[i - 1];
        }
        
        return output;
    }
    
    // return the next available index O(N)
    int getNextAvailablePosition(bool* visited, int n, int numJumps) {
        
        int currIndex = 0;
        int currJumps = 0;
        
        while(true) {
            if(currJumps == numJumps && visited[currIndex] == false)
                return currIndex;
            
            if(visited[currIndex] == false) {
                currJumps++;
            }
            
            currIndex = (currIndex + 1) % n;
        }
    }
    
    void helper(int n, int k, string& output, bool* visited, int* factorials, int initialN) {
        
        cout << "n: " << n << " output: " << output << endl;
        
        if(k == 0 || n == 0) {
            for(int i = 0; i < initialN; i++) {
                if(visited[i] == false) {
                    output += to_string(i + 1);
                    break;
                }
            }
            return;
        }
        
        int numJumps = 0;
        
        while(k > factorials[n - 1]) {
            k -= factorials[n - 1];
            numJumps++;
        }
        
        int index = getNextAvailablePosition(visited, initialN, numJumps);
        visited[index] = true;
        output += to_string(index + 1);
        
        helper(n - 1, k, output, visited, factorials, initialN);
    }
    
    string getPermutation(int n, int k) {
        // array to maintain visited/ selected elements
        bool* visited = new bool[n];
        
        // O(N)
        for(int i = 0; i < n; i++) {
            visited[i] = false;
        }
        
        cout << "Visited Array: " << endl;
        for(int i = 0; i < n; i++) {
            cout << visited[i] << " ";
        }
        cout << endl;
        
        // pre-calculate the factorials of all the numbers upto n
        int* factorials = calculateFactorial(n);
        
        string output = "";
        helper(n, k, output, visited, factorials, n);
        
        cout << "Output: " << output << endl;
        return output;
    }
};
