#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "r_file.h"


int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    uint32_t nbo1, nbo2;
    if(argc!=3){ //lack or excess of arguments
        printf("Wrong Syntax: Please correct your command.\nRight Syntax: %s <file1> <file2>\n",argv[0]);
        exit(1);
    }
    if(!(fp1 = fopen(argv[1],"rb"))){ //Can't find filename
        printf("file1 cannot be found.\n");
        exit(1);
    }
    if(!(fp2 = fopen(argv[2],"rb"))){ //Can't find filename
        printf("file2 cannot be found.\n");
        exit(1);
    }

    nbo1 = read_nbo(fp1);
    nbo2 = read_nbo(fp2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",nbo1,nbo1,nbo2,nbo2,(nbo1+nbo2),(nbo1+nbo2));

    return 0;
}
