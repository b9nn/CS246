/*
strcmp(s1, s2)

< 0 ===> s1 < s2
= 0 ===> s1 == s2
> 0 ===> s1 > s2 

*/



// want a more efficient way to compare strings

#include <compare>
#include <string>

string s1 = "ben";
string s2 = "jamin";

std::strong_ordering result = s1 <=> s2;

if result < 0 // then s1 < s2
if result = 0 // then s1 = s2
if result > 0 // then s1 > s2

// shortcut 
auto x = expr // type of x = type of expr

// adding <=> to vec

class vec {
    int x, y;
    public:
    std::strong_ordering operator<=>(const vec v){
        auto result = x <=> v.x; // not the overlaoded version bc this is acting on ints
        return (result == 0) ? y <=> v.y : res
    }
}

int main() {
    int y = 5;
    int &&x = y;
}