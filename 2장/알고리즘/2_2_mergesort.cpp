#include <iostream>
#include <list>
using namespace std;
list<int> mergesort(list<int> list);
list<int> merge1(list<int> left, list<int> right);

int main(){
    list<int> a = {3, 7, 6, 5, 10, 13, 1, 11, 31, 17, 19};
    list<int> sorted = mergesort(a);
    cout << "sorted size : " << sorted.size() <<endl;
    for(list<int>::iterator it = sorted.begin(); it != sorted.end(); it++){
        cout<<*it<<endl;
    }
    return 0;
}

list<int> mergesort(list<int> list1){
    if(list1.size() > 1){
        int n = list1.size();
        list<int> left;
        list<int> right;
        list<int>::iterator iter = list1.begin();
        for(int i =0; i<(int)(n/2); i++){
            left.push_back(*iter);
            iter++;
        }
        for(int i=0; i<n-(int)(n/2); i++){
            right.push_back(*iter);
            iter++;
        }
        left = mergesort(left);
        right = mergesort(right);
        list<int> list2 = merge1(left, right);
        return list2;
    }
    else return list1;
}

list<int> merge1(list<int> left, list<int> right){
    list<int> sorted;
    list<int>::iterator li = left.begin();
    list<int>::iterator ri = right.begin();
    while( (!left.empty()) || (!right.empty()) ){
        if( ( ( (*li) < (*ri) ) || right.empty() ) && !left.empty()){
            sorted.push_back(*li);
            li = left.erase(li);
        }
        else if ( ( (*li) > (*ri) || left.empty() ) && !right.empty() ){
            sorted.push_back(*ri);
            ri = right.erase(ri);
        }
    }
    return sorted;
}
