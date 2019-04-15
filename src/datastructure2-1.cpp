//============================================================================
// Name        : datastructure2-1.cpp
// Author      : Hyunju Kim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

bool isOpen(char ch);//���°�ȣ Ȯ���ϴ� �Լ�
bool isClosed(char ch);//�ݴ°�ȣ Ȯ���ϴ� �Լ�
bool matches(char ch, char openSymbol);//¦�� �´��� Ȯ���ϴ� �Լ�


typedef char ItemType;
const int MAX_STACK_SIZE=50;       // ������ �ִ� ũ�� ����


class Stack
{
	int top;                         // ���ÿ��� ���� ���� �ִ� ����� �迭��ġ
    ItemType data[MAX_STACK_SIZE]; // ��Ҹ� �����ϴ� �迭

public:
    Stack();		                   // ���� ������
    ~Stack();                      // ���� �Ҹ���
    bool isEmpty();				        // ����ִ��� Ȯ���ϴ� �Լ�
    bool isFull();				          // �� ���ִ��� Ȯ���ϴ� �Լ�
    void push(char ch);        // ���ÿ� ��� ����
    ItemType pop(); 	             // ���� �ֱٿ� ���ÿ� ���Ե� ��Ҹ� �����ϰ� ��ȯ
    ItemType peek(); 	             // ���� �ֱٿ� ���ÿ� ���Ե� ��Ҹ� ��ȯ
};


inline void error(char const *message)//�����޼��� ���
{
	cout<< message <<endl;
	exit(1);
}


Stack::Stack(){ top=-1;}//���� ������
Stack::~Stack(){}//���� �Ҹ���

bool Stack:: isEmpty()//������� Ȯ���ϴ� �Լ�
{
	return top == -1;//��������� -1��ȯ
}

bool Stack::isFull()//�� ���ִ��� Ȯ��
{
	return top == MAX_STACK_SIZE-1;//�� ���ֱ� ������ ��ü �迭ũ��-1
}

void Stack::push(char ch)//ch�� stack�� �Է�
{
	if(isFull())//�� ��������
	{
		error("���� Full");
	}
	//data[top++]=e;�� ���� �ǹ�
	else//���������Ƿ�
	{
		top++;//top�� ������Ŵ
		data[top]=ch;//ch���� data[top]�� �ֱ�
	}
}

ItemType Stack::pop()//pop�� �Լ�
{
	if(isEmpty())//���������
	{
		error("���� Empty");
	}
	return data[top--];//top���� 1�� �� �� ��ȯ
}

ItemType Stack::peek()
{
	if(isEmpty())
	{
		error("���� Empty");
	}
	return data[top];//�״�� ��ȯ
}



int main()
{
	char ch;//���� ��ȣ
	Stack stack;//class stack ����
	bool balanced = true;//������ ��������� balanced
	char openSymbol;//���°�ȣ �ǹ�


	//���� filename���� ���� �Է�

	while(cin.get(ch) && balanced)//�� ���ھ� �Է¹ޱ�
	{
		if (isOpen(ch))//���°�ȣ�� ��
		{
			stack.push(ch);//���ÿ� ����
		}

		else if(isClosed(ch))//�ݴ� ��ȣ�� ��
		{
			if(stack.isEmpty())//����ִ��� Ȯ��, ���� ����ִٸ�
			{
				balanced=false;//¦�� ���� �ʴ�
			}

			else//������� �ʴٸ�
			{
				openSymbol=stack.pop();//������ pop�� char�� openSymbol�� �ֱ�(���ʰ�ȣ)
				balanced=matches(ch, openSymbol);//ch�� openSymbol(���ʰ�ȣ)�� ¦�� ����
			}
		}
	}

	if(!balanced)//¦�� ���� ������
	{
		cout<<"-1"<<endl;//-1�� ���
	}

	else if(stack.isEmpty())//������ �� ����������� ¦�� �� �´ٴ� ��
	{
		cout<<"1"<<endl;
	}

	else
	{
		cout<<"-1"<<endl;
	}

	//sIN.close();
	return 0;
}




bool isOpen(char ch)//���� ��ȣ�� ������ �� �´��� Ȯ���ϴ� �Լ�
{
	if((ch =='(') || (ch =='{')|| (ch == '['))
	{
		return true;//������ ��
	}

	else
	{
		return false;//�ƴϸ� ����
	}
}

bool isClosed(char ch)//�ݴ� ��ȣ�� ������ ��
{
	if((ch == ')') || (ch == '}') ||(ch == ']'))
	{
		return true;//�̰� �� �ϳ��� ����
	}

	else
	{
		return false;//�ƴϸ� ����
	}
}

bool matches(char ch, char openSymbol)//¦�� �´��� Ȯ���ϴ� �Լ�
{
	if(((openSymbol == '(') && ch == ')') || ((openSymbol == '{') && ch == '}') || ((openSymbol == '[') && ch == ']'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
