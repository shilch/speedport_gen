/*
 * This password recovery tool calculates the default wpa2 phrase of
 * Speedport devices (Telekom).
 * It uses ESSID and BSSID to calculate a list of candidate
 * serial numbers which are used to generate the phrases.
 *
 * Usage:
 *   speedport_gen WLAN-XXXXXX XX:XX:XX:XX:XX:XX
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv) {
    if(argc != 3){
        printf("Need 2 parameters: ESSID and BSSID\n");
        return 1;
    }

    char* essid = argv[1];
    char* bssid = argv[2];

    if(strlen(essid) != 11){
        printf("Unsupported ESSID\n");
        return 1;
    }
    if(strlen(bssid) != 17){
        printf("Invalid BSSID\n");
        return 1;
    }

    char essid9 = (char) toupper(essid[9]);
    char essid10 = (char) toupper(essid[10]);
    char bssid13 = (char) toupper(bssid[13]);
    char bssid15 = (char) toupper(bssid[15]);
    char bssid16 = (char) toupper(bssid[16]);

    for(int x = 0; x < 16; x++)
    for(int y = 0; y < 16; y++)
    for(int z = 0; z < 16; z++)
        printf("SP-%c%X%c%c%c%c%X%X%X\n", essid9, z, essid10, bssid13, bssid15, bssid16, x, y, z);

    return 0;
}
