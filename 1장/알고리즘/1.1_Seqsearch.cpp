#include <iostream>
#include <vector>

void seqsearch(int size, const std::vector<int> list, int x);

int main(){
    int size;
    std::cin >> size ;
    std::vector<int> list(size);
    for(int i=0; i<size; i++){
        std::cin >> list[i];
    }

    seqsearch(size, list, 3);

    return size;
}

void seqsearch(int size, const std::vector<int> list, int x){
    int loc = 0;
    std::vector<int> ans_l;
    for(int i =0 ; i<size; i++){
        if(x==list[i]){
            ans_l.push_back(i);
        }
    }
    if(ans_l.size() == 0){
        std::cout << "X!!!\n" << std::endl;
    }
    else{
        std::cout << "O!!!\n" << std::endl;
    }
}
