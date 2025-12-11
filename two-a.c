#include <stdio.h>
#include <stdlib.h>

long read_long(char *s, int i)
{
	long v = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		v *= 10;
		v += s[i] - '0';
		i += 1;
	}

	return v;
}

long read_half(char *s, int i)
{
	long v = 0;
	int l = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		v *= 10;
		v += s[i] - '0';
		i += 1;
		l += 1;
	}

	if (l%2)
	{
		v = 1;
		for (int j=0; j<(l/2); j++)
		{
			v *= 10;
		}
	}
	else
	{
		for (int j=0; j<(l/2); j++)
		{
			v /= 10;
		}
	}

	return v;
}

long build_repeat(long v)
{
	long c = v;
	long h[100];
	int i = 0;
	
	while (c > 0)
	{
		h[i] = c%10;
		c /= 10;
		i += 1;
	}

	i -= 1;

	while (i >= 0)
	{
		v *= 10;
		v += h[i];
		i -= 1;
	}

	return v;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		return 0;
	}

	FILE *f = fopen(argv[1], "r");
	char s[5000];
	fgets(s, 5000, f);

	int i = 0;
	long c = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		long lb = read_long(s, i);
		long lh = read_half(s, i);

		while (s[i] != '-') i += 1;
		i += 1;

		long ub = read_long(s, i);
		long uh = read_half(s, i);

		for (long v = lh; v<=uh; v++)
		{
			long r = build_repeat(v);
			if (r >= lb && r <= ub) c += r;
		}	

		while (s[i] >= '0' && s[i] <= '9') i += 1;
		i += 1;
	}

	printf("%ld\n", c);

	return 0;
}

