#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>//exit(1)������
#include<string.h>//strcmp�ȽϺ���ͷ�ļ�

class Material           //������
{
public:
	void Entering(fstream);//��������Ϣ¼��
	void Inquire(fstream);//��һ���ʲ�ѯ
	void Append(fstream);//�����ʵ����
	void Getthing(fstream);//������
	void Showthing(fstream);//���ʿ���嵥
	void CreateTxt(fstream);//������Ϣ����
private:
	char ID[10];
	char thingname[40];
	long sum;
};


void main()
{
	int choice;
	fstream of("C:\\���ʿ���嵥.dat",ios::out|ios::app|ios::binary);
	of.close();   //�ر��½����ļ�
	Material thing;
	for(int j=0;j<50;j++)
	{	
	fstream file("C:\\���ʿ���嵥.dat",ios::in|ios::out|ios::binary);//����������ļ�
	if(!file) {cerr<<"�ļ��򿪳���"<<endl;return;} 
	cout<<"===============================================================================\n";
	cout<<"||                         ��ӭʹ�����ʹ���ϵͳ                              ||\n";
	cout<<"===============================================================================\n";//����ϵͳ����ѡ��
	cout<<"||                                                                           ||\n";
	cout<<"|| \t [1]��������Ϣ¼�� \t [2]���ʲ�ѯ \t\t [3]���������       ||\n";
	cout<<"|| \t [4]������         \t [5]����嵥�����ϵ�\t [6]������Ϣ����     ||\n";
	cout<<"||\t \t \t \t [0]�˳�ϵͳ \t \t \t \t     ||\n";
    cout<<"===============================================================================\n";
	cout<<"���������ѡ��: ";
	cin >> choice ;
    switch ( choice )
	{ case 1 : thing.Entering(file) ;system("cls"); break;      case 2 : thing.Inquire(file) ; system("cls");break;
      case 3 : thing.Append(file) ;system("cls"); break;        case 4 : thing.Getthing(file) ;system("cls"); break;
      case 5 : thing.Showthing(file) ; system("cls");break;     case 6 : thing.CreateTxt(file) ;system("cls");break;
      case 0 : cout << "�˳�ϵͳ\n" ; return ;
      default : cout << "������������������\n" ;system("cls");}
	file.close();
	}
}

void Material::Entering(fstream fs)//��������Ϣ¼�빦�ܶ���
{
	system("cls");
	int choice;
	fs.seekp(0,ios::end); // �Ѷ�ָ���Ƶ��ļ�ĩβ
	long fileend=fs.tellp();  //��¼�ļ�ĩβλ��
	for(int i=0;i<50;i++)
	{
	cout<<"===================================\n";
	cout<<"||\t  ��������Ϣ¼��  \t||\n";
	cout<<"===================================\n";
	cout<<"���������ʱ��:";  cin>>ID;
	cout<<"��������������:";  cin>>thingname;
	cout<<"��������������:";  cin>>sum;
	fs.write((char *)this,sizeof(Material));   //����������Ϣ¼�뵽�ļ���
	cout<<"����¼���밴1,�˳�¼���밴0:  ";  cin>>choice;
	if(choice==0) break;
	system("cls");
	}
}
void Material::Inquire(fstream fs)//��һ���ʲ�ѯ���ܶ���
{
	system("cls");
	int b,choice; char code[10],name[10];int x=0;//code�Ǳ�ţ�name����������
	fs.seekg(0,ios::end);// �Ѷ�ָ���Ƶ��ļ�ĩβ
	long fileend=fs.tellg();//��¼�ļ�ĩβλ��
	for(int i=0;i<50;i++)
	{
	cout<<"====================================================\n";
	cout<<"||                    ���ʲ�ѯ                    ||\n";
	cout<<"====================================================\n";
	cout<<"||   1.����������ѯ\t 2.����Ų�ѯ\t 0.�˳�   ||\n";
	cout<<"====================================================\n";
	cout <<"���������ѡ��: ";
	cin>>choice;
	if(choice!=1&&choice!=2&&choice!=0) {cout<<"ѡ����������������"<<endl;continue;}
	switch(choice)
	{
	case 1:
		{fs.seekg(0,ios::beg);
		cout<<"������Ҫ��ѯ����������";
		cin>>name;
		do {fs.read((char *)this,sizeof(Material));}
		while(strcmp(thingname,name)!=0&&fileend!=fs.tellg());
		if(strcmp(thingname,name)==0)//�Ƚ������Ƿ���ͬ
			cout<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;
		else {cout<<"���ʲ�����\n"; continue;}
		break;
		};
	case 2:
		{fs.seekg(0,ios::beg);
		cout<<"������Ҫ��ѯ�����ʱ�ţ�";
		cin>>code;
		do {fs.read((char *)this,sizeof(Material));}
		while(strcmp(ID,code)!=0&&fileend!=fs.tellg());
		if(strcmp(ID,code)==0)
			cout<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;
		else {cout<<"���ʲ�����\n"; continue;}
		break;
		};
	case 0:return;
	}
	cout<<"������ѯ�밴1,�˳���ѯ�밴0:  ";  cin>>b;
	if(b==0) break;
	system("cls");
	}
}
void Material::Append(fstream fs)//�����ʵ���ӹ��ܶ���
{
	system("cls");
	int c,choice; long num; char code[10],name[10];//code�Ǳ�ţ�name����������
	fs.seekp(0,ios::end);// ��дָ���Ƶ��ļ�ĩβ
	long fileend=fs.tellp();//��¼�ļ�ĩβλ��
	for(int i=0;i<50;i++)
	{
	cout<<"====================================================\n";
	cout<<"||                   ���������                    ||\n";
	cout<<"====================================================\n";
	cout<<"||   1.�����������\t 2.��������\t 0.�˳�   ||\n";
	cout<<"====================================================\n";
	cout <<"���������ѡ��: ";
	cin>>choice;
	if(choice!=1&&choice!=2&&choice!=0) {cout<<"ѡ����������������"<<endl;continue;}
	switch(choice)
	{
	case 1:
		{fs.seekp(0,ios::beg);
		cout<<"������Ҫ��ӵ���������";
		cin>>name;
		do { fs.read((char *)this,sizeof(Material));}
		while(strcmp(thingname,name)!=0&&fileend!=fs.tellp());
		if(strcmp(thingname,name)==0)
		{  cout<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;
		cout<<"�������������";
		cin>>num;
		if(num>0) 
		{sum+=num;  cout<<"��ӳɹ�!   ";
		fs.seekp( -long(sizeof(Material)), ios::cur );	// ָ�븴λ
        fs.write( (char *)this , sizeof(Material) );	// д���ļ�
        cout << "�ֿ������" << sum<< endl ;}//��ӿ��
		else {cout<<"������������\n"; continue;}	
		}
		else cout<<"���ʲ�����"<<endl;
		break;}
	case 2:
		{fs.seekp(0,ios::beg);
		cout<<"������Ҫ��ӵ����ʱ�ţ�";
		cin>>code;
		do { fs.read((char *)this,sizeof(Material));}
		while(strcmp(ID,code)!=0&&fileend!=fs.tellp());
		if(strcmp(ID,code)==0)
		{  cout<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;
		cout<<"�������������";
		cin>>num;
		if(num>0) 
		{sum+=num;   cout<<"��ӳɹ�!   ";
		fs.seekp( -long(sizeof(Material)), ios::cur );	// ָ�븴λ
        fs.write( (char *)this , sizeof(Material) );	// д���ļ�
        cout << "�ֿ������" << sum<< endl ;}//��ӿ��
		else {cout<<"������������\n"; continue;}
		}
		else cout<<"���ʲ�����"<<endl;
		break;}
	case 0: return;
	}
	cout<<"��������밴1,�˳�����밴0:  ";  cin>>c;
	if(c==0) break;
	system("cls");
	}
}
void Material::Getthing(fstream fs)//�����ʹ��ܶ���
{
	system("cls");
	ofstream outfile("C:\\���ϼ�¼�ļ�.txt",ios::app);//�������ļ�,д������������ļ�ĩβ
	if(!outfile) {cout<<"open error!"<<endl;   exit(1);}
	int d,t,choice; long num; char code[10],name[10];//code�Ǳ�ţ�name����������
	fs.seekp(0,ios::end);// ��дָ���Ƶ��ļ�ĩβ
	long fileend=fs.tellp();//��¼�ļ�ĩβλ��
	for(int i=1;i<50;i++)
	{
	cout<<"====================================================\n";
	cout<<"||                    ��ȡ����                    ||\n";
	cout<<"====================================================\n";
	cout<<"||   1.����������ȡ\t 2.�������ȡ\t 0.�˳�   ||\n";
	cout<<"====================================================\n";
	cout <<"���������ѡ��: ";
	cin>>choice;
	if(choice!=1&&choice!=2&&choice!=0) {cout<<"ѡ����������������"<<endl;continue;}
	switch(choice)
	{
	case 1:
		{fs.seekp(0,ios::beg);// ���ļ�ͷ��ʼ����
		cout<<"������Ҫ��ȡ����������";
		cin>>name;
		do { fs.read((char *)this,sizeof(Material));}//��������Ϣ��ȡ���ڴ���
		while(strcmp(thingname,name)!=0&&fileend!=fs.tellp());
		if(strcmp(thingname,name)==0)
		{  cout<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;
		cout<<"������ȡ������";
		cin>>num;
		t=sum-num;
		if(num>0&&t>=0) 
		{sum-=num;//��ȡ���ϣ����ٿ��
		outfile<<"��"<<i<<"�Σ�\t"<<"��ȡ"<<thingname<<"����: "<<num<<"  "<<"���:"<<sum<<endl;
		fs.seekp( -long(sizeof(Material)), ios::cur );	// ָ�븴λ
        fs.write( (char *)this, sizeof(Material) );	// д���ļ�
        cout << "��ȡ�ɹ����ֿ������" << sum<< endl ;}
		else {cout<<"������������\n"; continue;}	
		}
		else cout<<"���ʲ�����"<<endl;
		break;}
	case 2:
		{fs.seekp(0,ios::beg);// ���ļ�ͷ��ʼ����
		cout<<"������Ҫ��ȡ�����ʱ�ţ�";
		cin>>code;
		do { fs.read((char *)this,sizeof(Material));}
		while(strcmp(ID,code)!=0&&fileend!=fs.tellp());
		if(strcmp(ID,code)==0)
		{  cout<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;
		cout<<"������ȡ������";
		cin>>num;
		t=sum-num;
		if(num>0&&t>=0) 
		{sum-=num;//��ȡ���ϣ����ٿ��
		outfile<<"��"<<i<<"�Σ�\t"<<"��ȡ"<<thingname<<"����: "<<num<<"  "<<"���:"<<sum<<endl;
		fs.seekp( -long(sizeof(Material)), ios::cur );	// ָ�븴λ
        fs.write( (char *)this, sizeof(Material) );	// д���ļ�
        cout << "��ȡ�ɹ����ֿ������" << sum<< endl ;}
		else {cout<<"������������\n"; continue;}	
		}
		else cout<<"���ʲ�����"<<endl;	
		break;}
	case 0: return;
	}
	cout<<"������ȡ�����밴1,�˳���ȡ�����밴0:  ";  cin>>d;
	if(d==0) break;
	system("cls");
	}
	outfile.close();
}
void Material::Showthing(fstream fs)//������ϵ������ʿ���嵥
{
	system("cls");
	int e,choice;
	ifstream fh("C:\\���ϼ�¼�ļ�.txt");
	fs.seekg(0,ios::end);// �Ѷ�ָ���Ƶ��ļ�ĩβ
	long fileend=fs.tellg();//��¼�ļ�ĩβλ��
	for(int i=1;i<10;i++)
	{
	cout<<"====================================================\n";
	cout<<"||            ���ϵ������ʿ���嵥���            ||\n";
	cout<<"====================================================\n";
	cout<<"||   1.���ϵ�\t   2.���ʿ���嵥\t 0.�˳�   ||\n";
	cout<<"====================================================\n";
	cout <<"���������ѡ��: ";
	cin>>choice;
	if(choice!=1&&choice!=2&&choice!=0) cout<<"ѡ����������������"<<endl;
	switch(choice)
	{
	case 1:
		cout<<"========���ϵ�========"<<endl;
		char s[1024];
		while(fh.getline(s,1024)) cout<<s<<endl;//��fh�ж�ȡ1023���ַ���ŵ�s[1024]��
		fh.close();
		break;
	case 2:
		{ cout<<"========���ʿ���嵥========"<<endl;
		fs.seekg( 0, ios::beg );
        do 
		{ fs.read((char *)this, sizeof(Material)) ; 
		cout<<ID<<'\t'<<thingname<<'\t'<<"���:"<<sum<<endl;} 
		while(fileend!=fs.tellg() ) ;
        break ;
		}
	case 0 :  return ;
	}
	cout<<"������ģ���밴1,�˳��밴0:  ";  cin>>e;
	if(e==0) break;
	system("cls");
	}
}
void Material::CreateTxt(fstream fs)//������Ϣ����,������ʽ���ı�
{
	system("cls");
	int f;
	fstream ctxt("C://������Ϣ�ı�",ios::out);//д��ʽ���ı��ļ�
	fs.seekg(0,ios::end);// �Ѷ�ָ���Ƶ��ļ�ĩβ
	long fileend=fs.tellg();//��¼�ļ�ĩβλ��
	fs.seekg( 0, ios::beg ) ;		// �ƶ���ָ�뵽�ļ�ͷ
	for(int i=1;i<10;i++)
	{
	cout<<"====================================================\n";
	cout<<"||                ������Ϣ�����ĵ�            ||\n";
	cout<<"====================================================\n";
	do  { fs.read((char* )this,sizeof(Material));// �Ӷ������ļ�����¼
	ctxt<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;}
	while(fileend!=fs.tellg());
	ctxt.close();
	cout<<"������Ϣ�����ĵ������ɹ���Ҫ����ļ���( Y/N ) \n";
	char choice,s[100];
	cin>>choice;
	cout<<"============================\n";
	if(choice=='y'||choice=='Y')
	{ctxt.open("C://������Ϣ�ı�",ios::in);//���뷽ʽ���ļ�,ctxt��������Ϣ�ı�����
	while(!ctxt.eof() )
	{ctxt.getline(s,100);
	cout<<s<<endl;}
	}
	cout<<"�����������밴1,�˳��밴0:  ";  cin>>f;
	if(f==0) break;
	system("cls");
	}
	ctxt.close();
}


    

	
	
	


