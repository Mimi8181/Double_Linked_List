#include <iostream>
using namespace std;

struct Pekerja
{
    string nama;
    int umur, id;
    Pekerja *prev;
    Pekerja *next;
};

Pekerja *head, *tail, *cur, *newNode, *del, *afterNode;

void createDLL(string nama, int umur, int id)
{
    head = new Pekerja();
    head->nama = nama;
    head->umur = umur;
    head->id = id;
    head->next = NULL;
    head->prev = NULL;
    tail = head;
}

int countDLL()
{
    cur = head;
    int jumlah = 0;
    while (cur != NULL)
    {
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

void addFirst(string nama, int umur, int id)
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat" << endl;
    }
    else
    {
        newNode = new Pekerja();
        newNode->nama = nama;
        newNode->umur = umur;
        newNode->id = id;
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }
}

void addMid(string nama, int umur, int id, int posisi)
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat" << endl;
    }
    else
    {
        if (posisi <= 1 || posisi >= countDLL())
        {
            cout << "posisi salah" << endl;
        }
        else
        {
            newNode = new Pekerja();
            newNode->nama = nama;
            newNode->umur = umur;
            newNode->id = id;

            // transfersing
            cur = head;
            for (int i = 1; i < posisi - 1; i++)
            {
                cur = cur->next;
            }

            afterNode = cur->next;
            newNode->prev = cur;
            newNode->next = afterNode;
            cur->next = newNode;
            afterNode->prev = newNode;
        }
    }
}

void addLast(string nama, int umur, int id)
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat" << endl;
    }
    else
    {
        newNode = new Pekerja();
        newNode->nama = nama;
        newNode->umur = umur;
        newNode->id = id;
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void delFisrt()
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat" << endl;
    }
    else
    {
        del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
    }
}

void delMid(int posisi)
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat" << endl;
    }
    else
    {
        if (posisi <= 1 || posisi >= countDLL())
        {
            cout << "posisi salah" << endl;
        }
        else
        {
            cur = head;
            for (int i = 1; i < posisi - 1; i++)
            {
                cur = cur->next;
            }
            del = cur->next;
            afterNode = del->next;
            cur->next = afterNode;
            afterNode->prev = cur;
            delete del;
        }
    }
}

void delLast()
{

    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
}

void printDLL()
{
    if (head == NULL)
    {
        cout << "Double Linked List belum dibuat" << endl;
    }
    else
    {
        cur = head;
        while (cur != NULL)
        {
            cout << "Nama\t: " << cur->nama << endl;
            cout << "Umur\t: " << cur->umur << endl;
            cout << "Id\t: " << cur->id << endl
                 << endl;
            cur = cur->next;
        }
        cout << "jumlah data: " << countDLL() << endl;
        cout << "----------------------------" << endl;
    }
}

int main(int argc, char const *argv[])
{

    createDLL("Agus", 21, 01);
    addFirst("Bagas", 22, 02);
    addLast("Cecep", 30, 03);
    addMid("Dadang", 29, 04, 2);
    printDLL();

    delMid(1);
    printDLL();

    return 0;
}
