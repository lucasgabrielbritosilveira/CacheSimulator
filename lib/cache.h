#ifndef _CACHE
#define _CACHE
#define CacheLineSize 256
typedef struct {
    int tag;
    int firstAddress;
    int lastAddress;
    int hit;
    int miss;
    int status[2]; //d | v
    int word[4]; //word0 - word3
} CacheLine;

typedef struct {
    CacheLine lines[CacheLineSize];
} CacheMemory;

int AddressHandler(CacheMemory*,unsigned int);
void PrintCacheLines(CacheMemory*);
void InitCache(CacheMemory*);
#endif


