#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void decimal_to_binary(int decimal, int *binary, int *length) {
    int index = 0;
    while (decimal > 0) {
        binary[index++] = decimal % 2; // Store the binary digit
        decimal /= 2; // Divide by 2 to get the next bit
    }
    *length = index; // Set the length of the binary array
}

void xor_with_mask(int *binary, int length) {
int i;
    #pragma omp parallel for
	  
       for (i = 0; i < length; i++) {
          binary[i] = binary[i] ^ 1; // XOR with 1 (flip the bits)
    }
}

void print_binary(int *binary, int length) {
int i;
    for ( i = length - 1; i >= 0; i--) { // Print in reverse order
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int decimal;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    if (decimal < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    // Array to hold binary representation
    int binary[32]; // Assuming a maximum of 32 bits for simplicity
    int length;

    // Convert decimal to binary
    decimal_to_binary(decimal, binary, &length);

    printf("Binary representation: ");
    print_binary(binary, length);

    // Perform XOR operation with all bits set to 1
    xor_with_mask(binary, length);

    printf("Encrypted (XOR with all bits set to 1): ");
    print_binary(binary, length);

    return 0;
}