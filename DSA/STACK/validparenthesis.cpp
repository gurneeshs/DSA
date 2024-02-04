/*
    You are given an expression of bracket like {}, {()}, {(]}
    You have to check whether the expressions are valid or not, i.e. for each opening bracket, there
    should be a closing bracket in correct order
*/
#include <iostream>
#include <stack>
using namespace std;

bool match(char top, char ch){
    if(ch=='}' && top=='{'){
        return true;
    }
    else if(ch==')' && top=='('){
        return true;
    }
    else if(ch==']' && top=='['){
        return true;
    }
    else{
        return false;
    }
}
bool isValidParenthesis(string s)
{
    int len = s.length();
    stack<char> st;
    char ch;

    for (int i = 0; i < len; i++) {
      ch = s[i];
      if (ch == '}'||ch==')'||ch==']'){
          if(!st.empty()){
              char top = st.top();
              bool result = match(top,ch);
              if(!result){
                  return false;
              }
              else{
                  st.pop();
              }
          }
          else if(st.empty()){
              return false;
          }
      }
      else{
          st.push(ch);
      }
    }
    return true;
}
