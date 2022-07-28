<h2>Calling the hello_world(a, b) Function</h2>
```python
hello_world(6, 7)
```


1. The function object is pulled from the frame using \_\_pypperoni\_IMPL\_load\_name, this function takes in a PyString of the function name and returns the function object with the name in the locals dictionary of the frame, the returned function object is then pushed to the stack
```c++
 x = __pypperoni_IMPL_load_name(f, __consts_main[21]); /* 'hello_world' */
PUSH(x);
```

2. All required parameters are then loaded and pushed to the stack, in this case PyLongs 6 and 7
```c++
x = __consts_main[22]; /* 6 */
PUSH(x);
 
x = __consts_main[23]; /* 7 */
PUSH(x);
```

3. __pypperoni_IMPL_call_func__ is then called with the stack pointer and the amount of arguments, it returns the PyObject that the called function returns if it does return one, a pointer the kwargs is also passed in if they exist, the result is pushed to the stack
```c++
v = NULL;
u = __pypperoni_IMPL_call_func(&stack_pointer, 2, v);
PUSH(u);

```

**Note: Calling arugments are passed in through f_localsplus in the frame, all variables are stored in the f_localsplus dictionary of the frame (including class instances)** 
<h2>Complete Code Flow</h2>
```c++
 x = __pypperoni_IMPL_load_name(f, __consts_main[21]); /* 'hello_world' */
PUSH(x);

x = __consts_main[22]; /* 6 */
PUSH(x);

x = __consts_main[23]; /* 7 */
PUSH(x);

v = NULL;
u = __pypperoni_IMPL_call_func(&stack_pointer, 2, v);
PUSH(u);
```



<h2>Rogue Implementation</h2>
Hooking __pypperoni_IMPL_call_func__ would be invaluable because it would effectively hook every python function at once, if called the stack could be modified before code execution, the name of the function could be found within the function object on the stack

It would be pretty easy to recreate the call process and call functions manually, the main roadblock would be finding the frames. __pypperoni_IMPL_load_name__ could be hooked and used to create a map of frame objects and their functions, from there on functions could be called at will 
Here is a c++ recreation for hello_world

```c++
PyFrameObject* frame = (frameAddress);

PyLongObject* rogueHello_World(PyLongObject* a, PyLongObject* b)
{
	uint64_t stack[3];
	PyString* helloWorldPyStr = RoguePyString("hello_world");
	
	stack[0] = PyDict_GetItem(frame, helloWorldPyStr)
	stack[1] = a;
	stack[2] = b;

	return __pypperoni_IMPL_call_func(stack, 2, NULL);
}



PyLongObject* a = RoguePyInt(6);
PyLongObject* b = RoguePyInt(7);
rogueHello_World(a, b); // Returns a PyIntObject of 13
```