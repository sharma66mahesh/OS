#include<stdio.h>

int main(int argc, char *argv[])
{
    unsigned long newLines = 0, words = 0, bytes = 0;
    char c, c1;

    if(argc != 2)
    {
        printf("Usage: ./wc fileName");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    while((c = fgetc(fp)) != EOF)
    {
        if(c == '\n' || c == ' ' || c == '\t')
        {
            //check the previous char to see if it was a word
            fseek(fp, -2, SEEK_CUR);
            if((c1 = fgetc(fp)) != '\n' && c1 != ' ' && c1 != '\t')
            {
                words++;
            }
            fseek(fp, 1, SEEK_CUR);
            if(c == '\n')
            {
                newLines++;
            }
        }
        bytes++;
    }
    printf(" %lu %lu %lu %s\n", newLines, words, bytes, argv[1]);
    return 0;
}
