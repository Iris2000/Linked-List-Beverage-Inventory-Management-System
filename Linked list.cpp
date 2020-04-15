#include<conio.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<dos.h>
#include<cctype>
#include<sstream>
#include<string>
#include<cstring>

using namespace std;
bool check = true;
bool checkAdd = false;
struct node    //structure of the node
{
	string name;
	string price;
	string supName;
	int quan;
	node *next;

}*head,*lastptr;

void add()    //Add record
{
	node *prev=NULL;
	node *current=NULL;
	bool check = true;
	string beverage,supplier;
	int qty;
	char con;
	cout<<"You are currently in the add data page!\n";

	do{
		prev =head;
		current =head;
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
		do{
			cout<<"\nEnter the name of beverage: ";
			getline(cin, beverage);
			fflush(stdin);
		}while(beverage.length()<=0);
		
		do{
			cout<<"\nEnter the supplier's name: ";
			getline(cin, supplier);
		}while(supplier.length()<=0);
	
		
		for(int i=0; i<beverage.length();i++){
			beverage[i] = toupper(beverage[i]);
		}
		for(int j=0; j<supplier.length();j++){
			supplier[j]= toupper(supplier[j]);
		}
		while(current != NULL && current->name != beverage && current->supName != supplier) {
				prev = current;
				current = current->next;
			}
		if(current != NULL){
			
			if(current->name == beverage && current->supName == supplier){
				cout<<"\nEnter latest price of beverage\nPrevious price[RM "<<current->price<<" ] :RM ";
				cin>>current->price;
				fflush(stdin);
				cout<<"\nEnter the quantity of beverage [ "<<current->quan<<"  instock] : ";
				cin>>qty;
				current->quan = qty+current->quan;
			}else{
				fflush(stdin);
				cout<<"\nEnter price of beverage(RM 00.00): RM ";
				cin>>p->price;
				fflush(stdin);
				cout<<"\nEnter the quantity of beverage: ";
				cin>>p->quan;
				
				p->name = beverage;
				p->supName = supplier;
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
			}
								
		}else{
			fflush(stdin);
			cout<<"\nEnter price of beverage(RM 00.00): RM ";
			cin>>p->price;
			fflush(stdin);
			cout<<"\nEnter the quantity of beverage: ";
			cin>>p->quan;
			
			p->name = beverage;
			p->supName = supplier;
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
			cout<<"\nSupplier's name: ";
		    cout<<current ->supName;
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
			for(int i=0; i<nname.length();i++){
				nname[i] = toupper(nname[i]);
			}
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
				cout<<"\nSupplier's name: ";
				cout<<current->supName;
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
			for(int i=0; i<nname.length();i++){
				nname[i] = toupper(nname[i]);
			}
			
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

//Total amount for each beverage's list
void total_amount_beverage(){
	node *prev=NULL;
	node *current=NULL;
	char con;
	double total=0, subtotal;
	
	cout<<"Total amount for each beverage: "<<endl;
	
	prev=head;
	current=head;

	cout<<"Beverages\t\t\tPrice\t\t\tQuantity\t\t\tSub-total\t\tSupplier's name'"<<endl;
	cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------\n";
	
	while (current!= NULL) {
		double price = atof(current->price.c_str());
		int qty = current->quan;
		
		subtotal = price*qty;
		total = total+subtotal;
		cout<<current->name<<"\t\t\t\t$ "<<price<<"\t\t\t"<<qty<<"\t\t\t\t$ "<<subtotal<<"\t\t\t"<<current->supName;
		cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------\n";
		current = current->next;
	}
	
	cout<<"Total: RM"<<total<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\nDouble Press 'ENTER' return to previous page..."<<endl;
	getch();
}

//Supplier list
void supplier(){
	node *prev=NULL;
	node *current=NULL;
	char con;
	int total=0;
	string name, beverage;
//	char array[30];
	string array[30];
	int i=0;
	bool find = false;
	
	cout<<"Supplier list: "<<endl;
	
	prev=head;
	current=head;

	if(current == NULL){
		
		cout<<"\nThere are no record in the list.\n";
	}
	else{
		while(current!=NULL){
			find = false;
			name= current->supName;
			for (int j = 0; j < name.length(); j++) {
				name[j] = toupper(name[j]);
			}
			
			for (int k = 0; k < 30; k++) {
				if (array[k] == name) {
					find = true;
				}
			}
			
			if (!find) {
				array[i] = name;
				total++;
				cout << "\n"<<total<<". " << array[i];
				beverage=current->name;
				for (int y=0; y<=name.length()+1;y++){
					beverage[y]=toupper(beverage[y]);
				}
				cout <<" - "<<beverage;
			}else{
				beverage = current->name;
				for (int y=0; y<=name.length();y++){
					beverage[y]=toupper(beverage[y]);
				}
				cout<<" / "<<beverage;
			}
			i++;
			current = current->next;
		} 
	}
	cout<<"\nPress 'ENTER' return to previous page..."<<endl;
	getch();
}

//Beverage list
void beverage(){
	node *prev=NULL;
	node *current=NULL;
	char con;
	int total=0, num=0;
	
	cout<<"Beverage list: "<<endl;
	
	prev=head;
	current=head;
		
	cout<<"\nBeverages  |   Price"<<endl;
	cout<<"-------------------\n";
	
	while (current!= NULL) {
		num++;
		total = total+1;
		cout<<num<<". "<<current->name<<"  |  RM"<<current->price<<endl;
		current = current->next;
	}
	cout<<"-------------------\n";
	cout<<"Total Beverages: "<<total<<endl;
	cout<<"\nDouble Press 'ENTER' return to previous page..."<<endl;
	getch();
}

//Supplier & beverage list
void supplier_N_beverage(){
	node *prev=NULL;
	node *current=NULL;
	char con;
	double total=0;
	
	cout<<"Supplier list: "<<endl;
	
	prev=head;
	current=head;
		
	cout<<"Supplier's name\t\t\t\tProduct"<<endl;
	cout<<"-------------------\n";
	
	while (current!= NULL) {
		total = total+1;
		cout<<total<<". "<<current->supName<<"\t\t\t\t("<<current->name<<")"<<endl;
		current = current->next;
	}
	cout<<"-------------------\n";
	cout<<"Total Supplier: "<<total<<endl;
	
	cout<<"\nPress 'ENTER' return to previous page..."<<endl;
	getch();
}

//Total beverage in stock
void beverage_instock(){
	node *prev=NULL;
	node *current=NULL;
	string array[30];
	int qty[30];
	bool same=false;
	char con;
	int total=0, subtotal, num=0;
	
	cout<<"Beverage in stock: "<<endl;
	
	prev=head;
	current=head;
	cout<<"\nBeverages"<<endl;
	cout<<"-------------------\n";
	
	while (current!= NULL) {
		subtotal = current->quan;
		if(subtotal > 0){
			for(int i=0; i<30; i++){
				string n = current->name;
				if(array[i] == n){
					qty[i]= subtotal +qty[i];
					same =true;
				}				
			}
			if(!same){
				array[num]=current->name;
				qty[num]=current->quan;
				num++;
			}
			total = total+subtotal;
			current = current->next;
		}
	}
	if(total>0){
		for(int j=0;j<num;j++){
			cout<<j+1<<". "<<array[j]<<" [ "<<qty[j]<<" ] QTY"<<endl;
		}
		cout<<"\n-------------------\n";
		cout<<"\nTotal Beverage in stock: "<<total<<endl;
	}else{
			cout<<"\nThere are no record in the list.\n";
	}
	
	cout<<"\nPress 'ENTER' return to previous page..."<<endl;
	getch();
}


void report()  // view report
{
	char x;
	node *prev=NULL;
	node *current=NULL;
	prev=head;
	current=head;
	if(current == NULL){
		
		cout<<"\nThere are no record in the list.\n";
	}
	else{
		do{
		system("cls");
		cout<<"REPORT: "<<endl<<endl;
		cout<<"********************************************"<<endl;
		cout<<"*** 1--> Total amount for each beverage  ***"<<endl;
		cout<<"*** 2--> Supplier list                   ***"<<endl;
		cout<<"*** 3--> Beverage list                   ***"<<endl;
		cout<<"*** 4--> Supplier and beverage list      ***"<<endl;
		cout<<"*** 5--> Total beverage in the stock     ***"<<endl;
		cout<<"*** 6--> Exit Report(DOUBLE ENTER)       ***"<<endl;
		cout<<"********************************************"<<endl;
		x=getch();
		if(x=='1')
		{
			system("cls");
			total_amount_beverage();
		}
		else if(x=='2')
		{
			system("cls");
			supplier();
		}
		else if(x=='3')
		{
			system("cls");
			beverage();
		}
		else if(x=='4')
		{
			system("cls");
			supplier_N_beverage();
		}
		else if(x=='5')
		{
			system("cls");
			beverage_instock();
		}
		else if(x=='6')
		{
			break;
		}
		else
		{
		}
		
	}while(x != 27);
	}
	getch();
	cout<<"\nPress 'ENTER' return to previous page..."<<endl;
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
