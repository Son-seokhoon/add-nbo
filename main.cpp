#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t read_uint32(FILE* file) {
    uint32_t num;
    fread(&num, sizeof(uint32_t), 1, file);
    return ntohl(num);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: add-nbo <file1> <file2>\n");
        return 1;
    }

    FILE* file1 = fopen(argv[1], "rb");
    FILE* file2 = fopen(argv[2], "rb");

    if (file1 == NULL || file2 == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    uint32_t num1 = read_uint32(file1);
    uint32_t num2 = read_uint32(file2);
    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    fclose(file1);
    fclose(file2);

    return 0;
}
