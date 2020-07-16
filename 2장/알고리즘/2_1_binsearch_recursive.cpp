#include <iostream>
#include <vector>

using namespace std;
int binsearch(int list[], int x, int low, int high);

int main(){
    int a[10] = {1, 3, 7, 16, 19, 23, 27, 29, 35, 41};

    return binsearch(a, 16, 0, 9);
}

int binsearch(int list[], int x, int low, int high){
    int mid = (low+high)/2;
    if(list[mid] == x){
        return mid;
    }
    else if(list[low] > list[high]){
        return -1;
    }
    else{
        if(list[mid] > x){
            return binsearch(list, x, low, mid-1);
        }
        else    return binsearch(list, x, mid+1, high);
    }
}
