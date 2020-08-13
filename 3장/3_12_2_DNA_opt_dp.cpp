#include <iostream>
#include <vector>
#define INTMAX 987654321
using namespace std;

/*
10 8
AACAGTTACC
TAAGGTCA
*/
vector<vector<int>> dp;
vector<char> x;
vector<char> y;
int m,n;

void opt(int i, int j);
int min1(int a, int b, int c);

int main(){
    cin >> m >> n;
    x = vector<char>(m);
    y = vector<char>(n);
    dp = vector<vector<int>>(m+2, vector<int>(n+2, -1));
    for(int i=0; i< m+2; i++){
        dp[i][n+1] = INTMAX;
    }
    for(int j=0; j<n+2; j++){
        dp[m+1][j] = INTMAX;
    }
    for(int i=0; i<m; i++){
        cin >> x[i];
    }
    for(int j=0; j<n; j++){
        cin >> y[j];
    }
    opt(0, 0);
    for(int i=0; i<m+2; i++){
        for(int j=0; j<n+2;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "ANS : " << dp[0][0];
    return 0;
}

void opt(int i, int j){
    if(dp[i][j] != -1){
        return;
    }
    int penalty =0;
    //cout << i  << " " << j << " " << cost << endl;
    if(i==m){
        dp[i][j] = 2*(n-j);
        cout << i  << " " << j << " " << dp[i][j] << endl;
    }
    else if(j==n){
        dp[i][j] = 2*(m-i);
        cout << i  << " " << j << " " << dp[i][j] << endl;
    }
    else{
        if(x[i] == y[j])
            penalty =0;
        else
            penalty =1;
        if(dp[i+1][j] == -1){
            opt(i+1, j);
        }
        if(dp[i][j+1] == -1){
            opt(i, j+1);
        }
        if(dp[i+1][j+1] == -1){
            opt(i+1, j+1);
        }
        dp[i][j] = min1(dp[i+1][j+1]+penalty, dp[i+1][j]+2, dp[i][j+1]+2);
        cout << i  << " " << j << " " << dp[i][j] << endl;
    }
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
