#include <iostream>

using namespace std;
class complex{
  private:
  int real, imag;
  public:
  complex(int r = 0, int i = 0){
      real = r;
      imag = i;
  }
  complex operator + (complex const &obj){
      complex res;
      res.real = real + obj.real;
      res.imag = imag + obj.imag;
      return res;
      
  }
  complex operator * (complex const &obj){
      complex res;
      res.real = ((real)*(obj.real)) - ((imag)*(obj.imag));
      res.imag = ((real)*(obj.imag)) + ((obj.real)*(imag));
      return res;
  }

friend ostream & operator << (ostream &out,complex &obj);
friend istream & operator >> (istream &in,complex &obj);
};
ostream & operator << (ostream &out,complex &obj){
    out<<obj.real;
    out<<"+i"<<obj.imag;
    return out;
}
istream & operator >> (istream &in,complex &obj){
    cout<<"\n Enter real part: ";
    in>>obj.real;
    cout<<"\n Enter imaginary part: ";
    in>>obj.imag;
    return in;
}
int main()
{
    complex c1,c2,c3,c4;
    cout<< "\n Enter first number:";
    cin>>c1;
    cout<< "\n Enter second number:";
    cin>>c2;
    c3 = c1 + c2;
    cout<<"\n Addition is : "<<c3;
    c4 = c1 * c2;
    cout<<"\n Multiplication is : "<<c4;
    return 0;
}