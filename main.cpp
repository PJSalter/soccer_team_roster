#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    // prompting the user to insert 5 pairs of numbers.
    int numPlayers = 5;
    // Store the jersey numbers in one int vector and the ratings in another int vector.
    vector<int> jerseys(numPlayers);
    vector<int> ratings(numPlayers);
    // A player's jersey number (0 - 99)
    // the player's rating (1 - 9).

    for (int i = 0; i < numPlayers; i++)
    {
        cout << "Enter player " << (i + 1) << "'s jersey number:" << endl;
        cin >> jerseys.at(i);

        cout << "Enter player " << (i + 1) << "'s rating:" << endl;
        cin >> ratings.at(i);

        cout << endl;
    }

    cout << "ROSTER" << endl;
    for (int i = 0; i < numPlayers; i++)
    {
        cout << "Player " << (i + 1) << " -- Jersey number: " << jerseys.at(i) << ", Rating: " << ratings.at(i) << endl;
    }

    char menuOption;

    while (menuOption != 'q')
    {
        cout << endl;
        cout << "MENU" << endl;
        cout << "a - Add player" << endl;
        cout << "d - Remove player" << endl;
        cout << "u - Update player rating" << endl;
        cout << "r - Output players above a rating" << endl;
        cout << "o - Output roster" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        cout << "Choose an option:" << endl;
        cin >> menuOption;

        switch (menuOption)
        {
        case 'a':
        {
            int newJerseyNumber, newRating;
            cout << "Enter a new player's jersey number:" << endl;
            cin >> newJerseyNumber;

            cout << "Enter the player's rating:" << endl;
            cin >> newRating;

            jerseys.push_back(newJerseyNumber);
            ratings.push_back(newRating);

            // cout << "Player " << jerseys.size() << " -- Jersey number: " << newJerseyNumber << ", Rating: " << newRating << endl;
            break;
        }
        case 'd':
        {
            int removeJerseyNumber;
            cout << "Enter a jersey number: ";
            cin >> removeJerseyNumber;

            for (vector<int>::size_type i = 0; i < jerseys.size(); i++)
            {
                if (jerseys.at(i) == removeJerseyNumber)
                {
                    jerseys.erase(jerseys.begin() + i);
                    ratings.erase(ratings.begin() + i);
                    break;
                }
            }
            break;
        }
        case 'u':
        {
            int updateJerseyNumber, newRating;
            cout << "Enter a jersey number: ";
            cin >> updateJerseyNumber;

            cout << "Enter a new rating for player: ";
            cin >> newRating;

            for (vector<int>::size_type i = 0; i < jerseys.size(); i++)
            {
                if (jerseys.at(i) == updateJerseyNumber)
                {
                    ratings.at(i) = newRating;
                    cout << "New rating: " << ratings.at(i) << endl;
                    break;
                }
            }
            break;
        }
        case 'r':
        {
            int minRating;
            cout << "Enter a rating: ";
            cin >> minRating;

            cout << "ABOVE " << minRating << endl;
            for (vector<int>::size_type i = 0; i < ratings.size(); i++)
            {
                if (ratings.at(i) > minRating)
                {
                    cout << "Player " << (i + 1) << " -- Jersey number: " << jerseys.at(i) << ", Rating: " << ratings.at(i) << endl;
                }
            }
            break;
        }
        case 'o':
        {
            cout << "ROSTER" << endl;
            for (vector<int>::size_type i = 0; i < jerseys.size(); i++)
            {
                cout << "Player " << (i + 1) << " -- Jersey number: " << jerseys.at(i) << ", Rating: " << ratings.at(i) << endl;
            }
            break;
        }
        case 'q':
            break;
        default:
            break;
        }
    }

    return 0;
}
