#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef struct
{
	string name;
	int class_num;
	int score;
}student;
int comp(student a,student b);
int main()
{
	vector<student> stu;
	int n;
	student s;
	cin>>n;
	while(n--)
	{
		cin>>s.name>>s.class_num>>s.score;
		stu.push_back(s);		
	}
	sort(stu.begin(),stu.end(),comp);
	vector<student>::iterator it = stu.begin();
	cout<<"===score rank===\n";
	for(;it!=stu.end();it++)
		cout<<it->name<<'\t'<<it->class_num<<"  "<<it->score<<endl;
	return 0;
}
int comp(student a,student b)
{
	if(a.class_num!=b.class_num)
		return a.class_num <b.class_num;
	else if(a.score!=b.score)
		return a.score>b.score;
	else if(a.name.compare(b.name)<0)
		return 1;
	else 
		return 0;
}
