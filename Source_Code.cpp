#include <bits/stdc++.h>
#define ASCII_UPPER_A  65
using namespace std;

// Exhaustive Key Search for Shift Cipher
// Function to compute decrypted plain text
string decrypt(string ctext, int key)
{
    string ptext;
     // Use a constant for ASCII value of 'A'

    for (char c : ctext)
    {
        int temp;
        // Check if the character is within the range of uppercase letters
        if ((c - ASCII_UPPER_A - key) < 0)
            temp = c - ASCII_UPPER_A - key + 26; // Wrap around to the end of the alphabet
        else
            temp = c - ASCII_UPPER_A - key;

        // Append the decrypted character to the plain text
        ptext.push_back(char((temp % 26) + ASCII_UPPER_A));
    }
    return ptext;
}

int main()
{
    string ctext;
    cout << "Please enter the cipher text : " << endl;
    cin >> ctext;

    // Convert the input to uppercase
    transform(ctext.begin(), ctext.end(), ctext.begin(), ::toupper);

    // Key
    int k = 1;

    string ptext;

    // Print cipher text in 0 to 25 based indexing
    cout << endl
         << "Cipher Text in 0 to 25 based indexing : " << endl;
    for (char c : ctext)
    {
        cout << (c - ASCII_UPPER_A) << " ";
    }
    cout << endl
         << endl;

    bool check = 0;

    // Exhaustive search for keys from 1 to 25
    for (k = 1; k < 26; k++)
    {
        cout << "For key = " << k << ": ";
        ptext = decrypt(ctext, k);
        cout << ptext << endl;

        // Check if the decrypted text is meaningful
        cout << "Did you find it meaningful? [0 : No and 1 : Yes]" << endl;
        cin >> check;
        cout << endl;

        // If meaningful, break the loop
        if (check == 1)
        {
            break;
        }
    }

    // Display result based on whether a meaningful decryption was found
    if (check == 0)
        cout << "Sorry, the given cipher text is not encrypted using a shift cipher" << endl;
    else
    {
        cout << "----------------------------------------------------" << endl;
        cout << "Your Key is : " << k << endl;
        cout << "Cipher Text : " << ctext << endl;
        cout << "Plain Text  : " << ptext << endl;
    }

    return 0;
}
