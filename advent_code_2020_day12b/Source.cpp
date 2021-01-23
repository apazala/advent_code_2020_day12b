#include <stdio.h>
#include <inttypes.h>

int main() {

	FILE *fin = fopen("input.txt", "r");
	if (!fin) {
		fprintf(stderr, "Can't open input file\n");
		return 1;
	}

	char order;
	int value;
	int64_t iw = 1, jw = 10, i = 0, j = 0, aux;

	while (fscanf(fin, " %c%d", &order, &value) == 2) {
		switch (order)
		{
		case 'R':
			value = 360 - value;
		case 'L':
			switch (value)
			{

			case 90:
				aux = iw;
				iw = jw;
				jw = -aux;
				break;
			case 180:
				iw = -iw;
				jw = -jw;
				break;
			case 270:
				aux = iw;
				iw = -jw;
				jw = aux;
				break;
			default: puts("AHHHHHHHHHHH");
				break;
			}
			break;
		case 'N':
			iw += value;
			break;
		case 'E':
			jw += value;
			break;
		case 'S':
			iw -= value;
			break;
		case 'W':
			jw -= value;
			break;
		case 'F':
			i += value*iw;
			j += value*jw;
			break;
		default: puts("AHHHHHHHHHHH");
			break;
		}
	}

	fclose(fin);

	int d = 0;
	d += (i < 0 ? -i : i);
	d += (j < 0 ? -j : j);

	printf("%d\n", d);

	return 0;
}