#include<iostream>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

using namespace std;


char** parser(char* t)
{

	char **par;
	int i;

	std::cout.flush();


	char *token = strtok(t, " \n"); 

	i=0;

	while (token != NULL) 
	{
		par[i] = token; 
		token = strtok(NULL, " \n"); 
		i++;
	}
	
	par[i] = NULL;

	return par;

}	
