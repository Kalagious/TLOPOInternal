

1. Module functions have two purposes, to setup things used within them, and then to actually call them

```python
def hello_world(a, b):
    x = [ 5 ]
    x.append(a)
    x.append(b)
    print(x)

def goodbye_world(x):
    print(x)


hello_world(6, 7)
hello_world(7, 8)
goodbye_world("test")
```

The code would be transformed like so:
	1. Define the hello_world and goodbye world functions with modified names (_main__module_4_hello_world_38_2_4_), these functions can be interpreted 1 to 1 and will be called with each call of the original function, the code in these is pretty simple and is essentially the python code in c++
	2. There is a function for the main module called _main_MODULE_ that sets up both functions using the process described in "Setting Up Functions". The fuctions are set up once, and can then be called multiple times
	3. Then the functions are called in _main_MODULE_ using the process in Calling Functions 