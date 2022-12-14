#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

void Sum(char (&a)[2000], char (&b)[2000] ,short (&c)[2000], int &al, int &bl, int &cl)
{
    int ost = 0;
    cl = al;

    for(int i = 0; i <= al && i <= bl;i++)
    {
        c[i] = int((ost + a[al - i] + b [bl - i]) % 10);
        ost = int((ost + a[al - i] + b [bl - i]) / 10);
    }
    if(al > bl)
        for(int i = bl + 1; i <= al;i++)
        {
            c[i] = int((ost + a[al - i]) % 10);
            ost = int((ost + a[al - i]) / 10);
        }
    else if(al < bl)
        cl = bl;
        for (int i = al + 1; i <= bl; i++) {
            c[i] = int((ost + b[bl - i]) % 10);
            ost = int((ost + b[bl - i]) / 10);
        }
    while (ost != 0)
    {
        c[cl] = ost % 10;
        ost = ost / 10;
        cl += 1;
    }
}

void Prod(char (&a)[2000], char (&b)[2000] ,short (&c)[2000], int &al, int &bl, int &cl)
{
    int ost = 0;
    cl = al + bl + 1;
    int num;

    for(int i = 0; i < cl;i++)
    {
       num = 0;
       if (i <= al)
           for(int j = 0; j <= bl && j <= i;j++)
               num += a[al - i + j] * b[bl - j];
       else for (int j = 0; j < cl - i;j++)
               num += a[j] * b[bl - j - i + al];

       c[i] = int((ost + num)%10);
       //cout << num << '|' << ost << endl; //debug check
       ost = int((ost + num)/10);
    }
    while (ost != 0)
    {
        c[cl] = ost % 10;
        ost = ost / 10;
        cout <<ost << endl;
        cl += 1;
    }
}

int main()
{
    string ar, br;
    char a[2000], b[2000];
    short c[2000];
    int cl = 0;
    char oper;

    cout << "Type two numbers divided by enter, with less than 1000 digits" << endl;
    getline(cin, ar);
    getline(cin, br);

    for(int i = 0; i < ar.length(); i++)
    {
        a[i] = ar[i] - '0';
    }
    for(int i = 0; i < br.length(); i++)
    {
        b[i] = br[i] - '0';
    }
    int al = ar.length() - 1;
    int bl = br.length() - 1;

    cout << "Do you want to get sum or product? For product type *, everything else will count as sum" << endl;
    cin >> oper;
    if(oper != '*') Sum(a,b,c,al,bl,cl);
    else Prod(a,b,c,al,bl,cl);

    for (int i = cl - 1; i >= 0; i--){
        cout << c[i];
    }
    return 0;
}
