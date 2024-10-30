#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[])
{
    double kel, cel, farn;
    float input;
    input = atof(argv[1]);
    
    if ( argc == 3 )
    {
        switch(argv[2][0])
        {
            case 'C':
                case 'c':
                    if ( input > -273.15 )
                    {
                        farn = input*9/5+32;
                        kel = input+273.15;
                        printf("%.2f F\n%.2f K\n", farn, kel);
                    }
                    else
                    {
                        printf("Absolute zero\n");
                    }
                    break;
            case 'K':
                case 'k':
                    if ( input > 0 )
                    {
                        cel = input-273.15;
                        farn = cel*9/5+32;
                        printf("%.2f F\n%.2f C\n", farn, cel);
                    }
                    else
                    {
                        printf("Absolute zero\n");
                    }
                    break;
            case 'F':
                case 'f':
                    if ( input > -459.67 )
                    {
                        cel = (input-32)*5/9.0;
                        kel = cel-273.15;
                        printf("%.2f C\n%.2f K\n", cel, kel);
                    }
                    else
                    {
                        printf("Absolute zero\n");
                    }
                    break;
        }
    }
    else
    if ( argc == 2 )
    {
        if ( input > -273.15 )
        {
            farn = input*9/5.0+32;
            kel = input+273.15;
            printf("%.2f C:\n%.2f F\n%.2f K\n\n", input, farn, kel);
        }
        else
        {
            printf("Absolute zero\n");
        }
        farn=0; kel=0;

        if ( input > 0 )
        {
            cel = input-273.15;
            farn = cel*9/5+32;
            printf("%.2f K:\n%.2f F\n%.2f C\n\n", input, farn, cel);
        }
        else
        {
            printf("Absolute zero\n");
        }
        farn=0; cel=0;

        if ( input > -459.67 )
        {
            cel = (input-32)*5/9;
            kel = cel-273.15;
            printf("%.2f F:\n%.2f C\n%.2f K\n\n", input, cel, kel);
        }
        else
        {
            printf("Absolute zero\n");
        }
    }
    else
    {
        printf("Loser!");
    }
    return 0;
}
