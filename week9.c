#include<stdio.h>
#include<string.h>
#define MAX_FRAMES 100
#define DATA_SIZE 50
typedef struct{
int seq_no;
char data[DATA_SIZE];
}Frame;
void sortFrames(Frame buffer[],int n){
int i,j;
Frame temp;
for(i=0;i<n-1;i++){
for(j=0;j<n-i-1;j++){
if(buffer[j].seq_no>buffer[j+1].seq_no){
temp=buffer[j];
buffer[j]=buffer[j+1];
buffer[j+1]=temp;
}
}
}
}
int main(){
Frame buffer[MAX_FRAMES];
int n,i;
printf("Enter the number of frames to be received: ");
if(scanf("%d",&n)!=1||n<=0||n>MAX_FRAMES){
printf("Invalid number of frames.\n");
return 1;
}
printf("\n--- Enter Frame Details (Simulating Out-of-Order Arrival) ---\n");
for(i=0;i<n;i++){
printf("Enter Sequence Number for Frame %d: ",i+1);
scanf("%d",&buffer[i].seq_no);
printf("Enter Data for Frame (Seq %d): ",buffer[i].seq_no);
scanf("%s",buffer[i].data);
}
printf("\n>>> Buffer Status (Unsorted Frames Received):\n");
printf("-----------------------------------------\n");
printf("Sequence No.\tData\n");
printf("-----------------------------------------\n");
for(i=0;i<n;i++){
printf("%d\t\t%s\n",buffer[i].seq_no,buffer[i].data);
}
sortFrames(buffer,n);
printf("\n>>> Buffer Status (Sorted Frames):\n");
printf("-----------------------------------------\n");
printf("Sequence No.\tData\n");
printf("-----------------------------------------\n");
for(i=0;i<n;i++){
printf("%d\t\t%s\n",buffer[i].seq_no,buffer[i].data);
}
printf("\n>>> Reassembled Message: ");
for(i=0;i<n;i++){
printf("%s",buffer[i].data);
}
printf("\n\n");
return 0;
}
