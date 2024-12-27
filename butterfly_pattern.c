// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int n;
    int spaces;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    spaces = 2*n-2;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        for (int k = 0; k < spaces; k++) {
            printf(" ");
        }
        for (int l = i; l >= 1; l--) {
            printf("%d", l);
        }
        printf("\n");
        spaces -= 2;
    }
    
    spaces = 0;
    for(int i = n; i>=1; i--){
        for(int j=1; j<=i; j++){
            printf("%d",j);
        }
        for(int k = 0; k<spaces; k++){
            printf(" ");
        }
        for(int l=i; l>=1; l--){
            printf("%d",l);
        }
        printf("\n");
        spaces += 2;
    }

    return 0;
}