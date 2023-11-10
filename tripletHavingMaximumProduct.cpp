// Given an integer array, find a triplet having maximum product.

#include <iostream>
using namespace std;

int maximum3(int arr[], int n){
    bool isZero = false;
    int result = arr[0];

    int max1 = max(max(arr[0], arr[1]), arr[2]); // 2
    int max3 = min(min(arr[0], arr[1]), arr[2]); // 0
    int max2 = arr[0] + arr[1] + arr[2] - max1 - max3; // 1

    int min1 = max3; // 0
    int min2 = max2; // 1
    int min3 = max1; // 2

    int maxNeg1 = 0;
    int maxNeg2 = 0;
    int maxNeg3 = 0;

    int totalPositives = 0; 

    for(int i = 0; i < n; i++) {
        if(i>2){
            if(arr[i] > max1) {max3 = max2; max2 = max1; max1 = arr[i];}
            else if((arr[i]==max1) || (arr[i] > max2)) {max3 = max2; max2 = arr[i];}
            else if((arr[i] == max2) || (arr[i] > max3)) {max3 = arr[i];}
    
            if(arr[i] < min1) {min3 = min2; min2 = min1; min1 = arr[i];}
            else if((arr[i]==min1) || (arr[i] < min2)) {min3 = min2; min2 = arr[i];}
            else if((arr[i] == min2) || (arr[i] < min3)) {min3 = arr[i];}
        }

        if (arr[i] > 0) totalPositives++;
        else if(arr[i] == 0) isZero = true; // totalPositives++;
        else{
            if (maxNeg1==0)maxNeg1=arr[i];
            else if (maxNeg2==0)maxNeg2=arr[i];
            else if (maxNeg3==0){
                int x = maxNeg1, y = maxNeg2;
                maxNeg1 = max(max(x, y), arr[i]);
                maxNeg3 = min(min(x, y), arr[i]);
                maxNeg2 = x + y + arr[i] - maxNeg1 - maxNeg3;
            }else{
                if(arr[i] > maxNeg1) {maxNeg3 = maxNeg2; maxNeg2 = maxNeg1; maxNeg1 = arr[i];}
                else if((arr[i]==maxNeg1) || (arr[i] > maxNeg2)) {maxNeg3 = maxNeg2; maxNeg2 = arr[i];}
                else if((arr[i] == maxNeg2) || (arr[i] > maxNeg3)) {maxNeg3 = arr[i];}
            }
        }
    }

    int x,y,z;

    if(totalPositives>=3){
        result = max(max1*max2*max3, max1*min1*min2);
        if(max1*max2*max3 > max1*min1*min2)x=max1, y=max2, z=max3;
        else x=max1, y=min1, z=min2;
    }else if(totalPositives==2 || totalPositives==1){
        result = max1*min1*min2;
        x=max1, y=min1, z=min2;
    }else if(isZero){
        result = 0;
        x=0; y=maxNeg1, z=maxNeg2;
    }else{
        result = maxNeg1*maxNeg2*maxNeg3;
        x=maxNeg1, y=maxNeg2, z=maxNeg3;
    }



    cout<<"The triplet having the maximum product is: ("<<x<<", "<<y<<", "<<z<<") and the maxmum product is: "<<result<<endl;

    return result;
}

int main(){

    // Test Cases
    int test_cases = 10;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {-2, -1, 0, 1, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int arr3[] = {5, -2, -1, 3, 2};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    int arr4[] = {-4, 1, -8, 9, 6};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);

    int arr5[] = {1, 7, 2, -2, 5};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);

    // Function calls
    maximum3(arr1, n1); // The triplet having the maximum product is: (10, 9, 8) and the maxmum product is: 720
    maximum3(arr2, n2); // The triplet having the maximum product is: (2, -2, -1) and the maxmum product is: 4
    maximum3(arr3, n3); // The triplet having the maximum product is: (5, 3, 2) and the maxmum product is: 30
    maximum3(arr4, n4); // The triplet having the maximum product is: (9, -8, -4) and the maxmum product is: 288
    maximum3(arr5, n5); // The triplet having the maximum product is: (7, 5, 2) and the maxmum product is: 70

    return 0;
}
