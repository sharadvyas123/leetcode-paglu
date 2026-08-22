class Solution {
public:
    bool checkDivisibility(int n) {
        int summ = 0;
        int prod = 1;
        int temp = n;
        while(temp >0){
            summ += temp % 10;
            prod *= temp %10;
            temp /= 10;
        }
        return n % (summ + prod) == 0;
    }
};