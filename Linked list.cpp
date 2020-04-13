#include<conio.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<dos.h>
#include<cctype>
#include<sstream>
#include<string>

using namespace std;
bool check = true;
bool checkAdd = false;
struct node    //structure of the node
{
	string name;
	string price;
	int quan;
	node *next;
	
}*head,*lastptr;

void add()    //Add record
{
	bool check = true;
	char con;
	cout<<"You are currently in the add data page!\n";

	do{	
		if(con=='Y')
		{
			system("cls");
			cout<<"Add another beverage record\n";
			cin.ignore();
		}
		else if(checkAdd){
			cin.ignore();
		}
		node *p;
		p=new node;
		
		cout<<"\nEnter the name of beverage: ";
		getline(cin, p->name);
		fflush(stdin);
		cout<<"\nEnter price of beverage(RM 00.00): RM ";
		cin>>p->price;
		fflush(stdin);
		cout<<"\nEnter the quantity of beverage: ";
		cin>>p->quan;
		fflush(stdin);
		p->next=NULL;
		
		if(check)
		{
			head = p;
			lastptr = p;
			check = false;
		}
		else
		{
			lastptr->next=p;
			lastptr=p;
		}
			cout<<endl<<"Record Saved.\nWould you like to add another record? [Y/N]\n";
			cin >> con;
			con = toupper(con);
			while(con != 'Y' && con!= 'N'){
				cout<<endl<<"Invalid input.\nPlease enter again.[Y/N]\n";
				cin >> con;
				con = toupper(con);
			}		
	} while(con=='Y');
	checkAdd = true;
}
	
void view()   //view record list 
{
	node *ptr=NULL;
	node *prev=NULL;
	node *current=NULL;
	
	prev=head;
	current=head;
	
	cout<<"You are currently in the records page!\n";
	
	if(current == NULL)
	{
		cout<<"\nThere are no record in the list";
	}
	else{
		while (current!= NULL) {
			cout<<"\n-----------------------------";
			cout<<"\nName: ";
			cout<<current->name;
			cout<<"\nPrice: RM";
			cout<<current->price;
			cout<<"\nQuantity: ";
			cout<<current->quan;
			cout<<"\n-----------------------------\n";
			current = current->next;
		}
	}
	getch();
}
	
void search()   //search record
{
	node *prev=NULL;
	node *current=NULL;
	string nname;
	char con;
	
	cout<<"You are currently in the search data page!\n";
	 
	do {	
	
		prev=head;
		current=head;
		
		if(current == NULL)
		{
			cout<<"\nThere are no record in the list.\n";
			getch();
		} 
		else
		{
			if(con=='Y')
			{
				system("cls");
				cout<<"Search another beverage record\n";
				cin.ignore();
			}
			else if(checkAdd)
			{
				cin.ignore();
			}
			
			cout<<"\nEnter beverage name to search: ";
			getline(cin, nname);
			cin.clear();
			
			while(current != NULL && current->name != nname) {
				prev = current;
				current = current->next;
			}
			
			if(current == NULL){
				cout << endl << nname << " was not in the list." << endl;
				cout<<"\n\nWould you like to search another record? [Y/N]\n";
				cin >> con;
				con = toupper(con);
				while(con != 'Y' && con!= 'N'){
					cout<<endl<<"Invalid input.\nPlease enter again.[Y/N]\n";
					cin >> con;
					con = toupper(con);
				}		
			}
			else
			{
				cout<<"\n-----------------------------";
				cout<<"\nName: ";
				cout<<current->name;
				cout<<"\nPrice: RM";
				cout<<current->price;
				cout<<"\nQuantity: ";
				cout<<current->quan;
				cout<<"\n-----------------------------";
				cout<<"\n\nWould you like to search another record? [Y/N]\n";
				cin >> con;
				con = toupper(con);
				while(con != 'Y' && con!= 'N'){
					cout<<endl<<"Invalid input.\nPlease enter again.[Y/N]\n";
					cin >> con;
					con = toupper(con);
				}		
			}
		} 
	} while(con == 'Y');
}

void del()    //delete record 
{
	node *ptr=NULL;
	node *prev=NULL;
	node *current=NULL;
	 
	string nname;
	char con;
	
	cout<<"You are currently in the delete data page!\n";

	do{
		prev=head;
		current=head;
		
		if(current == NULL)
		{
			cout<<"\nThere are no record in the list.\n";
			con = 'N';
			getch();
		} 
		else 
		{
			if(con=='Y')
			{
				system("cls");
				cout<<"Delete another beverage record\n";
				cin.ignore();
			}
			else if(checkAdd)
			{
				cin.ignore();
			}
			
			cout<<"\nEnter beverage name to delete: ";
			getline(cin, nname);
			cin.clear();
			
			while(current != NULL && current->name != nname){
				prev = current;
				current = current->next;
			}
			
			if(current == NULL){
				cout << endl << nname << " was not in the list." << endl;
				delete ptr;
				cout<<"\n\nWould you like to delete another record? [Y/N]\n";
				cin >> con;
				con = toupper(con);
				while(con != 'Y' && con!= 'N'){
					cout<<endl<<"Invalid input.\nPlease enter again.[Y/N]\n";
					cin >> con;
					con = toupper(con);
				}		
			}
			else {
				if (current == head && current->next != NULL) 
				{
					cout<<"head";
					delete ptr;
					prev = head;
					head = head->next;
					current = head;
				} 
				else if (current == head && current->next == NULL)
				{
					cout<<"head next null";
					delete ptr;
					head = NULL;
					prev = head;
					current = head;
				}
				else
				{
					cout<<"not head";
					cout<<head->name;
					if (current->next == NULL) {
						delete ptr;
						prev = head;
						current = head;
						head->next = NULL; 
					} 
					else
					{	
						delete ptr;
						prev = head;
						current = head;
					}
				}
				
				cout << "\nThe record of " << nname << " was deleted." << endl;	
				if (current == NULL) 
				{
					cout<<"\nThe list is empty now.\n";
					con = 'N';
					getch();
				}
				else
				{
					cout<<"Would you like to delete another record? [Y/N]\n";
					cin >> con;
					con = toupper(con);
					while(con != 'Y' && con!= 'N'){
						cout<<endl<<"Invalid input.\nPlease enter again.[Y/N]\n";
						cin >> con;
						con = toupper(con);
					}		
				}
			}	
		}
	} while(con=='Y');
}

void report()  // view report
{
	cout<<"********************************************"<<endl;
	cout<<"*** 1--> Total amount for each beverage  ***"<<endl;
	cout<<"*** 2--> Supplier list                   ***"<<endl;
	cout<<"*** 3--> Beverage list                   ***"<<endl;
	cout<<"*** 4--> Supplier and beverage list      ***"<<endl;
	cout<<"*** 5--> Total beverage in the stock     ***"<<endl;
	cout<<"*** 6--> Exit Report                     ***"<<endl;
	cout<<"********************************************"<<endl;
}

int menu(){
	char x;
	cout<<"******************************************"<<endl;
	cout<<"** BEVERAGE INVENTORY MANAGEMENT SYSTEM **"<<endl;
	cout<<"******************************************\n"<<endl;
	system("pause");
	
	do
	{
		system("cls");
		cout<<"*****************************"<<endl;
		cout<<"*** 1--> Add New Record   ***"<<endl;
		cout<<"*** 2--> Delete Record    ***"<<endl;
		cout<<"*** 3--> Search Record    ***"<<endl;
		cout<<"*** 4--> View All Records ***"<<endl;
		cout<<"*** 5--> View Report      ***"<<endl;
		cout<<"*** 6--> Exit System      ***"<<endl;
		cout<<"*****************************"<<endl;
		x=getch();
		if(x=='1')
		{
			system("cls");
			add();
		}
		else if(x=='2')
		{
			system("cls");
			del();
		}
		else if(x=='3')
		{
			system("cls");
			search();
		}
		else if(x=='4')
		{
			system("cls");
			view();
		}
		else if(x=='5')
		{
			system("cls");
			report();
		}
		else if(x=='6')
		{
			exit(0);
		}
		else
		{
		}
	}while(x != 27);
		getch();
}

int main()
{
	menu();
}

