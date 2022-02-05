#include "../input/input.h"
int L1[4096];
int L2[1024];
void initMMU() {
    LoadFile("files/L1.txt",L1);
    LoadFile("files/L2.txt",L2);
}

unsigned int handlerMMU(unsigned int virtualAddress){
    unsigned int realAddress = 0;
    unsigned int vBase = virtualAddress >> 20;
    unsigned int rBase = 0;
    unsigned int offSet = 0;
    unsigned int L1Offset = 0;
    unsigned int L2Offset = 0;
    unsigned int tmp = L1[vBase];
    unsigned LSB = tmp & 0x3;

    switch (LSB) {
        case 0:
            printf("Page Fault\n");
            break;
        case 1:
            L2Offset = (virtualAddress&0x000FF000) >> 12;
            offSet = virtualAddress&0x00000FFF;
            realAddress = L2[L2Offset] | offSet;
            break;
        case 2:
            rBase= tmp&0xFFF00000;
            L1Offset = virtualAddress&0x000FFFFF;
            realAddress = rBase | L1Offset;
            break;
        case 3:
            L2Offset = (virtualAddress&0x000FFFFF) >> 10;
            offSet = virtualAddress&0x000003FF;
            realAddress = L2[L2Offset] | offSet;
            break;
    }

    return realAddress;
}