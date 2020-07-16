#include <iostream>
#include <array>

using namespace std;

int main(){
    array<int, 5> myArray = {9, 7, 6, 3, 1};
    array<int, 5>::iterator start = myArray.begin();
    array<int, 5>::iterator end = myArray.end();
    cout << distance(start, end) << endl;
    cout << myArray.at(distance(start, end)/2) << endl;
    return distance(start, end);
}
