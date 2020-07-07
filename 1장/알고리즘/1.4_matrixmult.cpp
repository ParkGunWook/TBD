#include <iostream>
#include <vector>

std::vector< std::vector<int> > matrixmult(const std::vector<std::vector<int> > m1, const std::vector<std::vector<int>> m2);
void matprint(const std::vector<std::vector<int>> m1);

int main(){
    int size1 = 2;
    std::cin >> size1;
    int size2 = 2;
    std::cin >> size2;
    std::vector< std::vector<int> > mat1(size1);
    std::vector< std::vector<int> > mat2(size2);
    for(int i=0; i<size1; i++){
        for(int j=0; j<size2 ;j++){
            int a;
            std::cin >> a;
            mat1.at(i).push_back(a);
        }
    }
    std::cout << "mat1 clear" << std::endl;
    for(int i=0; i<size2; i++){
        std::vector<int> temp(size1);
        //std::cin >> temp[0] >> temp[1];
        for(int j=0; j<size1; j++){
            std::cin >> temp[j];
        }
        mat2[i] = temp;
    }
    std::vector< std::vector<int> > ans;

    ans = matrixmult(mat1, mat2);
    matprint(ans);

    return size1;
}

std::vector< std::vector<int> > matrixmult(const std::vector<std::vector<int> > m1, const std::vector<std::vector<int>> m2){
    std::vector<std::vector<int>> ans(m1.size());
    if(m1.at(0).size() != m2.size()){
        std::cout << "Size not matched" << std::endl;
        exit(77);
    }
    for(int i =0; i< m1.size(); i++){
        for(int j=0; j<m2.at(0).size(); j++){
                int temp = 0;
                for(int k=0; k<m2.size(); k++){
                    temp+= m1[i][k]*m2[k][j];
                }
                ans[i].push_back(temp);
        }
    }
    return ans;
}
void matprint(const std::vector<std::vector<int>> m1){
    for(int i=0; i<m1.size() ; i++ ){
        for(int j=0; j<m1.at(0).size(); j++){
            std::cout << m1.at(i).at(j) << " " ;
        }
        std::cout << std::endl;
    }
}
