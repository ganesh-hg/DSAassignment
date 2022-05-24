#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 10

// class client data base declaration
class ClientDB;

//class Client  defination
class Client
{
    private:
    //Client info
        int id;
        string Name;
        long long int number;
        int next_prob;
        
    public:
    // default Constructor 
        Client()
        {
            this->id = -1;
            this->Name = "/0";
            this->number = 0;
            this->next_prob = -1;
        }
        //method to get Client data 
        void GetData()
        {
            cout<<"Enter the id of client : "<<endl;
            cin>>id;
            cout<<"Enter the name of client :"<<endl;
            cin>>Name;
            cout<<"Enter the number of client : "<<endl;
            cin>>number;
        }
        //Methos to show client data 
        void ShowData()
        {
            cout<<"The id of client is : "<<id<<endl;

            cout<<"The name of client is : "<<Name<<endl;

            cout<<"The Number of client is : "<<number<<endl;
        } 
    friend class ClientDB;
};
// class ClientDB defination 
class ClientDB
{
    public:
        Client HT[SIZE];          //array of object client 
        int index;
  
    int HashFunction(int id)
    {
        int index = id % SIZE;
        return(index);
    }
    //method to insert a new client record+
    void insert_record()
    {   
        Client c;
        c.GetData();
        index = HashFunction(c.id);
        
        if(HT[index].id == -1)        
        {
            cout<<"NO collision Element inserted at "<<index<<endl;
            HT[index] = c;
            HT[index].next_prob = index + 1;
        }
        else
        {
            int i = index;
            while(HT[i].id != -1)
            {
                i = HT[i].next_prob;        //this state ment will lead us to the next prob
            }
            HT[i] = c;                  //assign the value to empty record location after sloving collision 
            HT[i].next_prob = i + 1;    //increate the next prob
        } 
    }
    void show()
    {
        cout<<"------------------------------------";
        cout<<"\nIndex\tID\tName\t\tNumber\n";
        cout<<"-------------------------------------";
        for(int i = 0; i<SIZE; ++i)
        {
            cout<<i << "\t" <<HT[i].id << "\t" <<HT[i].Name<< "\t\t" <<HT[i].number<<endl;
        }
        cout<<"---------------------------------------";
    }
    void Search_record()
    {
        int i, key;
        cout<<"Enter the idu want to be searched : "<<endl;
        cin>>key;
        
        i = HashFunction(key);
        while(HT[i].id != key && HT[i].id != -1)
        {
            i = HT[i].next_prob;

        }
        if(key == HT[i].id)
        {
            cout<<"The id of client is : "<<HT[i].id<<endl;

            cout<<"The name of client is : "<<HT[i].Name<<endl;

            cout<<"The Number of client is : "<<HT[i].number<<endl;
            return;
        }
        cout<<"client not faund ";
    }
    void Delete_record()
    {
        int i, key, prev;
        cout<<"Enter the id you want to be Delete : "<<endl;
        cin>>key;
        
        i = HashFunction(key);
        while(HT[i].id != key && HT[i].id != -1)
        {
            i = HT[i].next_prob;

        }
        if(key == HT[i].id)
        {
            prev = i-1;
           cout<<"Deleting ....."<<HT[i].id;
           HT[prev].next_prob = HT[i].next_prob;
           HT[i].id  = -1;
           HT[i].Name = " ";    
           HT[i].number = 0;
           
           return;
        }
        cout<<"client not faund ";
    }

};
int main(void)
{
    int y, s, choice;
    bool flag = true;
    ClientDB c;
    while (flag)
    {
        cout << "\n____LIST_____\n";
        cout << "\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            c.insert_record();
            cout << endl;
            break;
        case 2:
            c.Search_record();
            cout << endl;
            break;
        case 3:
            c.Delete_record();
            cout << endl;
            break;
        case 4:
            c.show();
            cout << endl;
            break;
        case 5:
            exit(0);
            break;
        }
        char flag2;
        cout << "Do you want to continue(y or n) :" << endl;
        cin >> flag2;
        if (flag2 == 'n')
        {
            flag = false;
        }
    }

    return 0;
}