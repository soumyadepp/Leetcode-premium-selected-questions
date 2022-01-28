//Boyer Moore Voting Algo
class Solution {
public:

    int majorityElement(vector<int> &num) {
    int res = 0;
    for (int count = 1, i = 1; i < num.size(); i++) {
        num[res] == num[i] ? count++ : count--;
        if (count == 0) {
            res = i;
            count = 1;
        }
    }
    
    return num[res];
   }
};
