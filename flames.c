#include <stdio.h>
#include <string.h>
int check_count(char *str){
    int count=0;
    for(int i=0;i<strlen(str);i++){
        if(str[i]!=' '){
            count++;
        }
    }
    return count;
}

void remove_char(char *str, int index){
    int len=strlen(str);
    for(int i=index;i<len;i++){
        str[i]=str[i+1];
    }
    str[len]='\0';
} 

int calc_index(int total,int len,int offset){
    if(offset==0){
        int index=(total)%len;
        if(index==0){
            return len-1;
        }
        return index-1;
    }
    else{
        int index=(total+offset)%len;
        if(index==0){
            return len-1;
        }
        return index-1;
    }
}
int main(){
    char name1[20];
    char name2[20];

    printf("Enter your name: ");
    fgets(name1,20,stdin);
    printf("%s",name1);

    printf("Enter (you know who)'s name: ");
    fgets(name2,20,stdin);
    printf("%s",name2);

    for(int i=0;i<strlen(name1)-1;i++){
        for(int j=0;j<strlen(name2)-1;j++){
            if(name1[i]==name2[j]){
                name1[i]=' ';
                name2[j]=' ';
            }
        }
    }
    printf("%s",name1);
    printf("%s",name2);
    
    int name1_count=0;
    for(int i=0;i<strlen(name1)-1;i++){
        if(name1[i]!=' '){
            name1_count++;
        }
    }

    int name2_count=0;
    for(int i=0;i<strlen(name2)-1;i++){
        if(name2[i]!=' '){
            name2_count++;
        }
    }

    printf("1:%d\n",name1_count);
    printf("2:%d\n",name2_count);

    int total=name1_count+name2_count;
    printf("total:%d\n",total);

    char f[]="flames";
    int index=0;
    int offset=0;

    for(int i=1;i<=5;i++){
        index=calc_index(total,strlen(f),offset);
        remove_char(f,index);
        offset=index;
    }
    
    printf("The result is %s",f);
}