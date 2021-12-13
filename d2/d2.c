#include <stdio.h>
#include <stdlib.h>

int main(){
    int pos_x=0;
    int pos_y=0;
    int aim=0;
    int dataset[2000];
    int j=0;
    char str[20];
    FILE *fpointer= fopen("dataset.txt", "r");

    fscanf(fpointer, "%s", str);
    fscanf(fpointer, "%d", &j);

    if(str[2]=='\0'){
      aim-=j;
    }else if(str[4]=='\0'){
      aim+=j;
    }else{
      pos_x+=j;
      pos_y+=(aim*j);
    }
    while (!feof (fpointer))
    {  
      fscanf(fpointer, "%s", str);
      fscanf(fpointer, "%d", &j);
      if(str[2]=='\0'){
        aim=aim-j;
      }else if(str[4]=='\0'){
        aim+=j;
      }else{
        pos_x+=j;
        pos_y+=(aim*j);
      }
    }
    int answer=pos_y*pos_x;

    printf("%d\n", answer);
    fclose(fpointer);
    return 0;
}