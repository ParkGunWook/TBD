#include <iostream>
#include <vector>

using namespace std;

vector<int> input(9);

void quicksort(int low, int high);
int partition1(int low, int high, int mid);

int main(){
    input = {3, 10, 7, 13, 9, 2, 1, 6, 12};
    quicksort(0, input.size()-1);
    for(int i=0; i<9; i++){
        cout << input[i] <<endl;
    }
    return 0;
}

void quicksort(int low, int high){
    int mid = (low+high)/2;
    if(high > low){
        mid = partition1(low, high, mid);
        quicksort(low, mid-1);
        quicksort(mid+1, high);
    }
}

int partition1(int low, int high, int mid){
    int i, j, k, temp;
    i = low, j= high;
    while(i!=mid){
        if(input[i] > input[mid]){
            temp = input[mid-1];
            input[mid-1] = input[mid];
            input[mid] = temp;
            if(mid-1 != i){
            temp = input[mid];
            input[mid] = input[i];
            input[i] = temp;
            }
            mid--;
        }
        else{
            i++;
        }
    }
    while(j!=mid){
        if(input[j] < input[mid]){
            temp = input[mid+1];
            input[mid+1] = input[mid];
            input[mid] = temp;
            if(mid+1 != j){
            temp = input[mid];
            input[mid] = input[j];
            input[j] = temp;
            }
            mid++;
        }
        else{
            j--;
        }
    }
    return mid;
}


