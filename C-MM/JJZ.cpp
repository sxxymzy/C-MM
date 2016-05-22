#include "JJZ.h"

const int CAL_COUNT = 2;  // constant of process loop count
const int T0 = 7;  // constant of T0


bit_matrix _correlation_calculation(bit_matrix bit_matrix_1, int k, int rows_count){
    // step 2,3,4, loop CAL_COUNT times
    vector< vector<double> > _double_matrix_2 = new_matrix<vector<vector<double> >, vector<double> >(rows_count, rows_count);
    double sum = 0; // sum of bit_matrix_2
    double r0 = 0; // average of bit_matrix_2, r0 = sum / k;

    //      step 2 process
    for (int i=0; i<rows_count; i++){
        for(int j=0; j<rows_count; j++){
            int A=0; // equal
            int D=0; // non-equal
            if (i==j)_double_matrix_2[i][j] = 1;
            else{
                for (int ri=0; ri<T0; ri++){
                    if(bit_matrix_1[i][ri]==bit_matrix_1[j][ri]){
                        A++;
                    }
                    else{
                        D++;
                    }
                }
                _double_matrix_2[i][j] = double((A-D))/double(T0);
                sum += fabs(_double_matrix_2[i][j]); // step 3
            }
        }
    }
    cout << "-------------------------\nStep 2 Rk* Result is: \n";
    debug_matrix<vector<vector<double> > , vector<double> >(_double_matrix_2);

    //      step 3
    bit_matrix _bit_matrix_3 = new_matrix<bit_matrix, bit_vector>(rows_count, rows_count);
    r0 = sum / double(k);
    for (int i=0; i<rows_count; i++){
        for(int j=0; j<rows_count; j++){
            if(_double_matrix_2[i][j] >= r0) _bit_matrix_3[i][j] = 1;
            else{
                _bit_matrix_3[i][j] = 0;
            }
        }
    }
    cout << "-------------------------\nStep 3 Result is: \n";
    cout << "sum is " << sum << "\nr0 is " << r0 << "\n";
    cout << "Rk is \n";
    debug_matrix<bit_matrix, bit_vector>(_bit_matrix_3);
    return _bit_matrix_3;
}

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
    bit_matrix bit_matrix_1(rows_count);
    for (int i=0;i<rows_count;i++){
        bit_matrix_1[i] = bit_vector(F.begin()+i, F.begin()+i+T0);
    }
    cout << "-------------------------\nStep 1 result is:\n";
    debug_matrix<bit_matrix, bit_vector>(bit_matrix_1);

    // step 4, loop the computation
    bit_matrix bit_matrix_4 = bit_matrix_1;
    for (int i=0; i<CAL_COUNT; i++){
        cout << "-------------------------\n loop " << i + 1 << "\n";
        bit_matrix_4 = _correlation_calculation(bit_matrix_4, k, rows_count);
    }
    cout << "-------------------------\nStep 4 result is:\n";
    debug_matrix<bit_matrix, bit_vector>(bit_matrix_4);
    // step 5
    // process end
    string result;
    bit_vector bit_result = bit_matrix_4[0];
    for (bit_vector::iterator i = bit_result.begin(); i < bit_result.begin()+T0; i++){
        result += to_string(*i);
    }
    return result;
}

int main(){

    int k = 49;
    bit_vector F = random_list(k);
    cout << "Constants:\n";
    cout << "count is " << CAL_COUNT << ", T0 is " << T0 << "\n";

    string result;
    result = JJZ(F, k);

    cout << "-------------------------\nFinal result is:\n";
    cout << "result is " << result << endl;
}