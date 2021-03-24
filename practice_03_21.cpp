//
// Created by 19116 on 2021/3/21.
//

//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//class StringBad{
//private:
//    char* str;
//    int len;
//    static int num_strings;
//public:
//    StringBad(const char* s);
//    StringBad();
//    ~StringBad();
//    StringBad(const StringBad& st);
//    StringBad& operator = (const StringBad& st);
//    friend ostream& operator << (ostream& os,const StringBad& st);
//};
//int StringBad::num_strings = 0;
//StringBad& StringBad::operator = (const StringBad& st){
//    if(this == &st) return *this;
//    delete[] str;
//    len = st.len;
//    str = new char[len + 1];
//    strcpy(str,st.str);
//    return *this;
//}
//
//StringBad::StringBad(const StringBad& st) {
//    num_strings ++;
//    len = st.len;
//    str = new char[len + 1];
//    strcpy(str,st.str);
//    cout << num_strings << ": \"" << str << "\" object created\n";
//}
//StringBad::StringBad(const char* s){
//    len = strlen(s);
//    str = new char[len + 1];
//    strcpy(str,s);
//    num_strings ++;
//    cout << num_strings << ": \"" << str << "\" object created\n";
//}
//StringBad::StringBad() {
//    len = 4;
//    str = new char[4];
//    strcpy(str,"C++");
//    num_strings ++;
//    cout << num_strings << ": \"" << str << "\"default object created\n" ;
//}
//StringBad::~StringBad() {
//    cout << "\"" << str << "\" object deleted, ";
//    -- num_strings;
//    cout << num_strings << " left\n";
//    delete []str;
//}
//
//ostream& operator << (ostream& os,const StringBad& st) {
//    os << st.str;
//    return os;
//}
//void callme1(StringBad &rsb){
//    cout << "String passed by reference:\n";
//    cout << "   \"" << rsb << "\"\n" ;
//}
//
//void callme2(StringBad sb){
//    cout << "String passed by value:\n";
//    cout << "   \"" << sb << "\"\n";
//}
//int main(){
//    {
//        cout << "starting an inner block.\n";
//        StringBad headline1("Celery Stalks at Midnight");
//        StringBad headline2("Lettuce Prey");
//        StringBad sports("Spinach Leaves Bowl for Dollars");
//        cout << "headline1:" << headline1 << endl;
//        cout << "headline2:" << headline2 << endl;
//        cout << "sports: " << sports << endl;
//        callme1(headline1);
//        cout << "headline1: " << headline1 << endl;
//        callme2(headline2);
//        cout << "headline2: " << headline2 << endl;
//        cout << "Initialize one object to another:\n";
//        StringBad sailor = sports;
//        cout << "sailor: " << sailor << endl;
//        cout << "Assign one object to another:\n";
//        StringBad knot;
//        knot = headline1;
//        cout << "knot: " << knot << endl;
//        cout << "Exiting the block.\n";
//    }
//    cout << "End of main()\n";
//    return 0;
//}

//
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//class String{
//private:
//    char* str;
//    int len;
//    static int num_strings;
//    static const int CINLIM = 80;
//public:
//    String(const char* s);
//    String();
//    String(const String& s);
//    ~String();
//    int length() const{return len;}
//
//    String& operator = (const String& );
//    String& operator = (const char *);
//    char& operator[](int i);
//    const char& operator [](int i) const;
//
//    friend bool operator < (const String& st,const String& st2);
//    friend bool operator > (const String& st,const String st2);
//    friend bool operator == (const String& st,const String st2);
//    friend ostream& operator << (ostream& os,const String& st);
//    friend istream& operator >> (istream& is,String& st);
//
//    static int HowMany();
//};
//
//int String::num_strings = 0;
//String::String(const char* s){
//    len = strlen(s);
//    str = new char[len + 1];
//    strcpy(str,s);
//    num_strings ++;
//}
//String::String(){
//    len = 4;
//    str = new char[1];
//    str[0] = '\0';
//    num_strings ++;
//}
//String::String(const String& s) {
//    num_strings ++;
//    len = s.len;
//    str = new char[len + 1];
//    strcpy(str,s.str);
//
//}
//String::~String(){
//    -- num_strings;
//    delete [] str;
//}
//
//String& String::operator = (const String& st) {
//    if(this == &st) return *this;
//    delete[] str;
//    len = st.len;
//    str = new char[len + 1];
//    strcpy(str,st.str);
//    return *this;
//}
//String& String::operator = (const char * s) {
//    delete[] str;
//    len = strlen(s);
//    str = new char[len + 1];
//    strcpy(str,s);
//    return *this;
//}
//char& String::operator[](int i) {
//    return str[i];
//}
//const char& String::operator [](int i) const {
//    return str[i];
//}
//
//bool operator < (const String& st,const String& st2) {
//    return (strcmp(st.str,st2.str) < 0);
//}
//bool operator > (const String& st,const String st2){
//    return st2 < st;
//}
//bool operator == (const String& st,const String st2) {
//    return (strcmp(st.str,st2.str) == 0);
//}
//ostream& operator << (ostream& os,const String& st) {
//    os << st.str;
//    return os;
//}
//istream& operator >> (istream& is,String& st) {
//    char tmp[String::CINLIM];
//    is.get(tmp,String::CINLIM);
//    if(is) st = tmp;
//    while(is && is.get() != '\n');
//    return is;
//}
//
//int String::HowMany(){
//    return num_strings;
//}
//const int ArSize = 10;
//const int MaxLen = 81;
//int main(){
//    String name;
//    cout << "Hi, what's your name? \n>> " ;
//    cin >> name;
//
//    cout << name << ", please enter up to " << ArSize
//    << " short sayings <empty line to quit>:\n";
//    String sayings[ArSize];
//    char tmp[MaxLen];
//    int i;
//    for(i = 0;i < ArSize;i ++){
//        cout << i + 1 << ": " ;
//        cin.get(tmp,MaxLen);
//        while(cin && cin.get() != '\n') continue;
//        if(!cin || tmp[0] == '\0') break;
//        else sayings[i] = tmp;
//    }
//    int total = i;
//
//    if(total > 0){
//        cout << "Here are your sayings:\n";
//        for(i = 0;i < total;i ++)
//            cout << sayings[i][0] << ": " << sayings[i] << endl;
//        int shortest = 0;
//        int first = 0;
//        for(i = 1;i < total;i ++){
//            if(sayings[i].length() < sayings[shortest].length())
//                shortest = i;
//            if(sayings[i] < sayings[first]) first = i;
//        }
//        cout << "Shortest saying:\n" << sayings[shortest] << endl;
//        cout << "First alphabetically:\n" << sayings[first] << endl;
//        cout << "This program used " << String::HowMany()
//        << " String objects. Bye.\n" ;
//    }
//    else cout << "No input!" << endl;
//    return 0;
//}


