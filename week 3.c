#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int *frames;
bool *ack;
bool *loss_flag;
int total_frames;
int window_size;
bool is_lost(int frame_num){
if(frame_num>=2&&loss_flag[frame_num]){
loss_flag[frame_num]=true;
return true;
}
return false;
}
void send_frames(int start){
printf("Sending frames %d to %d\n",start,start+window_size-1);
for(int i=start;i<start+window_size&&i<total_frames;i++){
printf("Sent frame %d\n",frames[i]);
}
}
void receive_frames(int start){
for(int i=start;i<start+window_size&&i<total_frames;i++){
if(!ack[i]){
if(is_lost(frames[i])){
printf("Frame %d lost! Go-Back-N Triggered\n",frames[i]);
return;
}else{
printf("Frame %d received\n",frames[i]);
ack[i]=true;
}
}
}
}
int main(){
printf("Enter total frames: ");
scanf("%d",&total_frames);
printf("Enter window size: ");
scanf("%d",&window_size);
frames=(int *)malloc(sizeof(int)*total_frames);
ack=(bool *)malloc(sizeof(bool)*total_frames);
loss_flag=(bool *)malloc(sizeof(bool)*total_frames);
for(int i=0;i<total_frames;i++){
frames[i]=i;
ack[i]=false;
loss_flag[i]=false;
}
int base=0;
while(base<total_frames){
send_frames(base);
receive_frames(base);
if(!ack[base]){
printf("Retrying from frame %d...\n",base);
continue;
}
while(ack[base]&&base<total_frames)
base++;
}
printf("\nTransmission completed successfully!\n");
free(frames);
free(ack);
free(loss_flag);
return 0;
}
