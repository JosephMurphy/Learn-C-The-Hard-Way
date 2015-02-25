#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//define the person structure
struct Person {
	//setting all of the attributes that the person structure will have
	char *name;
	int age;
	int height;
	int weight;
};

//function to create a person using the person structure
struct Person *Person_create(char *name, int age, int height, int weight)
{
	//creating the who pointer, of type person structure defined above. Use malloc to allocate memory to be used by the structure
	struct Person *who = malloc(sizeof(struct Person));
	//making sure that the memory allocated to the structure is not invalid
	assert(who != NULL);
	
	//initialize each attribute of the person. strdup duplicates the string to the structure
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	//return the person once all attributes have been assigned
	return who;
}
//function to free up memory that was allocated to the person structure
void Person_destroy(struct Person *who)
{
	//double check to make sure this is valid data
	assert(who != NULL);
	//first, free up the memory used by strdup. Then the person structure
	free(who->name);
	free(who);
}
//function to print the attributes of a person
void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	//make two people structures
	struct Person *joe = Person_create(
		"Joe Alex", 32, 64, 140);

	struct Person *frank = Person_create(
		"Frank Blank", 20, 72, 180);

	//print them out and where they are in memory
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);
	
	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	//make everyone age 20 years and print them again
	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	//destroy them both
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}
