#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){

    int matrix[5][5];
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
           
            cin >> matrix[i][j];
}
}

   for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
    if(matrix[i][j] == 1){

        if(i<2){
            while(i != 2){
                i += 1;
                c += 1;
            }
        }
        if(j<2){
            while(j != 2){
                j += 1;
                d += 1;
            }
        }

        if(i>2){
            while(i != 2){
                i -= 1;
                e += 1;
            }
        }
        if(j>2){
            while(j != 2){
                j -= 1;
                f += 1;
            }
        }

    } 
    }
    
} 

cout << c+d+e+f << endl;


    return 0;
}