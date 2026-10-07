#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct student
{
	int roll;
	char name[20];
	float marks;
	struct student *next;
}sll;
void add_begin(sll **);
void print_node(sll *);
int count_node(sll *);
void add_end(sll **);
void save_file(sll *);
void read_file(sll **);
void add_middle(sll **);
void print_rec(sll *);
void reverse_rec(sll *);
void delete_all(sll **);
void delete_node(sll **);
void sort_data(sll *);
void reverse_print(sll *);
void reverse_link(sll **);
void search_node(sll *);
int main(){
	sll *headptr=0;
	int c=0,op;
	while(1)
	{
		printf("\033[31m enter your choice my dear !\033[0m\n");
		printf("\033[32m1.add_begin 2.add_end 3.add_middle 4.print_node\n5.count_node 6.save_file 7.read_file 8.reverse_print\n9.print_rec 10.reverse_rec 11.delete_all 12.delete_node\n13.search_node 14.sort_data 15.reverse_link 16.exit\033[0m\n");
		scanf("%d",&op);
		switch(op){
			case 1:add_begin(&headptr);break;
			case 2:add_end(&headptr);break;
			case 3:add_middle(&headptr);break;			
			case 4:print_node(headptr);break;
			case 5:c=count_node(headptr);
			       printf("%d\n",c);break;
			case 6:save_file(headptr);break;
			case 7:read_file(&headptr);break;
			case 8:reverse_print(headptr);break;			
			case 9:print_rec(headptr);break;
			case 10:reverse_rec(headptr);break;
			case 11:delete_all(&headptr);break;		
			case 12:delete_node(&headptr);break;			
			case 13:search_node(headptr);break;			
			case 14:sort_data(headptr);break;			
			case 15:reverse_link(&headptr);break;		
			case 16:exit(0);
		}
	}
}
//------------search node----------------
void search_node(sll *ptr)
{
	if(ptr==0)
	{
		printf("\033[31mno records found\033[0m\n");
		return;
	}
	int f=0;
	char name[20];
	printf("enter name to search:\n");
	scanf("%s",name);
	while(ptr)
	{
		if(strcmp(name,ptr->name)==0)
		{
			f=1;
			printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
		}
		ptr=ptr->next;
	}
	if(f==0)
		printf("%s: not found\n",name);
}
//--------------reverse links-----------
void reverse_link(sll **ptr)
{
	sll **a,*t=*ptr;
	int c=count_node(*ptr),i;
	if(c>1)
	{
		a=malloc(sizeof(sll *)*c);
		for(i=0;i<c;i++)
		{
			a[i]=t;
			t=t->next;
		}
		for(i=c-1;i>0;i--)
			a[i]->next=a[i-1];

		a[0]->next=0;
		*ptr=a[c-1];
	}		
}
//----------delete node----------
void delete_node(sll **ptr)
{
	sll *prev,*del=*ptr;
	if(*ptr==0)
	{
		printf("no records found\n");
		return ;
	}
	char name[10];
	printf("enter name:\n");
	scanf("%s",name);
	while(del)
	{
		if(strcmp(name,del->name)==0)
		{
			if(del==*ptr)
				*ptr=del->next;
			else 
				prev->next=del->next;
			free(del);
			return;
		}
		prev=del;
		del=del->next;
	}
	printf("name is not found\n");
}
//----------reverse print----------
void reverse_print(sll *ptr)
{
	if(ptr==0)
	{
		printf("no records found\n");
		return;
	}
	sll *t=ptr;
	int i,j,c=count_node(ptr);
	for(i=0;i<c;i++)
	{
		t=ptr;
		for(j=0;j<c-1-i;j++)
			t=t->next;
		printf("%d %s %f\n",t->roll,t->name,t->marks);
	}
}
//----------sort data---------------
void sort_data(sll *ptr)
{
	if(ptr==0)
	{
		printf("no records found\n");
		return;
	}
	sll *p1=ptr,*p2,t;
	int i,j,c=count_node(ptr);
	for(i=0;i<c-1;i++)
	{
		p2=p1->next;
		for(j=0;j<c-1-i;j++)
		{
			if(p1->roll >p2->roll)
			{
				t.roll=p1->roll;
				strcpy(t.name,p1->name);
				t.marks=p1->marks;
				p1->roll=p2->roll;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;
				p2->roll=t.roll;
				strcpy(p2->name,t.name);
				p2->marks=t.marks;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
	printf("data sorted sucessfully\n");
}
//-----------------reverse recursion-----------
void reverse_rec(sll *ptr)
{
	if(ptr)
	{
		if(ptr->next!=0)
			reverse_rec(ptr->next);
		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
		return;
	}
	else
		printf("no records found\n");
}

//---------------print recursion--------
void print_rec(sll *ptr)
{
	if(ptr)
	{
		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
		if(ptr->next!=0)
			print_rec(ptr->next);
	}
	else
		printf("no records found\n");
}

//------------------add begin---------------
void add_begin(sll **ptr)
{
	sll *new;
	static int roll=1;
	new=malloc(sizeof(sll));
	printf("\033[33m enter name & marks:\n");
	new->roll=roll++;
	scanf("%s %f",new->name,&new->marks);
	new->next=*ptr;
	*ptr=new;
}
//-------------print nodes----------------------
void print_node(sll *ptr)
{
	if(ptr==0)
	{
		printf("\033[31m no records found\033[0m");
		return;
	}
	while(ptr)
	{
		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
}
//------------count nodes-----------------------
int count_node(sll *ptr)
{
	int c=0;
	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	return c;
}
//-----------add end-------------------------
void add_end(sll **ptr)
{
	sll *new,*last;
	new=malloc(sizeof(sll));
	printf("\033[33menter roll ,name & marks:\033[0m\n");
	scanf("%d %s %f",&new->roll,new->name,&new->marks);
	new->next=0;
	if(*ptr==0)
	{
		*ptr=new;	
	}
	else
	{
		last=*ptr;
		while(last->next)
			last=last->next;
		last->next=new;
	}
}
//-------------add middle------------------
void add_middle(sll **ptr)
{

	sll *new,*t=*ptr;
	int pos;
	printf("\033[33menter roll,name & marks:\033[0m\n");
	scanf("%d %s %f",&new->roll,new->name,&new->marks);
	printf("enter pos:");
	scanf("%d",&pos);
	int i;
	if(pos==1)
	{
		new->next=*ptr;
		*ptr=new;
		return;
	}

	for(i=0;i<pos-1;i++)
	{
		t=t->next;
	}
	new->next=t->next;
	t->next=new;

}
//------------save nodes into file-----------------
void save_file(sll *ptr)
{
	FILE *fp;
	fp=fopen("data","r+");
	if(ptr==0){
		printf("no students data\n");
		return;
	}
	else
	{
		while(ptr)
		{
			fprintf(fp,"%d %s %f\n",ptr->roll,ptr->name,ptr->marks);
			ptr=ptr->next;
		}
		printf("records are saved in file\n");
		fclose(fp);
	}
}
//----------------read nodes from file------------
void read_file(sll **ptr)
{
	sll *new,*last;
	FILE *fp;
	fp=fopen("data","r");
	if(fp==0)
	{
		printf("student database not present\n");
		return;
	}
	while(1)
	{
		new=malloc(sizeof(sll));
		if(fscanf(fp,"%d %s %f",&new->roll,new->name,&new->marks)==-1)
			break;

		new->next=0;
		if(*ptr==0)
			*ptr=new;
		else
		{
			last=*ptr;
			while(last->next)
				last=last->next;
			last->next=new;
		}
	}
}
//--------------delete all--------------
void delete_all(sll **ptr)
{
	sll *del=*ptr;
	while(del)
	{
		*ptr=del->next;
		free(del);
		sleep(1);
		del=*ptr;
	}
	printf("all nodes are deleted\n");
}