#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<arpa/inet.h>

int main(int argc, char* argv[]){

    if(argc != 3)
    {
        printf("[*]Usage: ./add-nbo <file1> <file2>\n");
        exit(0);
    }

    FILE *fp1 = fopen(argv[1], "r");
    FILE *fp2 = fopen(argv[2], "r");

    if(fp1 == 0 || fp2 == 0)
    {
        printf("[*] File open error\n");
        exit(0);
    }

    uint32_t a, b, res;
    fread(&a, 1, 4, fp1);
    fread(&b, 1, 4, fp2);

    a = ntohl(a);
    b = ntohl(b);

    res = a + b;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, res, res);

    return 0;
}