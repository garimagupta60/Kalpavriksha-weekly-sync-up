#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 100000
typedef struct map{
    char character;
    int count;
}map;

map* hashmap;
int mapsize = 0;

void createmap(){
    hashmap = (map*)malloc(26*sizeof(map));
}

int findinmap(char character){
    for(int i=0; i<mapsize; i++){
        if(hashmap[i].character == character)return i;
    }
    return -1;
}

int main(){
    char string[maxsize];
    scanf("%[^\n]%*c",string);
    createmap();
    for(int i=0; i<strlen(string); i++){
        int index = findinmap(string[i]);
        if(index==-1){
            hashmap[mapsize].character = string[i];
            hashmap[mapsize].count = 1;
            mapsize++;
        }else{
            hashmap[index].count++;
        }

        int found = 0;
        for(int i=0; i<mapsize; i++){
            if(hashmap[i].count == 1){
                printf("%c",hashmap[i].character);
                found = 1;
                break;
            }
        }
        if(found == 0)printf("-1");
    }
    return 0;

}