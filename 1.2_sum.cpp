#include <iostream>
#include <vector>

int sum(const std::vector<int> list);

int main(){
    int size;
    std::cin >> size ;
    std::vector<int> list(size);
    for(int i=0; i<size; i++){
        std::cin >> list[i];
    }
    int ans = sum(list);

    std::cout << "Ans : " << ans << std::endl;

    return size;
}

int sum(const std::vector<int> list){
    int ans =0;
    for(std::vector<int>::const_iterator itr = list.begin(); itr != list.end(); itr++){
        ans += *itr;
    }
    return ans;
}
