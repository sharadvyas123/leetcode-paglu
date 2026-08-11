class Solution {
public:
    int fib(int n) {
        if(n < 2){
            return n;
        }
        return this->fib(n-1) + this->fib(n-2);
    }
};