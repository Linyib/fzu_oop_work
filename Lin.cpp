#include<stdio.h> 
#include<string.h>
int n;
char  type[20],name[20],name1[20],fu[20],num[20];
int change(char a[]){//������ת�������ֽ������� 
	int n;
	char str[10][4]={"��","һ","��","��","��","��","��","��","��","��"};
	for(int i=0;i<10;i++){
		if(!strcmp(a,str[i])) return n=i;
	} 
}
void change1(int n,char a[]){//������ת�������� 
	char str[10][4]={"��","һ","��","��","��","��","��","��","��","��"};
	strcpy(a,str[n]);
}
void change2(int n,char cnum[]){
	char a[20];
	if(n<10){change1(n,a),strcpy(cnum,a);}
	else{int t;
		t=n/10,n=n%10;
		if(t!=1){//���ǡ�ʮ���͡�һʮ���Ĳ�� 
			change1(t,a),strcpy(cnum,a),strcat(cnum,"ʮ");
			if(n!=0){change1(n,a),strcat(cnum,a);}//����ĩβ�������� 
		}
		else{strcpy(cnum,"ʮ");
			if(n!=0){change1(n,a),strcat(cnum,a);}
		}
	}
} 
int in(void){//���뺯�� 
	scanf("%s",name1);
	if(!strcmp(name1,"����")) return 0;//���������־ 
	if(strcmp(name1,name)) return 1;//�ж���������ǲ��Ƕ���ı��������򲻽��л���������
	scanf("%s %s",fu,num); 
	if(strcmp(fu,"����")) n-=change(num);//�ж�������� 
	else n+=change(num); 
	return 1;
} 
void out(int n){//������� 

	char cnum[20];
	change2(n,cnum);
	printf("%s",cnum);	
}
int main(int argc,char *argv[]){
	freopen(argv[1],"r",stdin); 
	scanf("%s %s %s %s",type,name,fu,num);
	n=change(num);
	if(!strcmp(type,"����")){//�ж������Ƿ�Ϊ�������� 
	while(1){
		if(!in()) break;
	}
	scanf("%s",name1);
	if(strcmp(name1,name)||n<0||n>99){// �ж����ѯ�ʶ����Ƿ��Ǹñ��������ֲ���0~99�ķ�Χ�� �����򱨴� 
		out(-1); return 0;}
	else out(n);
	}
	else out(-1); 
	return 0;	
}
