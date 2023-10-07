#include<iostream>

using namespace std;
int limit[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *m[13]={"null","January","February","March","April","May","June","July","August","September","October","November", "December"};
class date
{
	private:
			int day;
			int month;
			int year;
	public:
			date();
			date(int,int,int);
			void setDate(int,int,int);
			void setDay(int);
			void setMonth(int);
			void setYear(int);
			int getDay();
			int getMonth();
			int getYear();
			void printDate();
};
date::date()
{
}
date::date(int d,int m,int y)
{
		
		setMonth(m);
		setYear(y);
		setDay(d);
}
void date::setDay(int d)
{
		day = ((d>=1&&d<=limit[this->getMonth()])?d:1);
		if(this->getYear()%4==0&&this->getMonth()==2)
			day=((d>=1&&d<=29)?d:1);
}
void date::setMonth(int m)
{
		month =((m>=1&&m<=12)?m:1);
}
void date::setYear(int y)
{
		year = ((y>=1900&&y<=2023)?y:1900);
}
int date::getDay()
{
		return day;
}
int date::getYear()
{
		return year;
}
int date::getMonth()
{
		return month;
}
void date::printDate()
{
		cout<<this->getDay()<<":"<<m[this->getMonth()]<<":"<<this->getYear()<<endl;
}

class student
{
		private:
			char * id;
			char *name;
			date dob;
			char g;
		public:
			student();
			student(char *, char *, date, char);
			char getGender();
			void showStudent();
			
};
student::student()
{
}
student::student(char *i, char *n, date d, char gn)
{
		id = i;
		name = n;
		dob = d;
		g = gn;
}
void student::showStudent()
{
		cout<<"ID : "<< id<<endl;
		cout<<"Name : "<< name<<endl;
		cout<<"Date of birth : ";
		dob.printDate();
		cout<<"Gender : "<<g<<endl;
		
}
char student::getGender()
{
		return g;
}
class node
{
		private:
			student data;
			node * next;
		public:
			node(student );
			void setNext(node *);
			node* getNext();
			void showNode();
			student getData();
};

node::node(student d)
{
		data = d;
		next = NULL;
}
void node::setNext(node * ptr)
{
		next = ptr;
}
node* node::getNext()
{
		return next;
}
void node::showNode()
{
		data.showStudent();
}
student node::getData()
{
		return data;
}
class list
{
		private:
				node * head;
				node * current;
				int size;
				int maleCount;
				int femaleCount;
		public:
				list();
				void add(student d);
				void remove();
				void start();
				int getSize();
				void next();
				void showCurrent();
				void showList();
				int getFemaleCount();
				int getMaleCount();
				node* nodeToRemove();
};
list::list()
{
		head = NULL;
		current = NULL;
		size = 0;
}
void list::add(student d)
{
		node *ptr = new node(d);
		if(size == 0)
		{
				head = ptr;
				current = ptr;
				head->setNext(head);
		}
		else
		{
				ptr->setNext(current->getNext());
				current->setNext(ptr);
				current = ptr;
		}
		if(d.getGender()=='M')
		maleCount++;
		if(d.getGender()=='F')
		femaleCount++;
		size++;
}
void list::showList()
{
	node *ptr = head;
	do
	{
		ptr->showNode();
		ptr=ptr->getNext();
	}while(ptr!=head);
}
void list::remove()
{
	 
	node *ptr = current->getNext();
	current->setNext(ptr->getNext());
//	current=ptr->getNext();
	if(ptr==head)
		head=head->getNext();
		
	student s = ptr->getData();
	if(s.getGender()=='M')
	maleCount--;
	if(s.getGender()=='F')
	femaleCount--;
	
	delete ptr;
	size--;
}
void list::start()
{
		current = head;
}
int list::getSize()
{
		return size;
}
void list::next()
{
		current=current->getNext();
}
void list::showCurrent()
{
		current->getNext()->showNode();
}
int list::getFemaleCount()
{
		return femaleCount;
}
int list::getMaleCount()
{
		return maleCount;
}
node* list::nodeToRemove()
{
		return current->getNext();
}
int main()
{
		date d1(15,4,1983);
		
		//s1.showStudent();
		date d2(15,5,1983);
		
		//s2.showStudent();
		student s1("MCSF02E001","Ali", d2,'M');
		student s2("MCSF02E002","Ahmad", d2,'M');
		student s3("MCSF02E003","Hasan", d2,'M');
		student s4("MCSF02E004","AR", d2,'M');
		student s5("MCSF02E005","IRHA", d2,'F');
		student s6("MCSF02E006","Eshaal", d2,'F');
		student s7("MCSF02E007","Iqra", d2,'F');
		student s8("MCSF02E008","Uzair", d2,'M');
		student s9("MCSF02E009","Salman",d1, 'M');
		student s10("MCSF02E010","Mahnoor Bloach", d2,'F');
		student s11("MCSF02E0011","Ijaz",d1, 'M');
		student s12("MCSF02E0012","Iqbal",d1, 'M');
		student s13("MCSF02E0013","Sharif",d1, 'M');
		student s14("MCSF02E0014","Romaisa",d1, 'F');
		student s15("MCSF02E0015","Aleeha",d1, 'F');
		student s16("MCSF02E0016","Arfa",d1, 'F');
		student s17("MCSF02E017","Khansa",d1, 'F');
		student s18("MCSF02E0018","Hamid",d1, 'M');
		student s19("MCSF02E0019","Meerab",d1, 'F');
		student s20("MCSF02E0020","Ibrahim",d1, 'M');
		student s21("MCSF02E0021","Adil",d1, 'M');	
		student s22("MCSF02E0022","Adnan",d1, 'M');	
		student s23("MCSF02E0023","Rabea",d1, 'F');
		student s24("MCSF02E0024","Asher",d1, 'M');
		student s25("MCSF02E0025","Arif",d1, 'M');
		
		list l;
		l.add(s1);
		l.add(s2);
		l.add(s3);
		l.add(s4);
		l.add(s5);
		l.add(s6);
		l.add(s7);
		l.add(s8);
		l.add(s9);
		l.add(s10);
		l.add(s11);
		l.add(s12);
		l.add(s13);
		l.add(s14);
		l.add(s15);
		l.add(s16);
		l.add(s17);
		l.add(s18);
		l.add(s19);
		l.add(s20);
		l.add(s21);
//		l.add(s22);
//		l.add(s23);
//		l.add(s24);
//		l.add(s25);
		l.start();
		l.showList();
		int i;
		node *ptr;
		student s;
		while(l.getSize()>2)
		{
				for(i=1;i<=3;i++)
				{
						l.next();
				}
				
				ptr = l.nodeToRemove();
				s=ptr->getData();
				if(l.getFemaleCount()==1&&s.getGender()=='F')
				{
					l.next();
					continue;
				}
				if(l.getMaleCount()==1&&s.getGender()=='M')
				{
					l.next();
					continue;
				}
					
				cout<<"student to b removed : --------------"<<endl;
				l.showCurrent();
				l.remove();
		}
		cout<<endl<<endl<<"CR and GR data :-------------------- "<<endl;
		l.showList();
		
}
