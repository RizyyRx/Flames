#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 20

//returns count of a string after avoiding ' ' charcters
int check_count(char *str){
    int count=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]!=' '){
            count++;
        }
    }
    return count;
}

//removes a specific character in a string by giving an index value
void remove_char(char *str, int index){
    int len=strlen(str);
    for(int i=index;i<len;i++){
        str[i]=str[i+1];
    }
    str[len-1]='\0';
} 

//does an index calculation for removing characters each time by the rules the FLAMES game
int calc_index(int total,int len,int offset){
    //executes only the first time where there is no offset value
    if(offset==0){
        int index=(total)%len;
        if(index==0){
            return len-1;
        }
        return index-1;
    }
    //does the calculation using the offset value
    else{
        int index=(total+offset)%len;
        if(index==0){
            return len-1;
        }
        return index-1;
    }
}

//removes the '\n' that is appended when fgets is used to get user input 
void remove_newline(char *str) {
    size_t len = strlen(str);//using size_t is better than int to store length 
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main(){
    char name1[MAX_NAME_LENGTH];
    char name2[MAX_NAME_LENGTH];

    printf("Enter your name: ");
    fgets(name1,MAX_NAME_LENGTH,stdin);
    remove_newline(name1);
    

    printf("Enter (you know who)'s name : ");
    fgets(name2,MAX_NAME_LENGTH,stdin);
    remove_newline(name2);

    char n1[MAX_NAME_LENGTH];
    strcpy(n1,name1);
    char n2[MAX_NAME_LENGTH];
    strcpy(n2,name2);

    for(int i=0;i<strlen(name1)-1;i++){
        for(int j=0;j<strlen(name2)-1;j++){
            if(name1[i]==name2[j]){
                name1[i]=' ';
                name2[j]=' ';
            }
        }
    }
    // printf("%s\n",name1);
    // printf("%s\n",name2);
    
    int name1_count=check_count(name1);
    int name2_count=check_count(name2);

    // printf("name 1 count:%d\n",name1_count);
    // printf("name 2 count:%d\n",name2_count);

    int total=name1_count+name2_count;
    // printf("total:%d\n",total);

    char f[]="flames";
    int index=0;
    int offset=0;

    while(strlen(f)>1){
        index=calc_index(total,strlen(f),offset);
        remove_char(f,index);
        offset=index;
    }
    char result=f[0];
    // printf("The result is %c\n",result);

    if(result=='f'){
        printf("%s and %s are Friends ;)\n",n1,n2);
    }
    else if(result=='l'){
        printf("%s and %s are Lovers <3\n",n1,n2);
    }
    else if(result=='a'){
        printf("%s is Affectionate towards %s UwU\n",n1,n2);
    }
    else if(result=='m'){
        printf("%s and %s will get Married!!! (poggers)\n",n1,n2);
    }
    else if(result=='e'){
        printf("%s and %s are born Enemies (sadge)\n",n1,n2);
    }
    else if(result=='s'){
        printf("%s and %s are Brothers and Sisters (sus)\n",n1,n2);
    }


}