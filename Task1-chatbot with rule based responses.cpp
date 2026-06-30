#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Convert text to lowercase
string toLowerCase(string text)
{
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

int main()
{
    string userInput;

    cout << "=====================================\n";
    cout << "      AI Rule-Based Chatbot\n";
    cout << "=====================================\n";
    cout << "Type 'bye' to exit the chatbot.\n\n";

    while (true)
    {
        cout << "You: ";
        getline(cin, userInput);

        userInput = toLowerCase(userInput);

        if (userInput == "bye")
        {
            cout << "Bot: Goodbye! Have a great day.\n";
            break;
        }
        else if (userInput.find("hello") != string::npos ||
                 userInput.find("hi") != string::npos)
        {
            cout << "Bot: Hello! How can I help you today?\n";
        }
        else if (userInput.find("how are you") != string::npos)
        {
            cout << "Bot: I am fine. Thank you for asking!\n";
        }
        else if (userInput.find("your name") != string::npos)
        {
            cout << "Bot: My name is ChatBot.\n";
        }
        else if (userInput.find("college") != string::npos)
        {
            cout << "Bot: I can help with college-related questions.\n";
        }
        else if (userInput.find("course") != string::npos)
        {
            cout << "Bot: Popular courses include C++, Python, Java, AI, and Data Science.\n";
        }
        else if (userInput.find("ai") != string::npos)
        {
            cout << "Bot: AI stands for Artificial Intelligence.\n";
        }
        else if (userInput.find("dsa") != string::npos)
        {
            cout << "Bot: DSA stands for Data Structures and Algorithms.\n";
        }
        else if (userInput.find("time") != string::npos)
        {
            cout << "Bot: Sorry, I cannot access the current time.\n";
        }
        else if (userInput.find("thank") != string::npos)
        {
            cout << "Bot: You're welcome!\n";
        }
        else
        {
            cout << "Bot: Sorry, I don't understand that question.\n";
        }
    }

    return 0;
}
