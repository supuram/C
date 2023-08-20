#include <stdio.h>
#include<stdint.h>

int main() {
    struct PSI_buffer
    {
        uint32_t prev_ccounter;
        uint8_t *buffer;
        uint32_t buffer_length;
        uint32_t ccounter;
    };
    printf("Size of PSI_buffer = %lu bytes\n", sizeof(struct PSI_buffer));
    printf("Size of int = %zu bytes\n", sizeof(int));
    printf("Size of int32_t = %zu bytes\n", sizeof(int32_t));
    printf("Size of int16_t = %zu bytes\n", sizeof(int16_t));
    return 0;
}