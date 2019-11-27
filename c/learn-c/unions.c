#include <stdio.h>

/* define the union here */
union un {
	int integers[6];
	char chars[21];
};
int main() {

	// initializer lists like this are assigned to the first member of the union/struct!
	// There are 6 ints here so...
	union un intCharacters = {{1853169737, 1936876900, 1684955508, 1768838432, 561213039, 0}};

	/* testing code */
	printf("[");
	for(int i = 0; i < 19; ++i)
		printf("%c, ", intCharacters.chars[i]);
	printf("%c]\n", intCharacters.chars[19]);

	printf("%s\n", intCharacters.chars);
}
