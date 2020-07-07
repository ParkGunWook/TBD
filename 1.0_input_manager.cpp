#include <iostream>
#include <vector>

void func(int size, const std::vector<int> list);

int main(){
    //First way to push input with vector
    /*std::vector<int> list;
    int size;
    std::cin >> size ;
    for(int i = 0; i<size; i++){
        int input;
        std::cin >> input;
        list.push_back(input);
    }*/

    //second way to push input with vector
    int size;
    std::cin >> size ;
    std::vector<int> list(size);
    for(int i=0; i<size; i++){
        std::cin >> list[i];
    }


    for(std::vector<int>::iterator itr = list.begin(); itr != list.end(); itr++){
        std::cout << *itr << std::endl;
    }

    func(size, list);
    int size2;
    std::cin >> size2;
    std::vector < std::vector <int> > list2(size2, std::vector<int>(size,0));
    for(int i =0; i<size2; i++){
        for(int j =0; j< size; j++){
            list2[i][j] = 10*i + j;
        }
    }
    /*for(int i=0; i<size2; i++){
        for(int j=0; j<size; j++){
            std::cout << list2[i][j] <<std::endl;
        }
    }*/
    std::vector<int>();
    std::vector < std::vector <int> > list3(size2);
    for(int i=0 ; i< size2; i++){
        //Not Necessary but helpful
        //list3.push_back(list); // Only initialize list3[i] size list data doesn't count
        //list3.push_back(std::vector<int>()); // Only initialize list3[i] size list data doesn't count
        for(int j =0; j< size; j++){
            list3.at(i).push_back(list[j]);
            //list3[i].push_back(10*i+j);
        }
    }
    for(int i=0; i<size2; i++){
        for(int j=0; j<size; j++){
            std::cout << list3[i][j] <<std::endl;
        }
    }
    return size;
}

void func(int size, const std::vector<int> list){
    std::cout << "Input list" << std::endl;
    /*for(std::vector<int>::const_iterator itr = list.begin(); itr != list.end(); itr++){
        std::cout << *itr << std::endl;
    }*/
    std::cout << "Input size : " << list.size() << std::endl;
}
