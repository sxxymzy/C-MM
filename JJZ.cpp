#include <iostream>
#include <string>
#include <vector>
#define bit_vector vector<bool>
#define bit_matrix vector<bit_vector>

using namespace std;
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
    string result;

    // process begin
    // TODO
    cout << "count is " << CAL_COUNT << ", T0 is " << T0 << "\n";
    // process end

    for (bit_vector::iterator i = F.begin(); i < F.end(); i++){
        result += to_string(*i);
    }
    return result;
}

int main(){

    int k;
    bit_vector F(49);

    string result;

    /*
    assignment
    */
    k = 10;
    for (int i=0;i<49;i++){
        F[i] = i % 2;
    }

    result = JJZ(F, k);
    cout << "result is " << result << endl;
}