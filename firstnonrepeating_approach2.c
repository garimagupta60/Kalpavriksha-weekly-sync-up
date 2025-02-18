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
    for(int i=0; i<26; i++){
        hashmap[i].count = 0;
    }
}

int hash(char character){
    int index = character-'a';
    return index;
}

int main(){
    char string[maxsize];
    scanf("%[^\n]%*c",string);
    createmap();
    for(int i=0; i<strlen(string); i++){
        int index = hash(string[i]);
        if(hashmap[index].count == 0){
            hashmap[index].character = string[i];
            hashmap[index].count = 1;
        }else{
            hashmap[index].count++;
        }

        int found = 0;
        for(int i=0; i<26; i++){
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