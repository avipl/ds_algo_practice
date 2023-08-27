class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long sum = 0;
        unordered_set<int> uniq;
        
        for(int i = 1; n > 0; i++) {
            auto it = uniq.find(target - i);
            if(it == uniq.end()) {
                sum += i;
                uniq.insert(i);
                n--;
            }
        }
        
        return sum;
    }
};