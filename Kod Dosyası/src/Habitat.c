
#include "Habitat.h"

void VeriAta(Habitat *habitat, const char *dosyaadi)
{
    FILE *dosya = fopen(dosyaadi, "r");
    if (dosya == NULL)
    {
        printf("Dosya açma hatası!\n");
        exit(1);
    }

    int satir = 0, sutun = 0, num;
    while (fscanf(dosya, "%d", &num) == 1)
    {
        if (num >= 1 && num <= 9)
        {
            Bitki bitki = BitkiEkle(num);
            habitat->matris[satir][sutun] = bitki->super;
        }
        else if (num >= 10 && num <= 20)
        {
            Bocek bocek = BocekEkle(num);
            habitat->matris[satir][sutun] = bocek->super;
        }
        else if (num >= 21 && num <= 50)
        {
            Sinek sinek = SinekEkle(num);
            habitat->matris[satir][sutun] = sinek->super->super;
        }
        else if (num >= 51 && num <= 99)
        {
            Pire pire = PireEkle(num);
            habitat->matris[satir][sutun] = pire->super->super;
        }

        if (habitat->matris[satir][sutun] != NULL)
        {
            sutun++;
            if (sutun >= MAX_SATSUT)
            {
                printf("Sütun sayısı fazla!\n");
                exit(1);
            }
            char c = fgetc(dosya);
            if (c == '\n' || c == EOF)
            {
                habitat->satir++;
                habitat->sutun = sutun;
                sutun = 0;
                satir++;
                if (satir >= MAX_SATSUT)
                {
                    printf("Satır sayısı fazla!\n");
                    exit(1);
                }
            }
        }
    }

    fclose(dosya); 
}

void VeriYaz(const Habitat *habitat)
{
    for (int i = 0; i < habitat->satir; i++)
    {
        for (int j = 0; j < habitat->sutun; j++)
        {
            if (habitat->matris[i][j]->num != 0)
            {
                printf("%s ", habitat->matris[i][j]->gorunum());
            }
            else
            {
                printf("X ");
            }
        }
        printf("\n");
    }
}

void VeriYe(const Habitat *habitat)
{
    int n;
    int m;
    int c;
    int kontrol;
    for (int z = 0; z < habitat->satir; z++)
    {
        for (int x = 0; x < habitat->sutun; x++)
        {
            if (habitat->matris[z][x]->num != 0)
            {
                n = 0;
                m = 0;
                c = x;
                kontrol = 0;
                do
                {
                    if (m + c > habitat->sutun && z + n < habitat->satir)
                    {
                        n++;
                        m = 0;
                        c = 0;
                        kontrol = 1;
                    }
                    if(m>0 && m + c <= habitat->sutun && habitat->matris[z+n][c + m] != NULL )
                    {
                        HabSat(habitat, z, x, c, n, m);
                    }
                    else if (kontrol ==1 && m + c <= habitat->sutun && habitat->matris[z+n][c + m] != NULL)
                    {
                        HabSat(habitat, z, x, c, n, m);
                    }
                    m++;    

                } while (habitat->matris[z][x]->num != 0 && (c + m <= habitat->sutun +1 && z + n <= habitat->satir));
            }
        }
    }
}

void HabSat(const Habitat *habitat, int z, int x, int c, int n, int m)
{
    if (strcmp(habitat->matris[z][x]->gorunum(), "B") == 0)
    {
        if (strcmp(habitat->matris[z + n][c + m]->gorunum(), "P") == 0 || strcmp(habitat->matris[z + n][c + m]->gorunum(), "S") == 0)
        {
            habitat->matris[z + n][c + m]->num = 0;
        }
        else if (strcmp(habitat->matris[z + n][c + m]->gorunum(), "C") == 0)
        {
            habitat->matris[z][x]->num = 0;
        }
        else if (strcmp(habitat->matris[z + n][c + m]->gorunum(), "B") == 0)
        {
            if (habitat->matris[z][x]->num < habitat->matris[z + n][c + m]->num)
                habitat->matris[z][x]->num = 0;
            else
                habitat->matris[z + n][c + m]->num = 0;
        }
    }
    else if (strcmp(habitat->matris[z][x]->gorunum(), "C") == 0)
    {
        if (strcmp(habitat->matris[z + n][c + m]->gorunum(), "P") == 0 || strcmp(habitat->matris[z + n][c + m]->gorunum(), "B") == 0)
        {
            habitat->matris[z + n][c + m]->num = 0;
        }
        else if (strcmp(habitat->matris[z + n][c + m]->gorunum(), "S") == 0)
        {
            habitat->matris[z][x]->num = 0;
        }
        else if (strcmp(habitat->matris[z + n][c + m]->gorunum(), "C") == 0)
        {
            if (habitat->matris[z][x]->num < habitat->matris[z + n][c + m]->num)
                habitat->matris[z][x]->num = 0;
            else
                habitat->matris[z + n][c + m]->num = 0;
        }
    }
    else if (strcmp(habitat->matris[z][x]->gorunum(), "S") == 0)
    {
        if (strcmp(habitat->matris[z + n][c + m]->gorunum(), "P") == 0 || strcmp(habitat->matris[z + n][c + m]->gorunum(), "C") == 0)
        {
            habitat->matris[z + n][c + m]->num = 0;
        }
        else if (strcmp(habitat->matris[z + n][c + m]->gorunum(), "B") == 0)
        {
            habitat->matris[z][x]->num = 0;
        }
        else if (strcmp(habitat->matris[z + n][c + m]->gorunum(), "S") == 0)
        {
            if (habitat->matris[z][x]->num < habitat->matris[z + n][c + m]->num)
                habitat->matris[z][x]->num = 0;
            else
                habitat->matris[x + n][c + m]->num = 0;
        }
    }
    else if (strcmp(habitat->matris[z][x]->gorunum(), "P") == 0)
    {
        if (strcmp(habitat->matris[z + n][c + m]->gorunum(), "B") == 0 || strcmp(habitat->matris[z + n][c + m]->gorunum(), "C") == 0 || strcmp(habitat->matris[z + n][c + m]->gorunum(), "S") == 0)
        {
            habitat->matris[z][x]->num = 0;
        }
        else if (strcmp(habitat->matris[z + n][c + m]->gorunum(), "P") == 0)
        {
            if (habitat->matris[z][x]->num < habitat->matris[z + n][c + m]->num)
                habitat->matris[z][x]->num = 0;
            else
                habitat->matris[x + n][c + m]->num = 0;
        }
    }
}

void Temizle(Habitat *habitat)
{
    for (int z = 0; z < habitat->satir; z++)
    {
        for (int x = 0; x < habitat->sutun; x++)
        {
            free(habitat->matris[z][x]);
        }
        free(habitat->matris[z]); 
    }
    free(habitat->matris);
}

void Kazanan(const Habitat* habitat)
{

    for (int z = 0; z < habitat->satir; z++)
    {
        for (int x = 0; x < habitat->sutun; x++)
        {
            if((habitat->matris[z][x]->num != 0))
            printf("Kazanan: %s : (%d,%d)",habitat->matris[z][x]->gorunum(),z,x);
        }
    }
}
