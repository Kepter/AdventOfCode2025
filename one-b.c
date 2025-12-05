#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		return 0;
	}

	FILE *f = fopen(argv[1], "r");

	char s[50];
	int v = 0;
	int a = 50;
	while (fgets(s, 50, f))
	{
		int c = 0;
		int i = 1;

		while (s[i] >= '0' && s[i] <= '9')
		{
			c *= 10;
			c += s[i] - '0';
			i += 1;
		}

		v += c / 100;
		c = c % 100;

		int n = (a == 0);
		if(s[0] == 'L')
		{
			a -= c;
		}
		else
		{
			a += c;
		}

		if (a < 0)
		{
			a += 100;
			if (!n) v += 1;
		}
		else if (a > 99)
		{
			a -= 100;
			v += 1;
		}
		else if (a == 0 && !n)
		{
			v += 1;
		}
	}

	printf("%d\n", v);

	return 0;
}
