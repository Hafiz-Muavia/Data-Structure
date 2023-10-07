#include <iostream>
#include <iomanip>
using namespace std;

class node {
private:
    int data; // marks
    node* next;
    

public:
	string c_name;
    string c_code;
    node(int, const string&, const string&);
    void setdata(int, const string&, const string&);
    int getdata();
    void setnext(node*);
    node* getnext();
    void showdata();
};

node::node(int d, const string& code, const string& name) {
    setdata(d, code, name);
    next = nullptr;
}

void node::setdata(int d, const string& code, const string& name) {
    data = d;
    c_code = code;
    c_name = name;
}

int node::getdata() {
    return data;
}

void node::setnext(node* ptr) {
    next = ptr;
}

node* node::getnext() {
    return next;
}

void node::showdata() {
    cout << c_code << " : " << c_name << " : " << data << endl;
}

class linklist {
private:
    node* head;
    node* current;
    int size;

public:
    linklist();
    void addnode(int, const string&, const string&);
    void update(int, int);
    void find(int);
    void get(int);
    void remove(int);
    void showlist();
    float gpa_cal();
};

linklist::linklist() {
    head = nullptr;
    current = nullptr;
    size = 0;
}

void linklist::addnode(int d, const string& code, const string& name) {
    node* ptr = new node(d, code, name);

    if (size == 0) {
        head = ptr;
        current = ptr;
    } else {
        ptr->setnext(current->getnext());
        current->setnext(ptr);
        current = ptr;
    }

    size++;
}

void linklist::find(int d) {
    node* ptr = head;
    bool y = false;

    for (int i = 1; i <= size; i++) {
        if (ptr->getdata() == d) {
            cout << "Value is present in the list" << endl;
            y = true;
            break;
        }
        ptr = ptr->getnext();
    }

    if (!y) {
        cout << "Value not found in array" << endl;
    }
}

void linklist::update(int pos, int val) {
    node* ptr = head;

    if (pos > 0 && pos <= size) {
        for (int i = 1; i < pos; i++) {
            ptr = ptr->getnext();
        }
        ptr->setdata(val, ptr->c_code, ptr->c_name);
    } else {
        cout << "Invalid position" << endl;
    }
}

void linklist::get(int pos) {
    node* ptr = head;

    if (pos > 0 && pos <= size) {
        for (int i = 1; i < pos; i++) {
            ptr = ptr->getnext();
        }
        cout << "The value at position " << pos << " in the linked list is " << ptr->getdata() << endl;
    } else {
        cout << "Invalid position" << endl;
    }
}

void linklist::remove(int pos) {
    if (pos < 1 || pos > size) {
        cout << "Invalid position" << endl;
        return;
    }

    if (pos == 1) {
        node* temp = head;
        head = head->getnext();
        delete temp;
        size--;
    } else if (pos == size) {
        node* ptr = head;
        for (int i = 1; i < pos - 1; i++) {
            ptr = ptr->getnext();
        }
        delete ptr->getnext();
        ptr->setnext(nullptr);
        size--;
    } else {
        node* ptr = head;
        for (int i = 1; i < pos - 1; i++) {
            ptr = ptr->getnext();
        }
        node* temp = ptr->getnext();
        ptr->setnext(temp->getnext());
        delete temp;
        size--;
    }
    cout << "Linked list after removing value is: " << endl;
    showlist();
}

float linklist::gpa_cal() {
    if (size == 0) {
        cout << "No courses found for GPA calculation." << endl;
        return 0.0;
    }

    float sum = 0.0;
    node* ptr = head;

    while (ptr != nullptr) {
        int data = ptr->getdata();

        if (data >= 85)
            sum += 4;
        else if (data >= 80)
            sum += 3.7;
        else if (data >= 75)
            sum += 3.3;
         else if(data>=70)
			sum+=3.0;
		else if(data>=65)
			sum+=2.7;
		else if(data>=61)
			sum+=2.3;
		else if(data>=58)
			sum+=2.0;
		else if(data>=55)
			sum+=1.70;
		else if(data>=50)
			sum+=1.0;
        

        ptr = ptr->getnext();
    }

    float gpa = sum / size;
    return gpa;
}

void linklist::showlist() {
    node* ptr = head;

    while (ptr != nullptr) {
        ptr->showdata();
        ptr = ptr->getnext();
    }
}