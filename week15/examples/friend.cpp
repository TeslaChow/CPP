#include <iostream>
using namespace std; // 此处文件对应于视频 P67 9mins 处

class Sniper; // 3.在另一个类的上面声明本类；

class Supplier
{
    int storage;
public:
    Supplier(int storage = 1000): storage(storage){}

    // bool foo(Sniper & sniper){sniper.bullets++;}
    bool provide(Sniper & sniper);
};

class Sniper
{
private:
    int bullets;
public:
    Sniper(int bullets = 0): bullets(bullets){}
    // friend class Supplier;
    friend bool Supplier::provide(Sniper & sniper); // 当把另一个类的函数作为本类的友元/朋友时，要注意防止 出现循环导入，这时可以 1.先在本类中声明另一个类的函数作为友元函数；2.将该友元函数的定义写在本类的外部下面；3.在另一个类的上面声明本类；
};

    bool Supplier::provide(Sniper & sniper) // 2.将该友元函数的定义写在本类的外部下面
    {
        // bullets is a private member
        if (sniper.bullets < 20) //no enough bullets
        {
            if (this->storage > 100 )
            {
                sniper.bullets += 100;
                this->storage -= 100;
            }
            else if(this->storage > 0)
            {
                sniper.bullets += this->storage;
                this->storage = 0;
            }
            else
                return false;
        }
        cout << "sniper has " << sniper.bullets << " bullets now." << endl;
        return true;
    }

int main()
{
    Sniper sniper(2);
    Supplier supplier(2000);
    supplier.provide(sniper);
    return 0;
}