#include <iostream>
#include "stack.cpp"
#include <string>
int main()
{

	stack<int> s1(10);

	// string s;
	// getline(cin, s);
	// int size = s.length();
	// cout << size << endl;
	// for (int i = 0; i < size; i++)
	// {
	// 	if (s[i] != ' ')
	// 	{
	// 		s1.push(s[i]);
	// 	}
	// 	else
	// 	{
	// 		s1.print();
	// 		s1.deletestack();
	// 	}
	// }
	// s1.print();
	 s1.push(10);
	 s1.push(20);
	 s1.push(30);
	 s1.push(40);
	 s1.push(50);
	 s1.push(60);
	 s1.push(70);
	 s1.print();
	 s1.reverse();
	 s1.print();
	// string s = "()()()(()()){}{}(((()))}([])()[]{}{[]}";
	// cout << s1.Valid_Parentheses(s) << endl;

	// string s = "aabbaaccddsssabdehh";
	// string res = s1.RemoveAllAdjacentDuplicatesInString(s);
	// cout << res << endl;

	// int arr[5] = {-1, 3, 2, -5, 4};

	// s1.Asteroid_Collision(arr, 5);
	// s1.printfront();
	// s1.push(1);
	// s1.push(2);
	// s1.push(3);
	// s1.push(4);
	// s1.push(5);
	// int top = s1.get_top();
	// s1.insert_at_bottom(6, top);
	// s1.printfront();

	// string s = "()((())())";

	// cout << s1.Score_of_Parentheses(s) << endl;
	// cout<<"hello"<<endl;
}
