#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    FILE *fpointer= fopen("dataset.bin", "r");
    char ch[12];
    int total[12];
    int delta=0;
    int gama=0;
    for(int i=0; i<12; i++){
            total[i]=0;
    }

    fscanf(fpointer, "%s",ch);

    for(int i=0; i<12; i++){
        if(ch[i]=='1')
            total[i]++;
    }
    while (!feof (fpointer))
    {
        fscanf(fpointer, "%s",ch);
        for(int i=0; i<12; i++){
            if(ch[i]=='1')
                total[i]++;
        }
    }
    int x= pow(2,(12));
    printf("X:%d\n",x);
    for(int i=0; i<12; i++){
        if(total[i]>500){
            gama+=pow(2,(11-i));
        }else{
            delta+=pow(2,(11-i));
        }
    }

    for(int i=0; i<12; i++){
        printf("%d\n", total[i]);
    }
    printf("Delta:%d\n",delta);
    printf("Gama:%d\n",gama);
    printf("Result:%d\n",delta*gama);

    fclose(fpointer);
    return 0;
}