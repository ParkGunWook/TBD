#include <iostream>
#include <vector>

std::vector<int> exchange(const std::vector<int> list);

int main(){
    int size;
    std::cin >> size ;
    std::vector<int> list(size);
    for(int i=0; i<size; i++){
        std::cin >> list[i];
    }
    list = exchange(list);

    std::cout<< "ans" << std::endl;

    for(std::vector<int>::iterator itr = list.begin(); itr != list.end(); itr++){
        std::cout << *itr << std::endl;
    }

    return size;
}

std::vector<int> exchange(std::vector<int> list){
    for(std::vector<int>::iterator itr = list.begin(); itr != list.end()-1; itr++){
        for(std::vector<int>::iterator itr2 = itr+1; itr2 != list.end(); itr2++){
            if(*itr2 < *itr){
                int temp;
                temp = *itr2;
                *itr2 = *itr;
                *itr = temp;
            }
        }
    }
    return list;
}
