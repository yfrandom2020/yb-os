#include <util/util.h>
int strcmp(const char *str1, const char *str2) 
{
    // Util - Compare between two strings and return wether they are equal or not    
    while (*str1 && (*str1 == *str2)) 
    {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2; // 0 if equal
}



void *memset(void *ptr, int value, size_t num) 
{
    // Fill memory with values
    // In: 1) pointer to address 2) value to put 3) how many bytes
    unsigned char *p = (unsigned char *)ptr;
    unsigned char v = (unsigned char)value;

    // Fill given address with given value
    for (size_t i = 0; i < num; i++) 
    {
        *p++ = v;
    }

    return ptr;
}
