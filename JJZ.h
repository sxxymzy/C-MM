#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#define bit_vector vector<bool>
#define bit_matrix vector<bit_vector>

using namespace std;

template <typename O, typename I> O new_matrix(int rows_count, int col_count){
    O result_matrix(rows_count);
    for (int i=0;i<rows_count;i++){
        result_matrix[i] = I(col_count);
    }
    return result_matrix;
}

/* below for test */
template <typename O, typename I> void debug_matrix(O m){
//    cout << "--------[DEBUG]--------\n";
    for (typename O::iterator row = m.begin(); row<m.end(); row++){
        for (typename I::iterator col = (*row).begin(); col < (*row).end(); col++){
            cout << *col << " ";
        }
        cout << "\n";
    }
//    cout << "--------[DEBUG END]--------\n";
}

bit_vector random_list(int length){
    bit_vector F(length);
    srand(static_cast<unsigned int>(time(0)));
    for (int i=0;i<length;i++){
        F[i] = rand()%2;
    }
    return F;
}