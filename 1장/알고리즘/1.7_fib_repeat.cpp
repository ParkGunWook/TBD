#include <vector>

int fib(int n);

int main(){
    return fib(6);
}

int fib(int n){
    std::vector<int> save(n+1);
    save[0] = 0;
    if(n>0){
        save[1] = 1;
        for(int i=2; i<=n; i++){
            save[i] = save[i-1] + save[i-2];
        }
    }
    return save[n];
}
