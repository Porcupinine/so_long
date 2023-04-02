

#include "test.h"

int main(int argc, char **argv)
{
	if(argc < 2)
		return (1);
	test_read_map(argv);
	return(0);
}