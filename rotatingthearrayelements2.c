#include <stdio.h>

int main() {
    int arr[5]={2,3,4,5,1};
    for(int i=4;i>=2;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=1;
    arr[1]=2;
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
 }
    

    return 0;
}