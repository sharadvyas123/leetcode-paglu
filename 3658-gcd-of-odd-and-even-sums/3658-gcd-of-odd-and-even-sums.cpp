class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // return n;
        int e = 0 ;
        int o = 0;

        for(int num = 1 ; num <= 2*n  ; num++){
            if(num%2 == 0){
                e += num;
            }
            else{
                o += num;
            }
        }

        return g(e , o);
    }
private:
    int g(int a , int b){
        if(a > b) return g(a-b , b);
        else if (b > a) return g(a , b -a);
        return b;
    }
};