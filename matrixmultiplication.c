#include <stdio.h>
int main() {
    int r1=3, r2=3, c1=3, c2=3;
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    int brr[3][3]={9,8,7,6,5,4,3,2,1};
    int crr[3][3];

    for (int i =0;i<r1;i++){
        for (int j =0;j<c1;j++){
            int sum =0;
            for (int k =0;k<c2;k++){
                sum+= arr[i][k]*brr[k][j];
            }
            crr[i][j]= sum;
        }
    }
    for (int i =0;i<3;i++){
        for (int j =0;j<3;j++){
            printf("%d ",crr[i][j]);
        }
        printf("\n");
    }
    return 0;
}