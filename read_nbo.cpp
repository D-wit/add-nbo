#include "r_file.h"

uint32_t read_nbo(FILE *fp)
{
    uint32_t a;
    uint32_t temp_bin;
    fread(&temp_bin,sizeof(uint32_t),1,fp); //read bin file
    a = temp_bin; //buffer to variable
    fclose(fp);
    return ntohl(a); //Little_Endian to NBO
}
