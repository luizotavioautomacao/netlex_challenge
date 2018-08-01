/* ****************************************************************************************/
/* // **********  ////    NETLEX CHALLENGE

/* // **********  ////    How can compile the program?

/* // **********  ////    In prompt the command or terminal:

/* // **********  ////    LINUX: gcc anagram.c -o obj_exec && ./obj_exec 
/* // **********  ////    WINDOWS: gcc anagram.c -o obj_exec && obj_exec 

/* // **********  ////    Author: Luiz Otávio Mendes de Oliveira
/* // **********  ////    Creation date:    30jul2018
/* // **********  ////    Revision date:    30jul2018  
/* // **********  ////    ******************************************************************/

#include <stdio.h> // printf, puts, scanf
#include <stdlib.h>
#include <string.h> // strstr, strcmp, strchr, strcpy, strlen, strcat

void ordenation(int *, int);
char *readline();

int main()
{
    puts("Digite o numero de anagramas: ");
    char *n_str = readline();
    char *n_endptr; // trash, not number
    int n = strtol(n_str, &n_endptr, 10); // number of elements > convert string to long

    if (n_endptr == n_str || *n_endptr != '\0')
    {
     exit(EXIT_FAILURE);
    }

    puts("Digite anagrama: ");
    char *anagram = readline();

    puts("String que deseja saber se é permutada: ");
    char *permutation = readline();

    int *_ASCII_1 = malloc(sizeof(int) * n);
    int *_ASCII_2 = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    { // copy anagram to ASCII && copy permutation to ASCII
        _ASCII_1[i] = anagram[i];
        _ASCII_2[i] = permutation[i];
        //printf("_ASCII_1[%i], _ASCII_2[%i]\n", _ASCII_1[i], _ASCII_2[i]); // output in ASCII
    }

    ordenation(_ASCII_1, n);
    ordenation(_ASCII_2, n);

    for (int i = 0; i < n; i++)
    {
        if (_ASCII_1[i] == _ASCII_2[i])
            continue;
        else
        {
            printf("\nNão são anagramas!\n");
            printf("\n\\_(ツ)_/¯\n\n");
            return 0;
        }
    }

    printf("\n\n\nSÃ0 4NagRAmA$ =]\n\n\n");
    printf(" (\\__/) \n");
    printf("(='.'=) \n");
    printf("(\")_(\") \n\n\n");

    return 0;
}

void ordenation(int *ASCII, int n)
{
    int spin = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ASCII[i] >= ASCII[j])
            { // inverte as duas posições
                spin = ASCII[i];
                ASCII[i] = ASCII[j];
                ASCII[j] = spin;
            }
        }
    }

    // printf ASCII ordenado
    // for (int i = 0; i < n; i++)
    //     printf("ASCII[%i]: %i\n", i, ASCII[i]);
}

char *readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char *data = malloc(alloc_length);

    while (1)
    {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line)
        {
            break;
        }
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    }
    else
    {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

// for (int i = 0; i < n - 1; i++)
// {
//     minimum_coefficient = i;
//     for (int j = i + 1; i < n; j++)
//     {
//         if (*(ASCII + j) > *(ASCII + minimum_coefficient))
//             minimum_coefficient = j;
//     }

//     if (i != minimum_coefficient)
//     {
//         spin = ASCII[i];
//         ASCII[i] = ASCII[minimum_coefficient];
//     }
//     start = 1;

// while (*anagrama)
// {
//     // void ConvString2UI (char * s, unsigned int *j)
// }

// for (int i = 0; i < n; i++)
//     {
//         ConvString2UI(anagrama[i], &_ASCII_1[i]);
//         ConvString2UI(permutation[i], &_ASCII_2[i]);
//     }

// // ordenar _ASCII[i]
//     ordenation(&_ASCII_1, n);
//     ordenation(&_ASCII_2, n);

//     for (int i = 0; i < n; i++)
//     {
//         if (_ASCII_1[i] == _ASCII_2[i])
//         {
//             prinff("ASCII_1: %i ASCII_2: %i", _ASCII_1[i], _ASCII_2[i]);
//             continue;
//         }
//         else
//             prinff("Nao eh anagrama!\n");
//         break;
//     }