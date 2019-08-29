#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
#include <string>
#include <set>
#include <map>
using namespace std;
const int HourNum = 24;
const string OnLine = "on-line";

struct Time {
	int mon, dd, hh, mm, time;
	bool on;
	bool operator < (const Time &t)const{
		return this->time < t.time;
	}
};

int rate[HourNum];
map<string, set<Time> >bill;

int get_ans(int d1, int h1, int m1, int d2, int h2, int m2) {
	int cost = 0;
	while (d1 < d2 || h1 < h2 || m1 < m2) {
		m1++;
		cost += rate[h1];
		if (m1 == 60) {
			m1 = 0;
			h1++;
		}
		if (h1 == 24) {
			h1 = 0;
			d1++;
		}
	}
	return cost;
}

int main()
{
	int n;
	for (int i = 0; i < HourNum; i++) {
		cin >> rate[i];
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		string id, line;
		Time t;
		cin >> id;
		scanf("%d:%d:%d:%d", &t.mon, &t.dd, &t.hh, &t.mm);
		cin >> line;
		t.time = t.dd * 1440 + t.hh * 60 + t.mm;
		if (line.compare(OnLine)==0) {
			t.on = true;
		}
		else t.on = false;
		bill[id].insert(t);
	}
	for (auto i = bill.cbegin(); i != bill.cend(); i++) {
		int totalcost = 0;
		int printflag = 0;
		for (auto j = (i->second).cbegin(); j != (i->second).cend(); j++) {
			if (printflag == 0 && j->on == true)
				printflag = 1;
			else if (printflag == 1 && j->on == false)
				printflag = 2;
		}
		if (printflag > 1) {
            printf("%s %02d\n",(i->first).c_str(),((i->second).cbegin())->mon );
			int cost = 0;
			for (auto j = (i->second).cbegin(); j != (i->second).cend(); j++) {
				auto next = j;
				next++;
				if (j->on == true && next !=(i->second).cend()&& next->on == false) {
					printf("%02d:%02d:%02d %02d:%02d:%02d %d ", j->dd, j->hh, j->mm, next->dd, next->hh, next->mm,next->time-j->time);
					cost = get_ans(j->dd, j->hh, j->mm, next->dd, next->hh, next->mm);
					totalcost += cost;
					printf("$%.2f\n", cost / 100.0);
				}
			}
			printf("Total amount: $%.2f\n", totalcost/100.0);
		}
		else {
			continue;
		}
	}
    return 0;
}
