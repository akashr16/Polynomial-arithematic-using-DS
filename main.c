#include <stdio.h>
#include <stdlib.h>
struct node{
    float coeff;
    int expo;
    struct node* link;
};


struct node* insert(struct node* head,float co,int ex)
{
  struct node* temp;
  struct node* newp = malloc(sizeof(struct node));
  newp ->coeff = co;
  newp -> expo = ex;
  newp -> link = NULL;

  if (head == NULL || ex > head->expo)
  {
    newp->link = head;
    head =newp;
  }
  else
  {
        temp = head;
        while(temp->link != NULL && temp->link->expo >= ex)
            temp = temp->link;
        newp->link=temp->link;
        temp->link = newp;
  }
  return head;
}
struct node* create (struct node* head)
{
  int n,i;
  float coeff;
  int expo;

  printf("enter the number of terms: ");
  scanf("%d",&n);

  for(i=0; i<n; i++)
  {
      printf("enter the  coefficient of term %d: ",i+1);
      scanf("%f",&coeff);

      printf("enter the exponent of the term %d:",i+1);
      scanf("%d",&expo);

      head = insert(head,coeff,expo);
  }
  return head;

}
void print(struct node* head)
{
    if( head == NULL)
        printf(" polynomial contains zero nodes");
    else
    {
        struct node* temp = head;
        while(temp != NULL)
        {
            printf("(%.1fx^%d)", temp->coeff , temp->expo);
            temp = temp->link;
            if(temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}

int main()
{
   struct node* head = NULL;
   printf("enter the polynomial\n  ");
   head = create(head);
   print(head);
   return 0;
}
