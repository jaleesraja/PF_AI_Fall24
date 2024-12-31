

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
///////////////////////Contacts managment system/////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;


// ///////////////////////Structure for contacts//////////////////////////////////////
struct Contact
{
    string name;
    long long int pnum;
    void input()
    {
        cout<<"Enter name: ";
        cin.ignore();
        cin.clear();
        getline(cin,name);
        cout<<"Enter phone number: ";
        cin>>pnum;
    }
      void print()
        {
           cout << "Name: " <<name<< endl;
           cout << "Phone: " <<pnum<< endl;
        }
}
  contacts[100] =
{
    {"hassan",  3021900918},
    {"jalil", 3005869945},
    {"hjalil", 3005869949}
};
//////////////////////////////////Function for contact list/////////////////////////////////
void list()
{

            for (int i = 0; i < 100; i++) {
                if (   contacts[i].pnum!=0) {
                    contacts[i].print();


                }
            }
}
//////////////////////////////////funtion for search contact/////////////////////////////////
void search();
///////////////////////////////Function to delete contact////////////////////////////////////
void deleteContact(int count);
///////////////////////////////////Function to add a new contact/////////////////////////////
void add(int count)
{
   contacts[count].input();
}


//////////////////////////////Start Main function////////////////////////////////////////////
int main()
 {
    int count = 3;
    int choice;
    char choice2;

    do {
        cout << "\t1. Contact list "<< endl;
        cout << "\t2. Search contact" << endl;
        cout << "\t3. Add new contact" << endl;
        cout << "\t4. To Delete a contact "<< endl;
        cin>>choice;
        switch (choice) {
        case 1:
            list();
        	   break;
        case 2:
             search();
             break;
        case 3:
            // Add a new contact
            add(count);
        cout<<"contact added";
        count++;
            break;
        case 4:
             deleteContact(count);
             break;

        default:
              cout<<"Wrong choice:\n";
            break;
        }

        cout<<"\n\nPress Y to continue ";
    cin>>choice2;
    } while (toupper(choice2) == 'Y');

    return 0;
}
///////////////////////////////End of Main function/////////////////////////////////////////



////////////////////////////funtion for search contact//////////////////////////////////////

 void search(){
    string toSearch;
    bool status = false;

            status = false;
            cout<<"Enter Name to Search: ";
                   cin>>toSearch;
            for (int i = 0; i < 100; i++) {
                if (contacts[i].name == toSearch) {
                    contacts[i].print();
                    status = true;
                    break;
                }
            }
            if (!status) {
                cout << "Contact not found" << endl;
            }

 }

///////////////////Function for Delete contact///////////////////////////
void deleteContact(int count)
{
       string name;
       int i;
       cout<<"\n\nEnter Name of the contact you want to delete: ";
       cin.ignore();
       cin.clear();
       getline(cin,name);
       for(i = 0;i<count;i++)
    {
            if(contacts[i].name == name)
        {
                for(int j = i;j<count;j++)
            {
                contacts[j] = contacts[j+1];
            }
                count--;
                cout<<"Contact Deleted ..";
                break;
        }
    }
      if(i == count)
      cout<<"Contact not found..";
}

//////////////////////////////////////////////////////////////////////////////////
