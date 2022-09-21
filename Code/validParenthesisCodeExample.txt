// A 381 - Sereja and Dima - Codeforces
// Link : https://codeforces.com/contest/381/problem/A

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int numberOfCards;
    cin >> numberOfCards;
    int card;
    deque<int> cards;
    for (int i = 0; i < numberOfCards; i++)
    {
        cin >> card;
        cards.push_back(card);
    }
    int sereja = 0, dima = 0;
    for (int turn = 0; turn < numberOfCards; turn++)
    {
        if (cards.back() > cards.front())
        {
            if (turn % 2 == 0) // it means it is sereja turn
            {
                sereja += cards.back();
            }
            else // it means dima turn
            {
                dima += cards.back();
            }
            cards.pop_back();
        }
        else
        {
            if (turn % 2 == 0) // it means it is sereja turn
            {
                sereja += cards.front();
            }
            else // it means dima turn
            {
                dima += cards.front();
            }
            cards.pop_front();
        }
    }
    cout << sereja << " " << dima;
}
