#include <stdint.h>
#include <stdio.h>

void print_as_bin(char c) {
    for(int place = 128; place > 0; place /= 2) {
        if((c & place) == 0) printf("0");
        else printf("1");
    }
}


int main() {   
    char s = 200;
    unsigned char u = 200;

    printf("s: ");
    print_as_bin(s);
    printf("\t\tu: ");
    print_as_bin(u);
    printf("\n");

    //hhx use the width/size of the argument rather than the default size
    printf("s as hhx: %hhx\t\tu as hhx: %hhx\n", s, u); //hexadecimal --> base 16
                                                        //decimal --> base 10, binary --> base 2
                                                        //4 bit --> 0000 - 1001 (0-9) and 1010 - 1111 (A-F)
                                                        //2 hex digits represent 1 byte
                                                        //output: 11001000: 1100 (c) and 1000 (8)
    //UTF8 characters: 1-4 bytes
    //UTF8 prefixes in hex: 1 byte (0-7), 2 byte (start C or D), 3 byte (start E), 4 byte (start F)
    printf("s as x: %x\tu as x: %x\n", s, u); //x format char stands for hexadecimal
    //c8 = -70
    //s as x: ffffffc8 (utf - "sign-extending" printf wants to print 4 bytes for %x

    printf("s < 127: %d\t\tu < 127: %d\n", s > 127, u > 127);
}