#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
	char ch;
	char ft = ' ';
	int cnt = 0;
	FILE *pt;
	if ((pt = fopen(argv[2], "r")) == NULL) {
		printf("���ļ� %s ʧ�ܣ�", argv[2]);
		exit(1);
	}
	if (strcmp(argv[1], "-c") == 0) {
		while ((ch = getc(pt)) != EOF) {
			cnt++;//ͳ���ַ���
		}
		printf("�ַ���%d��\n", cnt);
	} else {
		while ((ch = getc(pt)) != EOF) {
			if ((ch >= '!' && ch <= '+') || (ch >= '-' && ch <= '~') && ((ft == ' ') || (ft == ','))) {
				cnt++;//ͳ�Ƶ�����
			}
			ft = ch;
		}
		printf("������%d��\n", cnt);
	}
	fclose(pt);
	return 0;
}
