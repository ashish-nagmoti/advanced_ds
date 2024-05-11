#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Member
{
    int memberId;
    string name;
    string phone;
    string email;
};

void addMember()
{
    ofstream outFile("members.txt", ios::app);

    Member newMember;
    cout << "\nEnter Member ID, Name, Phone, Email: ";
    cin >> newMember.memberId >> newMember.name >> newMember.phone >> newMember.email;


    outFile << newMember.memberId << " " << newMember.name << " " << newMember.phone << " " << newMember.email << endl;
    
    cout << "Member added successfully.\n";
    outFile.close();
}


void searchMember()
{
    int searchId;
    cout << "\nEnter Member ID to search: ";
    cin >> searchId;

    ifstream inFile("members.txt");
    if (!inFile)
    {
        cout << "File not found or unable to open.\n";
        return;
    }

    Member member;
    bool found = false;


    while (inFile >> member.memberId >> member.name >> member.phone >> member.email)
    {
        if (member.memberId == searchId)
        {
            cout << "\nMember Found:\n";
            cout << "Name: " << member.name << endl;
            cout << "Phone: " << member.phone << endl;
            cout << "Email: " << member.email << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Member with ID " << searchId << " not found.\n";
    }

    inFile.close();
}


void deleteMember()
{
    int memberId;
    cout << "\nEnter Member ID to delete: ";
    cin >> memberId;

    ifstream inFile("members.txt");
    if (!inFile)
    {
        cout << "File not found or unable to open.\n";
        return;
    }

    ofstream tempFile("temp.txt");

    Member member;
    bool found = false;


    while (inFile >> member.memberId >> member.name >> member.phone >> member.email)
    {
        if (member.memberId != memberId)
        {
            tempFile << member.memberId << " " << member.name << " " << member.phone << " " << member.email << endl;
        }
        else
        {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("members.txt");

    rename("temp.txt", "members.txt");

    if (found)
    {
        cout << "Member with ID " << memberId << " deleted successfully.\n";
    }
    else
    {
        cout << "Member with ID " << memberId << " not found.\n";
    }
}

void updateMember()
{
    int memberId;
    cout << "\nEnter Member ID to update: ";
    cin >> memberId;

    fstream file("members.txt", ios::in | ios::out);
    if (!file)
    {
        cout << "File not found or unable to open.\n";
        return;
    }

    Member member;
    bool found = false;

    while (file >> member.memberId >> member.name >> member.phone >> member.email)
    {
        if (member.memberId == memberId)
        {
            cout << "Enter new Name, Phone, Email: ";
            cin >> member.name >> member.phone >> member.email;

 
            file.seekp(file.tellg());
            file << member.memberId << " " << member.name << " " << member.phone << " " << member.email;
            found = true;
            cout << "Member information updated successfully.\n";
            break;
        }
    }

    file.close();

    if (!found)
    {
        cout << "Member with ID " << memberId << " not found.\n";
    }
}


int main()
{
    int choice;

    do {
        
        cout << "\n--- Club Members Management System ---\n";
        cout << "1. Add Member\n";
        cout << "2. Search Member\n";
        cout << "3. Delete Member\n";
        cout << "4. Update Member Information\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addMember();
                break;
            case 2:
                searchMember();
                break;
            case 3:
                deleteMember();
                break;
            case 4:
                updateMember();
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

