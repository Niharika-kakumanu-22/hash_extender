#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Constants for MD5
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

// MD5 functions
#define F(x, y, z) ((x & y) | ((~x) & z))
#define G(x, y, z) ((x & z) | (y & (~z)))
#define H(x, y, z) (x ^ y ^ z)
#define I(x, y, z) (y ^ (x | (~z)))

// Left rotation of x by n bits
#define ROTATE_LEFT(x, n) ((x << n) | (x >> (32 - n))

// Function to calculate MD5 hash
void md5(const char *input, size_t input_len, uint32_t *digest) {
    // Initialize MD5 state
    uint32_t state[4];
    state[0] = 0x67452301;
    state[1] = 0xEFCDAB89;
    state[2] = 0x98BADCFE;
    state[3] = 0x10325476;

    // Calculate the length in bits
    uint64_t bit_len = (uint64_t)input_len * 8;

    // Append the bit '1' to the message
    // ...

    // Append the message length in bits
    // ...

    // Process the message in 512-bit blocks
    // ...

    // Output the MD5 hash as 128 bits (4 words of 32 bits each)
    digest[0] = state[0];
    digest[1] = state[1];
    digest[2] = state[2];
    digest[3] = state[3];
}

int main() {
    // Define your scenario parameters
    char secret[] = "last 3 digits of your roll number";
    char data[] = "your full name";
    char append[] = "14XJ1A0XXX"; // Replace XXX with your roll number

    // Calculate the length of the concatenated message
    size_t message_len = strlen(secret) + strlen(data) + strlen(append);

    // Concatenate the message
    char message[message_len];
    strcpy(message, secret);
    strcat(message, data);

    // Calculate the MD5 hash of H(secret||data)
    uint32_t hash_secret_data[4]; // MD5 produces a 128-bit (4-word) hash
    md5(message, strlen(secret) + strlen(data), hash_secret_data);

    // Output the hash of H(secret||data)
    printf("H(secret||data): ");
    for (int i = 0; i < 4; i++) {
        printf("%08x", hash_secret_data[i]);
    }
    printf("\n");

    // Append the append string
    strcat(message, append);

    // Calculate the MD5 hash of H(secret||data||append)
    uint32_t hash_secret_data_append[4];
    md5(message, message_len, hash_secret_data_append);

    // Output the hash of H(secret||data||append)
    printf("H(secret||data||append): ");
    for (int i = 0; i < 4; i++) {
        printf("%08x", hash_secret_data_append[i]);
    }
    printf("\n");

    return 0;
}
