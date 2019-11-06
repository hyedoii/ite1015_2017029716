#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include "reply_admin.h"

using namespace std;

ReplyAdmin::ReplyAdmin() {
    list<string> chats;
    list<string>::iterator it;
}

ReplyAdmin::~ReplyAdmin() {}

bool ReplyAdmin::addChat(string _chat) {
    this->chats.push_back(_chat);
    
    return true;
}

bool ReplyAdmin::removeChat(int _index) {
    this->chats.erase(this->chats.begin() + _index);
    return true;
}

bool ReplyAdmin::removeChat(int *_indices, int _count) {
    int count = this->chats.size();
    for(int i = _count - 1; i >= 0; i--){
        this->chats.erase(this->chats.begin() + _indices[i]);
    }
    return true;
}

bool ReplyAdmin::removeChat(int _start, int _end) {
    int count = this->chats.size();
    if(_start < 0) _start = 0;
    if(_end > count - 1) _end = count - 1;
    for(int i = _end; i >= _start; i--){
        this->chats.erase(this->chats.begin() + i);
    }
    return true;
}

void ReplyAdmin::printChat() {
    int count = this->chats.size();
    for(int i=0; i< count; ++i)
    {
        cout << i << " " << chats[i] << endl;
    }
}

