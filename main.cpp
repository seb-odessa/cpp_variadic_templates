#include <iostream>
#include <string>


template<typename F, typename... T>
void call(F&& f, T&&... t)
{
    f(std::forward<T>(t)...);
}


struct Obj {
    void operator()(){std::cout<<"()";}

    template<typename T>
    void operator()(const T& v){std::cout<<"("<<v<<")";}

    template<typename Head, typename... Tail>
    void operator()(const Head& head, const Tail&... tail){
	std::cout<<"("<<head<<" ";
        operator()(tail...);
	std::cout<<")";
    }
};

int main() {

    Obj o;
    call(o);
    std::cout<<"\n";
    call(o, 1);
    std::cout<<"\n";
    call(o, true, 1, 2.5, "!!!");
    std::cout<<"\n";
    call(o, true, 1, 2.5, "!!!", std::string{"string"});
    std::cout<<"\n";

    std::cout<<"Done"<<std::endl;
}
