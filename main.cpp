#include <io.h>
#include <cstdio>
#include <cstring>
#include "SHX_font.h"

SHX_Font_t SHX_Font;

int convert_file(char *filename)
{
    char newfilename[1024];
    strcpy(newfilename, filename);
    char *pointer = newfilename;
    char *extension = 0;
    while (*pointer)
    {
        if (*pointer == '.')
            extension = pointer;
        pointer++;
    }
    if (extension == 0)
    {
        printf("Internal error\n");
    }
    *++extension = 'l';
    *++extension = 'f';
    *++extension = 'f';
    printf("%s -> %s\n", filename, newfilename);
    // return 0;

    SHX_Font.load_font(filename);
    SHX_Font.convert_to_unicode();
    SHX_Font.sort_symbols();
    SHX_Font.print_shape('A'); // debug
    SHX_Font.print_shape('B'); // debug
    SHX_Font.print_shape('C'); // debug
    // SHX_Font.print_shape(0x49A2);//debug
    // SHX_Font.print_shape(0x4EA2);//debug
    // SHX_Font.print_shape(0x55A2);//debug
    // SHX_Font.print_shape(0x56A2);//debug
    // SHX_Font.print_shape(0xE9A2);//debug
    // SHX_Font.print_shape(0xEAA1);//debug
    // SHX_Font.print_shape(0xECA2);//debug
    // SHX_Font.print_shape(0xEDA2);//debug
    // SHX_Font.print_shape(0xEFA2);//debug
    // SHX_Font.print_shape(0x95);//debug
    // SHX_Font.print_shape(0x42);//debug
    // SHX_Font.print_shape(0x4A);//debug
    // SHX_Font.print_shape(0x45);//debug
    SHX_Font.save_lff(newfilename);
    SHX_Font.free_memory();

    return 0;
}

int main(int argc, char **argv)
{
    printf("-- SHX font converter v.1.0 (x%i)\n", 8 * sizeof(void *));

    if (argc < 2)
    {
        printf("USAGE:\n");
        printf("SHX_font_converter 1.shx 2.shx 3.shx ...\n");
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        char *filename = argv[i];
        printf("Converting %s\n", filename);
        convert_file(filename);
    }
    return 0;
}
