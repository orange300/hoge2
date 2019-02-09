#include  <ctype.h>
#include  <stdio.h>

int main(void)
{
	int			   n;
	unsigned long  count = 0;
	unsigned char  buf[16];
	FILE  *fp;
	char  fname[64];	/* �t�@�C���� */

	printf("�t�@�C�����F");
	scanf("%s", fname);

	if ((fp = fopen(fname, "rb")) == NULL)					/* �I�[�v�� */
		printf("\a�t�@�C�����I�[�v���ł��܂���B\n");
	else {
		while ((n = fread(buf, 1, 16, fp)) > 0) {
			int	 i;

			printf("%08lX ", count);						/* �A�h���X */

			for (i = 0; i < n; i++)							/* 16�i�� */
				printf("%02X ", (unsigned)buf[i]);

			if (n < 16)
				for (i = n; i < 16; i++) printf("   ");

			for (i = 0; i < n; i++)							/* ���� */
				putchar(isprint(buf[i]) ? buf[i] : '.');

			putchar('\n');

			count += 16;
		}
		fclose(fp);											/* �N���[�Y */
	}

	return (0);
}
