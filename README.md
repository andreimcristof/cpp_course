# _
pet project for the lolz. learning c++ to understand differences to c#

##### gotchas

- declaration is in header files. Implementation is in cpp files. 
- classes cannot be redeclared in the implementation cpp, must access members by namespace to implement them
- unlike c#, in c++ there can be members declared directly in the namespace,  essentially fulfilling the role of static. 

##### compilation

g++ -o /tmp/output.sh *.cpp -std=c++14

