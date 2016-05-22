#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#define bit_vector vector<bool>
#define bit_matrix vector<bit_vector>

using namespace std;


/* below for test */

void debug_matrix(bit_matrix m){
    for (bit_matrix::iterator row = m.begin(); row<m.end(); row++){
        for (bit_vector::iterator col = (*row).begin(); col < (*row).end(); col++){
            cout << *col;
        }
        cout << "\n";
    }
}

bit_vector random_list(int length){
    bit_vector F(length);
    srand(static_cast<unsigned int>(time(0)));
    for (int i=0;i<length;i++){
        F[i] = rand()%2;
    }
    return F;
}