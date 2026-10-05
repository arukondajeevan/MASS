#include<stdio.h>
#include<string.h>
void main(){
int j,l,m,c,k;
char a[100],b[100];
printf("Enter the string: ");
fgets(a,sizeof(a),stdin);
a[strcspn(a,"\n")]='\0';
printf(" \n Sender side Stuffed frame:");
strcpy(b,"| DLESTX | ");
m=strlen(a);
for(j=0;j<m;){
if(a[j]=='d'){
if(a[j+1]=='l'){
if(a[j+2]=='e'){
c=j+2;
for(l=0;l<3;l++){
for(k=m;k>c;k--){
a[k]=a[k-1];
}
m++;
a[m]='\0';
c+=1;
}
a[j+3]='d';
a[j+4]='l';
a[j+5]='e';
a[m]='\0';
j+=5;
}
}
}
j++;
}
strcat(b,a);
strcat(b," | DLEETX |");
printf("\n%s",b);
printf("\n Receiver side destuffed frame: ");
m=strlen(a);
for(j=0;j<m;){
if(a[j]=='d'){
if(a[j+1]=='l'){
if(a[j+2]=='e'){
c=j;
for(l=0;l<3;l++){
for(k=c;k<m;k++)
a[k]=a[k+1];
}
c++;
}
j=c;
}
}
j++;
}
printf("\n%s",a);
}
