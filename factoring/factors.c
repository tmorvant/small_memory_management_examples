
#include <stdio.h>

unsigned* build_factors(unsigned N) {
    
    
    int arr[256];
    unsigned* ptr;
    if (N == 1 || N == 0) {
        
        return NULL;
    }
    int p = 2;
    int index = 0;
    while (N >= 2) {
        if(N % p == 0) {
            N = N / p;
            
            arr[index] = p;
            // printf("%d\n", arr[index]);
            index+=1;
        }
        else {
            p += 1;
        }
    }
    arr[index] = 0;
    // printf("%d\n", arr[index]);
    // printf("%d\n", index);
    ptr = (int) malloc((index + 1) * sizeof(int));
    if (ptr == NULL) {
        printf("Malloc unsuccessful");
        exit(0);
    }
    for (size_t i = 0; i <= index; i++)
    {
        ptr[i] = arr[i];
        //printf("%d\n", ptr[i]);
    }
    
    
    
    // while (i <= index) {
    //     ptr[i] = arr[i];
    // }
    

    //ptr = &arr[0];
    return ptr;
}

void show_array(unsigned* A) {
    
    if (A == NULL) {
        printf("\n");
        return;
    }
    int i = 0;
    //printf("%d\n", A[i]);
    while (A[i+1] != 0) {
        printf("%d, ", A[i]);
        i++;
    }
    printf("%d\n", A[i]);
}

unsigned* build_common(unsigned* A, unsigned* B) {
    
    if(A == NULL || B == NULL) {
        return NULL;
    }
    
    int arr[256];
    unsigned* ptr;
    int index = 0;
    int i = 0;
    int j = 0;
    int count = 0;
    
    while (A[i] != 0 && B[j] != 0) {
        //printf("%d, %d\n", *A, *B);
        if (A[i] == B[i]) {
            //arr[index] = A[i];
            count++;
            i++;
            j++;
            index++;
        }
        else if (A[i] < B[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    //printf("%d", count);
    ptr = (int) malloc ((count + 1) * sizeof(int));
    if (ptr == NULL) {
        printf("Malloc unsuccessful");
        exit(0);
    }

    i = 0;
    j = 0;
    index = 0;
    
    while (A[i] != 0 && B[j] != 0) {
        //printf("%d, %d\n", A[i], B[j]);
        if (A[i] == B[j]) {

            ptr[index] = A[i];
            
            i++;
            j++;
            index++;
        }
        else if (A[i] < B[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    ptr[index] = 0;
    //ptr = &arr[0];
    // int k = 0;
    // while (ptr[k] != 0) {
    //     printf("%d\n", ptr[k]);
    //     k++;
    // }
    // printf("%d\n", ptr[k]);
    return ptr;
}

int main() {
    

    //build_common(build_factors(600), build_factors(140));
    int M, N;
    //show_array(build_factors(600));
    
    printf("Enter two integers M, N:\n");
    scanf("%d, %d", &M, &N);

    printf("%d has factors: ", M);
    
    show_array(build_factors(M));

    printf("%d has factors: ", N);
   
    show_array(build_factors(N));
    
   
    
    printf("%d and %d have common factors: ", M, N);
    
    
    show_array(build_common(build_factors(M), build_factors(N)));
    return 0;
}