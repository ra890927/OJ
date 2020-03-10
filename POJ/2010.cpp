#include <iostream>
#include <algorithm>
#define MAX_N 100000 + 1
using namespace std;

struct Cow{
	int grade, cost;
};

struct Financial{
	int id, cost;
};

int C, N, F;
bool res = false;
Cow c[MAX_N];
Financial f[MAX_N];

bool cmp_grade(Cow &a, Cow &b){
	return a.grade < b.grade;
}

bool cmp_cost(Financial &a, Financial &b){
	return a.cost < b.cost;
}

bool check(int x){
	int sum = c[x].cost, rcnt = 0, lcnt = 0;
		
	for(int i = 0; i < N; i++){
		if(f[i].id < x && lcnt < C && sum + f[i].cost <= F){
			sum += f[i].cost;
			lcnt++;
		}
		else if(f[i].id > x && rcnt < C && sum + f[i].cost <= F){
			sum += f[i].cost;
			rcnt++;
		}
	}
	
	if(lcnt < C && rcnt < C) res = true;
	
	if(rcnt < C) return false;
	else return true;
}

int main(){
	cin >> C >> N >> F;
	
	C /= 2;
	
	for(int i = 0; i < N; i++)
		cin >> c[i].grade >> c[i].cost;
	
	sort(c, c + N, cmp_grade);
	
	for(int i = 0; i < N; i++){
		f[i].id = i;
		f[i].cost = c[i].cost;
	}
	
	sort(f, f + N, cmp_cost);
	
	int lb = 0, ub = N, mid;
	while(ub - lb > 1){
		mid = (lb + ub) / 2;
		if(check(mid)) lb = mid;
		else ub = mid;
	}
	
	if(res)
		cout << -1 << endl;
	else
		cout << c[lb].grade << endl;
		
	return 0;
}