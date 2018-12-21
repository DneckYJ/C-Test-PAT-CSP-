#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<stdbool.h>
#include<cstdlib>
using namespace std;
struct Student {
	char id[15];                     //准考证号
	int sorce;                       //分数
	int location_number;             //考场号
	int local_rank;                  //考场内排名
}stu[30010];
bool cmp(struct Student a, struct Student b) {
	if (a.sorce != b.sorce) return a.sorce > b.sorce;   //分数相同从高到低排序
	else return strcmp(a.id, b.id) < 0;                 //分数不同按准考证大小排序
}
int main() {
	int n, k, num = 0;                         //num为考场总人数
	scanf("%d", &n);                         //考场数
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &k);                         //考场内人数
		for (int j = 0; j < k; ++j) {
			scanf("%s %d", stu[num].id, &stu[num].sorce);
			stu[num].location_number = i;
			num++;
		}
		sort(stu + num - k, stu + num, cmp);      //对考场内考生排名
		stu[num - k].local_rank = 1;              //将考场第一名的local_rank记为1
		for (int j = num - k + 1; j < num; ++j) {            //对该考场剩余的考生
			if (stu[j].sorce == stu[j - 1].sorce) {           //如果与前一名考生分数相同
				stu[j].local_rank = stu[j - 1].local_rank;          //考场内排名local_rank也相同
			}
			else{
				stu[j].local_rank = j + 1 - (num - k);
			}
		}
	}
	printf("%d\n", num);
	sort(stu, stu + num, cmp);
	int r = 1;
	for (int i = 0; i < num; ++i) {
		if (i > 0 && stu[i].sorce != stu[i - 1].sorce) {
			r = i + 1;
		}
		printf("%s", stu[i].id);
		printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank, );
	}
	return 0;
}
