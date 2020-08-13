#include <iostream>
#include <vector>
#define INTMAX 987654321
using namespace std;

/*
10 8
AACAGTTACC
TAAGGTCA
*/
vector<char> x;
vector<char> y;
int m,n;

int opt(int i, int j, int cost);
int min1(int a, int b, int c);

int main(){
    cin >> m >> n;
    x = vector<char>(m);
    y = vector<char>(n);
    for(int i=0; i<m; i++){
        cin >> x[i];
    }
    for(int j=0; j<n; j++){
        cin >> y[j];
    }
    int optimal_cost = opt(0,0, 0);
    cout << "ANS : " << optimal_cost;
    return 0;
}

int opt(int i, int j, int cost){
    int penalty =0;
    //cout << i  << " " << j << " " << cost << endl;
    if(i==m){
        cost = 2*(n-j);
    }
    else if(j==n){
        cost = 2*(m-i);
    }
    else{
        if(x[i] == y[j])
            penalty =0;
        else
            penalty =1;
        cost = min1(opt(i+1, j+1, cost)+penalty, opt(i+1, j, cost)+2, opt(i, j+1, cost)+2);
    }
    return cost;
}

int min1(int a, int b, int c){
    int minnum = INTMAX;
    if(minnum > a){
        minnum = a;
    }
    if(minnum > b){
        minnum = b;
    }
    if(minnum > c){
        minnum = c;
    }
    return minnum;
}
