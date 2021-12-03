#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define Size 20 
  
int Top=-1;
char inp_array[Size];
void Push(char );
void Pop();
void show();
struct production{
  char NT;
  char rhs[10];
  char str[10];
  int len;

}pro[100];
int over=0;
int no_pro;
int empty(){
  return Top==-1;
  
}
char top()
{
   
        return inp_array[Top];
        
    
}
void reduce(int idx,char ch){
  int x=Top;
  while(x>=idx){
    Pop();
    x--;
  }

  Push(ch);
  //show();
}
/*
int same(char s[10],char y[10]){
  int l=strlen(y);
  char x[100];
  int k=0;
  for(int i=l-1;i>=0;i--){
    x[k++]=y[i];
  }
  x[k++]='\0';
  printf("%s\n",x);
  if(strcmp(x,s)==0){
    return 1;
  }
  return 0;

}*/

int  canreduce(){
  int idx=Top;
  char temp[100];
  int k=0;
  int flg=0;
  while(idx>=0){
    int x=k+1;

    while(x>=0){
      temp[x+1]=temp[x];
      x--;

    }
    temp[0]=inp_array[idx];
  
    temp[k+1]='\0';
   // printf("%s\n",temp);
   
    for(int i=0;i<no_pro;i++){
    // printf("%s tmp  %s\n",temp ,pro[i].rhs);
    
     

      if(strcmp(pro[i].rhs,temp)==0){
        if(over){show();printf("\t\t\t\t");}
        printf("\t\t\treduce %c-->\t %s \n",pro[i].NT,pro[i].rhs);
        reduce(idx,pro[i].NT);
         flg=1;
      }//if
    }//for



    k++;

    idx--;

  }
  return flg==1;
}
void readFromFile() {
    FILE* fptr;
    fptr = fopen("text.txt", "r");
    char buffer[10];
    int i;
    int j;
    while (fgets(buffer, sizeof(buffer), fptr)) {
      
        pro[no_pro].NT=buffer[0];
        int N=strlen(buffer);
        int k=0;
        for( i=0;buffer[i]!='\0';i++){
          

        pro[no_pro].str[i]=buffer[i];
       
       if(i>=2){
         pro[no_pro].rhs[k]=buffer[i];
         k++;
       }
        }// for 
       pro[no_pro].str[--i]='\0';
       pro[no_pro].rhs[--k]='\0';
       

        pro[no_pro].len =strlen(buffer) ;
       // printf("%s %d\n",pro[no_pro].rhs,(int)strlen(pro[no_pro].rhs));
        ++no_pro;
       
    }
    
}
int main()
{
 readFromFile() ;
 char str[100];

 scanf("%s",str);
 int i=0;
 int n=strlen(str);

 while(i<n){
   show();
   printf("\t\t\t");
   char ch=str[i];
   printf("%s\t\t\t",str+i);
   if(empty()){
    // Push('$');


   }
  
   if(canreduce()){
     //show();

   }else{
     
     printf("\t\t\tShift %c\n",ch);

     Push(ch);
     i++;
     //show();
   }

   


 }
 over=1;
 int count=4;
 while(count>0){
if(canreduce()){

}
count--;
 }
if(top()=='E' && Top==0){
  printf("Accpet\n");
}else{
  show();printf("\n");
  printf("Rejected \n");
}


 
    
}
  
void Push(char x)
{
   // char x;
     
    if(Top==Size-1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        //printf("\nEnter element to be inserted to the stack:");
        //scanf("%c",&x);
        Top=Top+1;
        inp_array[Top]=x;
    }
}
  
void Pop()
{
    if(Top==-1)
    {
        //printf("\nUnderflow!!");
    }
    else
    {
     //  printf("\nPopped element:  %c",inp_array[Top]);
        Top=Top-1;
    }
}


void show()
{
     
     
    if(Top==-1)
    {
        printf("\n $ ");
    }
    else
    {
        //printf("\nElements present in the stack: \n");
        printf("$");
        for(int i=0;i<=Top;i++)
            printf("%c ",inp_array[i]);
    }
   // printf("\n");
}
