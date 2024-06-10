#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
const int size = 100;
int counter = 0;
int option;
int count;
 int orderCount=0;
string username;
string password;
string model[size];
string color[size];
string price[size];
string name[size];
string qty[size];
string conditionOfCar[100];
string payedPricee[100];
string Name;
string Price;
string Model;
string Color;
string customerV;
string tempPrice;
bool loggedInUser = false;
int a = 0;
string Username[100];
string Password[100];
string Role[100];
string role;
void  storeInFileOrder();
void printLogo();
void printheader();
int SubMenuForLogging();
bool SignUp(string username, string password, string role);
string SignIn(string username, string password);
int MainMenuScreenForAdmin();
int MainMenuScreenForCustomer();
int ScreenForCreatingList();
int ListOfCars();
int AddNewCarToList();
int updatedlist();
int ScreenForDeletingCarFromList();
int updatedlist2();
bool priceValidation(string price);
int UpdateThePriceOfCar();
void seeFeedBack();
int SeeTheListOfCustomers();
string SeeTheListOfOrder();
int RecomandBestItemToCustomer();
void LogOutToExit();
void storeInFile(string username, string password,string role);
void readDataFromFile();
void viewUsers();
bool validation(string username,string password);
bool choiceValidation(int choice);
bool choiceCarValidation(int choice );
void storeInFileCreating(string Name,string Color,string Price,string Model,string qty); 
void   updateFromCarList( );
void readDataFromFileCreating();
void deleteFromCarList( );
void StoreDataOfCustomers( );
void ReadDataOfCustomers();
string Order[100];
string payedprice;
int choice;
string comment;
int ListOfAvailableCars();
int SelectTheCar();
int SelectConditionOfCar();
int PayPrice();
int DisplayBill();
int GiveFeedBack();
int CancelOrder();
int LogOut();

void storeInFileFeedBack(string name, string comment);
main()
{
    printLogo();
    cout << "press any key to continue";
    getch();
    printheader();
    readDataFromFile();
    readDataFromFileCreating();
    ReadDataOfCustomers();
    
    while (option != 4)
    {
        option = SubMenuForLogging();
         readDataFromFile();
        if (option == 1)
        {
            string username;
            string password, role;
            printheader();
            // system("cls");
            cout << "enter the username:";
            cin >> username;
            cout << "enter the password:";
            cin >> password;
            cout << "enter the role:";
            cin >> role;
            bool validate=validation(username,password);
            if(validate==false)
            {
                 cout << "INVALID USERNAME OR PASSWORD!-----";
                 
            }
            else
            {
             bool isvalid = SignUp(username, password, role);
            
             if (isvalid)
            {
                storeInFile( username, password,role);
                StoreDataOfCustomers( );
                cout << "SIGNED UP SUCCESFULLY!!"<<endl;
            }
            if (!isvalid)
            {
                cout << "INVALID USERNAME OR PASSWORD!---!!";
            }
            }
           
        }
        // system("cls");
        if (option == 2)
        {

            if (loggedInUser == false)
            {

                
                loggedInUser = true;

                printheader();
                cout << "enter the username:";
                cin >> username;

                cout << "enter the password:";
                cin >> password;
                bool validate=validation(username,password);
            if(validate==false)
            {
                 cout << "INVALID USERNAME OR PASSWORD!"<<endl;
            }
            else
            {
                // bool isvalid = SignUp(username, password, role);
                role = SignIn(username, password);
                loggedInUser=true;
            }
                  
            }
           
        //  cout << "role " << role << endl;
            if (role == "admin")
            {
                while (option != 8)
                {
                    system("cls");
                   
                    option = MainMenuScreenForAdmin();

                    printheader();
                    system("cls");
                    if (option == 1)
                    {
                        ScreenForCreatingList();
                        
                        ListOfCars();
                        getch();
                        system("cls");
                        printheader();
                        option = MainMenuScreenForAdmin();
                    }

                    if (option == 2)
                    {
                        AddNewCarToList();
                        updatedlist();
                        option = MainMenuScreenForAdmin();
                    }

                    if (option == 3)
                    {
                        ListOfCars();
                        ScreenForDeletingCarFromList();
                         ListOfCars();
                        option = MainMenuScreenForAdmin();
                        printheader();
                    }

                    if (option == 4)
                    {
                        UpdateThePriceOfCar();
                        option = MainMenuScreenForAdmin();
                        system("cls");
                        printheader();
                    }

                    if (option == 5)
                    {
                        SeeTheListOfCustomers();
                        option = MainMenuScreenForAdmin();
                    }
                    if(option==6)
                    {
                         RecomandBestItemToCustomer();
                        option = MainMenuScreenForAdmin();
                    }
                    if (option == 7)
                    {
                        seeFeedBack();
                        option = MainMenuScreenForAdmin();
                    }
                    if (option == 8)
                    {
                        LogOutToExit();
                        system("cls");
                    }
                }
             }

            else if (role == "customer")
            {
                option = MainMenuScreenForCustomer();
                printheader();
                system("cls");
                if (option == 1)
                {
                    ListOfAvailableCars();
                     option = MainMenuScreenForCustomer();
                }
                if (option == 2)
                {
                    SelectTheCar();
                     option = MainMenuScreenForCustomer();
                }
                if (option == 3)
                {
                    SelectConditionOfCar();
                     option = MainMenuScreenForCustomer();
                }
                if (option == 4)
                {
                    PayPrice();
                     option = MainMenuScreenForCustomer();
                }
                if (option == 5)
                {
                    DisplayBill();
                     option = MainMenuScreenForCustomer();
                }
                if (option == 6)
                {
                    GiveFeedBack();
                     option = MainMenuScreenForCustomer();
                }
                if (option == 7)
                {
                    CancelOrder();
                     option = MainMenuScreenForCustomer();
                }
                if (option == 8)
                {
                    LogOut();
                }
            }
        }
        if(option==3)
            {
                viewUsers();
            }

    }

    system("cls");
}
void printLogo()
{
    cout << "##   ##   ##  ##  #######  #######   ####     #####               ##    ##   ##  ######            ######   #######     ##     ####     ##### " << endl;
    cout << "##   ##   ##  ##   ##  ##   ##  ##    ##     ##   ##             ####   ###  ##   ##  ##            ##  ##   ##  ##    ####     ##     ##   ## " << endl;
    cout << "##   ##   ##  ##   ##       ##        ##     ##                 ##  ##  #### ##   ##  ##            ##  ##   ##       ##  ##    ##     ##     " << endl;
    cout << "## # ##   ######   ####     ####      ##      #####             ######  ## ####   ##  ##            ##  ##   ####     ######    ##      #####  " << endl;
    cout << "#######   ##  ##   ##       ##        ##          ##            ##  ##  ##  ###   ##  ##            ##  ##   ##       ##  ##    ##          ## " << endl;
    cout << "### ###   ##  ##   ##  ##   ##  ##    ## ##  ##   ##            ##  ##  ##   ##   ##  ##            ##  ##   ##  ##   ##  ##    ## ##  ##   ## " << endl;
    cout << "##   ##   ##  ##  #######  #######   ######   #####             ##  ##  ##   ##  ######            ######   #######   ##  ##   ######   #####  " << endl;
    cout<<"##################################################################################################################################################"<<endl;
    cout<<"##################################################################################################################################################"<<endl;
}

void printheader()
{
    system("cls");
    cout << "            " << "^Welcome to:^" << endl;
    cout << "*******************************************************" << endl;
    cout << "*******************************************************" << endl;
    cout << "**********                 **********" << endl;
    cout << "*********** WHEELS AND DEALS**********" << endl;
    cout << "**********                 **********" << endl;
    cout << "^A place where you can buy car of your dreams^" << endl;
    cout << "*******************************************************" << endl;
    cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;

}
int SubMenuForLogging()
{
    int option;
    cout << "  "  << " Logging Menu:" << endl;
    cout << "============================" << endl;
    cout << "Options:" << endl;
    cout << "01. SignUP to continue:" << endl;
    cout << "02. SignIn to continue:" << endl;
    cout << "03. view list of users:" << endl;
    cout << "04. Exit" << endl;
    cout << "enter your option:" << endl;
    cin >> option;
    return option;
    system("cls");
}
bool SignUp(string username, string password, string role)
{
    bool isPresent = false;
     
    for (int x = 0; x < counter; x++)
    {
        if (Username[x] == username && Password[x] == password)
        {
            isPresent = true;
            break;   
        }
    }
    if (isPresent == true)
    {
        
        cout << "USER ALREADY EXISTS!!";
        return false;
    }
    else if (counter < size)
    {
        Username[counter] = username;
        Password[counter] = password;
        Role[counter] = role;
        counter++;
        return true;
    }
    else
    {
        return false;
    }
    system("cls");
}

string SignIn(string username, string password)
{
   
    for (int i = 0; i < counter; i++)
    {
        

        if (Username[i] == username && Password[i] == password)
        {
            
            return Role[i];
        }
    }
    return "undefined";
    system("cls");
}

int MainMenuScreenForAdmin()
{
     
    int option;
  
   
    cout << "****************** MENU SCREEN FOR ADMIN*********************" << endl;
    cout<<"**************************************************************"<<endl;
    cout << "Option 01: Creat list of cars" << endl;
    cout << "Option 02: Add a new car " << endl;
    cout << "Option 03: Delete a previous car" << endl;
    cout << "Option 04: Update the price of car" << endl;
    cout << "Option 05: See the list of customers and their orders" << endl;
    cout << "Option 06: Recomand the best item to customer" << endl;
    cout<<  "Option 07: See FeedBack Given By the Customer "<< endl;
    cout<<  "Option 08: LogOut  "<< endl;
    cout << "Option 09: Exit " << endl;
    cout << "enter your option:" << endl;
    cin >> option;
      bool validate= choiceValidation(option);
    if(validate==false)
    {
        cout << "Invlaid Option choice !" << endl;
       MainMenuScreenForAdmin();
         
    }
    else
    {
        return option;
        system("cls");
}
    }
    
    

int MainMenuScreenForCustomer()
{
    int option;
    cout << "********************* MENU SCREEN FOR CUSTOMER***************" << endl;
    cout<<"**************************************************************"<<endl;
    cout << "Option 01: See list of cars" << endl;
    cout << "Option 02: Select the car" << endl; 
    cout << "Option 03: Select the condition  of car" << endl;
    cout << "Option 04: pay the price" << endl;
    cout << "Option 05: display  bills" << endl;
    cout << "Option 06: GiveFeed back" << endl;
    cout << "Option 07: Cancel order" << endl;
    cout << "Option 08: Log out " << endl;
    cout << "enter your option:" << endl;
    cin >> option;
    return option;
    system("cls");
}

int ScreenForCreatingList()
{

    cout << "enter the number of cars you want to add:";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cout << "enter the name of car:" << endl;
        cin >> name[a];
        cout << "enter the model of car:" << endl;
        cin >> model[a];
        cout << "enter the color of car:" << endl;
        cin >> color[a];
        cout << "enter the price of car:" << endl;
        cin >> price[a];
        cout << "enter the qty of car:" << endl;
        cin >> qty[a];
        storeInFileCreating(name[a],model[a], color[a],price[a],qty[a]);
        a++;
       
    }
    
    return 0;
    system("cls");
}

int ListOfCars()
{
    cout << "CarNumber"
         << "    "
         << "Name:"
         << "    "
         << "    "
         << "Model"
         << "   "
         << "    "
         << "Color"
         << "    "
         << "    "
         << "    "
         << "    "
         << "    "
         << "Price" 
         << "    "
         << "    "
         << "    "
         << "    "
         << "    "
         << "Qty"
         << endl;
    // cout << a;
    for (int i = 0; i < a; i++)
    {

        cout << "    "<< "    " << i + 1 << "    " << name[i] << "    " << model[i] << "  " << color[i] << "  " << price[i] << "  " << qty[i] << endl;
    }
    return 0;
    system("cls");
}
int AddNewCarToList()
{    
    cout << "Enter the name of  new car:" << endl;
    cin >> name[a];
    cout << "enter the model of new car:" << endl;
    cin >> model[a];
    cout << "enter the color of new car:" << endl;
    cin >> color[a];
    cout << "enter the price of new  car:" << endl;
    cin >> price[a];
     cout << "enter the qty of new  car:" << endl;
    cin >> qty[a];
    storeInFileCreating(name[a],model[a], color[a],price[a],qty[a]);
    a++;
    system("cls");
}
int updatedlist()
{
    ListOfCars();
    return 0;
    system("cls");
}

int updatedlist2()
{
     ListOfCars();
}

int UpdateThePriceOfCar()
{
    int numberOfCar;
    cout << "enter the numberOfCar whose price you want to update:" << endl;
    cin >> numberOfCar;

    string newPrice;
    cout << "enter the new price of car" << endl;
    cin >> newPrice;

    for (int i = 0; i < a; i++)
    {
        if ((numberOfCar - 1) == i)
            price[i] = newPrice;
    }
    cout<<"numberofcar"<<"\t\t"<<"newprice"<<endl;
    cout<<numberOfCar<<"\t\t"<<newPrice<<endl;
   
    updateFromCarList( );
     ListOfCars();
}


string SeeTheListOfOrder()
{
   cout<<Order;
}

int RecomandBestItemToCustomer()
{
    cout << "Recommanded Car:" << endl;
    // cout << "Audi" << endl;
    // cout << "Due to Best ratings and it is our most sold car" << endl;
    // system("cls");
}
void LogOutToExit()
{
    abort();
}


int ListOfAvailableCars()
{
    ListOfCars();
    readDataFromFileCreating();
}
int SelectTheCar()
{
    int order;
    string orderDetails;
     ListOfCars();
    cout << "Enter the number of Car you want to select" << endl;
    cin >> order;
    for (int i=0;i<=a;i++)
    {
        if(order-1==i)
        {
            cout << "name" << orderDetails;
            orderDetails=name[i]+""+model[i];
            tempPrice=price[i];
        }
    }
    cout << "Car  orderd" << orderDetails;
    Order[orderCount]=orderDetails;
    cout << "Car  orderd" << orderDetails;
}
int SelectConditionOfCar()
{   
    cout << "SELECT THE CONDITION OF CAR(NEW or OLD)" << endl;
    cout << "enter your choice" << endl;
    cin >> conditionOfCar[orderCount];
     
}
int PayPrice()
{
    string choice;
    string price;
    cout << "SELECT THE WAY OF PAYING(by cash or card)" << endl;
    cout << "enter your choice" << endl;
    cin >> choice;

       cout << "enter the price payed" << endl;

       cin >> price;
         

        bool validate=priceValidation( price);
        
        if(validate==true)
        {
            //  if(price<tempPrice)
            //  {
            //     return 0;
            //      cout << "  Enter the rquired amount!" << endl;
               
            //  }
            //  else
            //  {
             payedPricee[orderCount]=price;
            cout << "Transaction successfull"<<payedPricee[orderCount] << endl; 
            storeInFileOrder();
            //  }
        }
        else
        {
            PayPrice();
        }
       
}

int GiveFeedBack()
{
    cout << "enter your name:" << endl;
    cin >>customerV;
    cout << "enter your comment:" << endl;
    cin >> comment;
    storeInFileFeedBack(customerV,comment);

}

int DisplayBill()
{
    cout << "******************BILL******************" << endl;
    cout << Order[orderCount-1]<<endl;
    cout << payedPricee[orderCount-1];
}
    
    
int CancelOrder()
{
    
    string choice;
    string userdata;
    cout << "DO YOU WANT TO CANCEL ORDER?" << endl;
    cout << "enter your choice:";
    cin >> choice;
     ofstream writeFile;
         fstream file;
    file.open("orders.txt");
    writeFile.open("orders.txt");
    if(choice=="no")
    {
        cout<<"No"; 
    }
    if(choice=="yes") 
    {
       
    while(getline(file,userdata))
    {
        
     cout<<"djdfdkjfldkfjdlfjldkf"<<endl;
    for(int i=0;i<orderCount;i++)
    {
        if(1==i)
        {
            continue;
        }
       writeFile<<userdata<<endl;
    }
    }
    writeFile.close();
    
    cout << "your order has been canceled!";
    }
}
int LogOut()
{
    abort();
}

void viewUsers()
{
     cout << "Usernames"
         << "\t\t"
         << "Passwords"
          << "\t\t"
         "Role"<<endl;


         
    for (int idx = 0; idx < counter; idx++)
    {
        cout << Username[idx] << "\t\t\t" << Password[idx]<< "\t\t\t"<< Role[idx]<< endl;
    }
    
}

bool validation(string username,string password)
{
    
  if(password.length()>8)
  {
    return false;
  }
   int flag=0;
  
  // Checking if string contians special character
  for(int i=0;i<password.length();i++)
  {
    if ((password[i]>=48 && password[i]<=57)||
        (password[i]>=65 && password[i]<=90)||
        (password[i]>=97 && password[i]<=122))
        {
          continue;
        }
    else
    {
     
      flag=1;
      break;
    }
  }
   for(int i=0;i<password.length();i++)
  {
    if ((password[i]>=48 && password[i]<=57)||
        (password[i]>=65 && password[i]<=90)||
        (password[i]>=97 && password[i]<=122))
        {
          continue;
        }
    else
    {
     
      flag=1;
      break;
    }
  }
   for(int i=0;i<username.length();i++)
  {
    if (
        (username[i]>=65 && username[i]<=90)||
        (username[i]>=97 && username[i]<=122))
        {
          continue;
        }
    else
    {
     
      flag=1;
      break;
    }
  }
  if(flag==1)
  {
    cout<<"No special character or integer  is allowed in username or password"<<endl;
    return false;
  }

  return true;

}


bool choiceValidation(int choice)
{
    bool decider=false;
    for (int i=0;i<=8;i++)
    {
        if(choice==i)
        {
           decider=true;
        }
    }
    return decider;
}

bool choiceCarValidation(int choice)
{
     bool decider=false;
  cout << "The sum is " <<  sizeof(name) << endl;
    for (int i=0;i< 1;i++)
    {
       if(choice==i)
        {
           decider=true;
        }
    }
    
     return decider;
}

int ScreenForDeletingCarFromList()
{
    int numberOfCar;
    cout << "enter the number of car you want to Delete:" << endl;
    cin >> numberOfCar;
    cout << "The sum is " <<  sizeof(name) << endl;

 
 
    for (int i = 0; i < a; i++)
    {
        if (i == (numberOfCar - 1))
        {
            for (int j = i; j < (a - 1); j++)
            {
                model[j] = model[j + 1];
                name[j] = name[j + 1];
                color[j] = price[j + 1];
                price[j] = color[j + 1];
            }
            a--;
            break;
        }
    }
    
     deleteFromCarList();
    cout << "After Deleting remaining cars:" << endl;
    ListOfCars();
    system("cls");
    return 0;
       


}


void readDataFromFile()
{
    int countt=0;
    string userdata;
    string w = "";
    string username;
    string password;
    string role;
    fstream file;
    file.open("users.txt",ios::in);
    while(getline(file,userdata))
    {
        countt=0;
        for (auto x : userdata)
    {
        //   cout << "After " <<x <<endl;
        if (x == ',')
        {
           if(countt==0)
           {
                username=w;
                 w="";
                 countt++;
                continue;
                
                
           }
           
            if (countt==1)
           {
            
                password=w;
                w="";
                countt++;
                continue;
                
                
           }
               
           
        }
        else {
            w = w + x;
        }
    }
            role=w;
              w="";
        Username[counter] =  username;
        Password[counter] = password;
        Role[counter]=role;
        counter++;
        
}
        
    file.close();
}

void storeInFile(string userName, string password,string role)
{
    fstream file;
    file.open("users.txt", ios::app);
    file << userName <<","<< password <<","<< role <<endl;
    file.close();
}
void storeInFileCreating(string Name,string Model,string Color,string Price,string qty)
{
    fstream file;
    file.open("listOfCars.txt",ios::app);
    file<<Name<<","<<Model <<","<<Color<<","<<Price<<","<<qty<<endl;
    file.close();
}
void readDataFromFileCreating()
{
    int countt=0;
    string list;
    string l = "";
    fstream file;
    string nameC;
    string modelC;
    string colorC;
    string priceC;
    string qtyC;

    file.open("listOfCars.txt",ios::in);
    while(getline(file,list))
    {
        countt=0;
        for (auto x : list)
    {
        
      
        if (x == ',')
        {
        
        
           if(countt==0)
           {
                nameC=l;
                 l="";
                 countt++;
                continue;
                
                
           }
           
            if (countt==1)
           {
            
                modelC=l;
                l="";
                countt++;
                continue;
                
                
           }
           if(count==2)
           {
             
       
               colorC=l;
                l="";
                countt++;
                continue;
                
           }
           else
           {
                priceC=l;
                l="";
                countt++;
                continue;
           }
               
           
        }
        else {
       
            l = l + x;
        }
    }
            qtyC=l;
              l="";
             
        name[a]=nameC;
        model[a]=modelC;
        color[a]=colorC;
        price[a]=priceC;
        qty[a]=qtyC;
        a++; 
}
         
    file.close();   
}

void deleteFromCarList( )
{
    ofstream writeFile;
    writeFile.open("listOfCars.txt");
    for(int i=0;i<a;i++)
    {
       writeFile<<name[i]<<","<<model[i] <<","<<color[i]<<","<<price[i]<<","<<qty[i]<<endl;
    }
    writeFile.close();
}
void StoreDataOfCustomers()
{
    fstream writeFile;
    writeFile.open("ListOfCustomers.txt",ios::out);
    for (int i = 0; i < counter; i++)
    {
        if (Role[i] == "customer")
        {
         writeFile<< Username[i] << endl;
        }
    }
    writeFile.close();
    
}
void ReadDataOfCustomers()
{
    fstream writeFile;
  writeFile.open("ListOfCustomers.txt",ios::in);
    while(getline(writeFile,username))
    {
        count++;
    }
    writeFile.close();
}

void updateFromCarList( )
{
    ofstream writeFile;
    writeFile.open("listOfCars.txt");
    for(int i=0;i<a;i++)
    {
       writeFile<<name[i]<<","<<model[i] <<","<<color[i]<<","<<price[i]<<","<<qty[i]<<endl;
    }
    writeFile.close();
}


void storeInFileOrder()
{
    fstream file;
    file.open("orders.txt",ios::app);
    file<<username<<","<<Order[orderCount]<<","<<conditionOfCar[orderCount] <<","<<payedPricee[orderCount]<<endl;
    orderCount++;
    file.close();
}

void storeInFileFeedBack(string name, string comment)
{
     fstream file;
    file.open("feedBack.txt",ios::app);
    file<<name<<","<<comment<<endl;
    file.close();
}

int SeeTheListOfCustomers()
{
    string customer;
    string temCustomer[100];
    string y="";
    cout << " lIST OF customer" << endl;
    for (int i = 0; i < counter; i++)
    {
        if (Role[i] == "customer")
        {
             temCustomer[i]=Username[i];
            // cout << " " << Username[i] << endl;
        }
        
    
    }
    fstream readFile;
     readFile.open("orders.txt",ios::in);
     cout<<"**************Customer details*************"<<endl;
     cout<<""<<endl;
     cout << "Customer"<< "   "<<" order details " << "  "<<"  " << endl;
     cout<< "        "<< " Car Name" "   " <<"condition"<<"  " <<"Price"<<endl;
    while(getline(readFile,customer))
    {
          for (auto x : customer)
          {
             if(x==',')
             {
                // cout <<"        ";
                 cout << y ;
                 cout <<"      ";
                 y="";
             }
             else
             {
                y=y+x;
             }
          }
          cout<<y<<endl;
          y="";
          
        //   cout <<customer;
    //     for (auto x : customer)
    //    if(customer)
    //    {
          
    //    }

    }
    cout<<""<<endl;
     readFile.close();
    // StoreDataOfCustomers();
}

bool priceValidation(string price)
{
    for (int i=0;i<price.length();i++)
    {
      if ((price[i] >=65 && price[i]<=90)||
        (price[i]>=97 && price[i]<=122))
        {
            cout<<"Invalid Price!"<<endl;
            return false;
        }
    }

    return true;
    
}
 
void seeFeedBack()
{
     fstream readFile;
     string feed;
     readFile.open("feedBack.txt",ios::in);

      while(getline(readFile, feed))
      {
          cout<<"Users FeedBack!!!!!"<<endl;
           cout<< feed<<endl;
      }
}
