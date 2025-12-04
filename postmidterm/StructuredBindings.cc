/*
in general:
    - using class implies abstraction + invariants
    - using structs implies a collection of public info/data
*/

for (auto &[key, value] : m) { // structured binding on a map
    cout << key << value;
}

// only works if all the fields (in the binding) ARE PUBLIC

struct vec {
    int x, y
};

vec v{6, 7};
auto [x, y] : v // works

// also works with FIXED SIZED STACK ARRAYS
int arr[] = [1, 2, 3, 4, 5];
auto[x, y, z] = arr;
cout << x, y, z;
