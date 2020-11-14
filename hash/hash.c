#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define table 10007
#define szie 5000
typedef struct {
	int id;
	char name[20];
}student;
init(student** hashtable)
{
	for (int i = 0; i < table; i++)
	{
		hashtable[i] = NULL;
	}
}
destructor(student** hashtable)
{
	for (int i = 0; i < table; i++)
	{
		if (hashtable[i] != NULL)
		{
			free(hashtable[i]);
		}
	}
}
int findempty(student** hashtable, int id)
{
	int i = id % table;
	while (1)
	{
		if (hashtable[i % table] == NULL)
			return i % table;
		i++;
	}
}
int search(student** hashtable, int id)
{
	int i = id % table;
	while (1)
	{
		if (hashtable[i % table] == NULL)
			return -1;
		else if (hashtable[i % table]->id != NULL) return i;
		i++;
	}
}
add(student** hashtable, student* input, int key)
{
	hashtable[key] = input;
}
student* getvalue(student** hashtable, int key)
{
	return hashtable[key];
}
show(student** hashtable)
{
	for (int i = 0; i < table; i++)
	{
		if (hashtable[i] != NULL)
		{
			printf("key:[%d] man:[%s]\n", i, hashtable[i]->name);
		}
	}
}
main()
{
	student** hashtable;
	hashtable = malloc(sizeof(student*) * table);
	init(hashtable);

	for (int i = 0; i < table; i++)
	{
		student* Student = malloc(sizeof(student));
		Student->id = rand() % 100000;
		sprintf(Student->name, "man%d", Student->id);
		if (search(hashtable, Student->id) == -1)
		{
			int index = findempty(hashtable, Student->id);
			add(hashtable, Student, index);
		}
	}
	show(hashtable);
	destructor(hashtable);
}
