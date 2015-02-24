#include <stdio.h>

int main(int argc, char *argv[])
{
	//go through each string in argv
	int i = argc;
	while(i > 0){
		printf("arg %d: %s\n", i, argv[i]);
		i--;
	}

	//let's make our own array of strings
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};

	int num_states = 4;
	i = 0; // watch for this
	while(i < num_states){
		printf("state %d: %s\n", i, states[i]);
		i++;
	}

	//copy argv into states
	i = 0;
	while(i < argc){
		states[i] = argv[i];
		printf("The new state is: %s\n", states[i]);
		i++;
	}
	return 0;
}
