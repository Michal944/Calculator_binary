#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

int u1_u2_minus(const int &value, unsigned short &N)
{
    
    int VALUE_END;
    value<0 ? VALUE_END=(-1)*value : VALUE_END=value;
    int buf=1;
    while(buf<=VALUE_END)
    {    
        buf*=2;
        N++;
    }
    
    return buf;
}

void view_all(std::vector<unsigned short> &VEC)
{
    std::vector<unsigned short>::const_iterator iter;
    iter=VEC.cend();
    while(iter!=VEC.cbegin())
    {
        iter--;
        cout<<*iter;
    }
    cout<<endl;
}

class Cal
{
    std::vector<unsigned short> u1;
    std::vector<unsigned short> u2;
    std::vector<unsigned short> zm;
    std::vector<unsigned short> bcd;
    std::vector<unsigned short> bias;
    int value;
    unsigned short N_class;
    public:
        friend int u1_u2_minus(const int &value, unsigned short &N);
        friend void u1_u2_part2(int &buf, 
                                unsigned short &N,
                                std::vector<unsigned short> &u1);
        friend void view_all(std::vector<unsigned short> &VEC);
        void value_f(int v);
        void u1_f();
        void u2_f();
        void zm_f();
        void bcd_f();
        void bias_f();
};

void Cal::value_f(int v){ value=v;}

void u1_u2_part2(const int &buf, unsigned short &N, 
        std::vector<unsigned short> &u1)
{
    int n=0;
    int buf2=buf;
    while(n<N)
    {
       if(buf2%2==0)
           u1.push_back(0);
       else 
           u1.push_back(1);
       buf2/=2;
       n++;
    }
}


void Cal::u1_f()
{
    int buf;
    unsigned short N=0;
    if(value<0)
    {
        buf=u1_u2_minus(value,N);
        buf-=((-1*value)+1); //U1
        u1_u2_part2(buf,N, u1);
        u1.push_back(1);
    }
    else
    {
        buf=u1_u2_minus(value,N);
        u1_u2_part2(value,N,u1);
        u1.push_back(0);
    }
        cout<<"U1: ";
        view_all(u1);
    N_class=N;
    u1.clear();

}
void Cal::u2_f()
{
    
    int buf;
    unsigned short N=0;
    if(value<0)
    {
        buf=u1_u2_minus(value,N);
        buf+=value; //U2
        u1_u2_part2(buf,N, u2);
        u2.push_back(1);
    }
    else
    {
        u1_u2_minus(value,N);
        u1_u2_part2(value,N,u2);
        u2.push_back(0);
    }
        cout<<"U2: ";
        view_all(u2);
        u2.clear();

}

void Cal::zm_f()
{   
    int value_2;
    value<0 ? value_2=(-1*value) : value_2=value;
    u1_u2_part2(value_2,N_class,zm);
    value<0 ? zm.push_back(1) : zm.push_back(0);
    cout<<"ZM: ";
    view_all(zm);
    zm.clear();
}
void Cal::bias_f()
{
     int buf;
    unsigned short N=0;
    int value_b=value-128;
    if(value_b<0)
    {
        buf=u1_u2_minus(value_b,N);
        buf+=value_b; //Bias
        u1_u2_part2(buf,N, bias);
        bias.push_back(1);
    }
    else
    {
        u1_u2_minus(value,N);
        u1_u2_part2(value,N,bias);
        bias.push_back(0);
    }
        cout<<"BS: ";
        view_all(bias);
        bias.clear();

}

int main()
{
    Cal p1;
    char *s;
    s=new char[2];
    int choose;
    while(true)
    {
    cout<<"DECIMAL: ";
    cin>>s;
    
    if(s[0]=='q')
        break;
    choose=atoi(s);
    p1.value_f(choose);
    p1.u1_f();
    p1.u2_f();
    p1.zm_f();
    p1.bias_f();
    cin.clear();
    cin.ignore(1000, '\n');
    }

    delete [] s;
}





















