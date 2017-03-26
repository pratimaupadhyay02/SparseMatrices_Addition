#include<stdio.h>
#include<stdlib.h>


typedef struct linkedlist
{	int data;
	int row,col;
	struct linkedlist *add;
}
node;

void TRAVERSE(node **header);
void create(node **header);
int size;
void createadd(node **header,int row,int col,int val);
void add(node **header1,node **header2);

int main()
{	int n,data,val,item;
	node *head1=NULL;
	node *head2=NULL;
	node *head3=NULL;
	
	int r1,c1,r2,c2;
	while(1)
	{	printf("Press 1 to create list 1\n");
		printf("Press 2 to traverse list\n");
		printf("Press 3 to create list 2\n");
		printf("Press 4 to traverse list 3\n");
		printf("Press 5 to add two matrixes\n");
		//printf("Press 6 to display the added matrices\n");
		
		scanf("%d",&n);
	
	switch(n)
	{	case 1:create(&head1);
		break;
		case 2:
			
			TRAVERSE(&head1);
		break;
		case 3:create(&head2);
		break;
		case 4:TRAVERSE(&head2);
		break;
		case 5:add(&head1,&head2);
		break;
		//case 6:display(&head3);
			
	}}
return 0;
}


void create(node **header)
{	int i,n,data,row,col;
	node *temp,*p;
	printf("Enter the number of nodes you want\n");
	scanf("%d",&n);
	printf("Enter the size of matrices\n");
	scanf("%d",&size);
	
	temp=*header;
	if(temp==NULL)

	{	printf("Enter the value you want to assign to first node followed by row number and column number\n");
		scanf("%d",&data);
		scanf("%d",&row);
		scanf("%d",&col);	
		temp=(node*)malloc(sizeof(node));
		temp->data=data;
		temp->row=row;
		temp->col=col;
		temp->add=NULL;//assigned null i.e its the last node
		*header=temp;
	}
	
	for(i=2;i<=n;i++)
	{	printf("Enter the value to be inserted to the %d node followed by row number and column number:\t",i);
		scanf("%d",&data);
		scanf("%d",&row);
		scanf("%d",&col);
		
		temp=(node*)malloc(sizeof(node));
		temp->data=data;
		temp->row=row;
		temp->col=col;
		p=*header;
		while(p->add!=NULL)
		p=p->add;
		temp->add=NULL;		
		p->add=temp;//change null to the address of the new node		
		
	}
}	
void TRAVERSE(node **header)
{	node *temp;
	temp=*header;
	int i,j;
	if(temp==NULL)
	{	printf("The list is empty\n");
		return;
	}
	for(i=0;i<size;i++)
	{	for(j=0;j<size;j++)
		{	
		
			
			{	
				{	if(((temp->row)==i)&&((temp->col)==j))
					{	
						printf("%d\t",temp->data);
						temp= temp->add;
					}
					else
					printf("0\t");
					
				}
			}
		}
		printf("\n");
	}
}
			




void add(node **header1,node **header2)
{	
	node *head3=NULL;	
	node *temp1=*header1;
	node *temp2=*header2;
	node *p;
	int r3,c3;
	int r,c,v,r1,c1,v1;
	while(temp1!=NULL)
		{	if((temp1->row==temp2->row)&&(temp1->col==temp2->col))
			{	r=temp1->row;
				c=temp1->col;
				//printf("%d",c);
				v=temp1->data+temp2->data;
				createadd(&head3,r,c,v);
			
			}			
			else
			{	r=temp1->row;
				c=temp1->row;
				v=temp1->data;
				//printf("\n%dthe row of first",r);
				//printf("\n%dthe col of first",c);
				//printf("\n%dval",v);
				r1=temp2->row;
				c1=temp2->col;
				v1=temp2->data;
				//printf("\n%dsec",r1);
				//printf("\n%dsec",c1);
				//printf("\n%dval",v1);
				if(c1==c&&r>r1||r1==r&&c>c1)
				{	
					createadd(&head3,r,c,v);
					createadd(&head3,r1,c1,v1);
				} 
				else
				if(c1==c&&r1>r||r1==r&&c1>c)
				{	createadd(&head3,r1,c1,v1);
					createadd(&head3,r,c,v);
				}
				
				
			}
	
			temp1=temp1->add;
			temp2=temp2->add;
			
		}
	
	display(&head3);
	
	


}






void createadd(node **header,int row,int col,int val)
{		node *temp,*p,*q;
		int i,j;
	
	
	temp=*header;
	if(temp==NULL)

	{	
		temp=(node*)malloc(sizeof(node));
		temp->data=val;
		temp->row=row;
		temp->row=col;
		temp->add=NULL;//assigned null i.e its the last node
		*header=temp;
		//printf("%dhere\n",temp->data);
	}
	
		
		temp=(node*)malloc(sizeof(node));
		temp->data=val;
		temp->row=row;
		temp->col=col;
		p=*header;
		while(p->add!=NULL)
		{	p=p->add;
			//printf("%d",temp->data);
		}
		p->add=temp;//change null to the address of the new node
		temp->add=NULL;
		

	
		
		

	
}	

void display(node **header)
{	node *temp;
	temp=*header;
	int i,j;
	if(temp==NULL)
	{	printf("The list is empty\n");
		return;
	}
	for(i=0;i<size;i++)
	{	for(j=0;j<size;j++)
		{	
		
			
				//printf("%d %d  ",i,j);
					if(((temp->row)==i)&&((temp->col)==j))
					{	
						printf("%d\t",temp->data);
						temp= temp->add;
					}
					 
					else
					printf("0\t");
					
				
			
		}
		printf("\n");
	}
}
