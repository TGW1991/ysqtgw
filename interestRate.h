#ifndef INTERESTRATE_H
#define INTERESTRATE_H
using namespace std;
class interestrate 
       {
           private:
                    string owner;
                    double money_US;
                    double money_CH;
                    static double int_rate;
                    
                    
           public:
                    interestrate(string s,double m_U):owner(s),money_US(m_U),money_CH(m_U*int_rate) {}
                    interestrate():interestrate(" ",0.0) {}
                    double inter() {return int_rate;}
                    void do_display(ostream &is) const {is<<owner<<"     "<<money_US<<"      "<<money_CH<<endl;}
                    interestrate display(ostream &s){do_display(s);return *this;}
                    void rate(double r_rate);
                    
       };
        void interestrate::rate(double r_rate)
           {
               int_rate=r_rate;
           }
#endif