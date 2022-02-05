#include "cache.h"
#include <stdio.h>


void PrintCacheLines(CacheMemory* cache){
    for(int k =0; k < CacheLineSize; k++){
        printf("Linha: %03d - [0x%08X] [0x%08X - 0x%08X] H(%d) M(%d)\n", k, cache->lines[k].tag,cache->lines[k].firstAddress,cache->lines[k].lastAddress,cache->lines[k].hit,cache->lines[k].miss );
    }
}

void InitCache(CacheMemory* cache){
    for(int k =0; k < CacheLineSize; k++){
       cache->lines[k].tag = 0;
       cache->lines[k].firstAddress =0;
       cache->lines[k].lastAddress = 0;
       cache->lines[k].hit = 0;
       cache->lines[k].miss = 0;
       cache->lines[k].status[0] = 0;
       cache->lines[k].status[1] = 0;
    }
}

int AddressHandler(CacheMemory* cache, unsigned int address) {
    int tag   = address >> 12;
    int index = address >> 4 & 0xFF;

    if(cache->lines[index].tag == tag){
        (cache->lines[index].hit)++;
    } else {
         cache->lines[index].tag = tag;
         cache->lines[index].status[0] = 0; //d
         cache->lines[index].status[1] = 1; //v
         cache->lines[index].firstAddress = address&0xFFFFFFF0;
         cache->lines[index].lastAddress = address|0xF;
         (cache->lines[index].miss)++;
    }
}