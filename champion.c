#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "champion.h"

//createChampion
Champion* createChampion()
{
int num;
num = randGen(1,4);
Champion* a  = (Champion*) malloc (sizeof(Champion));
a->next = NULL;
switch(num){
case 1:
a->role = M; //Mage
a->level = randGen(5,8);
break;
case 2:
a->role = F; //Fighter
a->level = randGen(1,4);
break;
case 3:
a->role = S; //Support
a->level = randGen(3,6);
break;
case 4:
a->role = T; //Tank
a->level = randGen(1,8);
break;
}
return a;
}
//addChampion
Champion* addChampion(Champion* head,Champion* c)
{
Champion* temp = NULL;
Champion* prev = NULL;
Champion* cur = head;
//sorts and returns head
if(head == NULL){
return c;
}
if(c->level > head->level && prev == NULL){
temp = head;
head = c;
head->next = temp;
return head;
}

while(cur != NULL){
if(c->level > cur->level && prev != NULL){
prev->next = c;
c->next = cur;
return head;
}
prev = cur;
cur = cur->next;
}

if(cur == NULL){
prev->next = c;
}

return head;
}

//build champion list
Champion* buildChampionList(int n)
{
//Champion* a = NULL;
Champion* head = NULL;
Champion* cur = NULL;
int i;
for(i=0;i<n;i++){
cur = createChampion();
head = addChampion(head,cur);
//a=head;
}
return head;
}

//printChamprionList
void printChampionList(Champion* head)
{
char role;
Champion* temp;
temp = head;

while(temp != NULL){
switch(1+temp->role){
case 1:
role = 'M';
break;
case 2:
role = 'F';
break;
case 3:
role = 'S';
break;
case 4:
role = 'T';
break;
}
printf("%c%d ",role,temp->level);
temp = temp->next;
}
}
//removeChampion
Champion* removeChampion(Champion* head)
{
if(head == NULL){
return NULL;
}
Champion* a = head;
head = head->next;
free(a);
return head;
}
//destroyChampion
Champion* destroyChampionList(Champion* head)
{
Champion* temp = head;
while(head != NULL){
temp = head;
head = head->next;
free(temp);
}
return NULL;
}
//Generates random number
int randGen(int min,int max){

    int num  = min + rand() % (max + 1 - min);
    return num;
}

