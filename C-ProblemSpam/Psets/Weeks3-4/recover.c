#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // accept a single line arg
    if (argc != 2) {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL) {
        printf("Could not open the file\n");
        return 1;
    }

    uint8_t buffer[512];
    int jpeg_count = 0;

    FILE *f = NULL;

    // read while there's still data from the memory card
    while (fread(buffer, sizeof(uint8_t), 512, card) == 512) {
        char filename[8];
        // check for the first four bytes for JPEG headers
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) {
            if (f != NULL) {
                fclose(f);
            }
            sprintf(filename, "%03i.jpg", jpeg_count);
            f = fopen(filename, "w");
            fwrite(buffer, sizeof(uint8_t), 512, f);
            jpeg_count++;
        } else {
            if (f != NULL) {
                fwrite(buffer, sizeof(uint8_t), 512, f);
            }
        }
    }
    if (f != NULL) {
        fclose(f);
    }
    fclose(card);
    return 0;
}
