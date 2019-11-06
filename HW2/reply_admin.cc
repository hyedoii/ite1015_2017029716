#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

const int NUM_OF_CHAT = 200;

int getChatCount(string *_chatList)
{
	int i;
	for(i=0;i<NUM_OF_CHAT; ++i)
	{
		string s = _chatList[i];
		if(s.empty() == true) break;
	}
	return i;
}

void printChat(string *_chatList)
{
	int count = getChatCount(_chatList);
	for(int i = 0 ; i<count; ++i)
	{
		cout << i << " "<< _chatList[i] << endl;
	}
}

bool addChat(string *_chatList, string _chat){
    int count = getChatCount(_chatList);
    _chatList[count] = _chat;
    return true;
}
bool removeChat(string *_chatList, int _index){
    int i = 0;
    int count = getChatCount(_chatList);
    
        for(i=0;i<count;++i){
            _chatList[_index] = _chatList[_index+1];
            _index = _index + 1;
        }
    return true;
}

int main(void)
{
    string* chats = new string[NUM_OF_CHAT];
    
    addChat(chats, "Hello, Reply Administrator!");
    addChat(chats, "I will be a good programmer.");
    addChat(chats, "This class is awesome.");
    addChat(chats, "Professor Lim is wise.");
    addChat(chats, "Two TAs are kind and helpful.");
    addChat(chats, "I think TAs look cool.");
    
    while(true)
    {
        string command;
        getline(cin, command);
        
        if(command == "#quit") break;
        else if(command.find("remove") != -1)
        {
            if(command.find("-") != -1){
                
                int charTemp1, charTemp2;
                int n = command.size();
                int index, count, i = 0;
            
                charTemp1 = command[n-3] - 48;
                charTemp2 = command[n-1] - 48;
                
                count = charTemp2 - charTemp1;
                
                index = charTemp1;
                
                for(i = 0; i<count ; ++i){
                    removeChat(chats,index);
                }
                printChat(chats);
            }
            
            else if(command.find(",") != -1){
                int i = 0, n = 1;
                int index = command.size()-1;
                int arr[200] = {0};
                for(i = 0; i<command.size(); ++i){
                    if(command[i] == ',') n++;
                }
                for(i = 0; i < n ;i++){
                    arr[i] = command[index] - 48;
                    removeChat(chats, arr[i]);
                    index = index - 2;
                }
                printChat(chats);
            }
            else{
                int index;
                index = command[command.size()-1] - 48;
            
                if(removeChat(chats, index) == true)
                    printChat(chats);
            }
        }
        else if(addChat(chats, command))
            printChat(chats);
    }
    
    //delete chatting list
    delete[] chats;
    
    return 0;
}
