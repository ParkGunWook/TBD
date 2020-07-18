#include<iostream>
#include<cmath>
using namespace std;

void hanoi(int n, int from, int to){
    if(n==0){
        return;
    }
    else{
        hanoi(n-1, from, 6-from-to);
        cout<< from << " " << to << endl;
        hanoi(n-1, 6-from-to, to);
    }
}


int main(){
    int n;
    long long a = pow(2,n)-1;
    cin >> n;
    cout << a << endl;
    hanoi(n, 1, 3);
    return 0;
}
