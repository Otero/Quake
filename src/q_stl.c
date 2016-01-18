#include "lib/quakedef.h"

/*
 * Compare the two strings @string1 and @string2. This function replaces
 * the standard function strcmp of libc to make the code similar to the
 * original Quake where the developers created their own string compare
 * function
 *
 * Returns:
 * - equal: If both strings are equal, return 0
 * - @string1 > @string2: Return a negative number
 * - @string1 < @string2: Return a positive number
 */
int32_t Q_strcmp(uint8_t* string1, uint8_t* string2) {
    for(; *string1 == *string2; ++string1, ++string2) {
        if (!*string1) {
            // If we reach the null terminator, then the strings are the same
            // return 0
            return 0;
        }
    }
    // The strings are equal, therefore return 0
    return (*string1 < *string2) ? -1 : 1;
}


/*
 * Transform a character into its proper numerical value. The number @num
 * can be positive, negative or hexadecimal.
 *
 * De decimal representation of every number can be expressed as:
 *
 *  s a_n x 10^n + a_(n-1) x 10^(n-1) + a_(n-2) x 10^(n-2) ... + a_1 x 10 + a_0
 *
 * Where s in the sign of the number, a_n represent the decimal coeficient
 * of the number in that specific position and n represents the decimal
 * power where that the coeficient represents.
 *
 * This function uses this representation to return the numerical value of @num.
 *
 * Returns:
 * - success: Numerical value of the @num
 * - fail: Send an error and display error on screen
 */
int32_t Q_atoi(uint8_t* num) {
    int32_t sign = 1; // Sign for the final number
    int32_t num_value = 0; // Numerical value of param num

    // If the first value is a '-' char the number is considered negative
    if (*num == '-') {
        sign = -1;
        num++;
    }

    // Hexadecimal transformation
    if (num[0] == '0' && (num[1] == 'x' || num[1] == 'X')) {
        // Move the position of our pointer after the 'X' char
        num += 2;
        for (uint8_t current_char = *num; current_char != '\0'; current_char = *(++num)) {
            if (current_char >= '0' && current_char <= '9') {
                num_value = (num_value * 16) + (current_char - '0');
            }
            else if (current_char >= 'a' && current_char <= 'f') {
                num_value = (num_value * 16) + ((current_char - 'a') + 10);
            }
            else if (current_char >= 'A' && current_char <= 'F') {
                num_value = (num_value * 16) + ((current_char - 'A') + 10);
            }
        }
    }

    // Decimal transformation
    for(; *num; ++num) {
        num_value = (num_value * 10) + (*num - '0');
    }

    return sign * num_value;
}

/*
 * Copy the content of a string @source into @destiny
 *
 * Returns:
 * - None
 */
void Q_strcpy(uint8_t* destination, uint8_t* source) {
    while(*source) {
        *destination++ = *source++;
    }
    *destination = 0;
}

/*
 * Copy an specific number of bytes between two strings @source and @destiny
 *
 * Returns:
 * - None
 */
void Q_strncpy(uint8_t* destination, uint8_t* source, int32_t count) {
    if (count < 0) {
        return;
    }

    while (*source && count) {
        *destination++ = *source++;
        --count;
    }

    // If we still have more space to copy, intiallize to zero the memory in
    // that region
    while(count) {
        *destination++ = 0;
        --count;
    }
}


/*
 * Calculate the length of the string @string
 *
 * Returns:
 * - success: Length of @string
 */
int32_t Q_strlen(uint8_t* string) {
    int32_t length = 0;
    for(; *string; ++string, length++);

    return length;
}
