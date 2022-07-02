#include <chvm.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#if defined(__clang__)
    #include <getopt.h>
#elif defined(__GNUC__) || defined(__GNUG__)
    #include <unistd.h>
#endif

/**
 * total memory: 1,114,095 B (yaklaşık 1 MiB)
 * graphical buffer:
 * 		- size: 192000 B (187.5 KiB, 320x200x3, 24 bits for pixel)
 * 		- address: 0xE11EF (922095) (SP 0xE11E, OFFSET 0x10)
 * addressing: SP:OFFSET = SP * 16 + OFFSET
 * 0xE11E * 0x10 + 0xF = 0xE11EF
 */

int main(int argc, char **argv) {
    uint8_t gflag = 0;

    int c;

    while ((c = getopt(argc, argv, ":g")) != -1) {
        switch (c) {
            case 'g':
                gflag = 1;
                break;
            case '?':
                if (isprint(optopt))
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf(stderr,
                            "Unknown option character `\\x%x'.\n",
                            optopt);
                return 1;
            default:
                return 1;
        }
    }

    if (optind >= argc) {
        fprintf(stderr, "Missing filename\n");
        return -1;
    }

    vm_run(argv[optind]);

    return 0;
}