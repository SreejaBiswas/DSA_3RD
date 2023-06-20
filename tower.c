#include <stdio.h>

void printmove(int disk, int src, int dst){
    printf("move disk %d from rod %d to rod %d\n", disk, src, dst);
}

void hanoi(int n, int src, int aux, int dst){
    if (n == 1){
            printmove(n, src, dst);
            return;
    }
    hanoi(n-1, src, dst, aux);
    printmove(n, src, dst);
    hanoi(n-1, aux, src, dst);
}

int main(){
    int disks, src, dst, aux;
    printf("Enter number of disks: ");
    scanf("%d", &disks);
    hanoi(disks, 1, 2, 3);
    return 0;
}