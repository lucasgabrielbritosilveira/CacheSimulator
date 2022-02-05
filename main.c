#include "lib/cache.h"
#include "input/input.h"
#include "lib/mmu.h"
int main (){
    unsigned int bufferAddressSize = CountLines("files/address.txt");
    unsigned int bufferAddress[bufferAddressSize];
    unsigned int realAddress[bufferAddressSize];
    CacheMemory cache;

    initMMU();
    InitCache(&cache);

    LoadFile("files/address.txt",bufferAddress);

    for (int i = 0; i < bufferAddressSize; ++i) {
        printf("0x%X \n",bufferAddress[i]);
        realAddress[i] = handlerMMU(bufferAddress[i]);
    }

    for (int i = 0; i < bufferAddressSize; ++i) {
        AddressHandler(&cache,realAddress[i]);
    }

  PrintCacheLines(&cache);

	return 0;
}
