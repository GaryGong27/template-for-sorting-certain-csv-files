#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define buf 3000
int comparator(const void *p, const void *q);

typedef struct{ char *name;
                char *country;
                float population;
    }city;

int main()
{
    int i = 0;
    FILE *fp = fopen("cities.csv","r");
      int count = 0;
    char c;
    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        if (c == '\n')
            count = count + 1;
    }

    int size = count-1;
    city* (p[size]);
    for(i = 0;i<count;i++)/*initializing pointer*/
    {
        p[i] = (city*)malloc(sizeof(city));
    }
    fclose(fp);

    FILE *stream = fopen("cities.csv","r");
    char *token;
    int j;
    int k = 0;
    int counter = 0;
    char line[buf];
    while (fgets(line, buf, stream))
    {   if(counter == 0)
        {
            counter++;
            continue;
        }

        char* tmp = malloc(strlen(line)+1);
        strcpy(tmp,line);

        for(token = strtok(tmp,","),j = 0;j<6;token = strtok(NULL,","))
        {   j++;
            if(j == 1)
                p[k]->name = token;
            if(j == 5)
            {
                float temp = atof(token);
                p[k]->population = temp;
            }
            if(j == 6)
                p[k]->country = token;

        }
        k++;

    }

      qsort((city*)p,size,sizeof(city*),comparator);



    FILE *result = fopen("sorted.csv","w");
    fprintf(result,"city,population,country\n");
    int u;
    for( u = 0;u<size;u++)
        fprintf(result,"%s,%f,%s\n",p[u]->name,p[u]->population,p[u]->country);


    return 0;
}

int comparator(const void *p, const void *q)
{
    const city* ca = *(city**)p;
    const city* cb = *(city**)q;
    if(ca->population < cb->population)
        return 1;
    if(ca->population > cb->population)
        return -1;
    else
        return 0;
}
