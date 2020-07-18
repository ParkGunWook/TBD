#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

long long prod(int u, int v);
int size1(int a);

int main(){
    int a = 10394838;
    int b = 183748383;
    long long s = prod(a, b); // 8 vs 9
    cout << "Answer : " << s <<endl;
    long long a2 = 10394838;
    long long b2 = 183748383;
    if(a*b == a2*b2){
        cout << "nope" <<endl;
    }
    else if(a2 *b2 == s){
        cout << "This works" << endl;
    }
    return 0;
}


long long prod(int u, int v){
    int x =0, y=0, w=0, z=0;
    int n, m;
    n = max(size1(u), size1(v));
    if( size1(u)==0 || size1(v) ==0){
        return 0;
    }
    else if( n <= 1)
        return u*v;
    else {
        m = n/2;
        x = u / pow(10,m);
        w = v / pow(10,m);
        y = u - x * pow(10,m);
        z = v - w * pow(10,m);
        //cout << " x " << x << " y " << y << " w " << w << " z " << z << endl;
        return ( prod(x, w) * pow(10, 2*m) ) + ( prod(w,y) + prod(x,z) )* pow(10,m) + prod(y,z);
    }
}

int size1(int a){
    int n=0;
    while(a!=0){
        a= a/10;
        n++;
    }
    return n;
}
