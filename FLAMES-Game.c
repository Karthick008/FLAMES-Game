#include <stdio.h>
#include<stdlib.h>
struct Node{
  char c;
  struct Node* next;
};
struct Node* head=NULL;
struct Node* tail=NULL;

void insert(char);
char delete(struct Node*, int);
void lower(char arr[]);

int main(){
  int count=0, i, j = 0;
  insert('f'); //inserting "flames" for crossing X
  insert('l');
  insert('a');
  insert('m');
  insert('e');
  insert('s');
  char you[30]; char crush[20]; 
   char arr[26]={0}; //for hashing
  printf("Enter Your Name: ");
  scanf("%[^\n]s",you);
  printf("Enter Your Crush Name: ");
  scanf("\n%[^\n]s",crush);
  lower(you); lower(crush);
  for(i=0;you[i]!='\0';i++){
    arr[you[i]-97] +=1;  //storing the count of letter in hash
  } 
  for(i=0;crush[i]!='\0';i++){
    if(arr[crush[i]-97] != 0) //is value > 0 means already present 
       arr[crush[i]-97] -=1; //removing same letters in both, by decreasing hash count
    else if(crush[i] >= 97 && crush[i] <= 122)
       j++; //new letter present in Crush name
  }
  for(i=0; i<26; i++){
   count += arr[i]; //counting the total characters left in Your name
  }
  count = count+j; //summing up letter remaining in Crush name
  switch(delete(head,count)){ //calling delete by providing count 
    case 'f':
       printf("\n ?? Friends ??");
       break;
    case 'l':
       printf ("\n ?? Love ??");
       break;
    case 'a':
       printf("\n?? Affection ??");
       break;
    case 'm':
       printf("\n?? Marriage ??");
       break;
    case 'e':
       printf("\n?? Enemy ??");
       break;
    case 's':
       printf("\n ?? Bro/Sis ??");
       break;
    }
}

void lower(char arr[]){
  for(int i = 0; arr[i] != '\0'; i++){
    if(arr[i] >= 65 && arr[i] <= 90) 
     arr[i] = arr[i]+32; 
  }
}
void insert(char data){ //for creating circular linked list
   struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
   temp->c=data; temp->next=NULL;
  if(head==NULL){
    head = temp;
    tail= temp;
  }
  else{
    tail->next = temp;
    tail=temp;
    tail->next = head;
  }
}

char delete(struct Node* root,int count){  //this works on circular list with recursion
  int i=2;
  struct Node* temp=root;
  if(head==tail) return head->c; //when last one chrtr remains
  while(i++ < count){ //iterating to n-1 th node
    temp=temp->next;
  }
  if(count==1){ //removing current chrtr
   head=head->next;
   tail->next = head;
  }
  else if(temp->next == head){ //if its true means, current node to be deleted is head
    temp=head;
    tail->next=head->next;
    head=tail->next;
  }
  else if(temp->next==tail){ //node to be deleted is tail 
   tail=temp;
   tail->next = head;
   temp=tail;
  }
  else{ //deleting nodes in-between
   temp->next = temp->next->next;
  }
  return delete(temp->next,count); //calling by giving next node address, due to flames concept with count
}

