#include "testlib.h"

int a;
long long readAns(InStream& stream){
    long long x = stream.readLong(1, (long long)2e18, "Area of rectangle");
    return x;
}
long long is_square(long long x){
    long long l = 1;
    long long r = 1414213563;
    while(r-l>1){
        long long mid = l + (r - l) / 2;
        if(mid * mid <= x){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return l * l == x;
}
int main(int argc, char** argv){
    registerTestlibCmd(argc, argv);
    a = inf.readInt();
    long long pans = readAns(ouf);
    if(pans % a != 0){
        quitf(_wa, "It's Impossible to get this Area: %d", pans);
    }
    else{
        long long b = pans / a;
        if(is_square(1ll*a*a+1ll*b*b)){
            quitf(_ok, "answer = %d\n", pans);
        }
        else{
            quitf(_wa, "Diagonal is not integer");
        }
    }
    return 0;
}
