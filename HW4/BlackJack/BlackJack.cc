#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
//10, J, Q, K == 10; A == 1 || 11;

using namespace std;

int BlackJack(string *arr, int n)
{
    int total = 0;
    int string_to_int;
    
    string card[] = { "A", "K", "Q", "J", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
    vector<string> as(&card[0], &card[13]);
    
    vector<string>::iterator it;
    for (int i = 0; i < n; i++)
    {
        string Card;
        cin >> Card;
        arr[i] = Card;
    }
    
    for (int j = 0; j < n; j++)
    {
        it = find(as.begin(), as.end(), arr[j]);
        if (it == as.end())
        {
            cout << "try again" << endl;
            return 0;
        }
    }
    
    for (int k = 0; k < n; k++)
    {
        if (arr[k] == "K" || arr[k] == "Q" || arr[k] == "J")
            total += 10;
        else if (arr[k] != "K" || arr[k] != "Q" || arr[k] != "J" || arr[k] != "A")
        {
            string_to_int = atoi(arr[k].c_str());
            total += string_to_int;
        }
    }
    
    for (int l = 0; l < n; l++)
    {
        if (arr[l] == "A")
        {
            if (total <= 10)
                total += 11;
            else
                total += 1;
        }
    }
    
    if (total < 21)
        cout << total << endl;
    else if (total == 21)
        cout << "BlackJack" << endl;
    else
        cout << "Exceed" << endl;
    
    return 0;
}
int main(void)
{
    while (true)
    {
        string n;
        int num;
        cin >> n;
        
        if (n == "q")
            return 0;
        else
            num = atoi(n.c_str());
        
        if (num < 2)
            return 0;
        
        string *arr = new string[num];
        
        BlackJack(arr, num);
        
        delete[] arr;
    }
    return 0;
}

