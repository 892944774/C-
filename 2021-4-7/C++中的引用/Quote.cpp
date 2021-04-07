#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <string>

#if 0
int* func1()
{
	//�ڶ��Ͽ��������ص��Ǹ��������͵�ָ��
	int * p = new int(10);
	return p;
}

void func2()
{
	int * arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	delete[] arr;
}

int main()
{
	int * p = func1();
	cout << *p << endl;
	delete p;

	func2();
	return 0;
}
#endif

#if 0 
void test(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	test(a, b);
	cout << " a =" << a << endl;
	cout << " b =" << b << endl;
	return 0;
}
#endif

#if 0
//1.��Ҫ���ؾֲ�����������
int& func()
{
	//a��ջ������������󱾴ε��ý��������ص�ֵΪ�����
	int a = 10;
	return a;
}

//2.�����ĵ��ÿ�����Ϊ��ֵ
int& func2()
{
	//static���κ�����ȫ�ֱ�����������ȫ������ȫ�����ı�����ϵͳ�ͷ�
	static int a = 20;
	return a;
}

int main()
{
	int &a = func();
	cout << a << endl;
	cout << a << endl;

	int &b = func2();
	cout << b << endl;
	return 0;
}
#endif 

#if 0
int& func1(int &a)
{
	a = 20;
	return a;
}

//const�������ò����޸�
int& func2(const int &a)
{
	a = 20;
	return a;
}

int main()
{
	int a = 10;
	//int & ref = 10;//err
	//const int &ref = 10;//����const֮�󣬱��������˾仰�޸�Ϊint temp =10; �� int &ref = temp; 

	int &ret = func1(a);
	cout << ret << endl;

	int &ret = func2(a);//error
	cout << ret << endl;
	return 0;
}
#endif

#if 0 
//�������أ�1.������������ͬ 2.��������ͬ  3.�����Ĳ����б�ͬ������˳���������ͻ����������ͬ
//ע�⣺�������صķ���ֵ������Ϊ�������ص�����
void func()
{
	cout << "func()" << endl;
}

void func(int a)
{
	cout << "func()?" << endl;
}

//1.������Ϊ���ص�����
void func1(int &a)
{
	cout << "func1(int &a)" << endl;
}

void func1(const int &a)
{
	cout << "func1(const int &a)" << endl;
}

//2.������������Ĭ�ϲ���
void func2(int a, int b = 1)
{
	cout << "func2(int a, int b = 1)" << endl;
}

void func2(int a)
{
	cout << "func2(int a)" << endl;
}

int main()
{
	//func();
	int a = 10;
	func1(a);
	func1(10);//func1(const int &a)

	func2(10,10);//"func2(int a, int b = 1)"
	func2(10);//err
	return 0;
}
#endif

#if 0
class Circule
{
public:

	double calculate(int r)
	{
		return 2 * 3.14*r;
	}

	int r;
};
int main()
{
	//ʵ������ͨ��һ���࣬���崴��һ������Ĺ���
	Circule C;
	double ret = C.calculate(10);
	cout << ret << endl;
	return 0;
}
#endif

//����Ȩ��
//����Ȩ��--���ڿ��Է��ʣ�����Ҳ���Է���
//����Ȩ��--���ڿ��Է��ʣ����ⲻ���Է���   ������Է��ʸ��������
//˽��Ȩ��--���ڿ��Է��ʣ����ⲻ���Է���   ���಻�ܷ��ʸ��������
#if 0
class Person
{
public:
	string _name;
	void func()
	{
		car = "��";
		password = "1234";
	}

protected:
	string car;
private:
	string password;
};

int main()
{
	Person p1;
	p1.func();
	return 0;
}
#endif

#if 0
//structĬ�ϵķ���Ȩ���ǹ��е�
struct S
{
	int a;
};

//classĬ�ϵķ���Ȩ����˽�е�
class C
{
	int b;
};

int main()
{
	S s;
	C c;
	s.a = 1;
	c.b = 1;//err
	return 0;
}
#endif 

#if 0
class Person
{
public:
	int Getage(int a)
	{
		age = a;
		return age;
	}

	string Getname(string name)
	{
		_name = name;
		return _name;
	}

	string GetLover(string lover)
	{
		_lover = lover;
		return _lover;
	}

private:
	int age;
	string _name;
	string _lover;
};

int main()
{
	Person people;

	cout << people.Getage(10) << endl;
	cout << people.GetLover("zhang") << endl;
	cout << people.Getname("zzzz") << endl;
	return 0;
}
#endif

#if 0
class Person
{
public:
	//���캯����ɶ���ĳ�ʼ��
	//���캯���޷���ֵ������Ҫдvoid
	//���캯���ĺ�������������ͬ
	//���캯�������в��������Է�������
	//���������ʱ��ϵͳ���Զ����ù��캯��
	Person()
	{
		cout << "Person��Ĺ��캯��" << endl;
	}

	//����������ɶ��������
	//���������޷���ֵ������Ҫдvoid
	//��������������ͬ
	//���������������в���������������ǰ�� ���Զ�������������
	~Person()
	{
		cout << "Person�����������" << endl;
	}
};

int main()
{
	Person p;
	return 0;
}
#endif

#if 0
//���캯�����գ���Ϊ�вι�����޲ι���
//�������ͷ�Ϊ����ͨ���캯���Ϳ������캯��
class Person
{
public:
	//�޲ι���
	Person()
	{
		cout << "Person()���캯��" << endl;
	}

	//�вι���
	Person(int a)
	{
		age = a;
		cout << "Person()�вι���" << endl;
	}

	//��������
	Person(const Person &p)
	{
		age = p.age;
		cout << "Person()����" << endl;
	}

	~Person()
	{
		cout << "����" << endl;
	}

	int age;
};

//ֵ���ݵķ�ʽ����������
void DoWork(Person p)
{
	int age = 0;
	age = p.age;
}

void test()
{
	Person p;
	DoWork(p);
}

int main()
{
	//��Ҫд��	Person p();��ʱ�������Ὣ������䵱���Ǻ���������

	//Person p;//����Ĭ�Ϲ��캯��
	//Person p1(10);//�вι��캯��
	//Person p2(p1);//�������캯��
	//cout << p1.age << endl;

	test();
	return 0;
}
#endif

#if 0
class Person
{
public:
	Person()
	{
		cout << "Person�Ĺ��캯��" << endl;
	}

	Person(int age, int height)
	{
		_age = age;
		_height = new int(height);//���Ͽ��٣�����Ա�ֶ����٣�Ҳ��Ҫ����Ա�ֶ��ͷ�
		cout << "Person���вι��캯��" << endl;
	}

	Person(const Person &p)
	{
		_age = p._age;
		//_height = p._height;//ǳ�����Ĳ���

		//���
		_height = new int(*p._height);
	}

	~Person()
	{
		//���������ٵĳ����ͷ�
		if (_height != NULL)
		{
			delete _height;
			_height = NULL;
		}
		cout << "Person����������" << endl;
	}
	
	int _age;
	int *_height;
};

void test1()
{
	Person p1(12, 160);
	cout << p1._age <<  *p1._height << endl;

	Person p2(p1);
	cout << p2._age <<  *p2._height << endl;
}

int main()
{
	test1();
	return 0;
}
#endif

#if 0
class Phone
{
public:
	Phone(string pName)
	{
		cout << "Phone�Ĺ��캯��" << endl;
		_pName = pName;
	}

	~Phone()
	{
		cout << "Phone����������" << endl;
	}
	string _pName;
};

class Person
{
public:
	//Phone _Phone = phone; ��ʽת����
	Person(string name, string phone)
		: _Name(name)
		, _Phone(phone)
	{
		cout << "Person�Ĺ��캯��" << endl;
	}

	~Person()
	{
		cout << "Person����������" << endl;
	}
	string _Name;
	Phone _Phone;
};

//�����ʱ���ȹ������������Ķ����ٹ����Լ����������������Լ�����������������
int main()
{
	Person p("��ɭ", "��Ϊ");
	return 0;
}
#endif

#if 0
//��̬��Ա����
class Person
{
public:
	//1. ���еĶ�����һ������
	//2. ����׶ξͷ����ڴ�
	//3. ���������������ʼ������
	static int a;
private:
	int b;
};

int Person::a = 100;
//int Person::b = 200;

int main()
{
	//1.ͨ��������з���
	Person p;
	cout << p.a << endl;

	//2. ͨ���������з���
	cout << Person::a << endl;
	return 0;
}
#endif

#if 0
class Person
{
public:
	//��̬��Ա����
	static void func()
	{
		_a = 100;//��̬��Ա����  ���Է��ʾ�̬��Ա����
		_b = 200;//��̬��Ա����  �����Է��ʾ�̬��Ա����
		cout << "static void func()����" << endl;
	}

	static int _a;
	int _b;
};

int Person::_a = 0;

int main()
{
	//��̬��Ա�������ַ��ʷ�ʽ
	//1 ͨ������ֱ�ӷ���
	Person p;
    p.func();

	//2 ��������ֱ�ӷ���
	Person::func();
	return 0;
}
#endif

#if 0
//��Ա�����ͳ�Ա�����Ƿֿ��洢��
class Person
{
	int _a;//�Ǿ�̬�ĳ�Ա������������Ķ���

	static int _b;//��̬�ĳ�Ա��������������Ķ���

	void func()//�Ǿ�̬�ĳ�Ա��������������Ķ���
	{};
};

int Person::_b = 0;

int main()
{
	Person p;
	cout << sizeof(p) << endl;//4
	return 0;
}
#endif

#if 0
class Person
{
public:
	Person(int age)
	{
		//thisָ��ָ�� �����ó�Ա���� �����Ķ���
		this->age = age;
	}

	Person& PersonAddAge(Person &p)
	{
		this->age += p.age;

		//thisָ��p2��ָ�룬��*thisָ��ľ���p2
		return *this;
	}
	int age;
};

int main()
{
	Person p1(10);//p1������Person��Ĺ��캯����thisָ���ָ�����p1
	//cout << "p1�����䣺" << p1.age << endl;

	Person p2(10);
	p2.PersonAddAge(p1).PersonAddAge(p1);
	cout << "p2�����䣺" << p2.age << endl;

	return 0;
}
#endif

#if 0
class Person
{
public:
	void showClassname()
	{
		cout << "showClassname" << endl;
	}

	void showPersonAge()
	{
		cout << "showPersonAge" << _age << endl;
	}

	//����
	/*void showPersonAge()
	{
		if (this->NLL)
			return NULL;
		cout << "showPersonAge" << _age << endl;
	}*/
	int _age;
};

int main()
{
	Person * p1 = NULL;
	//p1->showClassname();//ok
	p1->showPersonAge();//err ��Ϊthisָ��ָ��Ϊ�գ�_age�ڱ���ʱ��������д��this->_age;
	return 0;
}
#endif

#if 0
//������
class Person
{
public:
	//thisָ��ı���  ��ָ�볣�� ָ���ָ���ܱ��޸�
	//const Person * const this;
	//�ڳ�Ա�����������const�����ε�thisָ���ָ���ܱ��޸ģ�ǰ���const���ε���thisָ���ֵ���ܱ��޸�
	void showPerson()const
	{
		//this->_age = 10;//�����޸�
		//this = NULL;//�����޸�
		this->_a = 122;
	}

	int _age;
	mutable int _a;//�����������ʹ�ڳ������У�Ҳ�����޸���ֵ������ؼ���mutable
};

int main()
{
	Person p;
	p.showPerson();

	//������
	const Person p1;
	//p1._age = 1;//���������޸ķǾ�̬��Ա����
	p1._a = 100;//����������޸�mutable���εĳ�Ա����

	//������ֻ�ܵ��ó����������ܵ�����ͨ�ĳ�Ա��������Ϊ��ͨ�ĳ�Ա�������޸�����
	return 0;
}
#endif

class Building
{
	//goodboy��Building�ĺ����ѣ����Է���Building��˽�г�Ա
	friend void goodboy(Building &ba);
public:
	Building()
	{
		SittingRoom = "����";
		BedRoom = "����";
	}

	string SittingRoom;

private:
	string BedRoom; 
	
};

//ȫ�ֺ���
void goodboy(Building &ba)
{
	cout << ba.SittingRoom << endl;
	cout << ba.BedRoom << endl;
}

int main()
{
	Building building;
	goodboy(building);
	return 0;
}