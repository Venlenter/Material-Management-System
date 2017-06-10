#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>//exit(1)的作用
#include<string.h>//strcmp比较函数头文件

class Material           //物资类
{
public:
	void Entering(fstream);//新物资信息录入
	void Inquire(fstream);//单一物资查询
	void Append(fstream);//旧物资的添加
	void Getthing(fstream);//领物资
	void Showthing(fstream);//物资库存清单
	void CreateTxt(fstream);//物资信息保存
private:
	char ID[10];
	char thingname[40];
	long sum;
};


void main()
{
	int choice;
	fstream of("C:\\物资库存清单.dat",ios::out|ios::app|ios::binary);
	of.close();   //关闭新建的文件
	Material thing;
	for(int j=0;j<50;j++)
	{	
	fstream file("C:\\物资库存清单.dat",ios::in|ios::out|ios::binary);//打开输入输出文件
	if(!file) {cerr<<"文件打开出错"<<endl;return;} 
	cout<<"===============================================================================\n";
	cout<<"||                         欢迎使用物资管理系统                              ||\n";
	cout<<"===============================================================================\n";//管理系统功能选择
	cout<<"||                                                                           ||\n";
	cout<<"|| \t [1]新物资信息录入 \t [2]物资查询 \t\t [3]旧物资添加       ||\n";
	cout<<"|| \t [4]领物资         \t [5]库存清单及领料单\t [6]物资信息生成     ||\n";
	cout<<"||\t \t \t \t [0]退出系统 \t \t \t \t     ||\n";
    cout<<"===============================================================================\n";
	cout<<"请输入操作选项: ";
	cin >> choice ;
    switch ( choice )
	{ case 1 : thing.Entering(file) ;system("cls"); break;      case 2 : thing.Inquire(file) ; system("cls");break;
      case 3 : thing.Append(file) ;system("cls"); break;        case 4 : thing.Getthing(file) ;system("cls"); break;
      case 5 : thing.Showthing(file) ; system("cls");break;     case 6 : thing.CreateTxt(file) ;system("cls");break;
      case 0 : cout << "退出系统\n" ; return ;
      default : cout << "输入有误，请重新输入\n" ;system("cls");}
	file.close();
	}
}

void Material::Entering(fstream fs)//新物资信息录入功能定义
{
	system("cls");
	int choice;
	fs.seekp(0,ios::end); // 把读指针移到文件末尾
	long fileend=fs.tellp();  //记录文件末尾位置
	for(int i=0;i<50;i++)
	{
	cout<<"===================================\n";
	cout<<"||\t  新物资信息录入  \t||\n";
	cout<<"===================================\n";
	cout<<"请输入物资编号:";  cin>>ID;
	cout<<"请输入物资名称:";  cin>>thingname;
	cout<<"请输入物资数量:";  cin>>sum;
	fs.write((char *)this,sizeof(Material));   //将新物资信息录入到文件中
	cout<<"继续录入请按1,退出录入请按0:  ";  cin>>choice;
	if(choice==0) break;
	system("cls");
	}
}
void Material::Inquire(fstream fs)//单一物资查询功能定义
{
	system("cls");
	int b,choice; char code[10],name[10];int x=0;//code是编号，name是物资名称
	fs.seekg(0,ios::end);// 把读指针移到文件末尾
	long fileend=fs.tellg();//记录文件末尾位置
	for(int i=0;i<50;i++)
	{
	cout<<"====================================================\n";
	cout<<"||                    物资查询                    ||\n";
	cout<<"====================================================\n";
	cout<<"||   1.按物资名查询\t 2.按编号查询\t 0.退出   ||\n";
	cout<<"====================================================\n";
	cout <<"请输入操作选项: ";
	cin>>choice;
	if(choice!=1&&choice!=2&&choice!=0) {cout<<"选择有误，请重新输入"<<endl;continue;}
	switch(choice)
	{
	case 1:
		{fs.seekg(0,ios::beg);
		cout<<"请输入要查询的物资名：";
		cin>>name;
		do {fs.read((char *)this,sizeof(Material));}
		while(strcmp(thingname,name)!=0&&fileend!=fs.tellg());
		if(strcmp(thingname,name)==0)//比较名称是否相同
			cout<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;
		else {cout<<"物资不存在\n"; continue;}
		break;
		};
	case 2:
		{fs.seekg(0,ios::beg);
		cout<<"请输入要查询的物资编号：";
		cin>>code;
		do {fs.read((char *)this,sizeof(Material));}
		while(strcmp(ID,code)!=0&&fileend!=fs.tellg());
		if(strcmp(ID,code)==0)
			cout<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;
		else {cout<<"物资不存在\n"; continue;}
		break;
		};
	case 0:return;
	}
	cout<<"继续查询请按1,退出查询请按0:  ";  cin>>b;
	if(b==0) break;
	system("cls");
	}
}
void Material::Append(fstream fs)//旧物资的添加功能定义
{
	system("cls");
	int c,choice; long num; char code[10],name[10];//code是编号，name是物资名称
	fs.seekp(0,ios::end);// 把写指针移到文件末尾
	long fileend=fs.tellp();//记录文件末尾位置
	for(int i=0;i<50;i++)
	{
	cout<<"====================================================\n";
	cout<<"||                   旧物资添加                    ||\n";
	cout<<"====================================================\n";
	cout<<"||   1.按物资名添加\t 2.按编号添加\t 0.退出   ||\n";
	cout<<"====================================================\n";
	cout <<"请输入操作选项: ";
	cin>>choice;
	if(choice!=1&&choice!=2&&choice!=0) {cout<<"选择有误，请重新输入"<<endl;continue;}
	switch(choice)
	{
	case 1:
		{fs.seekp(0,ios::beg);
		cout<<"请输入要添加的物资名：";
		cin>>name;
		do { fs.read((char *)this,sizeof(Material));}
		while(strcmp(thingname,name)!=0&&fileend!=fs.tellp());
		if(strcmp(thingname,name)==0)
		{  cout<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;
		cout<<"物资添加数量：";
		cin>>num;
		if(num>0) 
		{sum+=num;  cout<<"添加成功!   ";
		fs.seekp( -long(sizeof(Material)), ios::cur );	// 指针复位
        fs.write( (char *)this , sizeof(Material) );	// 写入文件
        cout << "现库存量：" << sum<< endl ;}//添加库存
		else {cout<<"数量输入有误\n"; continue;}	
		}
		else cout<<"物资不存在"<<endl;
		break;}
	case 2:
		{fs.seekp(0,ios::beg);
		cout<<"请输入要添加的物资编号：";
		cin>>code;
		do { fs.read((char *)this,sizeof(Material));}
		while(strcmp(ID,code)!=0&&fileend!=fs.tellp());
		if(strcmp(ID,code)==0)
		{  cout<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;
		cout<<"物资添加数量：";
		cin>>num;
		if(num>0) 
		{sum+=num;   cout<<"添加成功!   ";
		fs.seekp( -long(sizeof(Material)), ios::cur );	// 指针复位
        fs.write( (char *)this , sizeof(Material) );	// 写入文件
        cout << "现库存量：" << sum<< endl ;}//添加库存
		else {cout<<"数量输入有误\n"; continue;}
		}
		else cout<<"物资不存在"<<endl;
		break;}
	case 0: return;
	}
	cout<<"继续添加请按1,退出添加请按0:  ";  cin>>c;
	if(c==0) break;
	system("cls");
	}
}
void Material::Getthing(fstream fs)//领物资功能定义
{
	system("cls");
	ofstream outfile("C:\\领料记录文件.txt",ios::app);//打开领料文件,写入数据添加在文件末尾
	if(!outfile) {cout<<"open error!"<<endl;   exit(1);}
	int d,t,choice; long num; char code[10],name[10];//code是编号，name是物资名称
	fs.seekp(0,ios::end);// 把写指针移到文件末尾
	long fileend=fs.tellp();//记录文件末尾位置
	for(int i=1;i<50;i++)
	{
	cout<<"====================================================\n";
	cout<<"||                    领取物资                    ||\n";
	cout<<"====================================================\n";
	cout<<"||   1.按物资名领取\t 2.按编号领取\t 0.退出   ||\n";
	cout<<"====================================================\n";
	cout <<"请输入操作选项: ";
	cin>>choice;
	if(choice!=1&&choice!=2&&choice!=0) {cout<<"选择有误，请重新输入"<<endl;continue;}
	switch(choice)
	{
	case 1:
		{fs.seekp(0,ios::beg);// 从文件头开始检索
		cout<<"请输入要领取的物资名：";
		cin>>name;
		do { fs.read((char *)this,sizeof(Material));}//将物料信息读取到内存中
		while(strcmp(thingname,name)!=0&&fileend!=fs.tellp());
		if(strcmp(thingname,name)==0)
		{  cout<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;
		cout<<"物资领取数量：";
		cin>>num;
		t=sum-num;
		if(num>0&&t>=0) 
		{sum-=num;//领取物料，减少库存
		outfile<<"第"<<i<<"次：\t"<<"领取"<<thingname<<"数量: "<<num<<"  "<<"库存:"<<sum<<endl;
		fs.seekp( -long(sizeof(Material)), ios::cur );	// 指针复位
        fs.write( (char *)this, sizeof(Material) );	// 写入文件
        cout << "领取成功，现库存量：" << sum<< endl ;}
		else {cout<<"数量输入有误\n"; continue;}	
		}
		else cout<<"物资不存在"<<endl;
		break;}
	case 2:
		{fs.seekp(0,ios::beg);// 从文件头开始检索
		cout<<"请输入要领取的物资编号：";
		cin>>code;
		do { fs.read((char *)this,sizeof(Material));}
		while(strcmp(ID,code)!=0&&fileend!=fs.tellp());
		if(strcmp(ID,code)==0)
		{  cout<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;
		cout<<"物资领取数量：";
		cin>>num;
		t=sum-num;
		if(num>0&&t>=0) 
		{sum-=num;//领取物料，减少库存
		outfile<<"第"<<i<<"次：\t"<<"领取"<<thingname<<"数量: "<<num<<"  "<<"库存:"<<sum<<endl;
		fs.seekp( -long(sizeof(Material)), ios::cur );	// 指针复位
        fs.write( (char *)this, sizeof(Material) );	// 写入文件
        cout << "领取成功，现库存量：" << sum<< endl ;}
		else {cout<<"数量输入有误\n"; continue;}	
		}
		else cout<<"物资不存在"<<endl;	
		break;}
	case 0: return;
	}
	cout<<"继续领取物料请按1,退出领取物料请按0:  ";  cin>>d;
	if(d==0) break;
	system("cls");
	}
	outfile.close();
}
void Material::Showthing(fstream fs)//浏览领料单或物资库存清单
{
	system("cls");
	int e,choice;
	ifstream fh("C:\\领料记录文件.txt");
	fs.seekg(0,ios::end);// 把读指针移到文件末尾
	long fileend=fs.tellg();//记录文件末尾位置
	for(int i=1;i<10;i++)
	{
	cout<<"====================================================\n";
	cout<<"||            领料单或物资库存清单浏览            ||\n";
	cout<<"====================================================\n";
	cout<<"||   1.领料单\t   2.物资库存清单\t 0.退出   ||\n";
	cout<<"====================================================\n";
	cout <<"请输入操作选项: ";
	cin>>choice;
	if(choice!=1&&choice!=2&&choice!=0) cout<<"选择有误，请重新输入"<<endl;
	switch(choice)
	{
	case 1:
		cout<<"========领料单========"<<endl;
		char s[1024];
		while(fh.getline(s,1024)) cout<<s<<endl;//从fh中读取1023个字符存放到s[1024]中
		fh.close();
		break;
	case 2:
		{ cout<<"========物资库存清单========"<<endl;
		fs.seekg( 0, ios::beg );
        do 
		{ fs.read((char *)this, sizeof(Material)) ; 
		cout<<ID<<'\t'<<thingname<<'\t'<<"库存:"<<sum<<endl;} 
		while(fileend!=fs.tellg() ) ;
        break ;
		}
	case 0 :  return ;
	}
	cout<<"继续该模块请按1,退出请按0:  ";  cin>>e;
	if(e==0) break;
	system("cls");
	}
}
void Material::CreateTxt(fstream fs)//物资信息保存,创建格式化文本
{
	system("cls");
	int f;
	fstream ctxt("C://物资信息文本",ios::out);//写方式打开文本文件
	fs.seekg(0,ios::end);// 把读指针移到文件末尾
	long fileend=fs.tellg();//记录文件末尾位置
	fs.seekg( 0, ios::beg ) ;		// 移动读指针到文件头
	for(int i=1;i<10;i++)
	{
	cout<<"====================================================\n";
	cout<<"||                物资信息生成文档            ||\n";
	cout<<"====================================================\n";
	do  { fs.read((char* )this,sizeof(Material));// 从二进制文件读记录
	ctxt<<ID<<'\t'<<thingname<<'\t'<<sum<<endl;}
	while(fileend!=fs.tellg());
	ctxt.close();
	cout<<"物资信息保存文挡建立成功，要浏览文件吗？( Y/N ) \n";
	char choice,s[100];
	cin>>choice;
	cout<<"============================\n";
	if(choice=='y'||choice=='Y')
	{ctxt.open("C://物资信息文本",ios::in);//输入方式打开文件,ctxt与物资信息文本关联
	while(!ctxt.eof() )
	{ctxt.getline(s,100);
	cout<<s<<endl;}
	}
	cout<<"继续该摸快请按1,退出请按0:  ";  cin>>f;
	if(f==0) break;
	system("cls");
	}
	ctxt.close();
}


    

	
	
	


