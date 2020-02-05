#include<stdio.h> 
#include<string.h>
int n;
char  type[20],name[20],name1[20],fu[20],num[20];
int change(char a[]){//将汉字转化成数字进行运算 
	int n;
	char str[10][4]={"零","一","二","三","四","五","六","七","八","九"};
	for(int i=0;i<10;i++){
		if(!strcmp(a,str[i])) return n=i;
	} 
}
void change1(int n,char a[]){//将汉字转化成数字 
	char str[10][4]={"零","一","二","三","四","五","六","七","八","九"};
	strcpy(a,str[n]);
}
void change2(int n,char cnum[]){
	char a[20];
	if(n<10){change1(n,a),strcpy(cnum,a);}
	else{int t;
		t=n/10,n=n%10;
		if(t!=1){//考虑“十”和“一十”的差别 
			change1(t,a),strcpy(cnum,a),strcat(cnum,"十");
			if(n!=0){change1(n,a),strcat(cnum,a);}//考虑末尾是零的情况 
		}
		else{strcpy(cnum,"十");
			if(n!=0){change1(n,a),strcat(cnum,a);}
		}
	}
} 
int in(void){//输入函数 
	scanf("%s",name1);
	if(!strcmp(name1,"看看")) return 0;//输入结束标志 
	if(strcmp(name1,name)) return 1;//判断运算对象是不是定义的变量，否则不进行还回主函数
	scanf("%s %s",fu,num); 
	if(strcmp(fu,"增加")) n-=change(num);//判断运算符号 
	else n+=change(num); 
	return 1;
} 
void out(int n){//输出函数 

	char cnum[20];
	change2(n,cnum);
	printf("%s",cnum);	
}
int main(int argc,char *argv[]){
	freopen(argv[1],"r",stdin); 
	scanf("%s %s %s %s",type,name,fu,num);
	n=change(num);
	if(!strcmp(type,"整数")){//判断类型是否为“整数” 
	while(1){
		if(!in()) break;
	}
	scanf("%s",name1);
	if(strcmp(name1,name)||n<0||n>99){// 判断最后询问对象是否是该变量或数字不在0~99的范围内 ，否则报错 
		out(-1); return 0;}
	else out(n);
	}
	else out(-1); 
	return 0;	
}
