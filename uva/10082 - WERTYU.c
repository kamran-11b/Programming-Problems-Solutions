#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i, l;
    while(gets(str))
    {
        l = strlen(str);
        for(i = 0; i < l; ++i)
        {
            switch(str[i]){
            case '1':
                        str[i] = '`';
                        break;
            case '2':
                        str[i] = '1';
                        break;
            case '3':
                        str[i] = '2';
                        break;
            case '4':
                        str[i] = '3';
                        break;
            case '5':
                        str[i] = '4';
                        break;
            case '6':
                        str[i] = '5';
                        break;
            case '7':
                        str[i] = '6';
                        break;
            case '8':
                        str[i] = '7';
                        break;
            case '9':
                        str[i] = '8';
                        break;
            case '0':
                        str[i] = '9';
                        break;
            case '-':
                        str[i] = '0';
                        break;
            case '=':
                        str[i] = '-';
                        break;
            case 'W':
                        str[i] = 'Q';
                        break;
            case 'E':
                        str[i] = 'W';
                        break;
            case 'R':
                        str[i] = 'E';
                        break;
            case 'T':
                        str[i] = 'R';
                        break;
            case 'Y':
                        str[i] = 'T';
                        break;
            case 'U':
                        str[i] = 'Y';
                        break;
            case 'I':
                        str[i] = 'U';
                        break;
            case 'O':
                        str[i] = 'I';
                        break;
            case 'P':
                        str[i] = 'O';
                        break;
            case '[':
                        str[i] = 'P';
                        break;
            case ']':
                        str[i] = '[';
                        break;
            case 'S':
                        str[i] = 'A';
                        break;
            case 'D':
                        str[i] = 'S';
                        break;
            case 'F':
                        str[i] = 'D';
                        break;
            case 'G':
                        str[i] = 'F';
                        break;
            case 'H':
                        str[i] = 'G';
                        break;
            case 'J':
                        str[i] = 'H';
                        break;
            case 'K':
                        str[i] = 'J';
                        break;
            case 'L':
                        str[i] = 'K';
                        break;
            case ';':
                        str[i] = 'L';
                        break;
            case '\'':
                        str[i] = ';';
                        break;
            case '\\':
                        str[i] = '\'';
                        break;
            case 'X':
                        str[i] = 'Z';
                        break;
            case 'C':
                        str[i] = 'X';
                        break;
            case 'V':
                        str[i] = 'C';
                        break;
            case 'B':
                        str[i] = 'V';
                        break;
            case 'N':
                        str[i] = 'B';
                        break;
            case 'M':
                        str[i] = 'N';
                        break;
            case ',':
                        str[i] = 'M';
                        break;
            case '.':
                        str[i] = ',';
                        break;
            case '/':
                        str[i] = '.';
                        break;

            }
        }
        puts(str);
    }
    return 0;
}
