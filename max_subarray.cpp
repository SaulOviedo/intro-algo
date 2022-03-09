//
// 4.1 The maximun subarray problem
// Completado el 09/04/2022
//

#include <iostream>
#include <string>
using namespace std;

struct subarray {
    int left;
    int right;
    int sum;
};

subarray find_max_crossing_subarray(int A[], int low, int mid, int high) {
    subarray result;

    int left_sum = -10000;
    int sum = 0;
    for (int i=mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            result.left = i;
        }
    }

    int right_sum = -10000;
    sum = 0;
    for (int i=mid+1; i <= high; i++) {
        sum += A[i];
        if (sum > right_sum) {
            right_sum = sum;
            result.right = i;
        }
    }

    result.sum = left_sum + right_sum;
    return result;
}

subarray find_max_subarray(int A[], int low, int high) {
    if (low == high) {
        subarray result;
        result.left = low;
        result.right = high;
        result.sum = A[low];
        return result;
    }else{
        int mid = (low + high) / 2;
        subarray left = find_max_subarray(A, low, mid);
        subarray right = find_max_subarray(A, mid+1, high);
        subarray cross = find_max_crossing_subarray(A, low, mid, high);

        if (left.sum >= right.sum && left.sum >= cross.sum) {
            return left;
        }else if (right.sum >= left.sum && right.sum >= cross.sum) {
            return right;
        }else{
            return cross;
        }
    }
}

int main() {
    int A[] = {1,-1,2,1,-1,-1,1};
    subarray result = find_max_subarray(A, 0, 6);
    cout<<"left: "<<result.left<<" right: "<<result.right<<" sum: "<<result.sum<<endl;
    return 0;
}