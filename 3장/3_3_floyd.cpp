#include <iostream>
#include <vector>
#define MAX 99

using namespace std;

vector<vector<int>> floyd(int n, const vector<vector<int>> W);
vector<vector<int>> D;

int main(){
    vector<vector<int>> W = {{0,1,MAX,1,5}, {9,0,3,2,MAX}, {MAX,MAX,0,4,MAX}, {MAX,MAX,2,0,3}, {3,MAX,MAX,MAX,0} };
    for(int i =0; i <5; i++){
        for(int j=0; j<5; j++){
            cout << W[i][j] << " ";
        }
        cout <<endl;
    }
    D = floyd(5, W);
    for(int i =0; i <5; i++){
        for(int j=0; j<5; j++){
            cout << D[i][j] << " ";
        }
        cout <<endl;
    }
    return 0;
}

vector<vector<int>> floyd(int n, const vector<vector<int>> W){
    D = W;
    int i,j,k;
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0;j<n; j++)
                D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
    return D;
}
