#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint8_t field1 : 4;
    uint8_t field2 : 4;
    uint8_t field3 : 4;
    uint8_t field4 : 4;
} BitFieldData;

int main()
{
    BitFieldData data;
    uint8_t target;
    memcpy(&target, &data, sizeof(target));
    printf("Register Value: %x\n", target);
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (target & (1 << i)) ? 1 : 0);
    }
    return 0;
}