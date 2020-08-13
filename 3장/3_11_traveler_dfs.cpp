#include <iostream>
#include <vector>

using namespace std;

void travel(int start, int dest, int sum, int cnt);
vector<int> check;
int min1 = INT_MAX;
vector<vector<int>> input;
int n;
/*
4
9
0 1 2
0 2 9
1 0 1
1 2 6
1 3 4
2 1 7
2 3 8
3 0 6
3 1 3
*/
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        input.push_back(vector<int>(n, 0));
    }
    check = vector<int>(n,0);
    int n2;
    cin >> n2;
    for(int i=0; i<n2; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        cin >> input[temp1][temp2];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(input[i][j]==INT_MAX){
                cout << "MAX";
            }
            else{
                cout << input[i][j];
            }
        }
        cout << endl;
    }
    travel(0,0,0,0);
    return min1;
}

void travel(int start, int dest, int sum, int cnt){
    if(cnt==n && start == dest){
        if(min1>sum) min1 =sum;
        return;
    }
    for(int x=0; x<n;x++){
        if(input[dest][x]==0) continue;

        if(!check[dest] && input[dest][x] >0){
            check[dest] = 1;
            sum+=input[dest][x];
            if(sum<=min1){
                travel(start, x, sum, cnt+1);
                cout<<min1<<endl;
            }
            check[dest] = 0;
            sum -= input[dest][x];
        }
    }
}
