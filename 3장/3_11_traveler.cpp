#include <iostream>
#include <vector>
#include <cmath>
#define INF 987654321

using namespace std;

int travel(int cur_n, int cur_b);
int min1(int a, int b);
int Min(int a, int b);

vector<vector<int>> D;
int input[16][16];
int n, Answer_bit, N;

int main(){
    cin >> n;
    N = n;
    D = vector<vector<int>>(16, vector<int>(65536, -1));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> input[i][j];
        }
    }
    Answer_bit = (1 << n) - 1;
    cout << travel(0, 1);
    return 0;
}

int travel(int cur_n, int cur_b)
{
    if(cur_b == Answer_bit)
    {
        if(input[cur_n][0] == 0) return INF;
        else return input[cur_n][0];
    }

    if(D[cur_n][cur_b] != -1) return D[cur_n][cur_b];
    D[cur_n][cur_b] = INF;

    for(int i=0; i<n;i++){
        if(input[cur_n][i] == 0) continue;
        if((cur_b & (1 << i)) == (1 << i)) continue;

        D[cur_n][cur_b] = min1(D[cur_n][cur_b], input[cur_n][i] + travel(i, (cur_b| 1 << i) ));
    }
    return D[cur_n][cur_b];
}



int min1(int a, int b){
    if(a<b) return a;
    else return b;
}
