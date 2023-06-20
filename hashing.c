#include <stdio.h>
#include <stdlib.h>

void initialise(int **arr, int n){
    *arr = (int *) malloc(sizeof(int)*n);
}

void printtable(int *arr, int n){
    for(int i = 0; i<n; i+=1){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int **arr, int data, int n){
    int position = data%n;
    if(*((*arr)+position) == 0)
        *((*arr)+position) = data;
    else{
        int i = position;
        while(i != position-1){
            if(i == n) i = 0;
            int probePosition = (position+i)%n;
            if(*((*arr)+probePosition) == 0) {
                *((*arr)+probePosition) = data;
                break;
            }
            i += 1;
        }
    }
}

int main(){
    int *arr = NULL, n, size, data;
    printf("Enter the size -> ");
    scanf("%d", &n);
    size = n;
    initialise(&arr, n);
    while(size){
        size -= 1;
        printf("Enter the element -> ");
        scanf("%d", &data);
        insert(&arr, data, n);
    }
    printtable(arr, n);
    return 0;
}