#include <iostream>
#include <vector>
#include <string>

//Example Input
//4
//0.375 don
//0.375 isabelle
//0.125 ralph
//0.125 wally

using namespace std;
float optsearchtree(int n, const vector<float> p, vector<vector<float>>& A, vector<vector<int>> &R);

typedef struct tree_node{
    int key;
    tree_node* right;
    tree_node* left;
}tree_node;

tree_node* tree(int i, int j, const vector<vector<int>> &R);

int main(){
    int n;
    cin >> n;

    vector<float> p(n);
    vector<string> s;
    for(int i=0; i<n; i++){
        cin >> p[i];
        string temp;
        cin >> temp;
        s.push_back(temp);
    }
    for(int i=0; i<n; i++){
        cout << p[i] << " : " << s[i] << endl;
    }

    vector<vector<float>> A(n+2, vector<float>(n+1,0.0));
    vector<vector<int>> R(n+2, vector<int>(n+1,0));

    float ans = optsearchtree(n, p, A, R);
    for(int i=0; i<n+2; i++){
        for(int j=0; j<n+1; j++)
            cout << " " << A[i][j] << " ";
        cout << endl;
    }
    for(int i=0; i<n+2; i++){
        for(int j=0; j<n+1; j++)
            cout << " " << R[i][j] << " ";
        cout << endl;
    }
    tree_node* root = tree(1,n, R);
    cout << "root key is " << root->key << endl;
    cout << "root right key is " << root->right->key << endl;
    cout << "root left key is " << root->left->key << endl;
    return ans;
}

float optsearchtree(int n, const vector<float> p, vector<vector<float>>& A, vector<vector<int>> &R){
    float ans = 0;
    for(int i=1; i<n+1; i++){
        A[i][i] = p[i-1];
        R[i][i] = i;
    }
    for(int diagonal =1; diagonal < n; diagonal++){
        for(int i=1; i<n-diagonal+1; i++){
            int j=i+diagonal;
            float minval = INT_MAX;
            for(int k = i; k  <=j; k++){
                if(minval > A[i][k-1]+A[k+1][j]){
                    A[i][j] = A[i][k-1]+A[k+1][j];
                    minval = A[i][j];
                    R[i][j] = k;
                }
            }
            for(int k = i; k  <=j; k++){
                A[i][j] += p[k-1];
            }
        }
    }
    ans = A[1][n];
    return ans;
}

tree_node* tree(int i, int j, const vector<vector<int>> &R){
    int k;
    tree_node* p;
    k = R[i][j];
    if(k==0)
        return NULL;
    else{
        p = new tree_node;
        p->key = k;
        p->left = tree(i, k-1, R);
        p->right = tree(k+1, j, R);
        return p;
    }
}

