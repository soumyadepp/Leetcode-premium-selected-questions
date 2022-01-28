class Solution {
public:
    int reverse(int x) {
        int b = 0;
        while(x)
        {
            int y = x%10;
            if(b > 0 and b > (INT_MAX - x%10)/10) return 0;
            if(b < 0 and b < (INT_MIN - x%10)/10) return 0;
            b = b*10+y;
            x/=10;
        }
        if(x<0)
        {
            b*=-1;
        }
        return b;
    }
};
