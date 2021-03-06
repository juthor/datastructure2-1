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

bool isOpen(char ch);//오픈괄호 확인하는 함수
bool isClosed(char ch);//닫는괄호 확인하는 함수
bool matches(char ch, char openSymbol);//짝이 맞는지 확인하는 함수


typedef char ItemType;
const int MAX_STACK_SIZE=50;       // 스택의 최대 크기 설정


class Stack
{
	int top;                         // 스택에서 가장 위에 있는 요소의 배열위치
    ItemType data[MAX_STACK_SIZE]; // 요소를 저장하는 배열

public:
    Stack();		                   // 스택 생성자
    ~Stack();                      // 스택 소멸자
    bool isEmpty();				        // 비어있는지 확인하는 함수
    bool isFull();				          // 다 차있는지 확인하는 함수
    void push(char ch);        // 스택에 요소 삽입
    ItemType pop(); 	             // 가장 최근에 스택에 삽입된 요소를 삭제하고 반환
    ItemType peek(); 	             // 가장 최근에 스택에 삽입된 요소를 반환
};


inline void error(char const *message)//에러메세지 출력
{
	cout<< message <<endl;
	exit(1);
}


Stack::Stack(){ top=-1;}//스택 생성자
Stack::~Stack(){}//스택 소멸자

bool Stack:: isEmpty()//비었는지 확인하는 함수
{
	return top == -1;//비어있으면 -1반환
}

bool Stack::isFull()//다 차있는지 확인
{
	return top == MAX_STACK_SIZE-1;//다 차있기 때문에 전체 배열크기-1
}

void Stack::push(char ch)//ch을 stack에 입력
{
	if(isFull())//다 차있으면
	{
		error("스택 Full");
	}
	//data[top++]=e;랑 같은 의미
	else//안차있으므로
	{
		top++;//top을 증가시킴
		data[top]=ch;//ch값을 data[top]에 넣기
	}
}

ItemType Stack::pop()//pop할 함수
{
	if(isEmpty())//비어있으면
	{
		error("스택 Empty");
	}
	return data[top--];//top에서 1을 뺀 값 반환
}

ItemType Stack::peek()
{
	if(isEmpty())
	{
		error("스택 Empty");
	}
	return data[top];//그대로 반환
}



int main()
{
	char ch;//넣을 괄호
	Stack stack;//class stack 선언
	bool balanced = true;//스택이 비어있으면 balanced
	char openSymbol;//오픈괄호 의미


	//파일 filename으로 부터 입력

	while(cin.get(ch) && balanced)//한 문자씩 입력받기
	{
		if (isOpen(ch))//여는괄호일 때
		{
			stack.push(ch);//스택에 저장
		}

		else if(isClosed(ch))//닫는 괄호일 때
		{
			if(stack.isEmpty())//비어있는지 확인, 만약 비어있다면
			{
				balanced=false;//짝이 맞지 않다
			}

			else//비어있지 않다면
			{
				openSymbol=stack.pop();//스택의 pop할 char을 openSymbol에 넣기(왼쪽괄호)
				balanced=matches(ch, openSymbol);//ch와 openSymbol(왼쪽괄호)의 짝이 맞음
			}
		}
	}

	if(!balanced)//짝이 맞지 않으면
	{
		cout<<"-1"<<endl;//-1값 출력
	}

	else if(stack.isEmpty())//스택이 다 비워져있으면 짝이 다 맞다는 말
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




bool isOpen(char ch)//여는 괄호가 들어왔을 때 맞는지 확인하는 함수
{
	if((ch =='(') || (ch =='{')|| (ch == '['))
	{
		return true;//맞으면 참
	}

	else
	{
		return false;//아니면 거짓
	}
}

bool isClosed(char ch)//닫는 괄호가 들어왔을 때
{
	if((ch == ')') || (ch == '}') ||(ch == ']'))
	{
		return true;//이것 중 하나면 참임
	}

	else
	{
		return false;//아니면 거짓
	}
}

bool matches(char ch, char openSymbol)//짝이 맞는지 확인하는 함수
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
