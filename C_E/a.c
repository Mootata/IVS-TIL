#include <stdio.h>
#include <stdint.h>
int main()
{
    uint8_t canDataArray[8] = {0x64, 0xC8, 0x00, 0x00, 0x01, 0x32, 0x4E, 0x28};
    // Current Data : 403,128,0,1 G Sensor : 12,36,56,40
    // bit 0 1 2 3 4 5 6 7 / 0 1
    //  MSB                 LSB

    uint16_t currentData1 = ((uint16_t)canDataArray[0] << 2) | (canDataArray[1] >> 6);
    uint16_t currentData2 = ((uint16_t)(canDataArray[1] & 0x3F) << 4) | (canDataArray[2] >> 4);
    uint16_t currentData3 = ((uint16_t)(canDataArray[2] & 0x0F) << 6) | (canDataArray[3] >> 2);
    uint16_t currentData4 = ((uint16_t)(canDataArray[1] & 0x03) << 8) | canDataArray[4];

    uint8_t gsensor1 = ((canDataArray[5] >> 2) & 0x3F);
    uint8_t gsensor2 = ((canDataArray[5] & 0x03) << 4) | (canDataArray[6] >> 4);
    uint8_t gsensor3 = ((canDataArray[6] & 0x0F) << 2) | (canDataArray[7] >> 6);
    uint8_t gsensor4 = (canDataArray[7] & 0x3f);

    printf("Current Data:\n");
    printf("Current 1: %u\n", currentData1);
    printf("Current 2: %u\n", currentData2);
    printf("Current 3: %u\n", currentData3);
    printf("Current 4: %u\n", currentData4);
    printf("\nGsensor Data:\n");
    printf("Gsensor 1: %u\n", gsensor1);
    printf("Gsensor 2: %u\n", gsensor2);
    printf("Gsensor 3: %u\n", gsensor3);
    printf("Gsensor 4: %u\n", gsensor4);
    return 0;
}