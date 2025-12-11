#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		return 0;
	}

	FILE *f = fopen(argv[1], "r");
	char s[500];
	
	int v = 0;
	while(fgets(s, 500, f))
	{
		int c = 0;
		int b[500];
		int m = -1;

		for (int i=0; i<500; i++)
		{
			if (s[i] < '0')
			{
				c = i;
				break;
			}
		}

		for (int i=c-1; i>=0; i--)
		{
			if ((s[i] - '0') > m)
			{
				m = (s[i] - '0');
			}

			b[i] = m;
		}

		m = -1;
		for (int i=0; i<c-1; i++)
		{
			int t = (s[i] - '0') * 10 + b[i+1];
			if (t > m)
			{
				m = t;
			}
		}

		v += m;
	}

	printf("%d\n", v);
}
