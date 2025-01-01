#include<iostream>
#include<string.h>
using namespace std;
// final price calculator
int calculatePrice(int basePrice,bool addMess){
    double gst = 0.18*basePrice;
    int messCost = addMess ? 3000:0;
    return basePrice + gst + messCost;
}
// initial details of person.
void details(string &name , string &enroll , string &batch , string &course )
{
    cout<<"\nPlease enter your details given below : \n";
    cout<<"Name : - ";
    getline(cin,name);
    cout<<"Enrollment no.: - ";
    cin>>enroll;     
    cout<<"Batch : - "; 
    cin>>batch;
    cout<<"Course : - ";    
    cin>>course;
}
// confirmation of initial detail.
int confirm(const string &name ,const string &enroll , const string &batch , const string &course)
{
    cout<<"\n\nPlease confirm your details : - ";
    cout<<"\nName : - "<<name;
    cout<<"\nEnrollment no. : - "<<enroll;
    cout<<"\nBatch : - "<<batch;
    cout<<"\nCourse : - "<<course;
    cout<<"\nAll the details above are correct?";
    cout<<"\nFor YES - press 1 , For NO - press 2 : - ";
    int ch;
    cin>>ch;
    return ch;
}
// after confirmation booking details and final booking.
void booking()
{
    int singleRoomCount = 5;
    int  doubleRoomCount= 5;
    int tripleRoomCount = 5;
    cout<<"\nThank you for your confimation .";
    cout<<"\nWe offered three types of rooms : ";
    cout<<"\nSingle bed room (Available"<<singleRoomCount<<")";
    cout<<"\nDouble  sharing room (Available : "<<doubleRoomCount<<")";
    cout<<"\nTriple  sharing room (Available : "<<tripleRoomCount<<")";
    
    cout<<"\nDetails of rooms are given as follows : - ";
    cout<<"\nFor 1 seater room :- Base Price : 8000 + 18% GST";
    cout<<"\nFor 2 seater room :- Base Price : 6000 + 18% GST";
    cout<<"\nFor 3 seater room :- Base Price : 5000 + 18% GST";


    int roomChoice;
    

    while(true){
    cout<<"\nPlease select the room type .";
    cout<<"\nFor Single seater press 1. \nFor Double room sharing  press 2.\nFor Triple room shairng press 3.";
    cin>>roomChoice;
    if(roomChoice==1 && singleRoomCount>0){
        singleRoomCount--;
        break;
    }
    else if(roomChoice==2 && doubleRoomCount>0){
        doubleRoomCount--;
        break;
    }
    else if(roomChoice==3 && tripleRoomCount>0){
        tripleRoomCount--;
        break;
    }
    else cout<<"Invalid choice or NO room available. please try again";
    if(roomChoice>=1 && roomChoice<=3) break;
    else cout<<"Invalid Choice . Plese try again";
    }


    int basePrice = 0;
    switch(roomChoice){
        case 1:
            cout<<"\nYou Selected : Single seater room";
            basePrice = 8000;
            break;
        case 2:
            cout<<"\nYou Selected : Double sharing room";
            basePrice = 6000;
            break;
        case 3:
            cout<<"\nYou Selected : Triple sharing room";
            basePrice = 5000;
            break;
            default:
            cout<<"Invalid choice. Exiting.......";
    }
    cout<<"\nWe also provide mess service at an additional cost of 3000 rupees per month";
    int messChoice;
    while(true){
    cout<<"\nDo you want to add mess services?\npress 1 for YES , 2 for NO. ";
    cin>>messChoice;
    
    if(messChoice == 1 || messChoice==2) break; 
    else cout<<"\nInvalid Choice . Please try again";
    }
    bool addMess = (messChoice==1);
    int totalPrice = calculatePrice(basePrice,addMess);
    cout<<"Your total amout is : "<<totalPrice<<" rupees.\n";
    
    
}
void Payment()
{
    int paymentChoice = 0 ;
    while(true){
        cout << "\nProceed to Payment:\n1. Through UPI\n2. Through Debit Card\n3. Through Net Banking\n";
        cout << "Enter your choice: ";
        cin >> paymentChoice;
        if(paymentChoice>=1 && paymentChoice<=3) break;
        else cout<<"Invalid choice. Please try again";
    }
    
    switch (paymentChoice) 
    {
        case 1:
            cout << "\nPayment successful via UPI. Thank you!\n";
            break;
        case 2:
            cout << "\nPayment successful via Debit Card. Thank you!\n";
            break;
        case 3:
            cout << "\nPayment successful via Net Banking. Thank you!\n";
            break;
        default:
            cout << "\nInvalid payment method. Exiting...\n";
    }
}

int main()
{
    string name , enroll , batch , course;
    cout<< "\t\tWelcome\t\t\n";
    cout<<"\t\t-------\t\t";


    details( name ,  enroll ,  batch ,  course );


    int ch = confirm( name ,  enroll ,  batch ,  course);
    switch(ch){
        case 1:
        booking();
        Payment();
        break;
        case 2:
        cout<<"Please enter right details : - ";
        cin.ignore();
        details(name,enroll,batch,course);
        ch = confirm(name,enroll,batch,course);
        while(true){
        if(ch==1) 
        {
            booking();
            Payment();
        }
        else cout<<"\nDetails not confirmed . Exiting.....\n";
        break;
        default:
        cout<<"Wrong choice. Exiting......";
        }
    } 
    return 0;

}