#include <stdio.h>
#include <stdlib.h>

int doubled_digit_value(int digit) {
    int doubled_digit = digit * 2;
    int sum;
    if (doubled_digit >= 10) {
        sum = 1 + doubled_digit;
    } else {
        sum = doubled_digit;
    }
    return sum;
}

int main(void) {
    char input_char;
    int odd_length_checksum = 0;
    int even_length_checksum = 0;
    int position = 1;

    printf("Enter a number: ");
    input_char = getc(stdin);
    while (input_char != '\n') {
        if (input_char < '0' || input_char > '9') {
            fprintf(stderr, "ERROR: Input must be a valid number.\n");
            return EXIT_FAILURE;
        }
        int digit = input_char - '0';
        if (position % 2 == 0) {
            odd_length_checksum += doubled_digit_value(digit);
            even_length_checksum += digit;
        } else {
            odd_length_checksum += digit;
            even_length_checksum += doubled_digit_value(digit);
        }
        input_char = getc(stdin);
        position++;
    }

    int checksum;
    if ((position - 1) % 2 == 0) {
        checksum = even_length_checksum;
    } else {
        checksum = odd_length_checksum;
    }
    if (checksum % 10 == 0) {
        printf("Luhn checksum validation passed.\n");
    } else {
        printf("Luhn checksum validation failed.\n");
    }
    return EXIT_SUCCESS;
}
