# include <iostream>
# include <string>
# include "reply_admin.h"
# include <algorithm>

using namespace std;

int ReplyAdmin::getChatCount() {
    int i;
    for(i = 0; i < NUM_OF_CHAT; ++i) {
        string s = chats[i];
        if(s.empty() == true) break;
    }
    return i;
}
ReplyAdmin::ReplyAdmin() {
    chats = new string[NUM_OF_CHAT];
    addChat("Hello, Reply Administrator!");
    addChat("I will be a good programmer.");
    addChat("This class is awesome.");
    addChat("Professor Lim is wise.");
    addChat("Two TAs are kind and helpful.");
    addChat("I think male TA looks cool.");
}
ReplyAdmin::~ReplyAdmin() {
    delete[] chats;
}
bool ReplyAdmin::addChat(string _chat) {
    if(getChatCount() >= NUM_OF_CHAT) return false;
    chats[getChatCount()] = _chat;
    return true;
}
bool ReplyAdmin::removeChat(int _index) {
    if(getChatCount() -1 <_index) return false;
    int i;
    for(i = _index; i < getChatCount() - 1;i++) {
        chats[i] =chats[i + 1];
    }
    chats[i] = "";
    return true;
}           // #remove #
bool ReplyAdmin::removeChat(int *_indices, int _count) {
    int isChange = 0;
    for(int i = _count - 1; i >= 0; i--) {
        isChange += removeChat(_indices[i]);
    }
    if(isChange) return true;
    return false;
} // #remove #,#,#,#
bool ReplyAdmin::removeChat(int _start, int _end) {
    int isChange = 0;
    if(_start > _end) {
        int c =_start;
        _start = _end;
        _end = c;
    }
    for(int i = _end; i >= _start; i--) {
        isChange += removeChat(i);
    }
    if(isChange) return true;
    return false;
}      // #remove #-#
void ReplyAdmin::printChat() {
    for(int i = 0; i < getChatCount(); ++i) {
        cout << i << " " << chats[i] << endl;
    }
}
