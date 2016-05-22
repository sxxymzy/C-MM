#include "JJZ.h"

const int CAL_COUNT = 2;  // constant of process loop count
const int T0 = 7;  // constant of T0

/*
* JJZ is the function you need
* @params F: bit array F
* @params k: bit array F's length
**/
string JJZ(bit_vector F, int k){

    /*
     variables define
     */

    // process begin
    // step 1
    int rows_count = k%T0==0?k/T0:k/T0+1;
    bit_matrix bm1(rows_count);
    for (int i=0;i<rows_count;i++){
        bm1[i] = bit_vector(F.begin()+i, F.begin()+i+T0);
    }
    debug_matrix(bm1);
    // step 2,3,4, loop CAL_COUNT times

    // step 5
    // process end
    string result;
    cout << "count is " << CAL_COUNT << ", T0 is " << T0 << "\n";
    bit_vector bit_result(F.begin(), F.begin()+7);
    for (bit_vector::iterator i = bit_result.begin(); i < bit_result.begin()+T0; i++){
        result += to_string(*i);
    }
    return result;
}

int main(){

    int k = 49;
    bit_vector F = random_list(k);

    string result;
    result = JJZ(F, k);

    cout << "result is " << result << endl;
}