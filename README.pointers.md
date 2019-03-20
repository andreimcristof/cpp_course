## Pointers

`int myInt = 2;`

Since it's an int, `myInt` will be allocated 4 bytes of memory in the physical hardware, at a certain address. To locate the address, the position of the first byte is used and represented in hexadecimal.

Pointers are addresses to memory locations. The address can be used to read its contents. 

## Why know a variable's adddress 

It's more efficient to pass memory addresses, than passing actual variables around. E.g. when passing a struct to a function, what happens is that every element in the struct (variables, functions) are being copied over in a temp local struct , to satisfy the parameter demands of that function. If the struct is large, you're creating a copy of a very large thing. Passing around large objects slows things down. 

## Solution

Instead of  duplicating the object itself, you just pass an address to the initial object. That tells anyone who is interested in the object, where it can be located. If all you needed was to access some string variable in that object, just locate the object using the address pointer, and access the variable as needed. This will not copy the entire struct. 

`int* ptrToMyInt;` 
This is an uninitialized pointer to an int. It is not an int. Pointers don't have to be initialized. 
This particular pointer can only be initialized with an address to some integer variable. 

`ptr = &myInt;`

Here we initialize the pointer created above with the address of the first byte in memory that stores `myInt`.

Memory addresses are initialized with the accessor `&` (ampersand character). Addresses are just simple hexadecimal numbers. 


Accessing the stored value in the memory address 
`cout << *ptr;`

...is called "dereferencing the pointer".

## delete
Only pointers initialized with `new` can be freed with delete!

example: 
`int* intPtr = new int;` 
can call delete on this pointer

`string name { "Name1" }; string* namePtr { &name };`  
cannot call delete