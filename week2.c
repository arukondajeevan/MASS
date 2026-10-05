#include<stdio.h>
void crc(int data[],int data_len,int gen[],int gen_len,int rem[]){
int temp[100];
int i,j;
for(i=0;i<data_len;i++)
temp[i]=data[i];
for(i=0;i<=data_len-gen_len;i++){
if(temp[i]==1){
for(j=0;j<gen_len;j++)
temp[i+j]=gen[j];
}
}
for(i=0;i<gen_len-1;i++)
rem[i]=temp[data_len-gen_len+1+i];
}
int main(){
int data[50],gen[20];
int temp[50],rem[20];
int codeword[50];
int data_len,gen_len;
int i,error=0;
printf("Enter number of data bits:");
scanf("%d",&data_len);
printf("\nEnter data bits:\n");
for(i=0;i<data_len;i++)
scanf("%1d",&data[i]);
printf("\nEnter number of generator bits:");
scanf("%d",&gen_len);
printf("\nEnter generator bits:\n");
for(i=0;i<gen_len;i++)
scanf("%1d",&gen[i]);
for(i=0;i<data_len;i++)
temp[i]=data[i];
for(i=data_len;i<data_len+gen_len-1;i++)
temp[i]=0;
crc(temp,data_len+gen_len-1,gen,gen_len,rem);
for(i=0;i<data_len;i++)
codeword[i]=data[i];
for(i=0;i<gen_len-1;i++)
codeword[data_len+i]=rem[i];
printf("\nCRC Remainder: ");
for(i=0;i<gen_len-1;i++)
printf("%d",rem[i]);
printf("\nTransmitted codeword: ");
for(i=0;i<data_len+gen_len-1;i++)
printf("%d",codeword[i]);
crc(codeword,data_len+gen_len-1,gen,gen_len,rem);
printf("\nReceiver Side Remainder: ");
for(i=0;i<gen_len-1;i++)
printf("%d",rem[i]);
for(i=0;i<gen_len-1;i++){
if(rem[i]!=0){
error=1;
break;
}
}
if(error)
printf("\nError detected in received frame\n");
else
printf("\nNo error detected frame received correctly.\n");
return 0;
}
