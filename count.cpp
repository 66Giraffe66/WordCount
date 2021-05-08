#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
	char ch;
	char ft = ' ';
	int cnt = 0;
	FILE *pt;
	if ((pt = fopen(argv[2], "r")) == NULL) {
		printf("打开文件 %s 失败！", argv[2]);
		exit(1);
	}
	if (strcmp(argv[1], "-c") == 0) {
		while ((ch = getc(pt)) != EOF) {
			cnt++;//统计字符数
		}
		printf("字符数%d个\n", cnt);
	} else {
		while ((ch = getc(pt)) != EOF) {
			if ((ch >= '!' && ch <= '+') || (ch >= '-' && ch <= '~') && ((ft == ' ') || (ft == ','))) {
				cnt++;//统计单词数
			}
			ft = ch;
		}
		printf("单词数%d个\n", cnt);
	}
	fclose(pt);
	return 0;
}
