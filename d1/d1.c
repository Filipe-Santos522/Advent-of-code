#include <stdio.h>
#include <stdlib.h>


int main(){
    int dataset[2000];
    int j=0;
    FILE *fpointer= fopen("dataset.txt", "r");

    fscanf (fpointer, "%d", &dataset[j]);
    j++;   
    while (!feof (fpointer))
    {  
      fscanf (fpointer, "%d", &dataset[j]);
      j++;
    }
    
    for(int i=0;i<1998; i++)
        dataset[i]+=dataset[i+1]+dataset[i+2];

    int answer=0;
    for(int i=1; i<1998; i++){
        if(dataset[i]>dataset[i-1])
            answer++;
    }
    printf("%d", answer);
    return 0;
}