#include<iostream>
using namespace std;
class Person{
    private:
    int m_age;
    string m_name;
    public:
    void setName(string name)
    {
        m_name=name;
    }
    string getName()
    {
        return m_name;
    }
};
int main()
{
    Person s1;
    s1.setName("234324");
    cout<<s1.getName()<<endl;
}