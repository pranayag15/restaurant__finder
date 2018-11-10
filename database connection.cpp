#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<bits/stdc++.h>
using namespace std;
class vendor
{
	public:
		add_menu();
		delete_menu();
};
class user 
{
	/*public:
		order_food();
		billing();
		food_booking_conformation();
		add_to_cart();
		payment();*/
	public:
		int signup_and_signout(int opti);
		void location_search();
		
};
class Admin:public user
{
	public:
		void delete_user();
		//void make_admin();
		void add_restaurants();
	//	void make_vendor();
};
int user:: signup_and_signout(int option)
{
	if(option==2)
	{
		ofstream fout,pfout;
		char username[30];
	/*	fout.open("username");
		fout.close();
		pfout.open("checker_for_same_username",ios::in);
		pfout.close();*/
		tryagain:
		cout<<"Username:\t";
		cin>>username;
		cout<<"\n";
		cout<<"Password:";
		char password[30];
		cin>>password;
		cout<<"\n";
		strcat(username,password);
		//fout<<username;
	//	fout.close();
	//opening file for reading purpose only hence using ios::in
		ifstream fin,pfin;
		//checking if user exists or not
		fin.open("username",ios::in);
		int check=0;
		char check_username[30];
		int i=0;
		//cout<<username;
		while(fin)
		{
			fin.getline(check_username,10000);
			check=0;
			i=0;
		//	cout<<check_username;
					while(1)
			       {
					//cout<<a[i]<<b[i];
			        if(username[i]!=check_username[i])
			            check=1;
			            if(username[i]=='\0')
			            break;
			            i++;
			       }
				   if(check==0)
				   break;	
		}	
		fin.close();
		if(check==1)
		{
			char answer;
			cout<<"Sorry user not found,do you want to register\n";
			cin>>answer;
			if(answer=='n'||answer=='N')
			goto tryagain;
			cout<<"New to zomato iiit\n";
			cout<<"\nPlease register here\n";
			imp:
			cout<<"enter username\n";
			cin>>username;
			pfin.open("checker_for_same_username",ios::in);
			char checker[30];
			while(pfin)
			{
				pfin.getline(checker,10000);
				if(strcmp(checker,username)==0)
				{
					cout<<"Username already exist";
					pfin.close();
					goto imp;
				}
			}
			fout.open("username",ios::app);
			pfin.close();
			pfout.open("checker_for_same_username",ios::app);
			cout<<"enter password\n";
			cin>>password;
			fout<<username;
			pfout<<username;
			pfout<<endl;
			pfout.close();
			fout<<password;
			fout<<endl;
			cout<<"Hurray you are a customer of zomato iiit ";
			fout.close();
			cout<<"\n redirecting you to login page\n";
			goto tryagain;
		}
		
			cout<<"\n--user found----\n";
			cout<<"Hello, "<<username;
			cout<<"\n";	
			return 2;
	
	}
	if(option==1)
	{
		ofstream open_admin_file;
		/*open_admin_file.open("admins");
		open_admin_file.close();*/
		ifstream read_admin;
		char admin_user[30];
		char check_admin[30];
		read_admin.open("admins",ios::in);
		cout<<"Admin Username: ";
		cin>>admin_user;
		int check=0;
		while(read_admin)
		{
			read_admin.getline(check_admin,10000);
			if(strcmp(admin_user,check_admin)==0)
			check=1;
		}
		if(check==1)
		{
			cout<<"welcome admin";
			return 1;
		}
		else
		{
			cout<<"sorry you are not an admin\n";
			return 0;
		}
	}
}
void Admin::delete_user()
{
	char find_user[30];
	char is_this_the_user[30];
	char searched_user;
	char users[30];
	char copying[30];
	char show_user[30];
	ifstream viewing_users;
	viewing_users.open("checker_for_same_username",ios::in);
	while(viewing_users)
	{
		viewing_users.getline(users,10000);
		strcpy(show_user,users);
		cout<<show_user;
	//	if(users!='\n')
		//cout<<"\n";
		
	}
	viewing_users.close();
	cout<<"Please enter username to delete\n";
	cin>>find_user;
	ifstream delete_user;
	ofstream temporary_delete;
	temporary_delete.open("temporary");
	delete_user.open("checker_for_same_username",ios::in);
	while(delete_user)
	{
		delete_user.getline(is_this_the_user,10000);
		if(strcmp(find_user,is_this_the_user)==0)
		{
			temporary_delete<<'*';
		}
		else
		{
			temporary_delete<<is_this_the_user;
		}
		temporary_delete<<"\n";
    }
    temporary_delete.close();
    delete_user.close();
/*
    ifstream test;
    test.open("temporary",ios::in);
    char jackoff[100];
    while(test)
    {
    	test.getline(jackoff,10000);
    	cout<<jackoff;
	}
	test.close();*/
    ifstream after_temporary_delete_file_created;
    ofstream after_deleted_user;
    after_temporary_delete_file_created.open("temporary",ios::in);
    after_deleted_user.open("checker_for_same_username");
    while(after_temporary_delete_file_created)
    {
    	after_temporary_delete_file_created.getline(copying,10000);
    	after_deleted_user<<copying<<"\n";
	}
	after_temporary_delete_file_created.close();
    after_deleted_user.close();
	cout<<"user deleted\n";
	//ifstream viewing_users;
	viewing_users.open("checker_for_same_username",ios::in);
	while(viewing_users)
	{
		viewing_users.getline(users,10000);
		strcpy(show_user,users);
		cout<<show_user;
		
	}
	viewing_users.close();
   
    
    
    
}
void Admin:: add_restaurants()
{
	char selection;
	char restaurants[30];
	char password_vendor[30];
	string pincode;
	main_men:
	cout<<"Do you want to add restaurants in existing pincode?\n";
	cin>>selection;
	if(selection=='Y'||selection=='y')
	{
		cout<<"enter pincode\n";
		cin>>pincode;
		ofstream open_pincode;
		open_pincode.open(pincode.c_str(),ios::app);
		cout<<"enter restaurants name\n";
		cin>>restaurants;
		open_pincode<<restaurants;
		open_pincode<<"\n";
		open_pincode.close();
		cout<<"\nrestaurant added\n";
		cout<<"please add a tremporary password for vendor to login\n";
		ofstream input_username_for_vendor;
		input_username_for_vendor.open("vendors",ios::app);
		cin>>password_vendor;
		input_username_for_vendor<<pincode<<restaurants<<password_vendor<<"\n";
		input_username_for_vendor.close();
	}
	else
	{
		cout<<"warning!! if pincode already exist then all the data for that pincode will be deleted\n";
		cout<<"enter the pincode\n";
		cin>>pincode;
		ofstream open_pincode;
		open_pincode.open(pincode.c_str());
		open_pincode.close();
		cout<<"new pincode created\n";
		cout<<"pleae go to main menu and type yes\n";
		goto main_men;
	}
	
}
void user :: location_search()
{
	char restaurants[30];
	string pincode;
	string restaurant_name;
	cout<<"enter your pincode\n";
	cin>>pincode;
	ifstream open_restaurants_for_pincode;
	open_restaurants_for_pincode.open(pincode.c_str());
	while(open_restaurants_for_pincode)
	{
		cout<<open_restaurants_for_pincode.getline(restaurants,10000);
		
	}
	open_restaurants_for_pincode.close();
	cout<<"enter restaurants name as above";
	cin>>restaurant_name;
	ifstream open_rest;
	open_rest.open(restaurant_name.c_str(),ios::in);
	string item_name[100];
	string price[100];
	int i=0;
	while(open_rest)
	{
		getline(open_rest,item_name[i],',');
		getline(open_rest,price[i],'\n');
		cout<<item_name[i]<<"-------"<<price[i];
		i++;
		
	}
	char opt;
	open_rest.close();
	cout<<"please select the items from the menu\n";
	cout<<"to add any item press a\n";
	cout<<"to delete any item at any time press d";
	cout<<"\nselect items by their index number\n";
	cout<<"to conform your order press r\n";
	int total=0;
	while(1)
	{
		cin>>opt;
		if(opt=='a'||opt=='A')
		{
			cout<<"enter item number ";
			cin>>i;
			total = total+atoi(price[i].c_str());//int b = atoi(a.c_str());
		}
		if(opt=='d'||opt=='D')
		{
			cout<<"enter item number ";
			cin>>i;
			total = total-atoi(price[i].c_str());
		}
		if(opt=='r'||opt=='R')
		break;
		
	}
	cout<<total;
	
}
int main()
{
	int option;
    Admin a1;
    user u1;
    first_screen:
	cout<<"For admin press 1";
	cout<<"\nfor login and signup press 2";
	//cout<<"\nSkip Login press 3";
	cout<<"\nfor vendor login press 3\n";
	cin>>option;
	int returner;
	switch(option)
	{
		case 1:
			returner = a1.signup_and_signout(option);
			if(returner!=1)
			goto first_screen;
			else
			{
				//start admin options;
				int admin_options;
				admin_options_menu:
				//cout<<"hello admin\n";
				cout<<"press 1 for removing a user\n";
				cout<<"press 2 for adding restaurants\n";
				cout<<"press 3 for signout\n";
				//cout<<"press 3 for adding vendors";
				//cout<<"press 3 for  order food from your own software";
			//	cout<<"press 3 adding or removing admins";
				cin>>admin_options;
				switch(admin_options)
				{
					case 1:
						a1.delete_user();
						goto admin_options_menu;
						break;
					case 2:
						a1.add_restaurants();
						goto admin_options_menu;
						break;
					case 3:
						goto first_screen;
					default:
						goto admin_options_menu;
						break;
				}
			}
			break;
		case 2:
			returner = a1.signup_and_signout(option);
			if(returner!=2)
			goto first_screen;
			else
			{
				int u_option;
				cout<<"\npress 1 to continue";
				cout<<"\npress 2 to signout";
				cin>>u_option;
				switch(u_option)
				{
					case 1:
						u1.location_search();
						break;
					case 2:
						goto first_screen;
				}
				
				//cout<<"\nto clear your previous cart press 2";		
			}
			break;
		default:
			cout<<"option not found\n";
			goto first_screen;
			break;
			
	}
	
	
}
