#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<vector>

using namespace std;

COORD coord = {0, 0};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


class revenue
{
	private:
		
		static double trevenue;
		
	public:
		double revenueproduct;
		revenue()
		{
			revenueproduct=0;
		}
		void setrevenueproduct(double a)
		{
			revenueproduct=a;
		}
		void calculatetotalrevenue()
		{
			
		}
		double caltrevenue()
		{
			int a;double b,c;
			ifstream fptr;
    		fptr.open("revenue.txt");
			while (fptr >> a  >> b >> c  >>  revenueproduct) 
    		{
        		trevenue+=revenueproduct;
    		}
    		fptr.close();
   			getch();
		}
		static double gettrevenue()
		{
			return trevenue;
		}
};
class product:public revenue
{
	private:
		
		int barcode;
		char productname[50];
		char available;
		static int noofproducts;
		
	protected:
		
		double costprice;
		double saleprice;
		double quan;
		double totalsalesofproduct;
		
	public:
		product()
		{
			totalsalesofproduct=0;
			noofproducts++;
		}
		
		int getbarcode()
		{
			return barcode;
		}
		
		char* getname()
		{
			return productname;
		}
		
		double getprice()
		{
			return saleprice;
		}
		
		double gettotalsalesofproduct()
		{
			return totalsalesofproduct;
		}
		void seeproducts()
		{
			product nproduct;
    		cout << endl << endl <<endl << "\t\tDISPLAY ALL PRODUCTS !!!" << endl << endl; 
    		
			ifstream fptr;
    		fptr.open("ProductInventory.txt",ios::in|ios::app);
    		
			while (fptr >> nproduct.barcode >> nproduct.productname >> nproduct.quan >> nproduct.costprice >> nproduct.saleprice >> nproduct.totalsalesofproduct>>nproduct.available) 
    		{
        		nproduct.show_product();
        		cout << "\n\n====================================\n";
    		}
    		fptr.close();
   			getch();
		}
		void restockproduct()
		{
			int no, found = 0;
   			product nproduct;
   			fstream fptr;
    		cout << "\n\n\tTo Modify ";
    		cout << "\n\n\tPlease Enter The Product No. of The Product";cin >> no;
   			ofstream temp;
   			temp.open("temp.txt");
    		fptr.open("ProductInventory.txt", ios:: in | ios::out| ios::binary);
    		while (fptr >> nproduct.barcode >> nproduct.productname >> nproduct.quan >> nproduct.costprice >> nproduct.saleprice >> nproduct.totalsalesofproduct>>nproduct.available && found == 0) 
    		{
        		if (nproduct.barcode == no)
        		{
        			
            		
					nproduct.show_product();double stock;
            		cout << "\nPlease Enter The quantity of stock arrived for " << nproduct.getname();cin >> stock;
            		nproduct.restockproduct(stock);
            		
					
            		fptr << nproduct.barcode << " " << nproduct.productname << " " <<nproduct.quan << " " <<nproduct.costprice << " " <<nproduct.saleprice << " " <<nproduct.totalsalesofproduct <<" " <<nproduct.available;
            		cout << "\n\n\t Record Updated";
            		found = 1;
        		}
        		temp << nproduct.barcode << " " << nproduct.productname << " " <<nproduct.quan << " " <<nproduct.costprice << " " <<nproduct.saleprice << " " <<nproduct.totalsalesofproduct <<" " <<nproduct.available;
    		}
    		fptr.close();
    		temp.close();
    		remove("ProductInventory.txt");
    		rename("temp.txt","ProductInventory.txt");
    		if (found == 0)
        		cout << "\n\n Record Not Found ";
    		getch();	
		}
		
		void restockproduct(double a)
		{
			quan+=a;
			available = ( quan > 0 ) ? 'y' : 'n';
		}
		
		void addproduct()
		{
			cout << "Enter Product details: " << endl;
			cout << "Enter Barcode: "; 
			cin >> barcode;
			fflush(stdin);
			cout << "Enter Product Name: "; 
			cin>>productname;
			fflush(stdin);
			cout << "Enter Cost Price: ";
			cin >> costprice;
			fflush(stdin);
			cout << "Enter Sale Price: ";
			cin >> saleprice;
			fflush(stdin);
			cout << "Enter Quantity: ";
			cin >> quan;
			fflush(stdin);
			available = ( quan > 0 ) ? 'y' : 'n';
			totalsalesofproduct=0;
			noofproducts++;
		}
		void addproduct(int a)
		{
			product nproduct;
			nproduct.addproduct();
			ofstream fptr;
			fptr.open("ProductInventory.txt",ios::app);
			
			if(!fptr)
			{
				cout << "File doesn't exist.";
			}
			else
			{	
				fptr << nproduct.barcode << " " << nproduct.productname << " " <<nproduct.quan << " " <<nproduct.costprice << " " <<nproduct.saleprice << " " <<nproduct.totalsalesofproduct <<" " <<nproduct.available;
			}
			
			fptr.close();
			char ans;
			cout << "Do you want to add more new products(y for yes and n for no):";cin >> ans;
			
			if(ans=='y'|| ans=='Y')
			{
				addproduct(a);
			}
			else if(ans=='n' || ans=='N')
			{
				return;
			}
		}
		void show_product()
		{
			cout << "Product details: " << endl;
			cout << "Barcode: " <<  barcode << endl;
			cout << "Product Name: "; puts(productname);
			cout << "Price: " << saleprice << endl;
			cout << "Quantity: " << quan << endl;
			cout << "Available:"  << available << endl;
		}
		void show_product(int a)
		{
			cout << "Barcode: " <<  barcode << endl;
			cout << "Product Name: "; puts(productname);
			cout << "Cost Price: " << costprice << endl;
			cout << "Sale Price: " << saleprice << endl;
			cout << "Quantity Available: " << quan << endl;
			cout << "Total Product Sold: " << totalsalesofproduct << endl;
			
			
		}
		void settotalsalesofproduct(double a)
		{
			quan=quan-a;
			totalsalesofproduct+=a;
		}
		void modifyproduct()
		{
			int no, found = 0;
   			product nproduct;
   			fstream fptr;
    		cout << endl << "Modifying the Product:";
    		cout << endl << endl << "Please Enter The Barcode of The Product:";cin >> no;
    		ofstream temp;
    		temp.open("temp.txt");
    		fptr.open("ProductInventory.txt", ios:: in | ios::out);
    		while (fptr >> nproduct.barcode >> nproduct.productname >> nproduct.quan >> nproduct.costprice >> nproduct.saleprice >> nproduct.totalsalesofproduct>>nproduct.available && found == 0) 
    		{
        		if (nproduct.barcode == no) 
        		{
            		nproduct.show_product();
            		cout << "\nPlease Enter The New Details of Product" << endl;
            		nproduct.addproduct(0,0);
            		fptr << nproduct.barcode << " " << nproduct.productname << " " <<nproduct.quan << " " <<nproduct.costprice << " " <<nproduct.saleprice << " " <<nproduct.totalsalesofproduct <<" " <<nproduct.available;
            		cout << "\n\n\t Record Updated";
            		found = 1;
        		}
        		temp << nproduct.barcode << " " << nproduct.productname << " " <<nproduct.quan << " " <<nproduct.costprice << " " <<nproduct.saleprice << " " <<nproduct.totalsalesofproduct <<" " <<nproduct.available;
    		}
    		fptr.close();
    		temp.close();
    		remove("ProductInventory.txt");
    		rename("temp.txt", "ProductInventory.txt");
    		if (found == 0){
        		cout << "\n\n Record Not Found ";
        	}
    		getch();
		}
		
		void addproduct(int a,int b)
		{
			cout << "Enter Product details: " << endl;
			cout << "Enter Barcode: " << barcode << endl;
			fflush(stdin);
			cout << "Enter Name: " << productname << endl;
			fflush(stdin);
			cout << "Enter Cost Price: ";
			cin >> costprice;
			fflush(stdin);
			cout << "Enter Sale Price: ";
			cin >> saleprice;
			fflush(stdin);
			cout << "Enter Quantity: ";
			cin >> quan;
			fflush(stdin);
			available = ( quan > 0 ) ? 'y' : 'n';
			noofproducts++;
		}
		void deleteproduct()
		{
			int no;
   			product nproduct;
   			cout << "\n\n\n\tDelete Record";
    		cout << "\n\nPlease Enter The product no. of The Product You Want To Delete";
    		cin >> no;
    		fstream fptr1;
    		fptr1.open("ProductInventory.txt", ios:: in | ios::out);
    		fstream fptr2;
    		fptr2.open("Temporary.txt", ios::out);
    		fptr1.seekg(0, ios::beg);
    		while (fptr1 >> nproduct.barcode >> nproduct.productname >> nproduct.quan >> nproduct.costprice >> nproduct.saleprice >> nproduct.totalsalesofproduct>>nproduct.available) 
    		{
        		if (nproduct.barcode != no) 
        		{
            		fptr2 << nproduct.barcode << " " << nproduct.productname << " " <<nproduct.quan << " " <<nproduct.costprice << " " <<nproduct.saleprice << " " <<nproduct.totalsalesofproduct <<" " <<nproduct.available;
        		}
    		}
    		fptr2.close();
    		fptr1.close();
    		remove("ProductInventory.txt");
    		rename("Temporary.txt", "ProductInventory.txt");
    		cout << endl << endl << "\tRecord Deleted ..";
    		getch();
		}
		double calculaterevenueofproduct()
		{
			ofstream fptr;
			fptr.open("revenue.txt");
			revenueproduct	= totalsalesofproduct*(saleprice-costprice);
			fptr << barcode << " " << totalsalesofproduct << " " << saleprice << " " <<  revenueproduct;
			cout << "Total revenue is:" << revenueproduct;
			fptr.close();
			return revenueproduct;
		}
		void menu() 
		{
		    fstream fptr;
		    product nproduct;
		    fptr.open("ProductInventory.txt", ios:: in );
		    if (!fptr) 
		    {
		        cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File ";
		        cout << "\n\n\n Program is closing ....";
		        getch();
		    }
		
		    while (fptr >> nproduct.barcode >> nproduct.productname >> nproduct.quan >> nproduct.costprice >> nproduct.saleprice >> nproduct.totalsalesofproduct>>nproduct.available) 
		    {
		        nproduct.show_product();
		    }
		    fptr.close();
		}
		void printingsystem(){
			vector<int>orderbr;
			vector<double>quantity;
			int j = 0,c=0;
    		double amount, total = 0;
    		char ch = 'Y';
    		int found;
    		product::menu();
    		cout << "\n============================";
    		cout << "\n PLACE YOUR ORDER";
    		cout << "\n============================\n";
    		int a,b;
    		do 
    		{
        		cout << "\n\nEnter The Barcode Of The Product : ";
        		cin >> a;
        		cout << "\nQuantity in number : ";
        		cin >> b;
        		for(int i=0;(i<orderbr.size()) && (orderbr.size()!=0);i++){
        			if(a==orderbr[i]){
        				quantity[i]+=b;
        				c=1;
        				j++;
					}
				}
				if(c==0){
					orderbr.push_back(a);
					quantity.push_back(b);
				}
        		cout << "\nDo You Want To Order Another Product ? (y/n)";
        		cin >> ch;
    		} while (ch == 'y' || ch == 'Y');
    		cout << "\n\nThank You For Placing The Order";
    		char ac;
    		cout << "\n Do you want to remove any product";cin >> ac;
    		if(ac=='y' || ac=='Y')
			{
    			double b;
    			int c;
    			cout << "Enter barcode :";
				cin >> c;fflush(stdin);
    			cout << "How much quantity to be removed:";
				cin >>b;fflush(stdin);
				for(int i=0;(i<orderbr.size());i++)
				{
        			if(c==orderbr[i])
					{
        				if((b==quantity[i]) || (b>quantity[i]))
						{
        					orderbr[i]=0;
        					quantity[i]=0;
        					break;
						}
						else if(b<quantity[i])
						{
							quantity[i] = quantity[i]-b;
							break;
						}
					}
				}
			}
    		getch();
    		cout << "\n\n******************************** INVOICE ************************\n";
    		cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount";
    		product nproduct;
	   		fstream fptr;
	   		ofstream temp;
	   		temp.open("temp.txt");
	    	fptr.open("ProductInventory.txt", ios:: in | ios::out);
    		for(int x=0;(x<orderbr.size());x++){
	   			
	    		while (fptr) 
	    		{
	    			fptr >> nproduct.barcode >> nproduct.productname >> nproduct.quan >> nproduct.costprice >> nproduct.saleprice >> nproduct.totalsalesofproduct>>nproduct.available;
	        		if (nproduct.barcode == orderbr[x])
	        		{
	            		amount = nproduct.saleprice * quantity[x];
		                cout << "\n" << orderbr[x] << "\t" << nproduct.getname() <<"\t" << b << "\t\t" << nproduct.getprice() << "\t" << amount;
						nproduct.totalsalesofproduct+=quantity[x];
						nproduct.quan=nproduct.quan-quantity[x];
						total += amount;
	            		fptr << nproduct.barcode << " " << nproduct.productname << " " <<nproduct.quan << " " <<nproduct.costprice << " " <<nproduct.saleprice << " " <<nproduct.totalsalesofproduct <<" " <<nproduct.available;
	            		cout << "\n\n\t Record Updated";
	        		}
	        		temp << nproduct.barcode << " " << nproduct.productname << " " <<nproduct.quan << " " <<nproduct.costprice << " " <<nproduct.saleprice << " " <<nproduct.totalsalesofproduct <<" " <<nproduct.available;
	    		}
	    		
	    		getch();
			}
			
			fptr.close();
	    	temp.close();
	    	remove("ProductInventory.txt");
	    	rename("temp.txt","ProductInventory.txt");
    		cout << "\n\n\t\t\t\t\tTOTAL = " << total;
    		cout << "\n\n\t\t\t\tWith Tax= " << (total +(total*0.13));
    		getch();
		}
		void displaysearchproduct(int n) 
		{
			fstream fptr;
			product nproduct;
		    int flag = 0;
		    fptr.open("ProductInventory.txt", ios:: in );
		    while (fptr >> nproduct.barcode >> nproduct.productname >> nproduct.quan >> nproduct.costprice >> nproduct.saleprice >> nproduct.totalsalesofproduct>>nproduct.available) 
		    {
		        if (nproduct.getbarcode() == n) 
		        {
		            nproduct.show_product(0);
		            cout << "The total revenue of this product is :" << nproduct.calculaterevenueofproduct();
		            flag = 1;
		        }
		    }
		    fptr.close();
		    if (flag == 0)
		        cout << "\n\nRecords do not exist";
		    getch();
		}
};

int product :: noofproducts=0;

double revenue :: trevenue =0;
 

class employees:public product
{
	protected:
		
		string username;
		string password;
		
	public:
/*		int compare(char a[],char b[])
		{
    		for(int i=0;a[i]!='\0';i++)
			{
        		if(a[i]!=b[i])
            		return 0;
    		}
    		return 1;
		}*/
		void employeelogin()
		{
			employees e;
			string u,p;
			fflush(stdin);
			cout << "Username: " ;
			getline(cin,u);
			fflush(stdin);
			cout << "Password: ";
			getline(cin,p);
			fflush(stdin);

			ifstream fp;
    		fp.open("Employeepassword.txt");
    		
    		while (fp) 
    		{
    			int flag=0;
    			fp>>e.username;
				fp>> e.password;
        		if((strcmp(e.username.c_str(),u.c_str())==0) && (strcmp(e.password.c_str(),p.c_str()))==0)
				{
        			flag=1;
				}else
				{
					flag=0;
				}
				if(flag==1)
				{
        			employeemenu();
				}else
				{
					cout << endl << "This account does not exist";
				}
        			cout << "\n\n====================================\n";
    		}
    		fp.close();
		} 
		
		
		void employeemenu()
		{
			int choice;
	        cout << "press 1 to see Products Data" << endl;
	        cout << "press 2 to Add product" << endl ;
	        cout << "press 3 to restock a product" << endl;
	        cout << "press 4 to modify a product" << endl;
	        cout << "press 5 to delete a product" << endl;
	        cout << "press 6 to print bill" << endl;
	        cout << "press 7 to LOG OUT!" << endl << endl << endl;
	        cout << "Enter your choice: ";
	        cin >> choice;
	        switch(choice)
			{
	        	case 1:
				{
	        		seeproducts();
					break;
				}
				case 2:
				{
	        		addproducts();
					break;
				}
				case 3:
				{
	        		restockproduct();
					break;
				}
				case 4:{
					modifyproduct();
					break;
				}
				case 5:
				{
	        		deleteproduct();
					break;
				}
				case 6:{
					printingsystem();
					break;
				}
				case 7:
				{
	        		logoutaccount();
					break;
				}	
			}
		}
		
		void newaccount()
		{
			employees A;
			fflush(stdin);
			cout << "Enter username: ";
			cin>>A.username;
			fflush(stdin);
			cout << "Enter Password: ";
			cin>>A.password;
			fflush(stdin);
			ofstream fptr;
			fptr.open("Employeepassword.txt",ios::app);
			if(!fptr)
			{
				cout << "File doesn't exist.";
			}
			else
			{	
				fptr << A.username <<" "<< A.password << " ";
			}
			fptr.close();
		}
		
		void seeproducts()
		{
			product :: seeproducts();
		}
		
		void addproducts()
		{
			product :: addproduct(0);
		}
		void restockproduct()
		{
			product :: restockproduct();
		}
		
		void modifyproduct()
		{
			product :: modifyproduct();
		}
		
		void deleteproduct()
		{
			product :: deleteproduct();
		}
		
		void printingsystem()
		{
			product::printingsystem();
		}
		void logoutaccount()
		{
			cout << "YOU HAVE LOGGED OUT KNOW!";
		}
};
class admin:public employees
{
	private:
		
		static string ausername;
		static string apassword;
		static string aname;
		
	public:
		
		admin()
		{
			
		}
		
		admin(const admin &A)
		{
			
			ofstream fptr;
			fptr.open("Admin.txt");
			if(!fptr)
			{
				cout << "File doesn't exist.";
			}
			else
			{	
				fptr.write((char*)&A,sizeof(A));
			}
			fptr.close();
		}
		
		void adminlogin()
		{
			string u,p;
			cout << "Username: " ;cin >> u;
			cout << "Password: ";cin >> p;
			
			if(u==ausername && p==apassword)
			{
				adminmenu();
			}
			else
			{
				cout << endl << "Your username or password is incorrect";	
			}
			
		} 
		
		void adminmenu()
		{
			int a;
			cout << "Press 1 to see revenue generated by a product." << endl;
			cout << "Press 2 to see total revenue generated." << endl;
			cout << "Press 3 to add a new employee account." << endl;
			cout << "Press 4 to see products." << endl;
			cout << "Press 5 to logout" << endl;
			cout << "Choice:";cin >> a;
			switch(a)
			{
				
				case 1:
				{
					int a;
					cout << "Enter the barcode of the code:";
					cin >> a;
					displaysearchproduct(a);
					break;
				}
				case 2:
				{
					revenue::caltrevenue();
					cout << "Total revenue generated is: " << revenue::gettrevenue();
					break;
				}
				case 3:
				{
					newaccount();
					break;
				}
				case 4:
				{
					product :: seeproducts();
					break;
				}
				case 5:
				{
					logoutaccount();
					break;
				}
			}
			
		}
		void displaysearchproduct(int n) 
		{
			product::displaysearchproduct(n);
		}
		void calculaterevenueofproduct()
		{
			product :: calculaterevenueofproduct();
			
		}
		
		
		void newaccount()
		{
			employees :: newaccount();
		}
		
		void logoutaccount()
		{
			cout <<"YOU HAVE LOGGED OUT";
			
		}
};
string admin :: ausername = "Mughal";
string admin :: apassword = "123";
string admin :: aname = "Qasim";

class loginlogout:public admin
{	
	public:
		
		void loginaccount()
		{
			int ans;
			cout << "\n Please Select an Option: " << endl;
			cout << "1.Admin" << endl;
			cout << "2.Employee" << endl;
			cout << "Your Option:";cin >> ans;
			
			switch(ans)
			{
				case 1:
				{
					admin A;
					A.adminlogin();
					break;
				}
				case 2:
				{
					employees A;
					A.employeelogin();
					break;
				}
			}
			loginaccount();
		}
		
};
int main()
{
	gotoxy(47,25);
    cout <<"SUPER MARKET MANAGMENT SYSTEM";
    gotoxy(50,26);
    cout <<"\tPRJOECT OOPS \n";
    gotoxy(50,27);
	cout <<"ABDUL HADI 21K-3274 \n";
	gotoxy(50,28);
	cout <<"AGHA GULHASSAN 21K-3444 \n";
	gotoxy(50,29);
	cout <<"QASIM ASHFAQ 21K-4901\n";
    getch();
	loginlogout obj;
	obj.loginaccount();
}

