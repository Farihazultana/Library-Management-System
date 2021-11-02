#include<iostream>
#include<string>


using namespace std;

struct book
{
	string name;
	int id;
	book *next;
};
struct member
{
	string name;
	int id;
	member *next;
	book *bookList;
};

book *bookHead = new book();
member * memberHead = new member();

int insertBook(book *n, string name, int id)
{
	book *temp = new book();
	temp->next = n->next;
	n->next = temp;

	temp->name = name;
	temp->id = id;

	return 0;
}
int insertMember(member *n, string name, int id)
{
	member *temp = new member();
	temp->next = n->next;
	n->next = temp;

	temp->name = name;
	temp->id = id;
	temp->bookList = new book();
	temp->bookList->next = NULL;

	insertBook(temp->bookList, "Null", 0);

	return 0;
}

int viewBook(book *n)
{
	while (n->next != NULL)
	{
		if (n->next->name != "Null")
		{
			cout << n->next->name << "     " << n->next->id << endl;
		}
		n = n->next;
	}
	return 0;
}

int viewMember(member *n)
{
	while (n->next != NULL)
	{
		cout << n->next->name << "     " << n->next->id << endl;
		n = n->next;
	}
	return 0;
}


int deleteBook(book *n, int id)
{
	while (n->next != NULL)
	{
		if (n->next->id == id)
		{
			book *temp = n->next;
			n->next = n->next->next;
			free(temp);
			return 1;
		}
		n = n->next;
	}
	return 0;
}

int deleteMember(member *n, int id)
{
	while (n->next != NULL)
	{
		if (n->next->id == id)
		{
			member *temp = n->next;
			n->next = n->next->next;
			free(temp);
			return 1;
		}
		n = n->next;
	}
	return 0;
}


int parchaseBook(member *n, book *m, int nID, int mID)
{
	while (n->next != NULL)
	{
		if (n->next->id == nID)
		{
			while (m->next != NULL)
			{
				if (m->next->id == mID)
				{
					insertBook(n->next->bookList, m->next->name, m->next->id);
					deleteBook(bookHead, m->next->id);
					return 1;
				}
				m = m->next;
			}

		}
		n = n->next;
	}
	return 0;
}

int viewBook_Under_A_Member(member *n, int id)
{
	while (n->next != NULL)
	{
		if (n->next->id == id)
		{
			viewBook(n->next->bookList);
			return 1;
		}
		n = n->next;
	}
	return 0;
}

int returnBook(member *m, int memberID, int bookID)
{
	while (m->next != NULL)
	{
		if (m->next->id == memberID)
		{
			book *temp = m->next->bookList;

			while (temp->next != NULL)
			{
				if (temp->next->id == bookID)
				{
					insertBook(bookHead, temp->next->name, temp->next->id);
					
					deleteBook(m->next->bookList, bookID);

					
					return 1;
				}
				temp = temp->next;
			}
		}
		m = m->next;
	}
	return 0;
}

int main()
{
	insertBook(bookHead, "Chem 1", 101);
	insertBook(bookHead, "Chem 3", 1043);
	insertBook(bookHead, "Chem 10", 123);
	insertBook(bookHead, "Chem 15", 128);
	insertBook(bookHead, "Chem 21", 154);

	insertMember(memberHead, "Fariha", 001);
	insertMember(memberHead, "Nabila", 003);
	insertMember(memberHead, "Samiha", 006);
	insertMember(memberHead, "Sabila", 005);
	insertMember(memberHead, "Radiah", 007);


	/*parchaseBook(memberHead,bookHead,003,123);
	viewBook_Under_A_Member(memberHead,003);
	cout << "Hi\n";

	cout << "Before Return\n";
	viewBook(bookHead);
	viewBook_Under_A_Member(memberHead,003);
	returnBook(memberHead,003,123);
	cout << "After Return" << "\n";
	viewBook_Under_A_Member(memberHead,003);
	viewBook(bookHead);*/


	int command;

	while (1)
	{
		cout << "1.Insert Book\n2.View Book\n3.Delete book\n4.Add Member\n5.View Member\n6.Delete Member\n7.Give a book to student\n8.View Book Under a student\n9.To return A book\n\n0.Exit\n\n";


		cin >> command;
		if (command == 0)
		{
			break;
		}

		if (command == 1)
		{
			string name;
			int id;

			cout << " Insert Name and Id in seperate line: ";

			getchar();
			getline(cin, name);
			cin >> id;

			insertBook(bookHead, name, id);
		}
		else if (command == 2)
		{
			viewBook(bookHead);
		}
		else if (command == 3)
		{
			int id;
			cout << " Insert  Id: ";

			cin >> id;

			deleteBook(bookHead, id);
		}
		if (command == 4)
		{
			string name;
			int id;

			cout << " Insert Name and Id in seperate line: ";

			getchar();
			getline(cin, name);
			cin >> id;

			insertMember(memberHead, name, id);
		}
		else if (command == 5)
		{
			viewMember(memberHead);
		}
		else if (command == 6)
		{
			int id;
			cout << " Insert  Id: ";

			cin >> id;

			deleteMember(memberHead, id);
		}
		else if (command == 7)
		{
			int bookId, memberID;

			cout << "Enter Member id:";
			cin >> memberID;
			cout << "Enter Book id:";
			cin >> bookId;

			parchaseBook(memberHead, bookHead, memberID, bookId);
		}

		else if (command == 8)
		{
			int memberID;
			cout << "Enter Member id:";
			cin >> memberID;

			viewBook_Under_A_Member(memberHead, memberID);
		}
		else if (command == 9)
		{
			int memberId, bookID;
			cout << "Enter Member id:";
			cin >> memberId;
			cout << "Enter Book Id:";
			cin >> bookID;

			returnBook(memberHead, memberId, bookID);
		}

		cout << endl;
	}

}

