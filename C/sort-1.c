/*
 *  sort.c
 *  
 *
 *  Created by Sunip Mukherjee on 22/04/15.
 *  Copyright 2015 __MyCompanyName__. All rights reserved.
 *
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student 
{
	char name[255];
	float marks;
};                     //always give ';' after structure declaration
int compare (const void * a, const void * b)   // It is the most famous technique to sort a structure, not necessary to understand it completely but don't forget to use it..
{
	struct student p=*((struct student *)a);    // you have used selection sort which takes O(n*n) but it is quicksort which takes O(nlog n) that is better than selection sort.. 
	struct student q=*((struct student *)b);
	if(p.marks>q.marks)
		return -1;
	else if(p.marks==q.marks)
		return 0;
	else
		return 1;
}
main()
{
	int i,j,n;
	float b;
	struct student list[50];
	printf("Enter the number of students:\n");
	scanf("%d",&n);
	printf("Enter the data:\n");
	i=0;
	char data[255];
	size_t len=0;
	ssize_t read;
	read=0;
	while (i<n)
	{
		printf("Name:\n");
		getchar();          // it is needed to use getchar() before gets if it is used in a loop
		gets(data);        // I never use getline... gets() works fine
		strcpy(list[i].name,data);
		printf("Marks:\n");
		scanf("%f",&b);      //never insert space before %f or %d... we need to insert space before %c if it is in a loop.
		list[i].marks=b;
		i=i+1;		
	}	
	//free (data);
	/*i=1;
	do   
	{
		j=i;
		do
		{
			if(list[j].marks > list[j-1].marks)
			{
				struct student a=list[j];
				list[j]=list[j-1];
				list[j-1]=a;
			}
			j=j-1;
		}while(j>0);
		i=i+1;
	}while(i<=n);*/
	qsort(list,n,sizeof(struct student),compare);
	printf("The sorted list is:\n");
	i=0;            // I think it is better to use 'for' loop or general 'while' loop than 'do-while' loop
	do
	{
		printf("%s	%f\n",list[i].name,list[i].marks);
		i=i+1;
	}while(i<n);
}
